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


bool FileSystem::_save_bmp(string filename, ImageBuffer image)
{	
	// Add file extension
	string filename_format = filename + this->BMP_EXT;

	// Create File descriptor instance.
	FILE* file_out;

	// open file source.
	file_out = fopen(filename_format.c_str(), "wb");

	// check if file instance successfully opened.
	if (!file_out) 
	{
		return false;
	}
	
	// initialize buffer.
	uint8_t* buffer = nullptr;

	try
	{
		// Grab image buffer.
		buffer = image.get_binary();

		BITMAPINFOHEADER BMIH;
		BMIH.biSize = sizeof(BITMAPINFOHEADER);
		BMIH.biSizeImage = image.get_size();

		// Create the bitmap for this OpenGL context
		BMIH.biSize = sizeof(BITMAPINFOHEADER);
		BMIH.biWidth = image.get_x_dim();
		BMIH.biHeight = image.get_y_dim();
		BMIH.biPlanes = 1;
		BMIH.biBitCount = 24;
		BMIH.biCompression = BI_RGB;
		BMIH.biSizeImage = image.get_size();

		BITMAPFILEHEADER bmfh;
		int nBitsOffset = sizeof(BITMAPFILEHEADER) + BMIH.biSize;
		LONG lImageSize = BMIH.biSizeImage;
		LONG lFileSize = nBitsOffset + lImageSize;
		bmfh.bfType = 'B' + ('M' << 8);
		bmfh.bfOffBits = nBitsOffset;
		bmfh.bfSize = lFileSize;
		bmfh.bfReserved1 = bmfh.bfReserved2 = 0;

		//Write the bitmap file header.
		UINT nWrittenFileHeaderSize = fwrite(&bmfh, 1, sizeof(BITMAPFILEHEADER), file_out);

		//And then the bitmap info header.
		UINT nWrittenInfoHeaderSize = fwrite(&BMIH, 1, sizeof(BITMAPINFOHEADER), file_out);

		//Finally, write the image data itself.
		UINT nWrittenDIBDataSize = fwrite(buffer, 1, lImageSize, file_out);

		// Close file.
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

bool FileSystem::save_bmp(string filename, ImageBuffer image)
{
	return FileSystem::inst()->_save_bmp(filename, image);
}