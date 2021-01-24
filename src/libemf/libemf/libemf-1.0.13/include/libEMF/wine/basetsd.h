/*
 * Compilers that uses ILP32, LP64 or P64 type models
 * for both Win32 and Win64 are supported by this file.
 */

#ifndef __WINE_BASETSD_H
#define __WINE_BASETSD_H

#ifdef __cplusplus
extern "C" {
#endif /* defined(__cplusplus) */

/*
 * Win32 was easy to implement under Unix since most (all?) 32-bit
 * Unices uses the same type model (ILP32) as Win32, where int, long
 * and pointer are 32-bit.
 *
 * Win64, however, will cause some problems when implemented under Unix.
 * Linux/{Alpha, Sparc64} and most (all?) other 64-bit Unices uses
 * the LP64 type model where int is 32-bit and long and pointer are
 * 64-bit. Win64 on the other hand uses the P64 (sometimes called LLP64)
 * type model where int and long are 32 bit and pointer is 64-bit.
 */

/* Type model indepent typedefs */

typedef char          my__int8;
typedef unsigned char my__uint8;

typedef short          my__int16;
typedef unsigned short my__uint16;

typedef int          my__int32;
typedef unsigned int my__uint32;

// wogl
//typedef long long          my__int64;
//typedef unsigned long long my__uint64;
typedef long          my__int64;
typedef unsigned long my__uint64;

#if defined(_WIN64)

typedef my__uint32 my__ptr32;
typedef void    *my__ptr64;

#else /* FIXME: defined(_WIN32) */

typedef void    *my__ptr32;
typedef my__uint64 my__ptr64;

#endif

/* Always signed and 32 bit wide */

typedef my__int32 LONG32;
typedef my__int32 INT32;

typedef LONG32 *PLONG32;
typedef INT32  *PINT32;

/* Always unsigned and 32 bit wide */

typedef my__uint32 ULONG32;
typedef my__uint32 DWORD32;
typedef my__uint32 UINT32;

typedef ULONG32 *PULONG32;
typedef DWORD32 *PDWORD32;
typedef UINT32  *PUINT32;

/* Always signed and 64 bit wide */

typedef my__int64 LONG64;
typedef my__int64 INT64;

typedef LONG64 *PLONG64;
typedef INT64  *PINT64;

/* Always unsigned and 64 bit wide */

typedef my__uint64 ULONG64;
typedef my__uint64 DWORD64;
typedef my__uint64 UINT64;

typedef ULONG64 *PULONG64;
typedef DWORD64 *PDWORD64;
typedef UINT64  *PUINT64;

/* Win32 or Win64 dependent typedef/defines. */

#ifdef _WIN64

typedef my__int64 INT_PTR, *PINT_PTR;
typedef my__uint64 UINT_PTR, *PUINT_PTR;

#define MAXINT_PTR 0x7fffffffffffffff
#define MININT_PTR 0x8000000000000000
#define MAXUINT_PTR 0xffffffffffffffff

typedef my__int32 HALF_PTR, *PHALF_PTR;
typedef my__int32 UHALF_PTR, *PUHALF_PTR;

#define MAXHALF_PTR 0x7fffffff
#define MINHALF_PTR 0x80000000
#define MAXUHALF_PTR 0xffffffff

typedef my__int64 LONG_PTR, *PLONG_PTR;
typedef my__uint64 ULONG_PTR, *PULONG_PTR;
typedef my__uint64 DWORD_PTR, *PDWORD_PTR;

#else /* FIXME: defined(_WIN32) */

typedef my__int32 INT_PTR, *PINT_PTR;
typedef my__uint32 UINT_PTR, *PUINT_PTR;

#define MAXINT_PTR 0x7fffffff
#define MININT_PTR 0x80000000
#define MAXUINT_PTR 0xffffffff

typedef my__int16 HALF_PTR, *PHALF_PTR;
typedef my__uint16 UHALF_PTR, *PUHALF_PTR;

#define MAXUHALF_PTR 0xffff
#define MAXHALF_PTR 0x7fff
#define MINHALF_PTR 0x8000

typedef my__int32 LONG_PTR, *PLONG_PTR;
typedef my__uint32 ULONG_PTR, *PULONG_PTR;
typedef my__uint32 DWORD_PTR, *PDWORD_PTR;

#endif /* defined(_WIN64) || defined(_WIN32) */

typedef INT_PTR SSIZE_T, *PSSIZE_T;
typedef UINT_PTR SIZE_T, *PSIZE_T;

#ifdef __cplusplus
} /* extern "C" */
#endif /* defined(__cplusplus) */

#endif /* !defined(__WINE_BASETSD_H) */



