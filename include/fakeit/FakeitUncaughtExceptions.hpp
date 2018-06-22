/*
* Copyright (c) 2018 Oleg Anikin.
*
* This program is made available under the terms of the MIT License.
*
* Created on Jun 22, 2018
*/
#pragma once

#include <exception>

#if __cplusplus >= 201703L
#    define FAKEIT_CPP17_OR_GREATER
#endif

#if defined(FAKEIT_CPP17_OR_GREATER)
#    define FAKEIT_CONFIG_CPP17_UNCAUGHT_EXCEPTIONS
#endif

#if _MSC_VER >= 1900 // MSVC++ 14.0 or newer
#    define FAKEIT_CONFIG_CPP17_UNCAUGHT_EXCEPTIONS
#endif

namespace fakeit {

	inline bool uncaught_exceptions()
	{
#if defined(FAKEIT_CONFIG_CPP17_UNCAUGHT_EXCEPTIONS)
		return std::uncaught_exceptions() > 0;
#else
		return std::uncaught_exception();
#endif
	}

}