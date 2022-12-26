#include "base_test.h"

#include <conio.h> // _getch

#include "r2cm/r2cm_ostream.h"

namespace base_test
{
	r2cm::TitleFunctionT TestEndAction_None::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Base : TestEndAction_None";
		};
	}
	r2cm::DoFunctionT TestEndAction_None::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			std::cout << r2cm::tab2 << "Press [ESC] Key" << r2cm::linefeed;

			do
			{
			} while( 27 != _getch() );

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::None;
		};
	}



	r2cm::TitleFunctionT TestEndAction_Pause::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Base : TestEndAction_Pause";
		};
	}
	r2cm::DoFunctionT TestEndAction_Pause::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			std::cout << r2cm::tab2 << "Press [ESC] Key" << r2cm::linefeed;

			do
			{
			} while( 27 != _getch() );

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT TestEndAction_Exit::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Base : TestEndAction_Exit";
		};
	}
	r2cm::DoFunctionT TestEndAction_Exit::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			std::cout << r2cm::tab2 << "Press [ESC] Key" << r2cm::linefeed;

			do
			{
			} while( 27 != _getch() );

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Exit;
		};
	}
}