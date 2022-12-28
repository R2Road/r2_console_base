#pragma once

#include "r2cm_MenuProcessor.h"

namespace r2cm
{
	class iMenu;

	class Director
	{
	public:
		Director();

		void Setup( const iMenu& menu_writer );

		void Run();

	private:
		MenuProcessor mMenuProcessor;
	};
}