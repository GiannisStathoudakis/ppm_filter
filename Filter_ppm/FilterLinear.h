#pragma once

#ifndef _FILTERLINEAR
#define _FILTERLINEAR

#include "Filter.h"

class FilterLinear : public Filter {

public:
	math::Vec3<float> a;
	math::Vec3<float> c;
	Image* buf;

	FilterLinear(math::Vec3<float> a, math::Vec3<float> c);
	~FilterLinear();
	FilterLinear(const FilterLinear& src);
	Image operator<<(const Image& image) override;
};
#endif