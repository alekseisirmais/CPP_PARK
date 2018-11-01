#include <stdio.h>

unsigned char pr(unsigned char c) {
	return (c << 0) ^ (c << 1) ^ (c << 5) ^ (c << 6) ^ (c << 7);
}

unsigned char po(unsigned char n) {
	unsigned int a = 1;
	for (int i = 0;i < n;i++) {
		a = pr(a);
	}
	return a;
}

unsigned char lk(unsigned char arg) {
	unsigned char ret = 0;
	for (unsigned char i = 0;i < 8;i++) {
		ret ^= ((arg & (0b00000001 << i)) >> i)*po(i);
	}
	return ret;
}

int main() {
	for (unsigned char i = 0;i < 255;i++) {
		printf("%d\n\r", lk(i));
	}
	getchar();
	return 0;
}