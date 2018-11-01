#include <stdio.h>
#include "External.h"
#include "Internal.h"

inline void step(unsigned char* a, unsigned char* k) {
	XRG(a, k);
	KSP(a);
	LRA(a);
} 

inline void backstep(unsigned char* a, unsigned char* k) {
	XRG(a, k);
	LRB(a);
	KSB(a);
}

void encode(unsigned char* data, keys* key) {
	byte b;
	for (b = 0;b < 9;b++) {
		step(data, key->key[b].elem);
	}
	XRG(data, key->key[9].elem);
}

void encode_batch(unsigned char* arr, keys* key, unsigned int length) {
	unsigned int i;
	for (i = 0;i < length;i+=16) {
		encode(arr+i,key);
	}
}

void decode(unsigned char* data, keys* key) {
	byte b;
	XRG(data, key->key[9].elem);
	LRB(data);
	KSB(data);
	for (b = 9;b > 1;b--) {
		backstep(data, key->key[b - 1].elem);
	}
	XRG(data, key->key[0].elem);
}

void decode_batch(unsigned char* arr, keys* key, unsigned int length) {
	unsigned int i;
	for (i = 0;i < length;i+=16) {
		decode(arr+i, key);
	}
}

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