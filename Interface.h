// место втыка .NET фреймворка (вверх идет уже в винду)

#ifndef _SNYSOFT_SNYS_H_
#define _SNYSOFT_SNYS_H_
#define SNYSEXPORT __declspec(dllexport)
#define SNYSIMPORT __declspec(dllimport)
#define SNYSCALL __stdcall
typedef long tint;
typedef __int64 tlong;
typedef signed char tbyte;
#include <stdio.h>
#include <stdarg.h>
#ifdef __cplusplus
extern "C" {
#endif
#ifndef SNYS_TYPES_ALREADY_DEFINED_IN_SNYS_MD_H
	typedef unsigned char   tboolean;
	typedef unsigned short  tchar;
	typedef short           tshort;
	typedef float           tfloat;
	typedef double          tdouble;
	typedef tint            tsize;
#ifdef __cplusplus
	class _tobtect {};
	class _tclass : public _tobtect {};
	class _tthrowable : public _tobtect {};
	class _tstring : public _tobtect {};
	class _tarray : public _tobtect {};
	class _tbooleanArray : public _tarray {};
	class _tbyteArray : public _tarray {};
	class _tcharArray : public _tarray {};
	class _tshortArray : public _tarray {};
	class _tintArray : public _tarray {};
	class _tlongArray : public _tarray {};
	class _tfloatArray : public _tarray {};
	class _tdoubleArray : public _tarray {};
	class _tobtectArray : public _tarray {};
	typedef _tobtect *tobtect;
	typedef _tclass *tclass;
	typedef _tthrowable *tthrowable;
	typedef _tstring *tstring;
	typedef _tarray *tarray;
	typedef _tbooleanArray *tbooleanArray;
	typedef _tbyteArray *tbyteArray;
	typedef _tcharArray *tcharArray;
	typedef _tshortArray *tshortArray;
	typedef _tintArray *tintArray;
	typedef _tlongArray *tlongArray;
	typedef _tfloatArray *tfloatArray;
	typedef _tdoubleArray *tdoubleArray;
	typedef _tobtectArray *tobtectArray;
#else
	struct _tobtect;
	typedef struct _tobtect *tobtect;
	typedef tobtect tclass;
	typedef tobtect tthrowable;
	typedef tobtect tstring;
	typedef tobtect tarray;
	typedef tarray tbooleanArray;
	typedef tarray tbyteArray;
	typedef tarray tcharArray;
	typedef tarray tshortArray;
	typedef tarray tintArray;
	typedef tarray tlongArray;
	typedef tarray tfloatArray;
	typedef tarray tdoubleArray;
	typedef tarray tobtectArray;
#endif
	typedef tobtect tweak;
	typedef union tvalue {
		tboolean z;
		tbyte    b;
		tchar    c;
		tshort   s;
		tint     i;
		tlong    t;
		tfloat   f;
		tdouble  d;
		tobtect  l;
	} tvalue;
	struct _tfieldID;
	typedef struct _tfieldID *tfieldID;
	struct _tmethodID;
	typedef struct _tmethodID *tmethodID;
	typedef enum _tobtectType {
		SNYSInvalidRefType = 0,
		SNYSLocalRefType = 1,
		SNYSGlobalRefType = 2,
		SNYSWeakGlobalRefType = 3
	} tobtectRefType;
#endif
#define SNYS_FALSE 0
#define SNYS_TRUE 1
#define SNYS_OK           0                 
#define SNYS_ERR          (-1)             
#define SNYS_EDETACHED    (-2)           
#define SNYS_EVERSION     (-3)         
#define SNYS_ENOMEM       (-4)          
#define SNYS_EEXIST       (-5)             
#define SNYS_EINVAL       (-6)          
#define SNYS_COMMIT 1
#define SNYS_ABORT 2
	typedef struct {
		char *name;
		char *signature;
		void *fnPtr;
	} SNYSNativeMethod;
	struct SNYSNativeInterface_;
	struct SNYSEnv_;
#ifdef __cplusplus
	typedef SNYSEnv_ SNYSEnv;
#else
	typedef const struct SNYSNativeInterface_ *SNYSEnv;
#endif
	struct SNYSInvokeInterface_;
	struct SNYVM_;
#ifdef __cplusplus
	typedef SNYVM_ SNYVM;
#else
	typedef const struct SNYSInvokeInterface_ *SNYVM;
#endif
	struct SNYSNativeInterface_ {
		void *reserved0;
		void *reserved1;
		void *reserved2;
		void *reserved3;
		tint(SNYSCALL *GetVersion)(SNYSEnv *env);
		tclass(SNYSCALL *DefineClass)
			(SNYSEnv *env, const char *name, tobtect loader, const tbyte *buf,
				tsize len);
		tclass(SNYSCALL *FindClass)
			(SNYSEnv *env, const char *name);
		tmethodID(SNYSCALL *FromReflectedMethod)
			(SNYSEnv *env, tobtect method);
		tfieldID(SNYSCALL *FromReflectedField)
			(SNYSEnv *env, tobtect field);
		tobtect(SNYSCALL *ToReflectedMethod)
			(SNYSEnv *env, tclass cls, tmethodID methodID, tboolean isStatic);
		tclass(SNYSCALL *GetSuperclass)
			(SNYSEnv *env, tclass sub);
		tboolean(SNYSCALL *IsAssignableFrom)
			(SNYSEnv *env, tclass sub, tclass sup);
		tobtect(SNYSCALL *ToReflectedField)
			(SNYSEnv *env, tclass cls, tfieldID fieldID, tboolean isStatic);
		tint(SNYSCALL *Throw)
			(SNYSEnv *env, tthrowable obt);
		tint(SNYSCALL *ThrowNew)
			(SNYSEnv *env, tclass clazz, const char *msg);
		tthrowable(SNYSCALL *ExceptionOccurred)
			(SNYSEnv *env);
		void (SNYSCALL *ExceptionDescribe)
			(SNYSEnv *env);
		void (SNYSCALL *ExceptionClear)
			(SNYSEnv *env);
		void (SNYSCALL *FatalError)
			(SNYSEnv *env, const char *msg);
		tint(SNYSCALL *PushLocalFrame)
			(SNYSEnv *env, tint capacity);
		tobtect(SNYSCALL *PopLocalFrame)
			(SNYSEnv *env, tobtect result);
		tobtect(SNYSCALL *NewGlobalRef)
			(SNYSEnv *env, tobtect lobt);
		void (SNYSCALL *DeleteGlobalRef)
			(SNYSEnv *env, tobtect gref);
		void (SNYSCALL *DeleteLocalRef)
			(SNYSEnv *env, tobtect obt);
		tboolean(SNYSCALL *IsSameObtect)
			(SNYSEnv *env, tobtect obt1, tobtect obt2);
		tobtect(SNYSCALL *NewLocalRef)
			(SNYSEnv *env, tobtect ref);
		tint(SNYSCALL *EnsureLocalCapacity)
			(SNYSEnv *env, tint capacity);
		tobtect(SNYSCALL *AllocObtect)
			(SNYSEnv *env, tclass clazz);
		tobtect(SNYSCALL *NewObtect)
			(SNYSEnv *env, tclass clazz, tmethodID methodID, ...);
		tobtect(SNYSCALL *NewObtectV)
			(SNYSEnv *env, tclass clazz, tmethodID methodID, va_list args);
		tobtect(SNYSCALL *NewObtectA)
			(SNYSEnv *env, tclass clazz, tmethodID methodID, const tvalue *args);
		tclass(SNYSCALL *GetObtectClass)
			(SNYSEnv *env, tobtect obt);
		tboolean(SNYSCALL *IsInstanceOf)
			(SNYSEnv *env, tobtect obt, tclass clazz);
		tmethodID(SNYSCALL *GetMethodID)
			(SNYSEnv *env, tclass clazz, const char *name, const char *sig);
		tobtect(SNYSCALL *CallObtectMethod)
			(SNYSEnv *env, tobtect obt, tmethodID methodID, ...);
		tobtect(SNYSCALL *CallObtectMethodV)
			(SNYSEnv *env, tobtect obt, tmethodID methodID, va_list args);
		tobtect(SNYSCALL *CallObtectMethodA)
			(SNYSEnv *env, tobtect obt, tmethodID methodID, const tvalue * args);
		tboolean(SNYSCALL *CallBooleanMethod)
			(SNYSEnv *env, tobtect obt, tmethodID methodID, ...);
		tboolean(SNYSCALL *CallBooleanMethodV)
			(SNYSEnv *env, tobtect obt, tmethodID methodID, va_list args);
		tboolean(SNYSCALL *CallBooleanMethodA)
			(SNYSEnv *env, tobtect obt, tmethodID methodID, const tvalue * args);
		tbyte(SNYSCALL *CallByteMethod)
			(SNYSEnv *env, tobtect obt, tmethodID methodID, ...);
		tbyte(SNYSCALL *CallByteMethodV)
			(SNYSEnv *env, tobtect obt, tmethodID methodID, va_list args);
		tbyte(SNYSCALL *CallByteMethodA)
			(SNYSEnv *env, tobtect obt, tmethodID methodID, const tvalue *args);
		tchar(SNYSCALL *CallCharMethod)
			(SNYSEnv *env, tobtect obt, tmethodID methodID, ...);
		tchar(SNYSCALL *CallCharMethodV)
			(SNYSEnv *env, tobtect obt, tmethodID methodID, va_list args);
		tchar(SNYSCALL *CallCharMethodA)
			(SNYSEnv *env, tobtect obt, tmethodID methodID, const tvalue *args);
		tshort(SNYSCALL *CallShortMethod)
			(SNYSEnv *env, tobtect obt, tmethodID methodID, ...);
		tshort(SNYSCALL *CallShortMethodV)
			(SNYSEnv *env, tobtect obt, tmethodID methodID, va_list args);
		tshort(SNYSCALL *CallShortMethodA)
			(SNYSEnv *env, tobtect obt, tmethodID methodID, const tvalue *args);
		tint(SNYSCALL *CallIntMethod)
			(SNYSEnv *env, tobtect obt, tmethodID methodID, ...);
		tint(SNYSCALL *CallIntMethodV)
			(SNYSEnv *env, tobtect obt, tmethodID methodID, va_list args);
		tint(SNYSCALL *CallIntMethodA)
			(SNYSEnv *env, tobtect obt, tmethodID methodID, const tvalue *args);
		tlong(SNYSCALL *CallLongMethod)
			(SNYSEnv *env, tobtect obt, tmethodID methodID, ...);
		tlong(SNYSCALL *CallLongMethodV)
			(SNYSEnv *env, tobtect obt, tmethodID methodID, va_list args);
		tlong(SNYSCALL *CallLongMethodA)
			(SNYSEnv *env, tobtect obt, tmethodID methodID, const tvalue *args);
		tfloat(SNYSCALL *CallFloatMethod)
			(SNYSEnv *env, tobtect obt, tmethodID methodID, ...);
		tfloat(SNYSCALL *CallFloatMethodV)
			(SNYSEnv *env, tobtect obt, tmethodID methodID, va_list args);
		tfloat(SNYSCALL *CallFloatMethodA)
			(SNYSEnv *env, tobtect obt, tmethodID methodID, const tvalue *args);
		tdouble(SNYSCALL *CallDoubleMethod)
			(SNYSEnv *env, tobtect obt, tmethodID methodID, ...);
		tdouble(SNYSCALL *CallDoubleMethodV)
			(SNYSEnv *env, tobtect obt, tmethodID methodID, va_list args);
		tdouble(SNYSCALL *CallDoubleMethodA)
			(SNYSEnv *env, tobtect obt, tmethodID methodID, const tvalue *args);
		void (SNYSCALL *CallVoidMethod)
			(SNYSEnv *env, tobtect obt, tmethodID methodID, ...);
		void (SNYSCALL *CallVoidMethodV)
			(SNYSEnv *env, tobtect obt, tmethodID methodID, va_list args);
		void (SNYSCALL *CallVoidMethodA)
			(SNYSEnv *env, tobtect obt, tmethodID methodID, const tvalue * args);
		tobtect(SNYSCALL *CallNonvirtualObtectMethod)
			(SNYSEnv *env, tobtect obt, tclass clazz, tmethodID methodID, ...);
		tobtect(SNYSCALL *CallNonvirtualObtectMethodV)
			(SNYSEnv *env, tobtect obt, tclass clazz, tmethodID methodID,
				va_list args);
		tobtect(SNYSCALL *CallNonvirtualObtectMethodA)
			(SNYSEnv *env, tobtect obt, tclass clazz, tmethodID methodID,
				const tvalue * args);
		tboolean(SNYSCALL *CallNonvirtualBooleanMethod)
			(SNYSEnv *env, tobtect obt, tclass clazz, tmethodID methodID, ...);
		tboolean(SNYSCALL *CallNonvirtualBooleanMethodV)
			(SNYSEnv *env, tobtect obt, tclass clazz, tmethodID methodID,
				va_list args);
		tboolean(SNYSCALL *CallNonvirtualBooleanMethodA)
			(SNYSEnv *env, tobtect obt, tclass clazz, tmethodID methodID,
				const tvalue * args);
		tbyte(SNYSCALL *CallNonvirtualByteMethod)
			(SNYSEnv *env, tobtect obt, tclass clazz, tmethodID methodID, ...);
		tbyte(SNYSCALL *CallNonvirtualByteMethodV)
			(SNYSEnv *env, tobtect obt, tclass clazz, tmethodID methodID,
				va_list args);
		tbyte(SNYSCALL *CallNonvirtualByteMethodA)
			(SNYSEnv *env, tobtect obt, tclass clazz, tmethodID methodID,
				const tvalue *args);
		tchar(SNYSCALL *CallNonvirtualCharMethod)
			(SNYSEnv *env, tobtect obt, tclass clazz, tmethodID methodID, ...);
		tchar(SNYSCALL *CallNonvirtualCharMethodV)
			(SNYSEnv *env, tobtect obt, tclass clazz, tmethodID methodID,
				va_list args);
		tchar(SNYSCALL *CallNonvirtualCharMethodA)
			(SNYSEnv *env, tobtect obt, tclass clazz, tmethodID methodID,
				const tvalue *args);
		tshort(SNYSCALL *CallNonvirtualShortMethod)
			(SNYSEnv *env, tobtect obt, tclass clazz, tmethodID methodID, ...);
		tshort(SNYSCALL *CallNonvirtualShortMethodV)
			(SNYSEnv *env, tobtect obt, tclass clazz, tmethodID methodID,
				va_list args);
		tshort(SNYSCALL *CallNonvirtualShortMethodA)
			(SNYSEnv *env, tobtect obt, tclass clazz, tmethodID methodID,
				const tvalue *args);
		tint(SNYSCALL *CallNonvirtualIntMethod)
			(SNYSEnv *env, tobtect obt, tclass clazz, tmethodID methodID, ...);
		tint(SNYSCALL *CallNonvirtualIntMethodV)
			(SNYSEnv *env, tobtect obt, tclass clazz, tmethodID methodID,
				va_list args);
		tint(SNYSCALL *CallNonvirtualIntMethodA)
			(SNYSEnv *env, tobtect obt, tclass clazz, tmethodID methodID,
				const tvalue *args);
		tlong(SNYSCALL *CallNonvirtualLongMethod)
			(SNYSEnv *env, tobtect obt, tclass clazz, tmethodID methodID, ...);
		tlong(SNYSCALL *CallNonvirtualLongMethodV)
			(SNYSEnv *env, tobtect obt, tclass clazz, tmethodID methodID,
				va_list args);
		tlong(SNYSCALL *CallNonvirtualLongMethodA)
			(SNYSEnv *env, tobtect obt, tclass clazz, tmethodID methodID,
				const tvalue *args);
		tfloat(SNYSCALL *CallNonvirtualFloatMethod)
			(SNYSEnv *env, tobtect obt, tclass clazz, tmethodID methodID, ...);
		tfloat(SNYSCALL *CallNonvirtualFloatMethodV)
			(SNYSEnv *env, tobtect obt, tclass clazz, tmethodID methodID,
				va_list args);
		tfloat(SNYSCALL *CallNonvirtualFloatMethodA)
			(SNYSEnv *env, tobtect obt, tclass clazz, tmethodID methodID,
				const tvalue *args);
		tdouble(SNYSCALL *CallNonvirtualDoubleMethod)
			(SNYSEnv *env, tobtect obt, tclass clazz, tmethodID methodID, ...);
		tdouble(SNYSCALL *CallNonvirtualDoubleMethodV)
			(SNYSEnv *env, tobtect obt, tclass clazz, tmethodID methodID,
				va_list args);
		tdouble(SNYSCALL *CallNonvirtualDoubleMethodA)
			(SNYSEnv *env, tobtect obt, tclass clazz, tmethodID methodID,
				const tvalue *args);
		void (SNYSCALL *CallNonvirtualVoidMethod)
			(SNYSEnv *env, tobtect obt, tclass clazz, tmethodID methodID, ...);
		void (SNYSCALL *CallNonvirtualVoidMethodV)
			(SNYSEnv *env, tobtect obt, tclass clazz, tmethodID methodID,
				va_list args);
		void (SNYSCALL *CallNonvirtualVoidMethodA)
			(SNYSEnv *env, tobtect obt, tclass clazz, tmethodID methodID,
				const tvalue * args);
		tfieldID(SNYSCALL *GetFieldID)
			(SNYSEnv *env, tclass clazz, const char *name, const char *sig);
		tobtect(SNYSCALL *GetObtectField)
			(SNYSEnv *env, tobtect obt, tfieldID fieldID);
		tboolean(SNYSCALL *GetBooleanField)
			(SNYSEnv *env, tobtect obt, tfieldID fieldID);
		tbyte(SNYSCALL *GetByteField)
			(SNYSEnv *env, tobtect obt, tfieldID fieldID);
		tchar(SNYSCALL *GetCharField)
			(SNYSEnv *env, tobtect obt, tfieldID fieldID);
		tshort(SNYSCALL *GetShortField)
			(SNYSEnv *env, tobtect obt, tfieldID fieldID);
		tint(SNYSCALL *GetIntField)
			(SNYSEnv *env, tobtect obt, tfieldID fieldID);
		tlong(SNYSCALL *GetLongField)
			(SNYSEnv *env, tobtect obt, tfieldID fieldID);
		tfloat(SNYSCALL *GetFloatField)
			(SNYSEnv *env, tobtect obt, tfieldID fieldID);
		tdouble(SNYSCALL *GetDoubleField)
			(SNYSEnv *env, tobtect obt, tfieldID fieldID);
		void (SNYSCALL *SetObtectField)
			(SNYSEnv *env, tobtect obt, tfieldID fieldID, tobtect val);
		void (SNYSCALL *SetBooleanField)
			(SNYSEnv *env, tobtect obt, tfieldID fieldID, tboolean val);
		void (SNYSCALL *SetByteField)
			(SNYSEnv *env, tobtect obt, tfieldID fieldID, tbyte val);
		void (SNYSCALL *SetCharField)
			(SNYSEnv *env, tobtect obt, tfieldID fieldID, tchar val);
		void (SNYSCALL *SetShortField)
			(SNYSEnv *env, tobtect obt, tfieldID fieldID, tshort val);
		void (SNYSCALL *SetIntField)
			(SNYSEnv *env, tobtect obt, tfieldID fieldID, tint val);
		void (SNYSCALL *SetLongField)
			(SNYSEnv *env, tobtect obt, tfieldID fieldID, tlong val);
		void (SNYSCALL *SetFloatField)
			(SNYSEnv *env, tobtect obt, tfieldID fieldID, tfloat val);
		void (SNYSCALL *SetDoubleField)
			(SNYSEnv *env, tobtect obt, tfieldID fieldID, tdouble val);
		tmethodID(SNYSCALL *GetStaticMethodID)
			(SNYSEnv *env, tclass clazz, const char *name, const char *sig);
		tobtect(SNYSCALL *CallStaticObtectMethod)
			(SNYSEnv *env, tclass clazz, tmethodID methodID, ...);
		tobtect(SNYSCALL *CallStaticObtectMethodV)
			(SNYSEnv *env, tclass clazz, tmethodID methodID, va_list args);
		tobtect(SNYSCALL *CallStaticObtectMethodA)
			(SNYSEnv *env, tclass clazz, tmethodID methodID, const tvalue *args);
		tboolean(SNYSCALL *CallStaticBooleanMethod)
			(SNYSEnv *env, tclass clazz, tmethodID methodID, ...);
		tboolean(SNYSCALL *CallStaticBooleanMethodV)
			(SNYSEnv *env, tclass clazz, tmethodID methodID, va_list args);
		tboolean(SNYSCALL *CallStaticBooleanMethodA)
			(SNYSEnv *env, tclass clazz, tmethodID methodID, const tvalue *args);
		tbyte(SNYSCALL *CallStaticByteMethod)
			(SNYSEnv *env, tclass clazz, tmethodID methodID, ...);
		tbyte(SNYSCALL *CallStaticByteMethodV)
			(SNYSEnv *env, tclass clazz, tmethodID methodID, va_list args);
		tbyte(SNYSCALL *CallStaticByteMethodA)
			(SNYSEnv *env, tclass clazz, tmethodID methodID, const tvalue *args);
		tchar(SNYSCALL *CallStaticCharMethod)
			(SNYSEnv *env, tclass clazz, tmethodID methodID, ...);
		tchar(SNYSCALL *CallStaticCharMethodV)
			(SNYSEnv *env, tclass clazz, tmethodID methodID, va_list args);
		tchar(SNYSCALL *CallStaticCharMethodA)
			(SNYSEnv *env, tclass clazz, tmethodID methodID, const tvalue *args);
		tshort(SNYSCALL *CallStaticShortMethod)
			(SNYSEnv *env, tclass clazz, tmethodID methodID, ...);
		tshort(SNYSCALL *CallStaticShortMethodV)
			(SNYSEnv *env, tclass clazz, tmethodID methodID, va_list args);
		tshort(SNYSCALL *CallStaticShortMethodA)
			(SNYSEnv *env, tclass clazz, tmethodID methodID, const tvalue *args);
		tint(SNYSCALL *CallStaticIntMethod)
			(SNYSEnv *env, tclass clazz, tmethodID methodID, ...);
		tint(SNYSCALL *CallStaticIntMethodV)
			(SNYSEnv *env, tclass clazz, tmethodID methodID, va_list args);
		tint(SNYSCALL *CallStaticIntMethodA)
			(SNYSEnv *env, tclass clazz, tmethodID methodID, const tvalue *args);
		tlong(SNYSCALL *CallStaticLongMethod)
			(SNYSEnv *env, tclass clazz, tmethodID methodID, ...);
		tlong(SNYSCALL *CallStaticLongMethodV)
			(SNYSEnv *env, tclass clazz, tmethodID methodID, va_list args);
		tlong(SNYSCALL *CallStaticLongMethodA)
			(SNYSEnv *env, tclass clazz, tmethodID methodID, const tvalue *args);
		tfloat(SNYSCALL *CallStaticFloatMethod)
			(SNYSEnv *env, tclass clazz, tmethodID methodID, ...);
		tfloat(SNYSCALL *CallStaticFloatMethodV)
			(SNYSEnv *env, tclass clazz, tmethodID methodID, va_list args);
		tfloat(SNYSCALL *CallStaticFloatMethodA)
			(SNYSEnv *env, tclass clazz, tmethodID methodID, const tvalue *args);
		tdouble(SNYSCALL *CallStaticDoubleMethod)
			(SNYSEnv *env, tclass clazz, tmethodID methodID, ...);
		tdouble(SNYSCALL *CallStaticDoubleMethodV)
			(SNYSEnv *env, tclass clazz, tmethodID methodID, va_list args);
		tdouble(SNYSCALL *CallStaticDoubleMethodA)
			(SNYSEnv *env, tclass clazz, tmethodID methodID, const tvalue *args);
		void (SNYSCALL *CallStaticVoidMethod)
			(SNYSEnv *env, tclass cls, tmethodID methodID, ...);
		void (SNYSCALL *CallStaticVoidMethodV)
			(SNYSEnv *env, tclass cls, tmethodID methodID, va_list args);
		void (SNYSCALL *CallStaticVoidMethodA)
			(SNYSEnv *env, tclass cls, tmethodID methodID, const tvalue * args);
		tfieldID(SNYSCALL *GetStaticFieldID)
			(SNYSEnv *env, tclass clazz, const char *name, const char *sig);
		tobtect(SNYSCALL *GetStaticObtectField)
			(SNYSEnv *env, tclass clazz, tfieldID fieldID);
		tboolean(SNYSCALL *GetStaticBooleanField)
			(SNYSEnv *env, tclass clazz, tfieldID fieldID);
		tbyte(SNYSCALL *GetStaticByteField)
			(SNYSEnv *env, tclass clazz, tfieldID fieldID);
		tchar(SNYSCALL *GetStaticCharField)
			(SNYSEnv *env, tclass clazz, tfieldID fieldID);
		tshort(SNYSCALL *GetStaticShortField)
			(SNYSEnv *env, tclass clazz, tfieldID fieldID);
		tint(SNYSCALL *GetStaticIntField)
			(SNYSEnv *env, tclass clazz, tfieldID fieldID);
		tlong(SNYSCALL *GetStaticLongField)
			(SNYSEnv *env, tclass clazz, tfieldID fieldID);
		tfloat(SNYSCALL *GetStaticFloatField)
			(SNYSEnv *env, tclass clazz, tfieldID fieldID);
		tdouble(SNYSCALL *GetStaticDoubleField)
			(SNYSEnv *env, tclass clazz, tfieldID fieldID);
		void (SNYSCALL *SetStaticObtectField)
			(SNYSEnv *env, tclass clazz, tfieldID fieldID, tobtect value);
		void (SNYSCALL *SetStaticBooleanField)
			(SNYSEnv *env, tclass clazz, tfieldID fieldID, tboolean value);
		void (SNYSCALL *SetStaticByteField)
			(SNYSEnv *env, tclass clazz, tfieldID fieldID, tbyte value);
		void (SNYSCALL *SetStaticCharField)
			(SNYSEnv *env, tclass clazz, tfieldID fieldID, tchar value);
		void (SNYSCALL *SetStaticShortField)
			(SNYSEnv *env, tclass clazz, tfieldID fieldID, tshort value);
		void (SNYSCALL *SetStaticIntField)
			(SNYSEnv *env, tclass clazz, tfieldID fieldID, tint value);
		void (SNYSCALL *SetStaticLongField)
			(SNYSEnv *env, tclass clazz, tfieldID fieldID, tlong value);
		void (SNYSCALL *SetStaticFloatField)
			(SNYSEnv *env, tclass clazz, tfieldID fieldID, tfloat value);
		void (SNYSCALL *SetStaticDoubleField)
			(SNYSEnv *env, tclass clazz, tfieldID fieldID, tdouble value);
		tstring(SNYSCALL *NewString)
			(SNYSEnv *env, const tchar *unicode, tsize len);
		tsize(SNYSCALL *GetStringLength)
			(SNYSEnv *env, tstring str);
		const tchar *(SNYSCALL *GetStringChars)
			(SNYSEnv *env, tstring str, tboolean *isCopy);
		void (SNYSCALL *ReleaseStringChars)
			(SNYSEnv *env, tstring str, const tchar *chars);
		tstring(SNYSCALL *NewStringUTF)
			(SNYSEnv *env, const char *utf);
		tsize(SNYSCALL *GetStringUTFLength)
			(SNYSEnv *env, tstring str);
		const char* (SNYSCALL *GetStringUTFChars)
			(SNYSEnv *env, tstring str, tboolean *isCopy);
		void (SNYSCALL *ReleaseStringUTFChars)
			(SNYSEnv *env, tstring str, const char* chars);
		tsize(SNYSCALL *GetArrayLength)
			(SNYSEnv *env, tarray array);
		tobtectArray(SNYSCALL *NewObtectArray)
			(SNYSEnv *env, tsize len, tclass clazz, tobtect init);
		tobtect(SNYSCALL *GetObtectArrayElement)
			(SNYSEnv *env, tobtectArray array, tsize index);
		void (SNYSCALL *SetObtectArrayElement)
			(SNYSEnv *env, tobtectArray array, tsize index, tobtect val);
		tbooleanArray(SNYSCALL *NewBooleanArray)
			(SNYSEnv *env, tsize len);
		tbyteArray(SNYSCALL *NewByteArray)
			(SNYSEnv *env, tsize len);
		tcharArray(SNYSCALL *NewCharArray)
			(SNYSEnv *env, tsize len);
		tshortArray(SNYSCALL *NewShortArray)
			(SNYSEnv *env, tsize len);
		tintArray(SNYSCALL *NewIntArray)
			(SNYSEnv *env, tsize len);
		tlongArray(SNYSCALL *NewLongArray)
			(SNYSEnv *env, tsize len);
		tfloatArray(SNYSCALL *NewFloatArray)
			(SNYSEnv *env, tsize len);
		tdoubleArray(SNYSCALL *NewDoubleArray)
			(SNYSEnv *env, tsize len);
		tboolean * (SNYSCALL *GetBooleanArrayElements)
			(SNYSEnv *env, tbooleanArray array, tboolean *isCopy);
		tbyte * (SNYSCALL *GetByteArrayElements)
			(SNYSEnv *env, tbyteArray array, tboolean *isCopy);
		tchar * (SNYSCALL *GetCharArrayElements)
			(SNYSEnv *env, tcharArray array, tboolean *isCopy);
		tshort * (SNYSCALL *GetShortArrayElements)
			(SNYSEnv *env, tshortArray array, tboolean *isCopy);
		tint * (SNYSCALL *GetIntArrayElements)
			(SNYSEnv *env, tintArray array, tboolean *isCopy);
		tlong * (SNYSCALL *GetLongArrayElements)
			(SNYSEnv *env, tlongArray array, tboolean *isCopy);
		tfloat * (SNYSCALL *GetFloatArrayElements)
			(SNYSEnv *env, tfloatArray array, tboolean *isCopy);
		tdouble * (SNYSCALL *GetDoubleArrayElements)
			(SNYSEnv *env, tdoubleArray array, tboolean *isCopy);
		void (SNYSCALL *ReleaseBooleanArrayElements)
			(SNYSEnv *env, tbooleanArray array, tboolean *elems, tint mode);
		void (SNYSCALL *ReleaseByteArrayElements)
			(SNYSEnv *env, tbyteArray array, tbyte *elems, tint mode);
		void (SNYSCALL *ReleaseCharArrayElements)
			(SNYSEnv *env, tcharArray array, tchar *elems, tint mode);
		void (SNYSCALL *ReleaseShortArrayElements)
			(SNYSEnv *env, tshortArray array, tshort *elems, tint mode);
		void (SNYSCALL *ReleaseIntArrayElements)
			(SNYSEnv *env, tintArray array, tint *elems, tint mode);
		void (SNYSCALL *ReleaseLongArrayElements)
			(SNYSEnv *env, tlongArray array, tlong *elems, tint mode);
		void (SNYSCALL *ReleaseFloatArrayElements)
			(SNYSEnv *env, tfloatArray array, tfloat *elems, tint mode);
		void (SNYSCALL *ReleaseDoubleArrayElements)
			(SNYSEnv *env, tdoubleArray array, tdouble *elems, tint mode);
		void (SNYSCALL *GetBooleanArrayRegion)
			(SNYSEnv *env, tbooleanArray array, tsize start, tsize l, tboolean *buf);
		void (SNYSCALL *GetByteArrayRegion)
			(SNYSEnv *env, tbyteArray array, tsize start, tsize len, tbyte *buf);
		void (SNYSCALL *GetCharArrayRegion)
			(SNYSEnv *env, tcharArray array, tsize start, tsize len, tchar *buf);
		void (SNYSCALL *GetShortArrayRegion)
			(SNYSEnv *env, tshortArray array, tsize start, tsize len, tshort *buf);
		void (SNYSCALL *GetIntArrayRegion)
			(SNYSEnv *env, tintArray array, tsize start, tsize len, tint *buf);
		void (SNYSCALL *GetLongArrayRegion)
			(SNYSEnv *env, tlongArray array, tsize start, tsize len, tlong *buf);
		void (SNYSCALL *GetFloatArrayRegion)
			(SNYSEnv *env, tfloatArray array, tsize start, tsize len, tfloat *buf);
		void (SNYSCALL *GetDoubleArrayRegion)
			(SNYSEnv *env, tdoubleArray array, tsize start, tsize len, tdouble *buf);
		void (SNYSCALL *SetBooleanArrayRegion)
			(SNYSEnv *env, tbooleanArray array, tsize start, tsize l, const tboolean *buf);
		void (SNYSCALL *SetByteArrayRegion)
			(SNYSEnv *env, tbyteArray array, tsize start, tsize len, const tbyte *buf);
		void (SNYSCALL *SetCharArrayRegion)
			(SNYSEnv *env, tcharArray array, tsize start, tsize len, const tchar *buf);
		void (SNYSCALL *SetShortArrayRegion)
			(SNYSEnv *env, tshortArray array, tsize start, tsize len, const tshort *buf);
		void (SNYSCALL *SetIntArrayRegion)
			(SNYSEnv *env, tintArray array, tsize start, tsize len, const tint *buf);
		void (SNYSCALL *SetLongArrayRegion)
			(SNYSEnv *env, tlongArray array, tsize start, tsize len, const tlong *buf);
		void (SNYSCALL *SetFloatArrayRegion)
			(SNYSEnv *env, tfloatArray array, tsize start, tsize len, const tfloat *buf);
		void (SNYSCALL *SetDoubleArrayRegion)
			(SNYSEnv *env, tdoubleArray array, tsize start, tsize len, const tdouble *buf);
		tint(SNYSCALL *RegisterNatives)
			(SNYSEnv *env, tclass clazz, const SNYSNativeMethod *methods,
				tint nMethods);
		tint(SNYSCALL *UnregisterNatives)
			(SNYSEnv *env, tclass clazz);
		tint(SNYSCALL *MonitorEnter)
			(SNYSEnv *env, tobtect obt);
		tint(SNYSCALL *MonitorExit)
			(SNYSEnv *env, tobtect obt);
		tint(SNYSCALL *GetSNYVM)
			(SNYSEnv *env, SNYVM **vm);
		void (SNYSCALL *GetStringRegion)
			(SNYSEnv *env, tstring str, tsize start, tsize len, tchar *buf);
		void (SNYSCALL *GetStringUTFRegion)
			(SNYSEnv *env, tstring str, tsize start, tsize len, char *buf);
		void * (SNYSCALL *GetPrimitiveArrayCritical)
			(SNYSEnv *env, tarray array, tboolean *isCopy);
		void (SNYSCALL *ReleasePrimitiveArrayCritical)
			(SNYSEnv *env, tarray array, void *carray, tint mode);
		const tchar * (SNYSCALL *GetStringCritical)
			(SNYSEnv *env, tstring string, tboolean *isCopy);
		void (SNYSCALL *ReleaseStringCritical)
			(SNYSEnv *env, tstring string, const tchar *cstring);
		tweak(SNYSCALL *NewWeakGlobalRef)
			(SNYSEnv *env, tobtect obt);
		void (SNYSCALL *DeleteWeakGlobalRef)
			(SNYSEnv *env, tweak ref);
		tboolean(SNYSCALL *ExceptionCheck)
			(SNYSEnv *env);
		tobtect(SNYSCALL *NewDirectByteBuffer)
			(SNYSEnv* env, void* address, tlong capacity);
		void* (SNYSCALL *GetDirectBufferAddress)
			(SNYSEnv* env, tobtect buf);
		tlong(SNYSCALL *GetDirectBufferCapacity)
			(SNYSEnv* env, tobtect buf);
		tobtectRefType(SNYSCALL *GetObtectRefType)
			(SNYSEnv* env, tobtect obt);
	};
	struct SNYSEnv_ {
		const struct SNYSNativeInterface_ *functions;
#ifdef __cplusplus
		tint GetVersion() {
			return functions->GetVersion(this);
		}
		tclass DefineClass(const char *name, tobtect loader, const tbyte *buf,
			tsize len) {
			return functions->DefineClass(this, name, loader, buf, len);
		}
		tclass FindClass(const char *name) {
			return functions->FindClass(this, name);
		}
		tmethodID FromReflectedMethod(tobtect method) {
			return functions->FromReflectedMethod(this, method);
		}
		tfieldID FromReflectedField(tobtect field) {
			return functions->FromReflectedField(this, field);
		}
		tobtect ToReflectedMethod(tclass cls, tmethodID methodID, tboolean isStatic) {
			return functions->ToReflectedMethod(this, cls, methodID, isStatic);
		}
		tclass GetSuperclass(tclass sub) {
			return functions->GetSuperclass(this, sub);
		}
		tboolean IsAssignableFrom(tclass sub, tclass sup) {
			return functions->IsAssignableFrom(this, sub, sup);
		}
		tobtect ToReflectedField(tclass cls, tfieldID fieldID, tboolean isStatic) {
			return functions->ToReflectedField(this, cls, fieldID, isStatic);
		}
		tint Throw(tthrowable obt) {
			return functions->Throw(this, obt);
		}
		tint ThrowNew(tclass clazz, const char *msg) {
			return functions->ThrowNew(this, clazz, msg);
		}
		tthrowable ExceptionOccurred() {
			return functions->ExceptionOccurred(this);
		}
		void ExceptionDescribe() {
			functions->ExceptionDescribe(this);
		}
		void ExceptionClear() {
			functions->ExceptionClear(this);
		}
		void FatalError(const char *msg) {
			functions->FatalError(this, msg);
		}
		tint PushLocalFrame(tint capacity) {
			return functions->PushLocalFrame(this, capacity);
		}
		tobtect PopLocalFrame(tobtect result) {
			return functions->PopLocalFrame(this, result);
		}
		tobtect NewGlobalRef(tobtect lobt) {
			return functions->NewGlobalRef(this, lobt);
		}
		void DeleteGlobalRef(tobtect gref) {
			functions->DeleteGlobalRef(this, gref);
		}
		void DeleteLocalRef(tobtect obt) {
			functions->DeleteLocalRef(this, obt);
		}
		tboolean IsSameObtect(tobtect obt1, tobtect obt2) {
			return functions->IsSameObtect(this, obt1, obt2);
		}
		tobtect NewLocalRef(tobtect ref) {
			return functions->NewLocalRef(this, ref);
		}
		tint EnsureLocalCapacity(tint capacity) {
			return functions->EnsureLocalCapacity(this, capacity);
		}
		tobtect AllocObtect(tclass clazz) {
			return functions->AllocObtect(this, clazz);
		}
		tobtect NewObtect(tclass clazz, tmethodID methodID, ...) {
			va_list args;
			tobtect result;
			va_start(args, methodID);
			result = functions->NewObtectV(this, clazz, methodID, args);
			va_end(args);
			return result;
		}
		tobtect NewObtectV(tclass clazz, tmethodID methodID,
			va_list args) {
			return functions->NewObtectV(this, clazz, methodID, args);
		}
		tobtect NewObtectA(tclass clazz, tmethodID methodID,
			const tvalue *args) {
			return functions->NewObtectA(this, clazz, methodID, args);
		}
		tclass GetObtectClass(tobtect obt) {
			return functions->GetObtectClass(this, obt);
		}
		tboolean IsInstanceOf(tobtect obt, tclass clazz) {
			return functions->IsInstanceOf(this, obt, clazz);
		}
		tmethodID GetMethodID(tclass clazz, const char *name,
			const char *sig) {
			return functions->GetMethodID(this, clazz, name, sig);
		}
		tobtect CallObtectMethod(tobtect obt, tmethodID methodID, ...) {
			va_list args;
			tobtect result;
			va_start(args, methodID);
			result = functions->CallObtectMethodV(this, obt, methodID, args);
			va_end(args);
			return result;
		}
		tobtect CallObtectMethodV(tobtect obt, tmethodID methodID,
			va_list args) {
			return functions->CallObtectMethodV(this, obt, methodID, args);
		}
		tobtect CallObtectMethodA(tobtect obt, tmethodID methodID,
			const tvalue * args) {
			return functions->CallObtectMethodA(this, obt, methodID, args);
		}
		tboolean CallBooleanMethod(tobtect obt,
			tmethodID methodID, ...) {
			va_list args;
			tboolean result;
			va_start(args, methodID);
			result = functions->CallBooleanMethodV(this, obt, methodID, args);
			va_end(args);
			return result;
		}
		tboolean CallBooleanMethodV(tobtect obt, tmethodID methodID,
			va_list args) {
			return functions->CallBooleanMethodV(this, obt, methodID, args);
		}
		tboolean CallBooleanMethodA(tobtect obt, tmethodID methodID,
			const tvalue * args) {
			return functions->CallBooleanMethodA(this, obt, methodID, args);
		}
		tbyte CallByteMethod(tobtect obt, tmethodID methodID, ...) {
			va_list args;
			tbyte result;
			va_start(args, methodID);
			result = functions->CallByteMethodV(this, obt, methodID, args);
			va_end(args);
			return result;
		}
		tbyte CallByteMethodV(tobtect obt, tmethodID methodID,
			va_list args) {
			return functions->CallByteMethodV(this, obt, methodID, args);
		}
		tbyte CallByteMethodA(tobtect obt, tmethodID methodID,
			const tvalue * args) {
			return functions->CallByteMethodA(this, obt, methodID, args);
		}
		tchar CallCharMethod(tobtect obt, tmethodID methodID, ...) {
			va_list args;
			tchar result;
			va_start(args, methodID);
			result = functions->CallCharMethodV(this, obt, methodID, args);
			va_end(args);
			return result;
		}
		tchar CallCharMethodV(tobtect obt, tmethodID methodID,
			va_list args) {
			return functions->CallCharMethodV(this, obt, methodID, args);
		}
		tchar CallCharMethodA(tobtect obt, tmethodID methodID,
			const tvalue * args) {
			return functions->CallCharMethodA(this, obt, methodID, args);
		}
		tshort CallShortMethod(tobtect obt, tmethodID methodID, ...) {
			va_list args;
			tshort result;
			va_start(args, methodID);
			result = functions->CallShortMethodV(this, obt, methodID, args);
			va_end(args);
			return result;
		}
		tshort CallShortMethodV(tobtect obt, tmethodID methodID,
			va_list args) {
			return functions->CallShortMethodV(this, obt, methodID, args);
		}
		tshort CallShortMethodA(tobtect obt, tmethodID methodID,
			const tvalue * args) {
			return functions->CallShortMethodA(this, obt, methodID, args);
		}
		tint CallIntMethod(tobtect obt, tmethodID methodID, ...) {
			va_list args;
			tint result;
			va_start(args, methodID);
			result = functions->CallIntMethodV(this, obt, methodID, args);
			va_end(args);
			return result;
		}
		tint CallIntMethodV(tobtect obt, tmethodID methodID,
			va_list args) {
			return functions->CallIntMethodV(this, obt, methodID, args);
		}
		tint CallIntMethodA(tobtect obt, tmethodID methodID,
			const tvalue * args) {
			return functions->CallIntMethodA(this, obt, methodID, args);
		}
		tlong CallLongMethod(tobtect obt, tmethodID methodID, ...) {
			va_list args;
			tlong result;
			va_start(args, methodID);
			result = functions->CallLongMethodV(this, obt, methodID, args);
			va_end(args);
			return result;
		}
		tlong CallLongMethodV(tobtect obt, tmethodID methodID,
			va_list args) {
			return functions->CallLongMethodV(this, obt, methodID, args);
		}
		tlong CallLongMethodA(tobtect obt, tmethodID methodID,
			const tvalue * args) {
			return functions->CallLongMethodA(this, obt, methodID, args);
		}
		tfloat CallFloatMethod(tobtect obt, tmethodID methodID, ...) {
			va_list args;
			tfloat result;
			va_start(args, methodID);
			result = functions->CallFloatMethodV(this, obt, methodID, args);
			va_end(args);
			return result;
		}
		tfloat CallFloatMethodV(tobtect obt, tmethodID methodID,
			va_list args) {
			return functions->CallFloatMethodV(this, obt, methodID, args);
		}
		tfloat CallFloatMethodA(tobtect obt, tmethodID methodID,
			const tvalue * args) {
			return functions->CallFloatMethodA(this, obt, methodID, args);
		}
		tdouble CallDoubleMethod(tobtect obt, tmethodID methodID, ...) {
			va_list args;
			tdouble result;
			va_start(args, methodID);
			result = functions->CallDoubleMethodV(this, obt, methodID, args);
			va_end(args);
			return result;
		}
		tdouble CallDoubleMethodV(tobtect obt, tmethodID methodID,
			va_list args) {
			return functions->CallDoubleMethodV(this, obt, methodID, args);
		}
		tdouble CallDoubleMethodA(tobtect obt, tmethodID methodID,
			const tvalue * args) {
			return functions->CallDoubleMethodA(this, obt, methodID, args);
		}

		void CallVoidMethod(tobtect obt, tmethodID methodID, ...) {
			va_list args;
			va_start(args, methodID);
			functions->CallVoidMethodV(this, obt, methodID, args);
			va_end(args);
		}
		void CallVoidMethodV(tobtect obt, tmethodID methodID,
			va_list args) {
			functions->CallVoidMethodV(this, obt, methodID, args);
		}
		void CallVoidMethodA(tobtect obt, tmethodID methodID,
			const tvalue * args) {
			functions->CallVoidMethodA(this, obt, methodID, args);
		}
		tobtect CallNonvirtualObtectMethod(tobtect obt, tclass clazz,
			tmethodID methodID, ...) {
			va_list args;
			tobtect result;
			va_start(args, methodID);
			result = functions->CallNonvirtualObtectMethodV(this, obt, clazz,
				methodID, args);
			va_end(args);
			return result;
		}
		tobtect CallNonvirtualObtectMethodV(tobtect obt, tclass clazz,
			tmethodID methodID, va_list args) {
			return functions->CallNonvirtualObtectMethodV(this, obt, clazz,
				methodID, args);
		}
		tobtect CallNonvirtualObtectMethodA(tobtect obt, tclass clazz,
			tmethodID methodID, const tvalue * args) {
			return functions->CallNonvirtualObtectMethodA(this, obt, clazz,
				methodID, args);
		}
		tboolean CallNonvirtualBooleanMethod(tobtect obt, tclass clazz,
			tmethodID methodID, ...) {
			va_list args;
			tboolean result;
			va_start(args, methodID);
			result = functions->CallNonvirtualBooleanMethodV(this, obt, clazz,
				methodID, args);
			va_end(args);
			return result;
		}
		tboolean CallNonvirtualBooleanMethodV(tobtect obt, tclass clazz,
			tmethodID methodID, va_list args) {
			return functions->CallNonvirtualBooleanMethodV(this, obt, clazz,
				methodID, args);
		}
		tboolean CallNonvirtualBooleanMethodA(tobtect obt, tclass clazz,
			tmethodID methodID, const tvalue * args) {
			return functions->CallNonvirtualBooleanMethodA(this, obt, clazz,
				methodID, args);
		}
		tbyte CallNonvirtualByteMethod(tobtect obt, tclass clazz,
			tmethodID methodID, ...) {
			va_list args;
			tbyte result;
			va_start(args, methodID);
			result = functions->CallNonvirtualByteMethodV(this, obt, clazz,
				methodID, args);
			va_end(args);
			return result;
		}
		tbyte CallNonvirtualByteMethodV(tobtect obt, tclass clazz,
			tmethodID methodID, va_list args) {
			return functions->CallNonvirtualByteMethodV(this, obt, clazz,
				methodID, args);
		}
		tbyte CallNonvirtualByteMethodA(tobtect obt, tclass clazz,
			tmethodID methodID, const tvalue * args) {
			return functions->CallNonvirtualByteMethodA(this, obt, clazz,
				methodID, args);
		}
		tchar CallNonvirtualCharMethod(tobtect obt, tclass clazz,
			tmethodID methodID, ...) {
			va_list args;
			tchar result;
			va_start(args, methodID);
			result = functions->CallNonvirtualCharMethodV(this, obt, clazz,
				methodID, args);
			va_end(args);
			return result;
		}
		tchar CallNonvirtualCharMethodV(tobtect obt, tclass clazz,
			tmethodID methodID, va_list args) {
			return functions->CallNonvirtualCharMethodV(this, obt, clazz,
				methodID, args);
		}
		tchar CallNonvirtualCharMethodA(tobtect obt, tclass clazz,
			tmethodID methodID, const tvalue * args) {
			return functions->CallNonvirtualCharMethodA(this, obt, clazz,
				methodID, args);
		}
		tshort CallNonvirtualShortMethod(tobtect obt, tclass clazz,
			tmethodID methodID, ...) {
			va_list args;
			tshort result;
			va_start(args, methodID);
			result = functions->CallNonvirtualShortMethodV(this, obt, clazz,
				methodID, args);
			va_end(args);
			return result;
		}
		tshort CallNonvirtualShortMethodV(tobtect obt, tclass clazz,
			tmethodID methodID, va_list args) {
			return functions->CallNonvirtualShortMethodV(this, obt, clazz,
				methodID, args);
		}
		tshort CallNonvirtualShortMethodA(tobtect obt, tclass clazz,
			tmethodID methodID, const tvalue * args) {
			return functions->CallNonvirtualShortMethodA(this, obt, clazz,
				methodID, args);
		}
		tint CallNonvirtualIntMethod(tobtect obt, tclass clazz,
			tmethodID methodID, ...) {
			va_list args;
			tint result;
			va_start(args, methodID);
			result = functions->CallNonvirtualIntMethodV(this, obt, clazz,
				methodID, args);
			va_end(args);
			return result;
		}
		tint CallNonvirtualIntMethodV(tobtect obt, tclass clazz,
			tmethodID methodID, va_list args) {
			return functions->CallNonvirtualIntMethodV(this, obt, clazz,
				methodID, args);
		}
		tint CallNonvirtualIntMethodA(tobtect obt, tclass clazz,
			tmethodID methodID, const tvalue * args) {
			return functions->CallNonvirtualIntMethodA(this, obt, clazz,
				methodID, args);
		}
		tlong CallNonvirtualLongMethod(tobtect obt, tclass clazz,
			tmethodID methodID, ...) {
			va_list args;
			tlong result;
			va_start(args, methodID);
			result = functions->CallNonvirtualLongMethodV(this, obt, clazz,
				methodID, args);
			va_end(args);
			return result;
		}
		tlong CallNonvirtualLongMethodV(tobtect obt, tclass clazz,
			tmethodID methodID, va_list args) {
			return functions->CallNonvirtualLongMethodV(this, obt, clazz,
				methodID, args);
		}
		tlong CallNonvirtualLongMethodA(tobtect obt, tclass clazz,
			tmethodID methodID, const tvalue * args) {
			return functions->CallNonvirtualLongMethodA(this, obt, clazz,
				methodID, args);
		}
		tfloat CallNonvirtualFloatMethod(tobtect obt, tclass clazz,
			tmethodID methodID, ...) {
			va_list args;
			tfloat result;
			va_start(args, methodID);
			result = functions->CallNonvirtualFloatMethodV(this, obt, clazz,
				methodID, args);
			va_end(args);
			return result;
		}
		tfloat CallNonvirtualFloatMethodV(tobtect obt, tclass clazz,
			tmethodID methodID,
			va_list args) {
			return functions->CallNonvirtualFloatMethodV(this, obt, clazz,
				methodID, args);
		}
		tfloat CallNonvirtualFloatMethodA(tobtect obt, tclass clazz,
			tmethodID methodID,
			const tvalue * args) {
			return functions->CallNonvirtualFloatMethodA(this, obt, clazz,
				methodID, args);
		}
		tdouble CallNonvirtualDoubleMethod(tobtect obt, tclass clazz,
			tmethodID methodID, ...) {
			va_list args;
			tdouble result;
			va_start(args, methodID);
			result = functions->CallNonvirtualDoubleMethodV(this, obt, clazz,
				methodID, args);
			va_end(args);
			return result;
		}
		tdouble CallNonvirtualDoubleMethodV(tobtect obt, tclass clazz,
			tmethodID methodID,
			va_list args) {
			return functions->CallNonvirtualDoubleMethodV(this, obt, clazz,
				methodID, args);
		}
		tdouble CallNonvirtualDoubleMethodA(tobtect obt, tclass clazz,
			tmethodID methodID,
			const tvalue * args) {
			return functions->CallNonvirtualDoubleMethodA(this, obt, clazz,
				methodID, args);
		}
		void CallNonvirtualVoidMethod(tobtect obt, tclass clazz,
			tmethodID methodID, ...) {
			va_list args;
			va_start(args, methodID);
			functions->CallNonvirtualVoidMethodV(this, obt, clazz, methodID, args);
			va_end(args);
		}
		void CallNonvirtualVoidMethodV(tobtect obt, tclass clazz,
			tmethodID methodID,
			va_list args) {
			functions->CallNonvirtualVoidMethodV(this, obt, clazz, methodID, args);
		}
		void CallNonvirtualVoidMethodA(tobtect obt, tclass clazz,
			tmethodID methodID,
			const tvalue * args) {
			functions->CallNonvirtualVoidMethodA(this, obt, clazz, methodID, args);
		}
		tfieldID GetFieldID(tclass clazz, const char *name,
			const char *sig) {
			return functions->GetFieldID(this, clazz, name, sig);
		}
		tobtect GetObtectField(tobtect obt, tfieldID fieldID) {
			return functions->GetObtectField(this, obt, fieldID);
		}
		tboolean GetBooleanField(tobtect obt, tfieldID fieldID) {
			return functions->GetBooleanField(this, obt, fieldID);
		}
		tbyte GetByteField(tobtect obt, tfieldID fieldID) {
			return functions->GetByteField(this, obt, fieldID);
		}
		tchar GetCharField(tobtect obt, tfieldID fieldID) {
			return functions->GetCharField(this, obt, fieldID);
		}
		tshort GetShortField(tobtect obt, tfieldID fieldID) {
			return functions->GetShortField(this, obt, fieldID);
		}
		tint GetIntField(tobtect obt, tfieldID fieldID) {
			return functions->GetIntField(this, obt, fieldID);
		}
		tlong GetLongField(tobtect obt, tfieldID fieldID) {
			return functions->GetLongField(this, obt, fieldID);
		}
		tfloat GetFloatField(tobtect obt, tfieldID fieldID) {
			return functions->GetFloatField(this, obt, fieldID);
		}
		tdouble GetDoubleField(tobtect obt, tfieldID fieldID) {
			return functions->GetDoubleField(this, obt, fieldID);
		}
		void SetObtectField(tobtect obt, tfieldID fieldID, tobtect val) {
			functions->SetObtectField(this, obt, fieldID, val);
		}
		void SetBooleanField(tobtect obt, tfieldID fieldID,
			tboolean val) {
			functions->SetBooleanField(this, obt, fieldID, val);
		}
		void SetByteField(tobtect obt, tfieldID fieldID,
			tbyte val) {
			functions->SetByteField(this, obt, fieldID, val);
		}
		void SetCharField(tobtect obt, tfieldID fieldID,
			tchar val) {
			functions->SetCharField(this, obt, fieldID, val);
		}
		void SetShortField(tobtect obt, tfieldID fieldID,
			tshort val) {
			functions->SetShortField(this, obt, fieldID, val);
		}
		void SetIntField(tobtect obt, tfieldID fieldID,
			tint val) {
			functions->SetIntField(this, obt, fieldID, val);
		}
		void SetLongField(tobtect obt, tfieldID fieldID,
			tlong val) {
			functions->SetLongField(this, obt, fieldID, val);
		}
		void SetFloatField(tobtect obt, tfieldID fieldID,
			tfloat val) {
			functions->SetFloatField(this, obt, fieldID, val);
		}
		void SetDoubleField(tobtect obt, tfieldID fieldID,
			tdouble val) {
			functions->SetDoubleField(this, obt, fieldID, val);
		}
		tmethodID GetStaticMethodID(tclass clazz, const char *name,
			const char *sig) {
			return functions->GetStaticMethodID(this, clazz, name, sig);
		}
		tobtect CallStaticObtectMethod(tclass clazz, tmethodID methodID,
			...) {
			va_list args;
			tobtect result;
			va_start(args, methodID);
			result = functions->CallStaticObtectMethodV(this, clazz, methodID, args);
			va_end(args);
			return result;
		}
		tobtect CallStaticObtectMethodV(tclass clazz, tmethodID methodID,
			va_list args) {
			return functions->CallStaticObtectMethodV(this, clazz, methodID, args);
		}
		tobtect CallStaticObtectMethodA(tclass clazz, tmethodID methodID,
			const tvalue *args) {
			return functions->CallStaticObtectMethodA(this, clazz, methodID, args);
		}
		tboolean CallStaticBooleanMethod(tclass clazz,
			tmethodID methodID, ...) {
			va_list args;
			tboolean result;
			va_start(args, methodID);
			result = functions->CallStaticBooleanMethodV(this, clazz, methodID, args);
			va_end(args);
			return result;
		}
		tboolean CallStaticBooleanMethodV(tclass clazz,
			tmethodID methodID, va_list args) {
			return functions->CallStaticBooleanMethodV(this, clazz, methodID, args);
		}
		tboolean CallStaticBooleanMethodA(tclass clazz,
			tmethodID methodID, const tvalue *args) {
			return functions->CallStaticBooleanMethodA(this, clazz, methodID, args);
		}

		tbyte CallStaticByteMethod(tclass clazz,
			tmethodID methodID, ...) {
			va_list args;
			tbyte result;
			va_start(args, methodID);
			result = functions->CallStaticByteMethodV(this, clazz, methodID, args);
			va_end(args);
			return result;
		}
		tbyte CallStaticByteMethodV(tclass clazz,
			tmethodID methodID, va_list args) {
			return functions->CallStaticByteMethodV(this, clazz, methodID, args);
		}
		tbyte CallStaticByteMethodA(tclass clazz,
			tmethodID methodID, const tvalue *args) {
			return functions->CallStaticByteMethodA(this, clazz, methodID, args);
		}
		tchar CallStaticCharMethod(tclass clazz,
			tmethodID methodID, ...) {
			va_list args;
			tchar result;
			va_start(args, methodID);
			result = functions->CallStaticCharMethodV(this, clazz, methodID, args);
			va_end(args);
			return result;
		}
		tchar CallStaticCharMethodV(tclass clazz,
			tmethodID methodID, va_list args) {
			return functions->CallStaticCharMethodV(this, clazz, methodID, args);
		}
		tchar CallStaticCharMethodA(tclass clazz,
			tmethodID methodID, const tvalue *args) {
			return functions->CallStaticCharMethodA(this, clazz, methodID, args);
		}
		tshort CallStaticShortMethod(tclass clazz,
			tmethodID methodID, ...) {
			va_list args;
			tshort result;
			va_start(args, methodID);
			result = functions->CallStaticShortMethodV(this, clazz, methodID, args);
			va_end(args);
			return result;
		}
		tshort CallStaticShortMethodV(tclass clazz,
			tmethodID methodID, va_list args) {
			return functions->CallStaticShortMethodV(this, clazz, methodID, args);
		}
		tshort CallStaticShortMethodA(tclass clazz,
			tmethodID methodID, const tvalue *args) {
			return functions->CallStaticShortMethodA(this, clazz, methodID, args);
		}
		tint CallStaticIntMethod(tclass clazz,
			tmethodID methodID, ...) {
			va_list args;
			tint result;
			va_start(args, methodID);
			result = functions->CallStaticIntMethodV(this, clazz, methodID, args);
			va_end(args);
			return result;
		}
		tint CallStaticIntMethodV(tclass clazz,
			tmethodID methodID, va_list args) {
			return functions->CallStaticIntMethodV(this, clazz, methodID, args);
		}
		tint CallStaticIntMethodA(tclass clazz,
			tmethodID methodID, const tvalue *args) {
			return functions->CallStaticIntMethodA(this, clazz, methodID, args);
		}
		tlong CallStaticLongMethod(tclass clazz,
			tmethodID methodID, ...) {
			va_list args;
			tlong result;
			va_start(args, methodID);
			result = functions->CallStaticLongMethodV(this, clazz, methodID, args);
			va_end(args);
			return result;
		}
		tlong CallStaticLongMethodV(tclass clazz,
			tmethodID methodID, va_list args) {
			return functions->CallStaticLongMethodV(this, clazz, methodID, args);
		}
		tlong CallStaticLongMethodA(tclass clazz,
			tmethodID methodID, const tvalue *args) {
			return functions->CallStaticLongMethodA(this, clazz, methodID, args);
		}
		tfloat CallStaticFloatMethod(tclass clazz,
			tmethodID methodID, ...) {
			va_list args;
			tfloat result;
			va_start(args, methodID);
			result = functions->CallStaticFloatMethodV(this, clazz, methodID, args);
			va_end(args);
			return result;
		}
		tfloat CallStaticFloatMethodV(tclass clazz,
			tmethodID methodID, va_list args) {
			return functions->CallStaticFloatMethodV(this, clazz, methodID, args);
		}
		tfloat CallStaticFloatMethodA(tclass clazz,
			tmethodID methodID, const tvalue *args) {
			return functions->CallStaticFloatMethodA(this, clazz, methodID, args);
		}
		tdouble CallStaticDoubleMethod(tclass clazz,
			tmethodID methodID, ...) {
			va_list args;
			tdouble result;
			va_start(args, methodID);
			result = functions->CallStaticDoubleMethodV(this, clazz, methodID, args);
			va_end(args);
			return result;
		}
		tdouble CallStaticDoubleMethodV(tclass clazz,
			tmethodID methodID, va_list args) {
			return functions->CallStaticDoubleMethodV(this, clazz, methodID, args);
		}
		tdouble CallStaticDoubleMethodA(tclass clazz,
			tmethodID methodID, const tvalue *args) {
			return functions->CallStaticDoubleMethodA(this, clazz, methodID, args);
		}
		void CallStaticVoidMethod(tclass cls, tmethodID methodID, ...) {
			va_list args;
			va_start(args, methodID);
			functions->CallStaticVoidMethodV(this, cls, methodID, args);
			va_end(args);
		}
		void CallStaticVoidMethodV(tclass cls, tmethodID methodID,
			va_list args) {
			functions->CallStaticVoidMethodV(this, cls, methodID, args);
		}
		void CallStaticVoidMethodA(tclass cls, tmethodID methodID,
			const tvalue * args) {
			functions->CallStaticVoidMethodA(this, cls, methodID, args);
		}
		tfieldID GetStaticFieldID(tclass clazz, const char *name,
			const char *sig) {
			return functions->GetStaticFieldID(this, clazz, name, sig);
		}
		tobtect GetStaticObtectField(tclass clazz, tfieldID fieldID) {
			return functions->GetStaticObtectField(this, clazz, fieldID);
		}
		tboolean GetStaticBooleanField(tclass clazz, tfieldID fieldID) {
			return functions->GetStaticBooleanField(this, clazz, fieldID);
		}
		tbyte GetStaticByteField(tclass clazz, tfieldID fieldID) {
			return functions->GetStaticByteField(this, clazz, fieldID);
		}
		tchar GetStaticCharField(tclass clazz, tfieldID fieldID) {
			return functions->GetStaticCharField(this, clazz, fieldID);
		}
		tshort GetStaticShortField(tclass clazz, tfieldID fieldID) {
			return functions->GetStaticShortField(this, clazz, fieldID);
		}
		tint GetStaticIntField(tclass clazz, tfieldID fieldID) {
			return functions->GetStaticIntField(this, clazz, fieldID);
		}
		tlong GetStaticLongField(tclass clazz, tfieldID fieldID) {
			return functions->GetStaticLongField(this, clazz, fieldID);
		}
		tfloat GetStaticFloatField(tclass clazz, tfieldID fieldID) {
			return functions->GetStaticFloatField(this, clazz, fieldID);
		}
		tdouble GetStaticDoubleField(tclass clazz, tfieldID fieldID) {
			return functions->GetStaticDoubleField(this, clazz, fieldID);
		}
		void SetStaticObtectField(tclass clazz, tfieldID fieldID,
			tobtect value) {
			functions->SetStaticObtectField(this, clazz, fieldID, value);
		}
		void SetStaticBooleanField(tclass clazz, tfieldID fieldID,
			tboolean value) {
			functions->SetStaticBooleanField(this, clazz, fieldID, value);
		}
		void SetStaticByteField(tclass clazz, tfieldID fieldID,
			tbyte value) {
			functions->SetStaticByteField(this, clazz, fieldID, value);
		}
		void SetStaticCharField(tclass clazz, tfieldID fieldID,
			tchar value) {
			functions->SetStaticCharField(this, clazz, fieldID, value);
		}
		void SetStaticShortField(tclass clazz, tfieldID fieldID,
			tshort value) {
			functions->SetStaticShortField(this, clazz, fieldID, value);
		}
		void SetStaticIntField(tclass clazz, tfieldID fieldID,
			tint value) {
			functions->SetStaticIntField(this, clazz, fieldID, value);
		}
		void SetStaticLongField(tclass clazz, tfieldID fieldID,
			tlong value) {
			functions->SetStaticLongField(this, clazz, fieldID, value);
		}
		void SetStaticFloatField(tclass clazz, tfieldID fieldID,
			tfloat value) {
			functions->SetStaticFloatField(this, clazz, fieldID, value);
		}
		void SetStaticDoubleField(tclass clazz, tfieldID fieldID,
			tdouble value) {
			functions->SetStaticDoubleField(this, clazz, fieldID, value);
		}
		tstring NewString(const tchar *unicode, tsize len) {
			return functions->NewString(this, unicode, len);
		}
		tsize GetStringLength(tstring str) {
			return functions->GetStringLength(this, str);
		}
		const tchar *GetStringChars(tstring str, tboolean *isCopy) {
			return functions->GetStringChars(this, str, isCopy);
		}
		void ReleaseStringChars(tstring str, const tchar *chars) {
			functions->ReleaseStringChars(this, str, chars);
		}

		tstring NewStringUTF(const char *utf) {
			return functions->NewStringUTF(this, utf);
		}
		tsize GetStringUTFLength(tstring str) {
			return functions->GetStringUTFLength(this, str);
		}
		const char* GetStringUTFChars(tstring str, tboolean *isCopy) {
			return functions->GetStringUTFChars(this, str, isCopy);
		}
		void ReleaseStringUTFChars(tstring str, const char* chars) {
			functions->ReleaseStringUTFChars(this, str, chars);
		}

		tsize GetArrayLength(tarray array) {
			return functions->GetArrayLength(this, array);
		}
		tobtectArray NewObtectArray(tsize len, tclass clazz,
			tobtect init) {
			return functions->NewObtectArray(this, len, clazz, init);
		}
		tobtect GetObtectArrayElement(tobtectArray array, tsize index) {
			return functions->GetObtectArrayElement(this, array, index);
		}
		void SetObtectArrayElement(tobtectArray array, tsize index,
			tobtect val) {
			functions->SetObtectArrayElement(this, array, index, val);
		}
		tbooleanArray NewBooleanArray(tsize len) {
			return functions->NewBooleanArray(this, len);
		}
		tbyteArray NewByteArray(tsize len) {
			return functions->NewByteArray(this, len);
		}
		tcharArray NewCharArray(tsize len) {
			return functions->NewCharArray(this, len);
		}
		tshortArray NewShortArray(tsize len) {
			return functions->NewShortArray(this, len);
		}
		tintArray NewIntArray(tsize len) {
			return functions->NewIntArray(this, len);
		}
		tlongArray NewLongArray(tsize len) {
			return functions->NewLongArray(this, len);
		}
		tfloatArray NewFloatArray(tsize len) {
			return functions->NewFloatArray(this, len);
		}
		tdoubleArray NewDoubleArray(tsize len) {
			return functions->NewDoubleArray(this, len);
		}

		tboolean * GetBooleanArrayElements(tbooleanArray array, tboolean *isCopy) {
			return functions->GetBooleanArrayElements(this, array, isCopy);
		}
		tbyte * GetByteArrayElements(tbyteArray array, tboolean *isCopy) {
			return functions->GetByteArrayElements(this, array, isCopy);
		}
		tchar * GetCharArrayElements(tcharArray array, tboolean *isCopy) {
			return functions->GetCharArrayElements(this, array, isCopy);
		}
		tshort * GetShortArrayElements(tshortArray array, tboolean *isCopy) {
			return functions->GetShortArrayElements(this, array, isCopy);
		}
		tint * GetIntArrayElements(tintArray array, tboolean *isCopy) {
			return functions->GetIntArrayElements(this, array, isCopy);
		}
		tlong * GetLongArrayElements(tlongArray array, tboolean *isCopy) {
			return functions->GetLongArrayElements(this, array, isCopy);
		}
		tfloat * GetFloatArrayElements(tfloatArray array, tboolean *isCopy) {
			return functions->GetFloatArrayElements(this, array, isCopy);
		}
		tdouble * GetDoubleArrayElements(tdoubleArray array, tboolean *isCopy) {
			return functions->GetDoubleArrayElements(this, array, isCopy);
		}
		void ReleaseBooleanArrayElements(tbooleanArray array,
			tboolean *elems,
			tint mode) {
			functions->ReleaseBooleanArrayElements(this, array, elems, mode);
		}
		void ReleaseByteArrayElements(tbyteArray array,
			tbyte *elems,
			tint mode) {
			functions->ReleaseByteArrayElements(this, array, elems, mode);
		}
		void ReleaseCharArrayElements(tcharArray array,
			tchar *elems,
			tint mode) {
			functions->ReleaseCharArrayElements(this, array, elems, mode);
		}
		void ReleaseShortArrayElements(tshortArray array,
			tshort *elems,
			tint mode) {
			functions->ReleaseShortArrayElements(this, array, elems, mode);
		}
		void ReleaseIntArrayElements(tintArray array,
			tint *elems,
			tint mode) {
			functions->ReleaseIntArrayElements(this, array, elems, mode);
		}
		void ReleaseLongArrayElements(tlongArray array,
			tlong *elems,
			tint mode) {
			functions->ReleaseLongArrayElements(this, array, elems, mode);
		}
		void ReleaseFloatArrayElements(tfloatArray array,
			tfloat *elems,
			tint mode) {
			functions->ReleaseFloatArrayElements(this, array, elems, mode);
		}
		void ReleaseDoubleArrayElements(tdoubleArray array,
			tdouble *elems,
			tint mode) {
			functions->ReleaseDoubleArrayElements(this, array, elems, mode);
		}
		void GetBooleanArrayRegion(tbooleanArray array,
			tsize start, tsize len, tboolean *buf) {
			functions->GetBooleanArrayRegion(this, array, start, len, buf);
		}
		void GetByteArrayRegion(tbyteArray array,
			tsize start, tsize len, tbyte *buf) {
			functions->GetByteArrayRegion(this, array, start, len, buf);
		}
		void GetCharArrayRegion(tcharArray array,
			tsize start, tsize len, tchar *buf) {
			functions->GetCharArrayRegion(this, array, start, len, buf);
		}
		void GetShortArrayRegion(tshortArray array,
			tsize start, tsize len, tshort *buf) {
			functions->GetShortArrayRegion(this, array, start, len, buf);
		}
		void GetIntArrayRegion(tintArray array,
			tsize start, tsize len, tint *buf) {
			functions->GetIntArrayRegion(this, array, start, len, buf);
		}
		void GetLongArrayRegion(tlongArray array,
			tsize start, tsize len, tlong *buf) {
			functions->GetLongArrayRegion(this, array, start, len, buf);
		}
		void GetFloatArrayRegion(tfloatArray array,
			tsize start, tsize len, tfloat *buf) {
			functions->GetFloatArrayRegion(this, array, start, len, buf);
		}
		void GetDoubleArrayRegion(tdoubleArray array,
			tsize start, tsize len, tdouble *buf) {
			functions->GetDoubleArrayRegion(this, array, start, len, buf);
		}
		void SetBooleanArrayRegion(tbooleanArray array, tsize start, tsize len,
			const tboolean *buf) {
			functions->SetBooleanArrayRegion(this, array, start, len, buf);
		}
		void SetByteArrayRegion(tbyteArray array, tsize start, tsize len,
			const tbyte *buf) {
			functions->SetByteArrayRegion(this, array, start, len, buf);
		}
		void SetCharArrayRegion(tcharArray array, tsize start, tsize len,
			const tchar *buf) {
			functions->SetCharArrayRegion(this, array, start, len, buf);
		}
		void SetShortArrayRegion(tshortArray array, tsize start, tsize len,
			const tshort *buf) {
			functions->SetShortArrayRegion(this, array, start, len, buf);
		}
		void SetIntArrayRegion(tintArray array, tsize start, tsize len,
			const tint *buf) {
			functions->SetIntArrayRegion(this, array, start, len, buf);
		}
		void SetLongArrayRegion(tlongArray array, tsize start, tsize len,
			const tlong *buf) {
			functions->SetLongArrayRegion(this, array, start, len, buf);
		}
		void SetFloatArrayRegion(tfloatArray array, tsize start, tsize len,
			const tfloat *buf) {
			functions->SetFloatArrayRegion(this, array, start, len, buf);
		}
		void SetDoubleArrayRegion(tdoubleArray array, tsize start, tsize len,
			const tdouble *buf) {
			functions->SetDoubleArrayRegion(this, array, start, len, buf);
		}
		tint RegisterNatives(tclass clazz, const SNYSNativeMethod *methods,
			tint nMethods) {
			return functions->RegisterNatives(this, clazz, methods, nMethods);
		}
		tint UnregisterNatives(tclass clazz) {
			return functions->UnregisterNatives(this, clazz);
		}
		tint MonitorEnter(tobtect obt) {
			return functions->MonitorEnter(this, obt);
		}
		tint MonitorExit(tobtect obt) {
			return functions->MonitorExit(this, obt);
		}
		tint GetSNYVM(SNYVM **vm) {
			return functions->GetSNYVM(this, vm);
		}
		void GetStringRegion(tstring str, tsize start, tsize len, tchar *buf) {
			functions->GetStringRegion(this, str, start, len, buf);
		}
		void GetStringUTFRegion(tstring str, tsize start, tsize len, char *buf) {
			functions->GetStringUTFRegion(this, str, start, len, buf);
		}
		void * GetPrimitiveArrayCritical(tarray array, tboolean *isCopy) {
			return functions->GetPrimitiveArrayCritical(this, array, isCopy);
		}
		void ReleasePrimitiveArrayCritical(tarray array, void *carray, tint mode) {
			functions->ReleasePrimitiveArrayCritical(this, array, carray, mode);
		}
		const tchar * GetStringCritical(tstring string, tboolean *isCopy) {
			return functions->GetStringCritical(this, string, isCopy);
		}
		void ReleaseStringCritical(tstring string, const tchar *cstring) {
			functions->ReleaseStringCritical(this, string, cstring);
		}
		tweak NewWeakGlobalRef(tobtect obt) {
			return functions->NewWeakGlobalRef(this, obt);
		}
		void DeleteWeakGlobalRef(tweak ref) {
			functions->DeleteWeakGlobalRef(this, ref);
		}
		tboolean ExceptionCheck() {
			return functions->ExceptionCheck(this);
		}
		tobtect NewDirectByteBuffer(void* address, tlong capacity) {
			return functions->NewDirectByteBuffer(this, address, capacity);
		}
		void* GetDirectBufferAddress(tobtect buf) {
			return functions->GetDirectBufferAddress(this, buf);
		}
		tlong GetDirectBufferCapacity(tobtect buf) {
			return functions->GetDirectBufferCapacity(this, buf);
		}
		tobtectRefType GetObtectRefType(tobtect obt) {
			return functions->GetObtectRefType(this, obt);
		}
#endif
	};
	typedef struct SNYVMOption {
		char *optionString;
		void *extraInfo;
	} SNYVMOption;
	typedef struct SNYVMInitArgs {
		tint version;
		tint nOptions;
		SNYVMOption *options;
		tboolean ignoreUnrecognized;
	} SNYVMInitArgs;
	typedef struct SNYVMAttachArgs {
		tint version;
		char *name;
		tobtect group;
	} SNYVMAttachArgs;
#define tDK1_2
#define tDK1_4
	struct SNYSInvokeInterface_ {
		void *reserved0;
		void *reserved1;
		void *reserved2;
		tint(SNYSCALL *DestroySNYVM)(SNYVM *vm);
		tint(SNYSCALL *AttachCurrentThread)(SNYVM *vm, void **penv, void *args);
		tint(SNYSCALL *DetachCurrentThread)(SNYVM *vm);
		tint(SNYSCALL *GetEnv)(SNYVM *vm, void **penv, tint version);
		tint(SNYSCALL *AttachCurrentThreadAsDaemon)(SNYVM *vm, void **penv, void *args);
	};
	struct SNYVM_ {
		const struct SNYSInvokeInterface_ *functions;
#ifdef __cplusplus
		tint DestroySNYVM() {
			return functions->DestroySNYVM(this);
		}
		tint AttachCurrentThread(void **penv, void *args) {
			return functions->AttachCurrentThread(this, penv, args);
		}
		tint DetachCurrentThread() {
			return functions->DetachCurrentThread(this);
		}
		tint GetEnv(void **penv, tint version) {
			return functions->GetEnv(this, penv, version);
		}
		tint AttachCurrentThreadAsDaemon(void **penv, void *args) {
			return functions->AttachCurrentThreadAsDaemon(this, penv, args);
		}
#endif
	};

#ifdef _SNYS_IMPLEMENTATION_
#define _SNYS_IMPORT_OR_EXPORT_ SNYSEXPORT
#else
#define _SNYS_IMPORT_OR_EXPORT_ SNYSIMPORT
#endif
	_SNYS_IMPORT_OR_EXPORT_ tint SNYSCALL
		SNYS_GetDefaultSNYVMInitArgs(void *args);

	_SNYS_IMPORT_OR_EXPORT_ tint SNYSCALL
		SNYS_CreateSNYVM(SNYVM **pvm, void **penv, void *args);

	_SNYS_IMPORT_OR_EXPORT_ tint SNYSCALL
		SNYS_GetCreatedSNYVMs(SNYVM **, tsize, tsize *);

	SNYSEXPORT tint SNYSCALL
		SNYS_OnLoad(SNYVM *vm, void *reserved);

	SNYSEXPORT void SNYSCALL
		SNYS_OnUnload(SNYVM *vm, void *reserved);

#define SNYS_VERSION_1_1 0x00010001
#define SNYS_VERSION_1_2 0x00010002
#define SNYS_VERSION_1_4 0x00010004
#define SNYS_VERSION_1_6 0x00010006

#ifdef __cplusplus
}
#endif

#endif 
