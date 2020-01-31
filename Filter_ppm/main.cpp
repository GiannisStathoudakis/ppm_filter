//Giannis Stathoudakis
#include "FilterGamma.h"
#include "FilterLinear.h"
#include <iostream>
#include <sstream>

int main() {

	std::string file_name;

	std::cout << "insert ";
	std::getline(std::cin, file_name);

	std::cout << std::endl;

	std::stringstream ss(file_name);
	std::string tmp;
	std::vector<std::string> input_ar;

	while (getline(ss, tmp, ' ')) {
		input_ar.push_back(tmp);
	}

	if (input_ar[0] != "filter") {
		std::cout << "invalid input";
		system("pause");
		return 0;
	}

	file_name = input_ar.back();

	size_t found = file_name.find_last_of("\\");

	std::string path = file_name.substr(0, found + 1);

	file_name = file_name.substr(found + 1, file_name.length() - 1);

	std::string output_file = path + "filtered_" + file_name;

	Image image;

	file_name = path + file_name;

	if (!(image.load(file_name, ".ppm"))) {
		std::cout << "File can't be loaded." << std::endl;
		system("pause");
		return 0;
	}
	else {
		int i = 0;
		while (1) {
			if (input_ar[++i] == "-f") {
				i++;

				if (input_ar[i] == "linear") {

					math::Vec3<float> a = math::Vec3<float>(stof(input_ar[++i]), stof(input_ar[++i]), stof(input_ar[++i]));

					math::Vec3<float> c = math::Vec3<float>(stof(input_ar[++i]), stof(input_ar[++i]), stof(input_ar[++i]));

					FilterLinear* f = new FilterLinear(a, c);

					image = *f << image;
				}
				else if (input_ar[i] == "gamma") {
					float gamma = stof(input_ar[++i]);

					if (gamma > 2.0 || gamma < 0.5) {
						std::cout << "no valid gamma" << std::endl;
						system("pause");
						return 0;
					}
					FilterGamma* f = new FilterGamma(gamma);
					image = *f << image;
				}
			}
			else {
				break;
			}
		}
		if (image.save(output_file, ".ppm")) {
			std::cout << "Image saved successfully." << std::endl;
			system("pause");
			return 0;
		}
		else {
			std::cout << "something gone wrong" << std::endl;
			system("pause");
			return 0;
		}
	}
}