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
	MATHER_API void mather_destroy(void* m);
	MATHER_API double mather_add_1(void* m);
	MATHER_API double mather_add_2(void* m, double val);
	MATHER_API void mather_delta_1(void* m, double val);
	MATHER_API void mather_delta_2(void* m, double val);
	MATHER_API double mather_sum(void* m, double x, double y);
	MATHER_API double mather_get_one(void* m);
	MATHER_API double mather_get_two(void* m);

}