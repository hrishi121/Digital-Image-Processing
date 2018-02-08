//***********************************************************************
// EE569 Homework 1, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 2c
//***********************************************************************

#include "imageBasicOps.h"


void imageBasicOps::setDimensions(int newImgWidth,int newImgHeight) {

	imgWidth = newImgWidth;
	imgHeight = newImgHeight;
}

//***************************************************************************************

unsigned char *imageBasicOps::separatePlanes(unsigned char *imageData, int planeNum) {

	//Separating the plane
    int Size = imgHeight * imgWidth;

	unsigned char *plane = new unsigned char[Size];
	for (int i = 0; i < Size - 2; i++) {
		plane[i] = imageData[3*i + planeNum -1];
	}

	//cout << " Plane created " << endl;
	return plane;

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


