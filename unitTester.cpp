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



	void UnitTester::funcCheck::expect(const char * s, bool r) {
		expects.push_back(itemTest(s,r));
	}

	bool UnitTester::funcCheck::executeCheck() {
		for(auto it : expects) {
			passState = it.Result() && passState;
		}
		return passState;
	}
}
