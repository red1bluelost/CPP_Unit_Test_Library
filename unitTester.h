/* File:   unitTester.h
 * Author: Micah Weston
 * Info:   Holds class for unit tester
 */

#ifndef __UNIT_TESTER_H__
#define __UNIT_TESTER_H__

#include <cstdio>
#include <vector>
#include <memory>

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
			//disable copy constructor, assignment operator, and default constructor
			funcCheck( funcCheck & );
			funcCheck operator = ( funcCheck & );
			funcCheck();
			const char * const description;

			//item test class to be used in a vector
			class itemTest {
				const char * const description;
				bool result;
				//disable copy constructor, assignment operator, and default constructor
				itemTest( itemTest & );
				itemTest operator = ( itemTest & );
				itemTest ();

				public:
				itemTest (const char * s, bool r) : description(s) , result(r) {}
				bool Result();

			};

			bool passState = true;
			std::vector<std::unique_ptr<itemTest>> expects;


			public:
			void Expect(const char *, bool);
			bool executeCheck();
			funcCheck(const char *, void (funcCheck*) );

		};

		private:
		std::vector<std::unique_ptr<funcCheck>> checks;

		public:
		void FunctionTest(const char *, void (funcCheck*) );

	};
	
	//Use this short hand when writing your own tests
	typedef UnitTester::funcCheck* CheckPtr;
}

#endif//__UNIT_TESTER_H__
