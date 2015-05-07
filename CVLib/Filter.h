#pragma once
#include "opencv2/opencv.hpp"

using namespace cv;

class Filter
{
public:
	Filter();
	~Filter();

	static const Mat AbsDiffImage(const Mat image1, const Mat image2, const double mult = 1.0f);
	static const Mat AddImage(const Mat image1, const Mat image2, const double mult = 1.0f, const double add = 0);
	static const Mat AddImageWeighted(const Mat image1, const Mat image2, const double i1Weight = 0.5f, const double i2Weight = 0.5f, const double add = 0);
};

