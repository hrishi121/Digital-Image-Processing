//***********************************************************************
// EE569 Homework 2, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 3d
// Submission Date: 4th March, 2018
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



unsigned char **imageBasicOps::separatePlane(unsigned char *imgData, int planeNum) {

	//Separating the plane
	
    unsigned char **plane = new unsigned char *[imgHeight];
	for(int i = 0; i<imgHeight; i++)
		plane[i] = new unsigned char [imgWidth];

	if(planeNum != 0) {
		for (int i = 0; i < imgHeight; i++) {
			for (int j =0; j < imgWidth; j++) {
				plane[i][j] = imgData[i*imgWidth*3 + j*3 + planeNum - 1];
			}
		}
	}

	else {
		for (int i = 0; i < imgHeight; i++) {
			for (int j =0; j < imgWidth; j++) {
				plane[i][j] = imgData[i*imgWidth + j];
			}
		}
	}

	return plane;

}

//***************************************************************************************


unsigned char *imageBasicOps::separatePlane(unsigned char *imgData, int planeNum, int dummy) {

	//Separating the plane
    int Size = imgHeight * imgWidth;

	unsigned char *plane = new unsigned char[Size];
	for (int i = 0; i < imgHeight; i++) {
		for(int j =0; j< imgWidth; j++){
			plane[i*imgWidth + j] = imgData[3*i + planeNum -1];
		}
	}

	//cout << " Plane created " << endl;
	return plane;

}


//***************************************************************************************
