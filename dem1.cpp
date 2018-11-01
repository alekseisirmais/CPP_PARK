#include <stdio.h>
#include <string.h>
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
		memcpy(&bank.elem, &kl.elem, 16);
		work.elem[15] = iter + 1;
		LRA(work.elem);
		XRG(kl.elem, work.elem);
		KSP(kl.elem);
		LRA(kl.elem);
		XRG(kl.elem, kr.elem);
		memcpy(&kr.elem, &bank.elem, 16);
	}

	ks->key[2] = kl;
	ks->key[3] = kr;

	for (;iter < 16;iter++) {
		for (int i = 0;i < 16;i++) {
			work.elem[i] = 0;
		}
		memcpy(&bank.elem, &kl.elem, 16);
		work.elem[15] = iter + 1;
		LRA(work.elem);
		XRG(kl.elem, work.elem);
		KSP(kl.elem);
		LRA(kl.elem);
		XRG(kl.elem, kr.elem);
		memcpy(&kr.elem, &bank.elem, 16);
	}

	ks->key[4] = kl;
	ks->key[5] = kr;

	for (;iter < 24;iter++) {
		for (int i = 0;i < 16;i++) {
			work.elem[i] = 0;
		}
		memcpy(&bank.elem, &kl.elem, 16);
		work.elem[15] = iter + 1;
		LRA(work.elem);
		XRG(kl.elem, work.elem);
		KSP(kl.elem);
		LRA(kl.elem);
		XRG(kl.elem, kr.elem);
		memcpy(&kr.elem, &bank.elem, 16);
	}

	ks->key[6] = kl;
	ks->key[7] = kr;

	for (;iter < 32;iter++) {
		for (int i = 0;i < 16;i++) {
			work.elem[i] = 0;
		}
		memcpy(&bank.elem, &kl.elem, 16);
		work.elem[15] = iter + 1;
		LRA(work.elem);
		XRG(kl.elem, work.elem);
		KSP(kl.elem);
		LRA(kl.elem);
		XRG(kl.elem, kr.elem);
		memcpy(&kr.elem, &bank.elem, 16);
		
	}
	ks->key[8] = kl;
	ks->key[9] = kr;
}

int main() {

	keys k;
	batch l;
	batch r;

	l = { 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77 };
	r = { 0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10, 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef };

	initkeys(l, r, &k);

	for (int i = 0;i < 10;i++) {
		writebatch(k.key[i]);
	}

	getchar();
	getchar();

}