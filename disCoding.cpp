#include <iostream>
#include <bitset>
#include <cstdint>

struct NotFixMistake{
	std::string message;
    NotFixMistake(const std::string& msg) : message(msg) {}
};

uint8_t DeCoder(uint8_t c){
	uint8_t t = c;
	std::bitset<8> c_1 = t;
	
	bool b1 = t & 0x1;
	bool b2 = t & 0x2;
	bool b3 = t & 0x4;
	bool b4 = t & 0x8;
	bool b5 = t & 0x10;
	bool b6 = t & 0x20;
	bool b7 = t & 0x40;
	bool b8 = t & 0x80;
	
	bool s_0 = (b1 + b2 + b6 + b8)%2;
	bool s_1 = (b2 + b3 + b4 + b8)%2;
	bool s_2 = (b2 + b4 + b5 + b6)%2;
	bool p = (b1 + b2 + b3 + b4 + b5 + b6 + b7 + b8)%2;
	
	if((s_0 == 0 || s_1 == 0 || s_2 == 0) && p == 0){

		if(s_0 == 0 && s_1 == 0 && s_2 == 0){
			b2 ^= 1;
		}
		if(s_0 == 1 && s_1 == 0 && s_2 == 0){
			b4 ^= 1;
		}
		if(s_0 = 0 && s_1 == 1 && s_2 == 0){
			b6 ^= 1;
		}
		if(s_0 == 0 && s_1 == 0 && s_2 == 1){
			b8 ^= 1;
		}	

	}
	if((s_0 == 0 || s_1 == 0 || s_2 == 0) && p == 1){
		throw NotFixMistake("something wrong, and I can`t fix it\n");
	}
	
	uint8_t H = b2 + (b4 << 1) + (b6 << 2) + (b8 << 3);
		
	return H;
}

void glue(uint16_t c){
	uint8_t g = c >> 8;
	uint8_t t = c;
	try{
	uint8_t H = (DeCoder(g) << 4) + DeCoder(t);
	std::bitset<8> h = H;
	std::cout << h << std::endl;
	}
	catch (const NotFixMistake& e) {
        std::cout << e.message << std::endl;
	}
}
int main(){
	uint16_t c = 25673;
	glue(c);
}
