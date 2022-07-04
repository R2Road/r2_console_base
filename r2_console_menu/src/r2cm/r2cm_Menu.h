#pragma once

#include <functional>
#include <memory>
#include <string_view>
#include <vector>

namespace r2cm
{
	enum class eItemLeaveAction; 

	class iItem;
	class Director;

	using MenuUp = std::unique_ptr<class Menu>;
	class Menu
	{
	private:
		struct ItemInfo
		{
			ItemInfo(
				const char key_code
				, const std::function<const char*( )> name_function
				, const std::function<const r2cm::eItemLeaveAction()> do_function
			) :
				KeyCode( key_code )
				, NameFunction( name_function )
				, DoFunction( do_function )
			{}

			char KeyCode;
			std::function<const char*()> NameFunction;
			std::function<const r2cm::eItemLeaveAction()> DoFunction;
		};

		using ItemContainerT = std::vector<ItemInfo>;

	public:
		Menu( Director& director, const char* title_string, const char* description_string = "" );
		virtual ~Menu() {}

		void ShowTitle() const;
		void ShowDescription() const;
		void ShowMenu() const;

		eItemLeaveAction Do( const int key_code );

		void AddItem( const char key_code, iItem& item_obj );
		void AddItem( const char key_code, const std::function<const char*()> func_title, const std::function<const r2cm::eItemLeaveAction()> func_do );
		
		template<typename menu_T>
		void AddMenu( const char key_code )
		{
			AddItem(
				key_code
				, []()->const char* { return menu_T::GetTitle(); }
				, [&director = mDirector]()->r2cm::eItemLeaveAction
				{
					director.Setup( menu_T::Create( director ) );
					return r2cm::eItemLeaveAction::None;
				}
			);
		}

		void AddLineFeed();
		void AddSplit();
		void AddMessage( const char* const message );

	protected:
		Director& mDirector;
		std::string_view mTitleString;
		std::string_view mDescriptionString;

		ItemContainerT mItemContainer;
	};
}