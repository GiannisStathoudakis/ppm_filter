#include "image.h"
#include <iostream>

bool Image::load(const std::string& filename, const std::string& format) {

	if (tolower(filename[filename.length() - 1]) == format[3] && tolower(filename[filename.length() - 2]) == format[2] && tolower(filename[filename.length() - 3]) == format[1] && tolower(filename[filename.length() - 4]) == format[0]) {

		width, height = 0;
		float* components = image::ReadPPM(filename.c_str(), (int*)&width, (int*)&height);

		buffer.clear();

		if (components == nullptr) {
			return false;
		}

		for (unsigned int i = 1; i < 3 * width * height; i += 3) {
			math::Vec3<float> color(components[i], components[i + 1], components[i + 2]);
			buffer.push_back(color);
		}
		return true;
	}
	return false;
}

bool Image::save(const std::string& filename, const std::string& format) {

	if (width == 0 || height == 0 || buffer.empty()) {
		return false;
	}

	if (tolower(filename[filename.length() - 1]) == format[3] && tolower(filename[filename.length() - 2]) == format[2] && tolower(filename[filename.length() - 3]) == format[1] && tolower(filename[filename.length() - 4]) == format[0]) {

		int size = 3 * width * height;
		float* saveimage = new float[size];
		int j = 0;

		for (int i = 0; i < size; i += 3) {

			math::Vec3<float> color = buffer[j];

			saveimage[i] = color.r;
			saveimage[i + 1] = color.g;
			saveimage[i + 2] = color.b;

			j++;
		}
		return  image::WritePPM(saveimage, width, height, filename.c_str());
	}
	return false;
}

void Image::setbuf(unsigned int x, unsigned int y, math::Vec3<float> value) {
	buffer[y * width + x] = value;
}

math::Vec3<float> Image::getbuf(unsigned int x, unsigned int y) {
	return buffer[y * width + x];
}