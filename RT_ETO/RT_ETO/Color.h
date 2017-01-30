#ifndef COLOR_H
#define COLOR_H

#pragma once

using namespace std;

class Color
{
	public:
		/**
		* R value.
		*/
		float r;

		/**
		* G value.
		*/
		float g;

		/**
		* B value.
		*/
		float b;

	public:
		/**
		* Color Constructor.
		*/
		Color(float _r, float _g, float _b);

		/**
		* Color Constructor.
		*/
		Color();

		/**
		* Color Deconstructor.
		*/
		~Color();

		/**
		* Add color operator with Color
		*/
		virtual Color operator +(const Color& obj);

		/**
		* Subtract color operator with Color
		*/
		virtual Color operator -(const Color& obj);

		/**
		* Multiply color operator with Color
		*/
		virtual Color operator *(const Color& obj);

		/**
		* Divide color operator with Color
		*/
		virtual Color operator /(const Color& obj);

		/**
		* Add self color operator with Color
		*/
		virtual void operator +=(const Color& obj);

		/**
		* Subtract self color operator with Color
		*/
		virtual void operator -=(const Color& obj);

		/**
		* Multiply self color operator with Color
		*/
		virtual void operator *=(const Color& obj);

		/**
		* Divide self color operator with Color
		*/
		virtual void operator /=(const Color& obj);


		

		/**
		* Add color operator with float
		*/
		virtual Color operator +(const float& obj);

		/**
		* Subtract color operator with float
		*/
		virtual Color operator -(const float& obj);

		/**
		* Multiply color operator with float
		*/
		virtual Color operator *(const float& obj);

		/**
		* Divide color operator with float
		*/
		virtual Color operator /(const float& obj);

		/**
		* Add self color operator with float
		*/
		virtual void operator +=(const float& obj);

		/**
		* Subtract self color operator with float
		*/
		virtual void operator -=(const float& obj);

		/**
		* Multiply self color operator with float
		*/
		virtual void operator *=(const float& obj);

		/**
		* Divide self color operator with float
		*/
		virtual void operator /=(const float& obj);

};

#endif