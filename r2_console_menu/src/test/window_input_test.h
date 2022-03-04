#pragma once

#include "base/r2_iItem.h"
#include "base/r2_Singleton.h"

namespace window_input_test
{
	class TestKeyboardInputCollector : public r2::iItem, public r2::SingleTon<TestKeyboardInputCollector>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}