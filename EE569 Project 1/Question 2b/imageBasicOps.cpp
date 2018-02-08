//***********************************************************************
// EE569 Homework 1, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 2b
// Submission Date: 4th February, 2016
//***********************************************************************


#include "imageBasicOps.h"

void imageBasicOps::setDimensions(int newImgWidth,int newImgHeight) {

	imgWidth = newImgWidth;
	imgHeight = newImgHeight;
}


//***************************************************************************************

unsigned char *imageBasicOps::readImage(char imageName[], int bytesPerPixel) {

	FILE *file;

	int Size = imgWidth * imgHeight;
	unsigned char *imageData = new unsigned char [Size*bytesPerPixel];

	// Read image (filename specified by first argument) into image data matrix
	if (!(file=fopen(imageName,"r+b"))) {
		cout << "Cannot open file: " << imageName << endl;
		exit(1);
	}

	fread(imageData, sizeof(unsigned char), Size*bytesPerPixel, file);
	fclose(file);
	return imageData;
}

//***************************************************************************************

void imageBasicOps::saveImage(unsigned char *imageData, char imageName[], int bytesPerPixel) {

	FILE *otherFile;
	int Size = imgWidth * imgHeight;

	if (!(otherFile=fopen(imageName,"wb"))) {
		cout << "Cannot open file: " << imageName << endl;
		exit(1);
	}

	fwrite(imageData, sizeof(unsigned char), Size*bytesPerPixel, otherFile);
	fclose(otherFile);
}

//***********************************************************************************


