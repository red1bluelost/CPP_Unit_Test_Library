/* File:   unitTester.cpp
 * Author: Micah Weston
 * Info:   Implements unit tester class
 */

#include "unitTester.h"

namespace r1bl {
	bool UnitTester::funcCheck::itemTest::Result() {
		if(!result) {
			printf("%s\n", description);
		}
		return result;
	}

	void UnitTester::funcCheck::Expect(const char * s, bool r) {
		expects.emplace_back(new itemTest(s,r));
	}

	bool UnitTester::funcCheck::executeCheck() {
		for(auto & it : expects) {
			passState = it->Result() && passState;
		}
		return passState;
	}

	UnitTester::funcCheck::funcCheck(const char * s, void test(funcCheck*) ) : description(s) {
		test(this);
	}

	void UnitTester::FunctionTest(const char * s, void test(funcCheck*) ) {
		checks.emplace_back(new funcCheck(s, test));
	}

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
