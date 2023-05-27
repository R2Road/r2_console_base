#pragma once

#include "r2cm_MenuConstant.h"

namespace r2tm
{
	class iItem
	{
	public:
		virtual ~iItem() {}

		virtual TitleFunctionT GetTitleFunction() const = 0;
		virtual DoFunctionT GetDoFunction() const = 0;
	};
}