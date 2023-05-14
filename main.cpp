#include <string>
//#include "gtest/gtest.h"
#include "rvalue_reference.h"

//TEST(RVALUE_REFERENCE, RVALUE_REFERENCE_1) {
//	EXPECT_EQ(9, rvalue_reference());
//	EXPECT_EQ(4, rvalue_reference2());
//}

int main(int argc, char** argv) {
//	::testing::InitGoogleTest(&argc, argv);
	int ret = rvalue_reference();
	int ret2 = rvalue_reference2();

	return ret+ret2;

//	return RUN_ALL_TESTS();
}
