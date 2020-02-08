// raytracingoneweekend.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main()
{
	const int width = 400;
	const int height = 300;
	const int CHANNEL_NUM = 3;
	uint8_t* pixels = new uint8_t[width * height * CHANNEL_NUM];

	
	int index = 0;
	for (int j = height - 1; j >= 0; --j)
	{
		for (size_t i = 0; i < width; ++i)
		{
			float r = float(i) / float (width);
			float g = float(j) / float (height);
			float b = 0.2f;
			char ir = char(255.99*r);
			char ig = char(255.99*g);
			char ib = char(255.99*b);
			pixels[index++] = ir;
			pixels[index++] = ig;
			pixels[index++] = ib;
		}
	}

	 stbi_write_png("stbpng.png", width, height, CHANNEL_NUM, pixels, width * CHANNEL_NUM);
	 delete[] pixels;

	 return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
