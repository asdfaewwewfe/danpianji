//#include <REGX52.H>
//void main()
//{
//	while(1)
//	{
//		if(P3_1==0)
//			P2_0=1;
//		else
//			P2_0=0;
//		if(P3_0==0)
//			P2_1=0;
//		else
//			P2_1=1;
//	}
//}
#include <REGX52.H>
void Delay(unsigned int xms)		//@12.000MHz
{
	while (xms--) {
		unsigned char i, j;

		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}
void main() {
	unsigned char a = 0xFE;
	unsigned char b;
	P2 = 0xFE;
	while (1) {
		if (P3_1 == 0) {
			Delay(20);
			while (P3_1 == 0);
			P2 = a;
			if (b == 8) {
				a = 0xFE;
				b = 0;
			}
			a = a << 1 | 0x01;
			++b;
		}
	}
}
//#include <REGX52.H>
//unsigned char b = 0;
//void Delay(unsigned int xms)
//{
//	while (xms--) {
//		unsigned char i, j;
//
//		i = 2;
//		j = 239;
//		do {
//			while (--j);
//		} while (--i);
//	}
//}
//
//void main() {
//	unsigned char a = 0xFE;
//	P2 = 0xFE;
//	while (1) {
//		if (P3_1 == 0) {
//			Delay(20);
//			while (P3_1 == 0);
//			P2 = a;
//			a = (a << 1) | 0x01;
//			if (a == 0xFF) {
//				a = 0xFE;
//			}
//			Delay(5);
//		}
//	}
//}
