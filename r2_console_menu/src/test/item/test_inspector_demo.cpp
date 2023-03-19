#include "test_inspector_demo.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace test_inspector_demo
{
	r2cm::TitleFunctionT Demo::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Demo";
		};
	}
	r2cm::DoFunctionT Demo::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			LS();

			{
				DECLARATION_MAIN( int i = 0 );
				DECLARATION_MAIN( int j = i );

				SS();

				EXPECT_EQ( i, j );

				SS();

				PROCESS_MAIN( i = 1 );
				PROCESS_MAIN( i = 2 );
				EXPECT_NE( i, 1 );
				EXPECT_EQ( i, 2 );
			}

			LS();

			{
				struct S
				{
					int i = 255;

					void Do()
					{
						i <<= 2;
					}
				};

				OUTPUT_FILE_RANGE( "src/test/item/test_inspector_demo.cpp", 40, 48 );

				LF();

				DECLARATION_MAIN( S s );

				LF();

				PROCESS_MAIN( s.Do() );
				EXPECT_EQ( 255 * 2 * 2, s.i );

				LF();

				OUTPUT_VALUE( s.i );

				LF();

				OUTPUT_BINARY( s );
			}

			LS();

			{
				OUTPUT_SUBJECT( "�ȵǴ� ��" );

				LF();

#pragma warning( push )
#pragma warning( disable : 4002 )
				OUTPUT_CODE( std::pair<int, int> a );
#pragma warning( pop )

				LF();

				OUTPUT_NOTE( "���ڰ� 2���� ���ø��� ���𿡴� Inspector �� ����� �ȵȴ�. C4002" );
			}

			LS();

			return r2cm::eDoLeaveAction::Pause;
		};
	}
}