//C wrapper header file for the MatherCPP class
#pragma once
#ifdef MATHERLIB_EXPORTS
#define MATHER_API __declspec(dllexport)
#else
#define MATHER_API __declspec(dllimport)
#endif

extern "C"
{

	MATHER_API void* mather_create_1();
	MATHER_API void* mather_create_2(double start);
	MATHER_API void* mather_create_3(double start1, double start2);
	MATHER_API void mather_destroy(void* a);
	MATHER_API double mather_add_1(void* a);
	MATHER_API double mather_add_2(void* a, double val);
	MATHER_API double mather_sum(void* a, double x, double y);
	MATHER_API double mather_get_one(void*);
	MATHER_API double mather_get_two(void*);

}