/* File:   unitTester.cpp
 * Author: Micah Weston
 * Info:   Implements unit tester class
 */

#include "unitTester.h"

namespace r1bl {
	//Returns if the expected result actually occurred
	bool UnitTester::funcCheck::itemTest::Result() {
		if(!result) {
			printf("%s\n", description);
		}
		return result;
	}

	//Adds a test within a function check that expects a specific result to be true
	void UnitTester::funcCheck::Expect(const char * s, bool r) {
		expects.emplace_back(new itemTest(s,r));
	}

	//Checks if all the expected results occurred in a single function test
	bool UnitTester::funcCheck::executeCheck() {
		for(auto & it : expects) {
			passState = it->Result() && passState;
		}
		return passState;
	}

	//Initializes a single function check
	UnitTester::funcCheck::funcCheck(const char * s, void test(funcCheck*) ) : description(s) {
		test(this);
	}

	//Creates a function test that takes a discription and a lambda function 
	//containing user defined expectations
	void UnitTester::FunctionTest(const char * s, void test(funcCheck*) ) {
		checks.emplace_back(new funcCheck(s, test));
	}

	//Runs through each function check to see if everything passes and outputs the result
	void UnitTester::ExecuteUnitTest() {
		printf("%s\n\n", unitTestTitle);
		for(auto & it : checks) {
			if(it->executeCheck()) {
				++passCount;
			} else {
				++failCount;
				printf("%s\n", it->Describe());
			}
		}
		failCount == 0 ? printf("Pass\n") : printf("Fail\n");
		printf("Passed: %ld | Failed: %ld", passCount, failCount);
	}
}
