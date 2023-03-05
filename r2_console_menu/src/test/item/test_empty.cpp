#include "test_empty.h"

#include <conio.h> // _getch

#include "r2cm/r2cm_ostream.h"

namespace test_empty
{
	r2cm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Empty Test";
		};
	}
	r2cm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			LS();

			std::cout << r2cm::tab2 << "Do Something" << r2cm::linefeed;

			LS();

			return r2cm::eDoLeaveAction::Pause;
		};
	}
}