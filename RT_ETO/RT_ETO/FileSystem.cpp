#include "stdafx.h"
#include "FileSystem.h"

FileSystem* FileSystem::instance;

FileSystem::FileSystem()
{

}

FileSystem::~FileSystem()
{
	// TEST: For memory leaks.
	delete FileSystem::inst();
}

FileSystem* FileSystem::inst()
{
	if (FileSystem::instance == nullptr)
	{
		FileSystem::instance = new FileSystem();
	}
	return FileSystem::instance;
}


bool FileSystem::_save_jpeg(string filename, ImageBuffer image)
{
	// Add file extension
	string filename_format = filename + this->JPEG_EXT;

	// Create File descriptor instance.
	FILE* file_out;
	// open file source.
	file_out = fopen(filename_format.c_str(), "wb");

	// check if file instance successfully opened.
	if (!file_out) 
	{
		return false;
	}
	
	uint8_t* buffer = nullptr;
	try
	{
		// Grab image buffer.
		buffer = image.get_binary();

		// Write buffer.
		fwrite(buffer, 3, sizeof(buffer), file_out);

		// Close file instance.
		fclose(file_out);

		// Delete allocated buffer data.
		delete[] buffer;
	}
	catch (const std::exception& e)
	{
		// if error occurs, print stack, delete buffer, and return false.
		e.what();
		delete[] buffer;
		return false;
	}

	return true;
}

bool FileSystem::save_jpeg(string filename, ImageBuffer image)
{
	return FileSystem::inst()->_save_jpeg(filename, image);
}