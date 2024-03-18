#include <iostream>
#include <bitset>

int main() {

	char b = 'e';	
	char p1;
	char p2;
	char p3;
	char p;
	char Hemming;
		
	p1 = (((b & 0x1) + ((b & 0x2) >> 1) + ((b & 0x8) >> 3))) & 0x1;
	
	std::bitset<8> b1(p1);
	
	p2 = (((b & 0x1) + ((b & 0x4) >> 2) + ((b & 0x8)>> 3))& 0x1) << 1;
	
	std::bitset<8> b2(p2);
	
	p3 = ((((b & 0x2) >> 1) + ((b & 0x4) >> 2) + ((b & 0x8) >> 3))& 0x1) << 3;
	
	std::bitset<8> b3(p3);
	
	p = (((b & 0x1) + ((b & 0x2) >> 1) + ((b & 0x8) >> 3) +  ((b & 0x4) >> 2) + p2 + p1 + p3 )& 0x1) << 7; 
	
	std::bitset<8> b0(p);
	
	Hemming = ((b & 0x1) << 2) + ((b & 0x2) << 3) + ((b & 0x8) << 3) +  ((b & 0x4) << 3) + p2 + p1 + p3 + p;
	std::bitset<8> h(Hemming);
	std::bitset<8> t(b);

	std::cout << b << " : " << t;
	std::cout <<  " code Hemming 8/4: " << h << "\n";

	
}
