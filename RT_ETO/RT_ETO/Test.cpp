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
	cout << "\t..." << msg << endl;
	this->set_color(COLOR::DEFAULT_WHITE);

	if (!is_pass) 
	{
		system("pause");
	}
}

/**
* ASSERT EQUAL METHODS.
*/

void Test::ASSERT_EQUALS(string msg, string val_1, string val_2)
{
	this->print_message("ASSERT EQUALS: " + msg, val_1 == val_2);
}

void Test::ASSERT_EQUALS(string msg, int val_1, int val_2)
{
	this->print_message("ASSERT EQUALS: " + msg, val_1 == val_2);
}

void Test::ASSERT_EQUALS(string msg, float val_1, float val_2)
{
	this->print_message("ASSERT EQUALS: " + msg, val_1 == val_2);
}

void Test::ASSERT_EQUALS(string msg, double val_1, double val_2)
{
	this->print_message("ASSERT EQUALS: " + msg, val_1 == val_2);
}

void Test::ASSERT_EQUALS(string msg, char val_1, char val_2)
{
	this->print_message("ASSERT EQUALS: " + msg, val_1 == val_2);
}

void Test::ASSERT_EQUALS(string msg, uint8_t val_1, uint8_t val_2)
{
	this->print_message("ASSERT EQUALS: " + msg, val_1 == val_2);
}

/**
* ASSERT GREATER THAN EQUAL METHODS.
*/

void Test::ASSERT_GREATER_THAN_EQUAL(string msg, float val_1, float val_2)
{
	this->print_message("ASSERT GREATER THAN EQUAL: " + msg, val_1 >= val_2);
}

/**
* ASSERT LESS THAN EQUAL METHODS.
*/

void Test::ASSERT_LESS_THAN_EQUAL(string msg, float val_1, float val_2)
{
	this->print_message("ASSERT LESS THAN EQUAL: " + msg, val_1 <= val_2);
}

/**
* ASSERT NOT EQUAL METHODS.
*/

void Test::ASSERT_NOT_EQUAL(string msg, string val_1, string val_2)
{
	this->print_message("ASSERT NOT EQUAL: " + msg, val_1 != val_2);
}

void Test::ASSERT_NOT_EQUAL(string msg, int val_1, int val_2)
{
	this->print_message("ASSERT NOT EQUAL: " + msg, val_1 != val_2);
}

void Test::ASSERT_NOT_EQUAL(string msg, float val_1, float val_2)
{
	this->print_message("ASSERT NOT EQUAL: " + msg, val_1 != val_2);
}

void Test::ASSERT_NOT_EQUAL(string msg, double val_1, double val_2)
{
	this->print_message("ASSERT NOT EQUAL: " + msg, val_1 != val_2);
}

void Test::ASSERT_NOT_EQUAL(string msg, char val_1, char val_2)
{
	this->print_message("ASSERT NOT EQUAL: " + msg, val_1 != val_2);
}

void Test::ASSERT_NOT_EQUAL(string msg, uint8_t val_1, uint8_t val_2)
{
	this->print_message("ASSERT NOT EQUAL: " + msg, val_1 != val_2);
}

/**
* ASSERT TRUE METHODS.
*/

void Test::ASSERT_TRUE(string msg, bool val)
{
	this->print_message("ASSERT TRUE: " + msg, val);
}

/**
* ASSERT FALSE METHODS.
*/

void Test::ASSERT_FALSE(string msg, bool val)
{
	this->print_message("ASSERT FALSE: " + msg, !val);
}

/**
* PRINT METHODS.
*/

void Test::HEADER_PRINT(string msg)
{
	this->set_color(COLOR::CYAN);
	cout << endl << endl << msg << endl << endl;
}
