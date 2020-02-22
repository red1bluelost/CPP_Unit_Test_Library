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
		//Class to contain the tests for a single function/procedure
		class funcCheck {
			//disable copy constructor, assignment operator, and default constructor
			funcCheck( funcCheck & );
			funcCheck operator = ( funcCheck & );
			funcCheck();

			const char * const description;

			//item test class to be used in a vector
			//holds specific expectations for a function chect to have worked
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

			//vector holding all the expectation tests for a single function check
			std::vector<std::unique_ptr<itemTest>> expects;

			public:
			funcCheck(const char *, void (funcCheck*) );

			const char * Describe() {return description;}

			bool executeCheck();

			//Used to define and check that specific results have occurred in the function
			void Expect(const char *, bool);
		};

		private:
		//vector containing all the function tests for a unit
		std::vector<std::unique_ptr<funcCheck>> checks;

		public:
		//Three main methods to create a unit test
		
		//Initializes unit test object with a specific name
		UnitTester(const char * s) : unitTestTitle(s) {}

		//Creates tests that can be ran to verify the unit
		void FunctionTest(const char *, void (funcCheck*) );

		//Checks if all tests passed and outputs a summary
		void ExecuteUnitTest();

	};
	
	//Use this short hand when writing your own tests
	typedef UnitTester::funcCheck* CheckPtr;
}

#endif//__UNIT_TESTER_H__
