#include "InspectorMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "RootMenu.h"

#include "test_r2cm/inspector_test.h"

r2cm::MenuUp InspectorMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu(
		director
		, GetTitle()
	) );

	{
		ret->AddItem( '1', inspector_test::Basic::GetInstance() );
		ret->AddItem( '2', inspector_test::Value::GetInstance() );



		ret->AddLineFeed();



		ret->AddItem( 'q', inspector_test::Binary::GetInstance() );
		ret->AddItem( 'w', inspector_test::Binaries::GetInstance() );



		ret->AddLineFeed();



		ret->AddItem( 'a', inspector_test::ShowFile::GetInstance() );



		ret->AddLineFeed();



		ret->AddSplit();



		ret->AddMenu<RootMenu>( 27 );
	}

	return ret;
}