#pragma once
#include "opencv2/opencv.hpp"

using namespace cv;

class Morph
{

public:
	Mat OutImage;

	Morph();
	~Morph();

	static const Mat OpeningCircle(const Mat* image, const int i, const int j);
	static const Mat ClosingCircle(const Mat* image, const int i, const int j);
};

