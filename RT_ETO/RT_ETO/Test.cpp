#include "stdafx.h"
#include "Test.h"

Test::Test() 
{
	this->chandle = GetStdHandle(STD_OUTPUT_HANDLE);
}

Test::~Test() {

}

void Test::set_color(COLOR color)
{
	SetConsoleTextAttribute(this->chandle, color);
}

void Test::print_message(string msg, bool is_pass)
{
	
	if (is_pass)
	{
		this->set_color(COLOR::GREEN);
		cout << "PASS";
	}
	else 
	{
		this->set_color(COLOR::RED);
		cout << "FAILED";
	}

	this->set_color(COLOR::YELLOW);
	cout << "\t\t..." << msg << endl;
	this->set_color(COLOR::DEFAULT_WHITE);
}

void Test::ASSERT_EQUALS(string msg, string val_1, string val_2)
{
	this->print_message(msg, val_1 == val_2);
}

void Test::ASSERT_EQUALS(string msg, int val_1, int val_2)
{
	this->print_message(msg, val_1 == val_2);
}

void Test::ASSERT_EQUALS(string msg, float val_1, float val_2)
{
	this->print_message(msg, val_1 == val_2);
}

void Test::ASSERT_EQUALS(string msg, double val_1, double val_2)
{
	this->print_message(msg, val_1 == val_2);
}

void Test::ASSERT_EQUALS(string msg, char val_1, char val_2)
{
	this->print_message(msg, val_1 == val_2);
}

void Test::ASSERT_EQUALS(string msg, uint8_t val_1, uint8_t val_2)
{
	this->print_message(msg, val_1 == val_2);
}

void Test::ASSERT_GREATER_THAN_EQUAL(string msg, float val_1, float val_2)
{
	this->print_message(msg, val_1 >= val_2);
}

void Test::ASSERT_LESS_THAN_EQUAL(string msg, float val_1, float val_2)
{
	this->print_message(msg, val_1 <= val_2);
}

void Test::HEADER_PRINT(string msg)
{
	this->set_color(COLOR::CYAN);
	cout << endl << endl << msg << endl << endl;
}
