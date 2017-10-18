#ifndef TEST_H
#define TEST_H

#include "ITest.h"

#pragma once

using namespace std;

class Test : public ITest
{
	public:

		enum COLOR
		{
			BLUE = 1,
			GREEN = 2,
			CYAN = 3,
			RED = 4,
			PURPLE = 5,
			YELLOW_DARK = 6,
			DEFAULT_WHITE = 7,
			GRAY = 8,
			BRIGHT_BLUE = 9,
			BRIGHT_GREEN = 10,
			BRIGHT_CYAN = 11,
			BRIGHT_RED = 12,
			PINK = 13,
			YELLOW = 14,
			BRIGHT_WHITE = 15
		};

		Test();

		~Test();

		virtual void print_header() = 0;

		virtual bool do_test() = 0;

	private:

		virtual void set_color(COLOR color);

		virtual void print_message(string msg, bool is_pass);

	protected:

		/**
		* ASSERT EQUAL METHODS.
		*/
		virtual void ASSERT_EQUALS(string msg, string val_1, string val_2);

		virtual void ASSERT_EQUALS(string msg, int val_1, int val_2);

		virtual void ASSERT_EQUALS(string msg, float val_1, float val_2);

		virtual void ASSERT_EQUALS(string msg, double val_1, double val_2);

		virtual void ASSERT_EQUALS(string msg, char val_1, char val_2);

		virtual void ASSERT_EQUALS(string msg, uint8_t val_1, uint8_t val_2);

		/**
		* ASSERT GREATER THAN EQUAL METHODS.
		*/

		virtual void ASSERT_GREATER_THAN_EQUAL(string msg, float val_1, float val_2);

		/**
		* ASSERT LESS THAN EQUAL METHODS.
		*/

		virtual void ASSERT_LESS_THAN_EQUAL(string msg, float val_1, float val_2);

		/**
		* ASSERT NOT EQUAL METHODS.
		*/

		virtual void ASSERT_NOT_EQUAL(string msg, string val_1, string val_2);

		virtual void ASSERT_NOT_EQUAL(string msg, int val_1, int val_2);

		virtual void ASSERT_NOT_EQUAL(string msg, float val_1, float val_2);

		virtual void ASSERT_NOT_EQUAL(string msg, double val_1, double val_2);

		virtual void ASSERT_NOT_EQUAL(string msg, char val_1, char val_2);

		virtual void ASSERT_NOT_EQUAL(string msg, uint8_t val_1, uint8_t val_2);

		/**
		* ASSERT TRUE METHODS.
		*/
		
		virtual void ASSERT_TRUE(string msg, bool val);

		/**
		* ASSERT FALSE METHODS.
		*/

		virtual void ASSERT_FALSE(string msg, bool val);

		/**
		* PRINT METHODS.
		*/

		virtual void HEADER_PRINT(string msg);

	protected:

		HANDLE chandle;
};

#endif