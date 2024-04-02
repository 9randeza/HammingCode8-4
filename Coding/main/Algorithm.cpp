#include <bitset>


short HammingCode(auto b){	
	bool p1;
	bool p2;
	bool p3;
	bool p4;
	
	short Hemming;
	
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

std::bitset<16> glue(auto b){
	auto c = b;
	auto a = b >> 4;
	
	short Hamming_1 = HammingCode(c);
	short Hamming_2 = HammingCode(a) << 8;
	std::cout << Hamming_1 << " " << Hamming_2 << std::endl;
	std::bitset<16> Hamming = Hamming_1 + Hamming_2;
	
	
	return Hamming;
}
