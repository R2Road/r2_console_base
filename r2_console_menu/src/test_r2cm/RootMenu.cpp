#include "RootMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_VersionInfo.h"

#include "test_r2cm/base_test.h"
#include "test_r2cm/color_test.h"
#include "test_r2cm/empty_test.h"
#include "test_r2cm/inspector_test.h"
#include "test_r2cm/key_test.h"
#include "test_r2cm/window_utility_test.h"

#include "test_r2cm/AnotherMenu.h"

const char* RootMenu::GetTitle()
{
	static const std::string ret =
		std::string( "Root Menu" )
		+ " : <" + r2cm::VersionInfo.String4Version + ">";
	return ret.c_str();
}

r2cm::MenuUp RootMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu(
		director
		, GetTitle()
		, r2cm::VersionInfo.String4Road2Version_1_0_0
	) );

	{
		ret->AddMessage( "\t<Menu ��ü�� test �� ���� iItem ��ü�� ���� �޴��� ���� Menu ��ü�� �߰� ����.>" );



		ret->AddLineFeed();



		ret->AddItem( '1', empty_test::Basic::GetInstance() );
		ret->AddItem( '2', empty_test::Basic::GetInstance() );
		ret->AddItem(
			'3'
			, r2cm::None
			, []()->const char* { return "Show Title With Lambda"; }
			, []()->r2cm::eItemLeaveAction
			{
				std::cout << "##### Show Title With Lambda #####" << r2cm::linefeed2;
				return r2cm::eItemLeaveAction::Pause;
			}
		);



		ret->AddLineFeed();



		ret->AddItem(
			'5'
			, r2cm::None
			, []()->const char* { return AnotherMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( AnotherMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
		ret->AddMessage( "\t> Another Menu �� ���� �޴��� ���� �Դϴ�." );
		ret->AddMenu<AnotherMenu>( '6' );
		ret->AddMessage( "\t> AddMenu �Լ��� ����ϸ� �޴� �̸��� ������ ���� �˴ϴ�." );



		ret->AddLineFeed();



		ret->AddItem( 'q', key_test::Basic::GetInstance() );
		ret->AddItem( 'w', color_test::Basic::GetInstance() );



		ret->AddLineFeed();



		ret->AddItem( 'a', inspector_test::Basic::GetInstance() );
		ret->AddItem( 's', inspector_test::Value::GetInstance() );
		ret->AddItem( 'd', inspector_test::Binary::GetInstance() );
		ret->AddItem( 'f', inspector_test::ShowFile::GetInstance() );



		ret->AddLineFeed();



		ret->AddItem( 'z', base_test::TestEndAction_None::GetInstance() );
		ret->AddItem( 'x', base_test::TestEndAction_Pause::GetInstance() );
		ret->AddItem( 'c', base_test::TestEndAction_Exit::GetInstance() );



		ret->AddLineFeed();



		ret->AddItem( 'b', window_utility_test::MoveCursorWithClearBuffer::GetInstance() );
		ret->AddItem( 'n', window_utility_test::FillColor::GetInstance() );



		ret->AddSplit();



		ret->AddItem(
			27
			, r2cm::None
			, []()->const char* { return "Exit"; }
			, []()->r2cm::eItemLeaveAction { return r2cm::eItemLeaveAction::Exit; }
		);
	}

	return ret;
}