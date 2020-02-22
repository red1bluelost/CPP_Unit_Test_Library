/* File:   unitTester.h
 * Author: Micah Weston
 * Info:   Holds class for unit tester
 */

#ifndef __UNIT_TESTER_H__
#define __UNIT_TESTER_H__

#include <cstdio>
#include <vector>

namespace r1bl {
	

	//Main class for the unit tester
	class UnitTester {
		//disable copy constructor, assignment operator, and default constructor
		UnitTester( UnitTester & );
		UnitTester operator = ( UnitTester & );
		UnitTester();

		const char * const unitTestTitle; //string of the unit test title
		
		unsigned long int passCount = 0;
		unsigned long int failCount = 0;

		public:
		class funcCheck {
			//disable assignment operator and default constructor
			funcCheck operator = ( funcCheck & );
			funcCheck();

			//item test class to be used in a vector
			class itemTest {
				const char * description;
				bool result;
				//disable assignment operator and default constructor
				itemTest operator = ( itemTest & );
				itemTest ();

				public:
				itemTest (const char * s, bool r) : description(s) , result(r) {};
				bool Result();

			};

			bool passState = true;
			std::vector<itemTest> expects;


			public:
			void expect(const char *, bool);
			bool executeCheck();

		};

		private:
		std::vector<funcCheck> checks;

		public:
		void FuncCheck(const char *, void (funcCheck*) );

	};
	
	
	typedef UnitTester::funcCheck* CheckPtr;
}

#endif//__UNIT_TESTER_H__
