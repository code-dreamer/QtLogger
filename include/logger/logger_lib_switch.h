#pragma once

#include <QtCore/qglobal.h>

//--------------------------------------------------------------------
//
// It defines the way the library is built (static or dynamic)
//
//	If you want to build library as a static
//	or fully include it to your project, you should define LOGGER_LIB.
//	Otherwise, define LOGGER_DLL.
//
//--------------------------------------------------------------------

#ifndef LOGGER_EXPORT
	#if defined(LOGGER_LIB)
		#define LOGGER_EXPORT		// build as a static library
	#else
		#ifdef LOGGER_DLL
			#define LOGGER_EXPORT		Q_DECL_EXPORT //__declspec(dllexport)
		#else
			#define LOGGER_EXPORT		Q_DECL_IMPORT //__declspec(dllimport)
		#endif
	#endif
#endif