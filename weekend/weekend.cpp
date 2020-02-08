#include <iostream>
#include <fstream>
#include <sstream>

#include "vec3.h"

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
			vec3 col(float(i) / float (width), float(j) / float (height),0.2f);
			char ir = char(255.99*col[0]);
			char ig = char(255.99*col[1]);
			char ib = char(255.99*col[2]);
			pixels[index++] = ir;
			pixels[index++] = ig;
			pixels[index++] = ib;
		}
	}

	 stbi_write_png("stbpng.png", width, height, CHANNEL_NUM, pixels, width * CHANNEL_NUM);
	 delete[] pixels;

	 return 0;
}
