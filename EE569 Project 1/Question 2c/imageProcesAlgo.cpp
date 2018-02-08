//***********************************************************************
// EE569 Homework 1, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 2c
// Submission Date: 4th February, 2016
//***********************************************************************

#include "imageProcesAlgo.h"


unsigned char *imageProcesAlgo::RGB2CMY(unsigned char *imageData) {

	int Size = imgHeight * imgWidth;
	unsigned char *cmyImage = new unsigned char [Size*3];

	//CMY-(K) color space representation
	for(int i = 0; i < (Size - 3); i++) {

		cmyImage[3*i] = 255 - imageData[3*i];
		cmyImage[3*i + 1] = 255 - imageData[3*i + 1];
		cmyImage[3*i + 2] = 255 - imageData[3*i + 2];
	}

	return cmyImage;

}



//************************************************************************************************************************




unsigned char *imageProcesAlgo::mirror(unsigned char *img) {

	unsigned char *mirrorImage = new unsigned char[imgWidth * imgHeight * 3];

	for(int i = 0; i<imgHeight; i++) {
		for(int j = 0; j<imgWidth; j++) {
			mirrorImage[i*imgWidth*3 + j*3] = img[i*imgWidth*3 - j*3 + (imgWidth - 1)*3];
			mirrorImage[i*imgWidth*3 + j*3 + 1] = img[i*imgWidth*3 + (imgWidth - 1)*3 - j*3 + 1];
			mirrorImage[i*imgWidth*3 + j*3 + 2] = img[i*imgWidth*3 + (imgWidth - 1)*3 - j*3 + 2];
		}
	}

	return mirrorImage;
}



//*******************************************************************************************


map<unsigned char,double> imageProcesAlgo::cumulativeHist(unsigned char *plane) {


    int h1 = this->imgHeight;
    int w1 = this->imgWidth;

	imageProcesAlgo temp1;
	temp1.setDimensions(w1, h1);

	map<unsigned char, double> temp, temp2;

	int Size = imgHeight * imgWidth;

	for(int j = 0; j<256; j++){
            unsigned char k = j;
			temp[k] = 0;
			temp2[k] = 0;
		}

	for(int i =0; i<Size; i++) {
		for(int j = 0; j<256; j++) {
            unsigned char k = j;
			if(plane[i] == k)
				temp[k] = temp[k] + 1;
		}
	}

	int sum = 0;
    for(int i = 0; i<256; i++){
        unsigned char k = i;
        sum = sum + temp[k];
      	temp2[k] = sum;
      }

    for(int i = 0; i<256; i++){
        unsigned char k = i;
        temp2[k] = temp2[k] / (imgHeight*imgWidth);
    }
     return temp2;

}


//*******************************************************************************************


unsigned char *imageProcesAlgo::histCopy(unsigned char *filmImg, unsigned char *origImg, int plane, int h1, int w1) {

	int h2 = this->imgHeight;
    int w2 = this->imgWidth;

	imageProcesAlgo temp1, temp2;
	temp1.setDimensions(w1, h1);
	temp2.setDimensions(w2, h2);

    unsigned char *origPlane = temp1.separatePlanes(origImg, plane);
	unsigned char *filmPlane = temp2.separatePlanes(filmImg, plane);


	map<unsigned char,double> origMap = temp1.cumulativeHist(origPlane);
	map<unsigned char,double> filmMap = temp2.cumulativeHist(filmPlane);

	unsigned char *newImg = new unsigned char[h1*w1];

	for(int i = 0; i<h1; i++){
		for(int j = 0; j<w1; j++){
			newImg[i*w1 + j] = origPlane[i*w1 + j];
		}
	}

	//temp1.saveImage(newImg, "test.raw", 1);
	double temp_arr[256];

	for(int i = 0; i<256; i++) {
		unsigned char k1 = i;
		for(int j = 0; j<256; j++){
			unsigned char k2 = j;
			temp_arr[j] = 0;
		}

		for(int j = 0; j<256; j++){
			unsigned char k2 = j;
			temp_arr[j] = fabs(origMap[k1] - filmMap[k2]);
		}

		int N= sizeof(temp_arr) / sizeof(double);
		int min = distance(temp_arr, min_element(temp_arr, temp_arr + N));

		for(int i = 0; i<h1; i++){
			for(int j = 0; j<w1; j++){
				if(origPlane[i*w1 + j] == k1)
					newImg[i*w1 + j] = min;
			}
		}
		//cout << int(min) << endl;
	}


	temp1.freeMemory(origPlane);
	temp2.freeMemory(filmPlane);
	return newImg;
}

//*******************************************************************************************


unsigned char *imageProcesAlgo::histMapping(unsigned char *filmImg, unsigned char *origImg, int h1, int w1) {

	int h2 = this->imgHeight;
    int w2 = this->imgWidth;

	imageProcesAlgo temp1, temp2;
	temp2.setDimensions(w2, h2);
	temp1.setDimensions(w1, h1);

	unsigned char *newImg = new unsigned char[h1*w1*3];

	unsigned char *newPlane1 = temp2.histCopy(filmImg, origImg, 1, h1, w1);
	unsigned char *newPlane2 = temp2.histCopy(filmImg, origImg, 2, h1, w1);
	unsigned char *newPlane3 = temp2.histCopy(filmImg, origImg, 3, h1, w1);

	for(int i = 0; i<h1; i++) {
		for(int j= 0; j<w1; j++) {
			newImg[i*w1*3 + j*3] = newPlane1[i*w1 + j];
			newImg[i*w1*3 + j*3 + 1] = newPlane2[i*w1 + j];
			newImg[i*w1*3 + j*3 + 2] = newPlane3[i*w1 + j];
		}
	}

	temp1.freeMemory(newPlane1);
	temp1.freeMemory(newPlane2);
	temp1.freeMemory(newPlane3);
	temp1.saveImage(newImg, "Film_unmirrored.raw", 3);
	return newImg;

}

//*******************************************************************************************
