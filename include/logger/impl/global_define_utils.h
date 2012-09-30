#pragma once

#define DISABLE_COPY_ASSIGN(ClassName)			\
	private:									\
		ClassName(const ClassName&);			\
		ClassName(const ClassName&&);			\
		ClassName& operator=(const ClassName&); \
		ClassName& operator=(const ClassName&&);
