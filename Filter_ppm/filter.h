#pragma once
#ifndef _FILTER
#define _FILTER

#include "image.h"

using namespace image;

class Filter {

public:
	virtual Image operator << (const Image& image) = 0;
};
#endif