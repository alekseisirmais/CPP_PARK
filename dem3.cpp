#include <stdio.h>
#include "External.h"
#include "Internal.h"

void writebatch(batch k) {
	for (int i = 0;i < 16;i++) {
		printf("%02X", k.elem[i]);
	}
	printf("\n\r");
}

void initkeys(batch kl, batch kr, keys* ks) {

	batch bank;
	batch work;

	ks->key[0] = kl;
	ks->key[1] = kr;

	unsigned char iter = 0;

	for (;iter < 8;iter++) {
		for (int i = 0;i < 16;i++) {
			work.elem[i] = 0;
		}
		for (int i = 0;i < 16;i++) {
			bank.elem[i] = kl.elem[i];
		}
		work.elem[15] = iter + 1;
		LRA(work.elem);
		XRG(kl.elem, work.elem);
		KSP(kl.elem);
		LRA(kl.elem);
		XRG(kl.elem, kr.elem);
		for (int i = 0;i < 16;i++) {
			kr.elem[i] = bank.elem[i];
		}
	}

	ks->key[2] = kl;
	ks->key[3] = kr;

	for (;iter < 16;iter++) {
		for (int i = 0;i < 16;i++) {
			work.elem[i] = 0;
		}
		for (int i = 0;i < 16;i++) {
			bank.elem[i] = kl.elem[i];
		}
		work.elem[15] = iter + 1;
		LRA(work.elem);
		XRG(kl.elem, work.elem);
		KSP(kl.elem);
		LRA(kl.elem);
		XRG(kl.elem, kr.elem);
		for (int i = 0;i < 16;i++) {
			kr.elem[i] = bank.elem[i];
		}
	}

	ks->key[4] = kl;
	ks->key[5] = kr;

	for (;iter < 24;iter++) {
		for (int i = 0;i < 16;i++) {
			work.elem[i] = 0;
		}
		for (int i = 0;i < 16;i++) {
			bank.elem[i] = kl.elem[i];
		}
		work.elem[15] = iter + 1;
		LRA(work.elem);
		XRG(kl.elem, work.elem);
		KSP(kl.elem);
		LRA(kl.elem);
		XRG(kl.elem, kr.elem);
		for (int i = 0;i < 16;i++) {
			kr.elem[i] = bank.elem[i];
		}
	}

	ks->key[6] = kl;
	ks->key[7] = kr;

	for (;iter < 32;iter++) {
		for (int i = 0;i < 16;i++) {
			work.elem[i] = 0;
		}
		for (int i = 0;i < 16;i++) {
			bank.elem[i] = kl.elem[i];
		}
		work.elem[15] = iter + 1;
		LRA(work.elem);
		XRG(kl.elem, work.elem);
		KSP(kl.elem);
		LRA(kl.elem);
		XRG(kl.elem, kr.elem);
		for (int i = 0;i < 16;i++) {
			kr.elem[i] = bank.elem[i];
		}
	}
	ks->key[8] = kl;
	ks->key[9] = kr;
}

int main() {

	batch a,b,c,d;

	a = { 0x64, 0xa5, 0x94, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
	b = { 0xd4, 0x56, 0x58, 0x4d, 0xd0, 0xe3, 0xe8, 0x4c, 0xc3, 0x16, 0x6e, 0x4b, 0x7f, 0xa2, 0x89, 0x0d };
	c = { 0x79, 0xd2, 0x62, 0x21, 0xb8, 0x7b, 0x58, 0x4c, 0xd4, 0x2f, 0xbc, 0x4f, 0xfe, 0xa5, 0xde, 0x9a };
	d = { 0x0e, 0x93, 0x69, 0x1a, 0x0c, 0xfc, 0x60, 0x40, 0x8b, 0x7b, 0x68, 0xf6, 0x6b, 0x51, 0x3c, 0x13 };

	LRA(a.elem);
	LRA(b.elem);
	LRA(c.elem);
	LRA(d.elem);

	writebatch(a);
	writebatch(b);
	writebatch(c);
	writebatch(d);

	LRB(a.elem);
	LRB(b.elem);
	LRB(c.elem);
	LRB(d.elem);

	writebatch(a);
	writebatch(b);
	writebatch(c);
	writebatch(d);
	

	getchar();
	getchar();

}