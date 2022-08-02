#include "color_modifier_test.h"

#include "r2cm/r2cm_ostream.h"

namespace color_modifier_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Color Modifier : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab2 << r2cm::ColorModifier( r2cm::eColor::FG_Red ) << "Do Something" << r2cm::ColorModifier() << r2cm::linefeed;

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab2 << r2cm::clm( r2cm::eColor::BG_Red ) << r2cm::clm( r2cm::eColor::FG_Blue ) << "Do Something" << r2cm::clm() << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}