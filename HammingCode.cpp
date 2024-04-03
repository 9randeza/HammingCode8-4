#include <iostream>
#include <bitset>
#include <cstdint>

uint16_t HammingCode(auto b){	
	bool p1;
	bool p2;
	bool p3;
	bool p4;
	
	uint16_t Hemming;
	
	bool b1 = b & 0x1;
	bool b2 = b & 0x2;
	bool b3 = b & 0x4;
	bool b4 = b & 0x8;

	p1 = (b1 + b3 + b4 + 1)%2;
	p2 = (b1 + b2 + b4 + 1)%2;
	p3 = (b1 + b2 + b3 + 1 )%2 ;
	p4 = (b1 + b2 + b3 +  b4 + p2 + p1 + p3 + 1)%2; 

	Hemming = (b1 << 1) + (b2 << 3) + (b4 << 7) +  (b3 << 5) + (p2 << 2) + (p1)  + (p3 << 4) + (p4 << 6);
	
	return Hemming;
}

std::bitset<16> glue(uint8_t b){
	uint8_t c = b & 0xF;
	uint8_t a = b >> 4;
	
	uint16_t Hamming_1 = HammingCode(c);
	uint16_t Hamming_2 = HammingCode(a) << 8;
	std::cout << Hamming_1 << " " << Hamming_2 << std::endl;
	std::bitset<16> Hamming = Hamming_1 + Hamming_2;
	
	
	return Hamming;
}


int main() {
	char  c = 'B';
	uint8_t i = 4;
	std::bitset<8> t1(c);
	std::bitset<8> t2(i);
	std::cout << c << " : " << t1 << std::endl;
	std::cout <<  "code Hemming 8/4: " << glue(c) << "\n";
	std::cout << i << " : " << t2 << std::endl;
	std::cout <<  "code Hemming 8/4: " << glue(i) << "\n";
}
