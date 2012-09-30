#pragma once

#ifdef UNUSED
	#error "UNUSED already defined"	
#else
	#define UNUSED(identifier) /* identifier */
#endif

#define DISABLE_COPY_ASSIGN(ClassName)			\
	private:									\
	ClassName(const ClassName&);				\
	ClassName(const ClassName&&);				\
	ClassName& operator=(const ClassName&);		\
	ClassName& operator=(const ClassName&&);

//#define DISABLE_WARNINGS __pragma(warning(push, 0))
//#define ENABLE_WARNINGS __pragma(warning(pop))
