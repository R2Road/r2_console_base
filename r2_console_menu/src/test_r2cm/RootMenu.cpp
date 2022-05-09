#include "pch.h"
#include "RootMenu.h"

#include "r2cm/r2cm_constant.h"
#include "r2cm/r2cm_Director.h"

#include "test_r2cm/base_test.h"
#include "test_r2cm/empty_test.h"
#include "test_r2cm/inspector_test.h"
#include "test_r2cm/key_test.h"

#include "test_r2cm/AnotherMenu.h"

r2cm::MenuUp RootMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu(
		director
		, GetTitle(),
				"> Inprogress : BlaBla"
		"\n"	"> To do : BlaBla"
		"\n"	"> To do : BlaBla"
		"\n"	"> To do : BlaBla"
	) );

	{
		ret->AddItem( '1', empty_test::Basic::GetInstance() );
		ret->AddItem( '2', empty_test::Basic::GetInstance() );
		ret->AddItem(
			'3'
			, []()->const char* { return "Show Title With Lambda"; }
			, []()->r2cm::eTestEndAction
			{
				std::cout << "##### Show Item With Lambda #####" << r2cm::linefeed2;
				return r2cm::eTestEndAction::Pause;
			}
		);



		ret->AddLineFeed();



		ret->AddItem(
			'5'
			, []()->const char* { return AnotherMenu::GetTitle(); }
			, [&director]()->r2cm::eTestEndAction
			{
				director.Setup( AnotherMenu::Create( director ) );
				return r2cm::eTestEndAction::None;
			}
		);



		ret->AddLineFeed();



		ret->AddItem( 'q', key_test::Basic::GetInstance() );



		ret->AddLineFeed();



		ret->AddItem( 'a', inspector_test::Basic::GetInstance() );
		ret->AddItem( 's', inspector_test::ShowFile::GetInstance() );



		ret->AddLineFeed();



		ret->AddItem( 'z', base_test::TestEndAction_None::GetInstance() );
		ret->AddItem( 'x', base_test::TestEndAction_Pause::GetInstance() );
		ret->AddItem( 'c', base_test::TestEndAction_Exit::GetInstance() );



		ret->AddSplit();



		ret->AddItem(
			27
			, []()->const char* { return "Exit"; }
			, []()->r2cm::eTestEndAction { return r2cm::eTestEndAction::Exit; }
		);
	}

	return ret;
}