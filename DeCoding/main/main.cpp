#include <iostream>
#include "algorithm.cpp"
#include <gtest/gtest.h>
#include <string>
#include <cstdint>

TEST(Test, Test1){
	uint16_t Hamming = 25673;
	uint8_t origin = 66;
	std::pair<int ,std::string> result = glue(Hamming);
	ASSERT_EQ(origin, result.first);
}

TEST(Test, Test2){
	uint16_t origin;
	ASSERT_FALSE(origin);
}

TEST(Test, Test3){
	uint16_t Hamming = 25667;
	std::string error = "something wrong, and I can`t fix it\n";
	std::pair<int, std::string> result = glue(Hamming);
	ASSERT_EQ(error, result.second);
}

TEST(Test, Test4){
	uint16_t Hamming = 25665;
	uint8_t origin = 66;
	std::pair<int, std::string> result = glue(Hamming);
	ASSERT_EQ(origin, result.first);
}
	
int main(int argc, char** argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
