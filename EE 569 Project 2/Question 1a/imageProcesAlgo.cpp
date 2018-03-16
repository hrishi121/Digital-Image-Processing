//***********************************************************************
// EE569 Homework 2, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 1a
// Submission Date: 4th March, 2018
//***********************************************************************

#include "imageProcesAlgo.h"

unsigned char imageProcesAlgo::BilinInter(unsigned char **plane, double x, double y) {
	// imgData : The original input image
	// x: x coordinate in new image, which is to be interpolated
	// y: y coordinate in new image, which is to be interpolated

	int h1 = this->imgHeight;
    int w1 = this->imgWidth;

	imageProcesAlgo temp1;
	temp1.setDimensions(w1, h1);

	unsigned char newPixelValue;

	int tempX = floor(x);
	int tempY = floor(y);

	if(x >= 511) {
        tempX = tempX - 1;
        tempY = tempY - 1;
	}
	double deltaX = x - tempX;
	double deltaY = y - tempY;

	newPixelValue = (1 - deltaX) * (1 - deltaY) * plane[tempX][tempY]
				  + (deltaX) * (1 - deltaY) * plane[tempX][tempY + 1]
				  + (1 - deltaX) * (deltaY) * plane[tempX + 1][tempY]
				  + (deltaX) * (deltaY) * plane[tempX + 1][tempY + 1];

	return newPixelValue;
}

//*****************************************************************************************************


unsigned char *imageProcesAlgo::Square2CircleWarp(unsigned char *imgData) {

	int h1 = this->imgHeight;
    int w1 = this->imgWidth;

	imageProcesAlgo temp1;
	temp1.setDimensions(w1, h1);
	unsigned char *newImg = new unsigned char[w1 * h1 * 3];

	for(int i = 0; i<w1*h1*3; i++)
		newImg[i] = 0;


    unsigned char **plane1 = temp1.separatePlane(imgData, 1);
    unsigned char **plane2 = temp1.separatePlane(imgData, 2);
    unsigned char **plane3 = temp1.separatePlane(imgData, 3);

	double u, v, x, y;
	for(int i = 0; i<imgWidth; i++) {
		for(int j = 0; j<imgHeight; j++) {

			u = (double(i)/256) - 1;
			v = (double(j)/256) - 1;

			if( sqrt(u*u + v*v) <= 1) {

				x = (0.5*(sqrt(2 + u*u - v*v + 2*sqrt(2)*u) - sqrt(2 + u*u - v*v - 2*sqrt(2)*u)) + 1)*256;
				y = (0.5*(sqrt(2 - u*u + v*v + 2*sqrt(2)*v) - sqrt(2 - u*u + v*v - 2*sqrt(2)*v)) + 1)*256;
				newImg[i*imgWidth*3 + j*3]     = temp1.BilinInter(plane1, x, y);
				newImg[i*imgWidth*3 + j*3 + 1] = temp1.BilinInter(plane2, x, y);
				newImg[i*imgWidth*3 + j*3 + 2] = temp1.BilinInter(plane3, x, y);
			}
		}
	}

	for(int i = 0; i< imgHeight; i++) {
        delete[] plane1[i];
        delete[] plane2[i];
        delete[] plane3[i];
    }
    delete[] plane1;
    delete[] plane2;
    delete[] plane3;

	return newImg;
}


//*****************************************************************************************************

unsigned char *imageProcesAlgo::Circle2SquareWarp(unsigned char *imgData) {
	int h1 = this->imgHeight;
    int w1 = this->imgWidth;

	imageProcesAlgo temp1;
	temp1.setDimensions(w1, h1);
	unsigned char *newImg = new unsigned char[w1 * h1 * 3];

	for(int i = 0; i<w1*h1*3; i++)
		newImg[i] = 0;


    unsigned char **plane1 = temp1.separatePlane(imgData, 1);
    unsigned char **plane2 = temp1.separatePlane(imgData, 2);
    unsigned char **plane3 = temp1.separatePlane(imgData, 3);

	double u, v, x, y;
	for(int i = 0; i<imgWidth; i++) {
		for(int j = 0; j<imgHeight; j++) {

			x = (double(i)/256) - 1;
			y = (double(j)/256) - 1;

			u = x*sqrt(1 - (0.5 * y * y));
			v = y*sqrt(1 - (0.5 * x * x));
			
			newImg[i*imgWidth*3 + j*3]     = temp1.BilinInter(plane1, (u+1)*256, (v+1)*256);
			newImg[i*imgWidth*3 + j*3 + 1] = temp1.BilinInter(plane2, (u+1)*256, (v+1)*256);
			newImg[i*imgWidth*3 + j*3 + 2] = temp1.BilinInter(plane3, (u+1)*256, (v+1)*256);

		}
	}

	for(int i = 0; i< imgHeight; i++) {
        delete[] plane1[i];
        delete[] plane2[i];
        delete[] plane3[i];
    }
    delete[] plane1;
    delete[] plane2;
    delete[] plane3;

	return newImg;
}

//*****************************************************************************************************
