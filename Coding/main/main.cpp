#include <iostream>
#include "algorithm.cpp"
#include <bitset>
#include <gtest/gtest.h>

TEST(Test, Test1){
	char origin = 'v';
	std::bitset<16> Hamming = 0x2F38;
	
	ASSERT_EQ(Hamming, glue(origin));
}
TEST(Test, Test2){
	char origin;
	ASSERT_FALSE(origin);
}

TEST(Test, Test3){
	int origin = 5;
	std::bitset<16> Hamming = 0x1573;
	
	ASSERT_EQ(Hamming, glue(origin));
}
	
int main(int argc, char** argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
