#pragma once

#include "r2cm/r2cm_iItem.h"

namespace test_color_modifier
{
	class Basic : public r2tm::iItem
	{
	public:
		r2tm::TitleFunctionT GetTitleFunction() const override;
		r2tm::DoFunctionT GetDoFunction() const override;
	};
}