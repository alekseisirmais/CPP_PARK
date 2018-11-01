#pragma once

#include "sarkanym_SarkanyCryptoProvider.h"

typedef unsigned char byte;

typedef struct batch { byte elem[16]; } batch;
typedef struct keys { batch key[10]; } keys;

void initkeys(batch, batch, keys*);

void encode_batch(unsigned char*, keys*, unsigned int);
void decode_batch(unsigned char*, keys*, unsigned int);

// Линкуем это с асмом
extern "C" void LRA(unsigned char*);
extern "C" void KSP(unsigned char*);
extern "C" void KSB(unsigned char*);
extern "C" void LBA(unsigned char*);
extern "C" void LBB(unsigned char*);
extern "C" void LRB(unsigned char*);
extern "C" void XRG(unsigned char*, unsigned char*);