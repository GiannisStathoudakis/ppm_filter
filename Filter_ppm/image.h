#pragma once
#ifndef _IMAGE
#define _IMAGE

#include "imageio.h"
#include "vec3.h"
#include "array2d.h"
#include "ppm.h"


class Image : public math::Array2D<math::Vec3<float>>, public image::ImageIO {

public:

	bool load(const std::string& filename, const std::string& format);

	bool save(const std::string& filename, const std::string& format);

	void setbuf(unsigned int x, unsigned int y, math::Vec3<float> value);

	math::Vec3<float> getbuf(unsigned int x, unsigned int y);
};
#endif