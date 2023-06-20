#pragma once
#include <comdef.h>
#include <string>

#ifdef MATHERCPPTOVBA_EXPORTS
#define MATHERSTRING_API __declspec(dllexport)
#else
#define MATHERSTRING_API __declspec(dllimport)
#endif

extern "C" {
	MATHERSTRING_API BSTR ConvertMBSToBSTR(const std::string& str); //should not be called in VBA
	MATHERSTRING_API std::string BSTRtoString(BSTR inBSTR); //should not be called in VBA
	MATHERSTRING_API BSTR WINAPI test_function();
	MATHERSTRING_API BSTR WINAPI is_apple(BSTR inBSTR);
}