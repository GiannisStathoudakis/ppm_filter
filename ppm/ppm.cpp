#include "ppm.h"
#include <fstream>
#include <iostream>
#include <string>


float* image::ReadPPM(const char* filename, int* w, int* h) {

	std::ifstream file(filename, std::ios::binary);
	bool er = true;
	float* rgb = nullptr;

	if (!file.is_open()) {
		std::cout << "something went wrong with our file " << filename << " can't open." << std::endl;
		file.close();
		return rgb;
	}

	std::string line;
	file >> line;

	if (line[0] == 'P' && line[1] != '6') {
		std::cout << "Error, file's format isn't P6." << std::endl;
		er = false;
	}
	else {
		file >> line;
		*w = stoi(line);
		file >> line;
		*h = stoi(line);
		file >> line;
		if (stoi(line) > 255) {
			std::cout << "Error, pixel size too large." << std::endl;
			er = false;
		}
	}

	if (er) {
		int size = 3 * (*w) * (*h);
		rgb = new float[size];
		char* color = new char[size];
		file.read(color, size);
		for (int i = 0; i < size; i++) {
			rgb[i] = (unsigned char)color[i] / 255.f;
		}
		delete[] color;
		std::cout << "Image dimensions are: " << *w << " X " << *h << std::endl;
	}
	file.close();
	return rgb;
}

bool image::WritePPM(const float* data, int w, int h, const char* filename) {

	std::ofstream file(filename, std::ios::binary);

	if (!file.is_open() || data == nullptr) {
		std::cout << "something didn't go well, can't create file" << std::endl;
		return false;
	}
	else {

		file << "P6" << std::endl;
		file << w << std::endl;
		file << h << std::endl;
		file << 255 << std::endl;

		char rgb;
		for (int i = 0; i < 3 * w * h; i++) {
			rgb = 255 * data[i];
			file.write(&rgb, 1);
		}
	}
	file.close();
	return true;
}