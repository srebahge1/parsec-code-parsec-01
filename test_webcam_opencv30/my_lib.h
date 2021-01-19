#ifndef MY_LIB_H
#define MY_LIB_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include "opencv2/opencv.hpp"
#include <cuda_runtime.h>
using namespace cv;
Mat contours(Mat frame);
Mat seuillage(Mat frame);
Mat bnw(Mat frame);
Mat mirroir(Mat frame);
#endif
