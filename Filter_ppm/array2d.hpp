#pragma once
#include "array2d.h"

namespace math {

	template<typename T>
	const unsigned int Array2D<T>::getWidth() const {
		return width;
	}

	template<typename T>
	const unsigned int Array2D<T>::getHeight() const {
		return height;
	}

	template<typename T>
	T* Array2D<T>::getRawDataPtr() {
		return &buffer;
	}

	template<typename T>
	void Array2D<T>::setData(const T* const& data_ptr) {

		if (width * height > 0 && data_ptr != nullptr) {
			buffer = data_ptr;
		}
	}

	template<typename T>
	T& Array2D<T>::operator()(unsigned int x, unsigned int y) {
		return buffer[y * width + x];
	}

	template<typename T>
	Array2D<T>::Array2D(unsigned int width, unsigned int height, const T* data_ptr) {
		this->width = width;
		this->height = height;

		for (int i = 0; i < width * height; i++) {
			buffer.push_back(*data_ptr);
		}
	}

	//Copy constructor
	template<typename T>
	Array2D<T>::Array2D(const Array2D& src) {
		width = src.width;
		height = src.height;
		buffer = src.buffer;
	}

	//destructor
	template<typename T>
	Array2D<T>::~Array2D() {
		buffer.clear();
	}

	//Copy assignment operator
	template<typename T>
	Array2D<T>& Array2D<T>::operator=(const Array2D& right) {
		width = right.width;
		height = right.height;
		buffer = right.buffer;

		return *this;
	}
}