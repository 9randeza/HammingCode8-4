#include <iostream>
#include <bitset>


std::bitset<8> HammingCode(auto b){	
	bool p1;
	bool p2;
	bool p3;
	bool p;
	
	std::bitset<8> Hemming;
	
	bool b1 = b & 0x1;
	bool b2 = b & 0x2;
	bool b3 = b & 0x4;
	bool b4 = b & 0x8;

	p1 = (b1 + b2 + b4)%2;
	p2 = (b1 + b3 + b4)%2;
	p3 = (b2 + b3 + b4)%2 ;
	p = (b1 + b2 + b3 +  b4 + p2 + p1 + p3 )%2; 

	Hemming = (b1 << 2) + (b2 << 4) + (b4 << 6) +  (b3 << 5) + (p2 << 1) + p1  +( p3 << 3) +( p << 7);
	
	return Hemming;
}

int main() {

	char  c = 'e' ;
	int i = 9;
	std::bitset<8>  h1 = HammingCode(c);
	std::bitset<8>  h2 = HammingCode(i);
	std::bitset<8> t1(c);
	std::bitset<8> t2(i);
	std::cout << c << " : " << t1;
	std::cout <<  " code Hemming 8/4: " << h1 << "\n";
	std::cout << i << " : " << t2;
	std::cout <<  " code Hemming 8/4: " << h2 << "\n";
}
