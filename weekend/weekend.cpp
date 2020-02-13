#include <iostream>
#include <fstream>
#include <sstream>

#include "vec3.h"
#include "ray.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

bool hit_sphere(const vec3& center, float radius, const ray& r) {
	vec3 oc = r.origin() - center;
	float a = dot(r.direction(), r.direction());
	float b = 2.0 * dot(oc, r.direction());
	float c = dot(oc,oc) - radius*radius;
	float discriminant = b*b - 4*a*c;
	return discriminant > 0;
}

vec3 color(const ray &r){
	if(hit_sphere(vec3(0,0,-1), 0.5f, r)){
		return vec3(1,0,0);
	}
	vec3 unit_direction = unit_vector(r.direction());
	float t = 0.5f * (unit_direction.y()+1.0f);
	return (1.0f - t) * vec3(1.0f, 1.0f, 1.0) + t * vec3(0.5f,0.7f,1.0f);
}

int main()
{
	const int width = 200;
	const int height = 100;
	const int CHANNEL_NUM = 3;
	uint8_t* pixels = new uint8_t[width * height * CHANNEL_NUM];

	vec3 lower_left_corner(-2.0, -1.0, -1.0);
	vec3 horizontal(4.0,0.0,0.0);
	vec3 vertical(0.0,2.0,0.0);
	vec3 origin;

	int index = 0;
	for (int j = height - 1; j >= 0; --j)
	{
		for (size_t i = 0; i < width; ++i)
		{
			float u = float(i) / float (width);
			float v = float(j) / float (height);
			ray r (origin, lower_left_corner + u*horizontal + v*vertical);
			vec3 col = color(r);

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
