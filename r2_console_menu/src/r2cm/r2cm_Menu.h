#pragma once

#include <memory>
#include <string_view>
#include <vector>

#include "r2cm_DoLeaveAction.h"

namespace r2cm
{
	class Director;
	class iItem;
	class iMenuWriter;

	class Menu
	{
	private:
		struct ItemInfo
		{

			ItemInfo(
				const char key_code
				, const int color_code
				, const r2cm::TitleFunctionT title_function
				, const r2cm::DoFunctionT do_function
			) :
				KeyCode( key_code )
				, ColorCode( color_code )
				, TitleFunction( title_function )
				, DoFunction( do_function )
			{}

			char KeyCode;
			int ColorCode;
			r2cm::TitleFunctionT TitleFunction;
			r2cm::DoFunctionT DoFunction;
		};

		using ItemContainerT = std::vector<ItemInfo>;

	public:
		Menu( Director& director );

		void Reset( const iMenuWriter& menu_obj );

		void ShowTitle() const;
		void ShowDescription() const;
		void ShowItems() const;

		eDoLeaveAction Do( const int key_code );

		void AddItem( const char key_code, const int color_code, const r2cm::TitleFunctionT& func_title, const r2cm::DoFunctionT& func_do );
		void AddItem( const char key_code, const r2cm::TitleFunctionT& func_title, const r2cm::DoFunctionT& func_do );
		void AddItem( const char key_code, const iItem& item_obj );

		void AddMenu( const char key_code, const iMenuWriter& menu_obj );

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