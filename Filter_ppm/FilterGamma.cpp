#include "FilterGamma.h"

FilterGamma::FilterGamma(float gamma) {
	this->gamma = gamma;
	buf = new Image();
}

FilterGamma::~FilterGamma() {
	delete buf;
}

FilterGamma::FilterGamma(const FilterGamma& src) {
	gamma = src.gamma;
	buf = new Image(*src.buf);
}

Image FilterGamma::operator<<(const Image& image) {
	delete buf;

	buf = new Image(image);

	int h = buf->getHeight();
	int w = buf->getWidth();
	math::Vec3<float> temp;

	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {

			temp = buf->getbuf(x, y);
			temp.r = pow(temp.r, gamma);
			temp.g = pow(temp.g, gamma);
			temp.b = pow(temp.b, gamma);

			temp = temp.clampToLowerBound(0);
			temp = temp.clampToUpperBound(1);

			buf->setbuf(x, y, temp);
		}
	}
	return *buf;
}