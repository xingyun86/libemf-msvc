/*
 * EMF: A library for generating ECMA-234 Enhanced Metafiles
 * Copyright (C) 2002 lignum Computing, Inc. <dallenbarnett@users.sourceforge.net>
 * $Id: emf.h 93 2020-04-18 13:30:11Z dallenbarnett $
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */
#ifndef _EMF_H
#define _EMF_H

#include <stdio.h>
#include <string.h>

#include <libEMF/wine/windef.h>
#include <libEMF/wine/winbase.h>
#include <libEMF/wine/wingdi.h>
#include <libEMF/wine/winuser.h>
#include <libEMF/wine/winerror.h>

#if defined(LIBEMF_EXPORTS)
#define EMF_DECLARE(type)	/*extern "C"*/ __declspec(dllexport) type __stdcall
#elif defined(LIBEMF_IMPORTS)
#define EMF_DECLARE(type)	/*extern "C"*/ __declspec(dllimport) type __stdcall
#else
#define EMF_DECLARE(type) type
#endif

#ifdef __cplusplus
extern "C" {
#endif                                                                          
/*
 * Here are additional, non-"standard" routines which the author deems useful.
 */
EMF_DECLARE(HDC) CreateEnhMetaFileWithFILEA( HDC context, FILE* fp, const RECT* size,
				LPCSTR description );
EMF_DECLARE(HDC) CreateEnhMetaFileWithFILEW( HDC context, FILE* fp, const RECT* size,
				LPCWSTR description );
EMF_DECLARE(HENHMETAFILE) CloseEnhMetaFileWithFILE( HDC context );
/*
 * This function will only produce output if the library has been compiled with
 * editing enabled (e.g., ./configure --enable-editing).
 */
EMF_DECLARE(VOID) EditEnhMetaFile ( HENHMETAFILE metafile );
#ifdef __cplusplus
}
#endif                                                                          

#endif /* _EMF_H */
