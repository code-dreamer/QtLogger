#pragma once

#ifdef UNUSED
#	error "UNUSED already defined"	
#else
#	define UNUSED(identifier) /* identifier */
#endif

#define DISABLE_COPY_ASSIGN(ClassName)			\
	private:									\
	ClassName(const ClassName&);				\
	ClassName(const ClassName&&);				\
	ClassName& operator=(const ClassName&);		\
	ClassName& operator=(const ClassName&&);

//#define DISABLE_WARNINGS __pragma(warning(push, 0))
//#define ENABLE_WARNINGS __pragma(warning(pop))

#include <cassert>

#if defined(ASSERT)
#	pragma message ("ASSERT already defined.")
#else
#	define ASSERT(condition)	assert(condition)
#endif

#if defined(CHECK_PTR)
#	pragma message ("CHECK_PTR already defined.")
#else
#	define CHECK_PTR(pointer)								\
	ASSERT_MSG(pointer != nullptr, "Invalid pointer");		\
	Q_CHECK_PTR(pointer)
#endif

#if defined(ASSERT_MSG)
#	pragma message ("ASSERT_MSG already defined.")
#else
#	if defined(DEBUG)
#		define ASSERT_MSG(condition, message) \
	(void)( (!!(condition)) || (_wassert(_CRT_WIDE(#condition) _CRT_WIDE("\nMessage: ") _CRT_WIDE(#message), _CRT_WIDE(__FILE__), __LINE__), 0) )
#	else
#		define ASSERT_MSG(condition, message) ((void)0)
#	endif
#endif


template<typename T>
static void safeDelete(T*& ptr)
{
	CHECK_PTR(ptr);

	typedef char TypeIsCompleteCheck[sizeof(T)];
	if (ptr != nullptr) {
		delete ptr;
		ptr = nullptr;
	}
}

template<typename T>
static void safeSeleteA(T*& ptr) 
{
	CHECK_PTR(ptr);

	typedef char TypeIsCompleteCheck[sizeof(T)];
	if (ptr != nullptr) {
		delete[] ptr;
		ptr = nullptr;
	}
}
