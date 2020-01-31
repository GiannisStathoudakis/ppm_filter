#pragma once
#ifndef _FILTERGAMMA
#define _FILTERGAMMA

#include "Filter.h"

class FilterGamma : public Filter {
protected:
	float gamma;
	Image* buf;

public:
	FilterGamma(float gamma);
	~FilterGamma();
	FilterGamma(const FilterGamma& src);
	Image operator<<(const Image& image) override;
};
#endif