#include "interface.h"

#ifndef _Included_sarkanym_SarkanyCryptoProvider
#define _Included_sarkanym_SarkanyCryptoProvider
#ifdef __cplusplus
extern "C" {
#endif

	SNYEXPORT tobtectArray SNYCALL Kernel_sarkanym_SarkanyCryptoProvider_regenKeys
	(tNIEnv *, tclass, tbyteArray, tbyteArray);

	SNYEXPORT tbyteArray SNYCALL Kernel_sarkanym_SarkanyCryptoProvider_encrypt
	(tNIEnv *, tclass, tbyteArray, tbyteArray, tlong, tint);

	SNYEXPORT tbyteArray SNYCALL Kernel_sarkanym_SarkanyCryptoProvider_decrypt
	(tNIEnv *, tclass, tbyteArray, tbyteArray, tlong, tint);

#ifdef __cplusplus
}
#endif
#endif