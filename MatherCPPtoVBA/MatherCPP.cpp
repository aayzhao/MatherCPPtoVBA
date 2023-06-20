//source code for declarations in MatherCPP
#include "pch.h"
#include "MatherCPP.h"

MatherCPP::MatherCPP()
{
	num1 = 0.0;
	num2 = 0.0;
}

MatherCPP::MatherCPP(double x)
{
	num1 = 0.0 + x;
	num2 = 0.0 + x;
}

MatherCPP::MatherCPP(double x, double y)
{
	num1 = 0.0 + x;
	num2 = 0.0 + y;
}

double MatherCPP::add_nums()
{
	return num1 + num2;
}

double MatherCPP::add_num_one(double num)
{
	return num1 + num;
}

double MatherCPP::sum(double x, double y)
{
	return x + y;
}

double MatherCPP::get_num1()
{
	return num1;
}

double MatherCPP::get_num2()
{
	return num2;
}