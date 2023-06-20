//wrapper definitions for C wrapper for MatherCPP class
#include "pch.h"
#include "Mather.h"
#include "MatherCPP.h"

void* WINAPI mather_create_1()
{
	void* m;
	MatherCPP obj;
	m = &obj;

	return m;
}

void* WINAPI mather_create_2(double start)
{
	void* m;
	MatherCPP obj(start);
	m = &obj;

	return m;
}

void* WINAPI mather_create_3(double start1, double start2)
{
	void* m;
	MatherCPP obj(start1, start2);
	m = &obj;

	return m;
}

//deprecated. You should not need to use, as object should only be destroyed when Excel
//shuts down anyway, thus having the system automatically handle memory cleanup.
void WINAPI mather_destroy(void* m)
{
	if (m == NULL)
		return;
	delete (MatherCPP*)m;
}

double WINAPI mather_add_1(void* m)
{
	if (m == NULL)
		return -1.0;
	MatherCPP* obj = (MatherCPP*)m;
	return obj->add_nums();
}

double WINAPI mather_add_2(void* m, double x)
{
	if (m == NULL)
		return -1.0;
	MatherCPP* obj = (MatherCPP*)m;
	return obj->add_num_one(x);
}

double WINAPI mather_sum(void* m, double x, double y)
{
	if (m == NULL)
		return -1.0;
	MatherCPP* obj = (MatherCPP*)m;
	return obj->sum(x, y);
}


//C style wrapped getters for the MatherCPP class
double WINAPI mather_get_one(void* m)
{
	if (m == NULL)
		return -1.0;
	MatherCPP* obj = (MatherCPP*)m;
	return obj->get_num1();
}

double WINAPI mather_get_two(void* m)
{
	if (m == NULL)
		return -1.0;
	MatherCPP* obj = (MatherCPP*)m;
	return obj->get_num2();
}