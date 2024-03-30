#include <iostream>
#include <bitset>

int main(){
	short c = 153;
	
	int g = c >> 8;
	int t = c;
	
	std::bitset<8> c_1 = t;
	std::bitset<8> c_2 = g;
	
	
	bool b1 = t & 0x1;
	bool b2 = t & 0x2;
	bool b3 = t & 0x4;
	bool b4 = t & 0x8;
	bool b5 = t & 0x10;
	bool b6 = t & 0x20;
	bool b7 = t & 0x40;
	bool b8 = t & 0x80;
	
	bool s_0 = (b2 + b4 + b6 + b8)%2;
	bool s_1 = (b3 + b4 + b7 + b8)%2;
	bool s_2 = (b4 + b5 + b6 + b7)%2;
	bool p = (b1 + b2 + b3 + b4 + b5 + b6 + b7 + b8)%2;
	
	
	if(s_0 == 0 && s_1 == 0 && s_2 == 0 && p == 0){
		std::cout << "evrething good: " << c_1 << std::endl;
	}
	if((s_0 == 1 || s_1 == 1 || s_2 == 1) && p == 1){
		std::cout << "some thing wrong\n";
		int i = (s_0) + (s_1 << 1) + (s_2 << 2);
		int mask = 0x80 >> i;
		t ^= mask;
		std::bitset<8> c_1 = t;
		std::cout << s_0 << " " << s_1 << " " << s_2 << std::endl;
		std::cout << "good version: " << c_1 << std::endl;

	}
	if((s_0 == 1 || s_1 == 1 || s_2 == 1) && p == 0){
		std::cout << "something wrong, and I can`t fix it\n";
	}
	if(s_0 == 0 && s_1 == 0 && s_2 == 0 && p == 1){
		std::cout << "p is wrong\n";
		t ^= 0x1;
		std::bitset<8> c_1 = t;
		std::cout << "good version: " << c_1 << std::endl;
	}
}
