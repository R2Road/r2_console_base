#pragma once

#include "r2cm/r2cm_iMenu.h"

class InspectorMenu : public r2cm::iMenu
{
public:
	r2cm::TitleFunctionT GetTitleFunction() const override;
	r2cm::DescriptionFunctionT GetDescriptionFunction() const override;
	r2cm::WriteFunctionT GetWriteFunction() const override;
};