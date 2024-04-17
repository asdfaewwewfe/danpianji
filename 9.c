#include <REGX52.H>
#include <INTRINS.H>
unsigned char RE[] = { 0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,
0x77,0x7C,0x39,0x5E,0x79,0x71 };
void Delay(xms)		//@12.000MHz
{
	while (xms--) {
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	}
}

void re(unsigned char Location, Number) {
	switch (Location) {
	case 1:P2_4 = 1; P2_3 = 1; P2_2 = 1; break;
	case 2:P2_4 = 1; P2_3 = 1; P2_2 = 0; break;
	case 3:P2_4 = 1; P2_3 = 0; P2_2 = 1; break;
	case 4:P2_4 = 1; P2_3 = 0; P2_2 = 0; break;
	case 5:P2_4 = 0; P2_3 = 1; P2_2 = 1; break;
	case 6:P2_4 = 0; P2_3 = 1; P2_2 = 0; break;
	case 7:P2_4 = 0; P2_3 = 0; P2_2 = 1; break;
	case 8:P2_4 = 0; P2_3 = 0; P2_2 = 0; break;
	}
	P0 = RE[Number];
	Delay(120);
}
void main()
{

	while (1) {
		re(1, 1);
		re(2, 2);
		re(3, 3);
		re(4, 4);
		re(5, 5);
		re(6, 6);
		re(7, 7);
		re(8, 8);
	}
}