//C wrapper header file for the MatherCPP class
#pragma once
#ifdef MATHERCPPTOVBA_EXPORTS
#define MATHER_API __declspec(dllexport)
#else
#define MATHER_API __declspec(dllimport)
#endif

extern "C"
{
	struct mather;
	typedef struct mather mather_t;

	MATHER_API mather_t* mather_create_1();
	MATHER_API void* mather_create_2(double start);
	MATHER_API void* mather_create_3(double start1, double start2);
	MATHER_API void mather_destroy(mather_t* m);
	MATHER_API double mather_add_1(void* m);
	MATHER_API double mather_add_2(void* m, double val);
	MATHER_API void mather_delta_1(mather_t* m, double val);
	MATHER_API void mather_delta_2(void* m, double val);
	MATHER_API double mather_sum(mather_t* m, double x, double y);
	MATHER_API double mather_get_one(mather_t* m);
	MATHER_API double mather_get_two(void* m);

}