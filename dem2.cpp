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

	a = { 0xff, 0xee, 0xdd, 0xcc, 0xbb, 0xaa, 0x99, 0x88, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x00 };
	b = { 0xb6, 0x6c, 0xd8, 0x88, 0x7d, 0x38, 0xe8, 0xd7, 0x77, 0x65, 0xae, 0xea, 0x0c, 0x9a, 0x7e, 0xfc };
	c = { 0x55, 0x9d, 0x8d, 0xd7, 0xbd, 0x06, 0xcb, 0xfe, 0x7e, 0x7b, 0x26, 0x25, 0x23, 0x28, 0x0d, 0x39 };
	d = { 0x0c, 0x33, 0x22, 0xfe, 0xd5, 0x31, 0xe4, 0x63, 0x0d, 0x80, 0xef, 0x5c, 0x5a, 0x81, 0xc5, 0x0b };

	KSP(a.elem);
	KSP(b.elem);
	KSP(c.elem);
	KSP(d.elem);

	writebatch(a);
	writebatch(b);
	writebatch(c);
	writebatch(d);

	KSB(a.elem);
	KSB(b.elem);
	KSB(c.elem);
	KSB(d.elem);

	writebatch(a);
	writebatch(b);
	writebatch(c);
	writebatch(d);


	getchar();
	getchar();

}