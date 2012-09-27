#pragma once

// Windows.h must be included for activeqt\shared\qaxtypes.h
/*#ifndef _INC_WINDOWS
#include "WindowsHeaders.h"
#endif

#ifndef __unknwn_h__
#include <Unknwn.h>
#endif*/

#define QT_NO_CAST_FROM_ASCII
#define QT_NO_CAST_TO_ASCII
#define QT_NO_CAST_FROM_BYTEARRAY
#define QT_USE_FAST_CONCATENATION
#define QT_USE_FAST_OPERATOR_PLUS
#define QT_LARGEFILE_SUPPORT
#define QT_NO_KEYWORDS
#define QT_USE_QSTRINGBUILDER

#include <QtCore/qt_windows.h>

//#include <ActiveQt>
//#include <Phonon>
#define QT_CORE_LIB
#include <QtCore>
//#include <QtDBus>
//#include <QtDeclarative>
//#include <QtDesigner>
//#define QT_GUI_LIB
//#include <QtGui>
//#include <QtHelp>
//#include <QtMultimedia>
//#define QT_NETWORK_LIB
//#include <QtNetwork>
//#include <QtOpenGL>
//#include <QtScript>
//#include <QtScriptTools>
//#include <QtSql>
//#include <QtSvg>
//#include <QtTest>
//#include <QtUiTools>
//#include <QtWebKit>
//#define QT_XML_LIB
//#include <QtXml>
//#define QT_XMLPATTERNS_LIB
//#include <QtXmlPatterns>
