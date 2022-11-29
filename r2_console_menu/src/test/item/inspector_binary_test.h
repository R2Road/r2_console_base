#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace inspector_binary_test
{
	class Binary : public r2cm::iItem, public r2cm::SingleTon<Binary>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};

	class Binaries : public r2cm::iItem, public r2cm::SingleTon<Binaries>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};
}