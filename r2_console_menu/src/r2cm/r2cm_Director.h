#pragma once

#include "r2cm_MenuProcessor.h"

namespace r2cm
{
	class iMenuWriter;

	class Director
	{
	public:
		Director();

		void Setup( const iMenuWriter& menu_writer );

		void Run();

	private:
		MenuProcessor mMenu;
	};
}