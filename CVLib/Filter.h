#pragma once
#include "opencv2/opencv.hpp"
#include <string>

using namespace cv;

class Filter
{
public:
	Filter();
	~Filter();

	static const Mat AbsDiffImage(const Mat* image1, const Mat* image2, const double mult = 1.0);
	static const Mat AddImage(const Mat* image1, const Mat* image2, const double mult = 1.0, const double add = 0.0);
	static const Mat AddImageWeighted(const Mat* image1, const Mat* image2, const double i1Weight = 0.5, const double i2Weight = 0.5, const double add = 0.0);
	static const Mat InvertImage(const Mat* image);
	static inline const Mat ScaleImage(const Mat* image, const double mult, const double add = 0.0);
	static const Mat SubImage(const Mat* image1, const Mat* image2, const double mult = 1.0, const double add = 0.0);

	static const Mat RGBToGray(const Mat* image);
	static const Mat DerivateImage(const Mat* image, std::string mode, const int degree);

};

