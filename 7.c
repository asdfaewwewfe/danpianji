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
	unsigned char b = 0;
	P2 = 0xFE;
	while (1) {
		if (P3_1 == 0) {
			Delay(20);
			while (P3_1 == 0);
			P2 = a;
			a = (a << 1) | 0x01;
			if (b == 7) {
				a = 0xFE;
				b = -1;
			}
			b++;
		}
	}
}