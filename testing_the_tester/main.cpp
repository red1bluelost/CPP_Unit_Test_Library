#include "../unitTester.h"

int main() {
	r1bl::UnitTester t("Testing the tester");

	t.FunctionTest("Adding and subtracting", [](r1bl::CheckPtr checker) {
			int a = 1 + 1;
			int b = 3 - 2;
			int c = 4 + 7;
			checker->Expect("1+1 = 2", (a == 2));
			checker->Expect("3-2 = 1", (b == 1));
			checker->Expect("4+7 = 11", (c == 11));
			});

	t.FunctionTest("Multiplying and dividing", [](r1bl::CheckPtr checker) {
			int a = 4 * 20;
			int b = 42 / 7;
			checker->Expect("4*20 = 80", (a == 80));
			checker->Expect("42/7 = 6",  (b == 6));
			});

	t.ExecuteUnitTest();

	return 0;
}
