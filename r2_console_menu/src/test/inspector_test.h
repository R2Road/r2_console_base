#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace inspector_test
{
	class Basic : public r2::iItem, public r2::SingleTon<Basic>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}