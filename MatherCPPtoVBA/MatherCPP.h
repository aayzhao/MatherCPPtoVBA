//header file for MatherCPP
#pragma once
class MatherCPP
{
public:
	//various constructors
	MatherCPP();
	MatherCPP(double x);
	MatherCPP(double x, double y);

	double add_nums();
	double add_num_one(double num);
	double sum(double x, double y);
	void delta_num1(double num);
	void delta_num2(double num);
	double get_num1();
	double get_num2();

private:
	double num1;
	double num2;
};