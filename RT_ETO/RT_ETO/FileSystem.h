#pragma once
#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include <Windows.h>
#include <fstream>
#include <iostream>
#include <string>
#include "ImageBuffer.h"
#include "Color.h"

using namespace std;

class FileSystem
{
	private:

		/**
		* Singleton FileSystem isntance.
		*/
		static FileSystem* instance;

		/**
		* Constant value for jpeg file extension.
		*/
		const char* BMP_EXT = ".bmp";

	private:

		/**
		* FileSystem Constructor.
		*/
		FileSystem();

		/**
		* FileSystem Deconstructor.
		*/
		~FileSystem();

		/**
		* Grabs singleton instance of FileSystem.
		*/
		static FileSystem* inst();

		virtual bool _save_bmp(string filename, ImageBuffer image);

		virtual ImageBuffer _load_bump_map(string filename);

		virtual ImageBuffer _load_texture_map(string filename);

	public:
		
		/**
		* Singleton: saves image buffer as bmp file. 
		*/
		static bool save_bmp(string filename, ImageBuffer image);

		/**
		* Singleton: load bump map as image buffer.
		*/
		static ImageBuffer load_bump_map(string filename);

		/**
		* Singleton: load texture map as image buffer.
		*/
		static ImageBuffer load_texture_map(string filename);
};

#endif