#include "FilterLinear.h"

FilterLinear::FilterLinear(math::Vec3<float> a, math::Vec3<float> c) {
	this->a = a;
	this->c = c;
	buf = new Image();
}

FilterLinear::~FilterLinear() {
	delete buf;
}

FilterLinear::FilterLinear(const FilterLinear& src) {
	a = src.a;
	c = src.c;
	buf = new Image(*src.buf);
}

Image FilterLinear::operator<<(const Image& image) {
	delete buf;
	buf = new Image(image);

	int h = buf->getHeight();
	int w = buf->getWidth();
	math::Vec3<float> temp;

	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {

			temp = buf->getbuf(x, y);
			temp = a * temp + c;
			temp = temp.clampToLowerBound(0);
			temp = temp.clampToUpperBound(1);

			buf->setbuf(x, y, temp);
		}
	}
	return *buf;
}