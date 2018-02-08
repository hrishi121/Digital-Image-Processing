//***********************************************************************
// EE569 Homework 1, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 1
// Submission Date: 4th February, 2016
//***********************************************************************

#include "imageProcesAlgo.h"

//************************************************************************************************

void imageProcesAlgo::RGB2Gray(unsigned char *imageData, int imageHeight,
							   int imageWidth) {

	imageBasicOps temp1;

	int Size = imageHeight * imageWidth;
	unsigned char *grayImage = new unsigned char [Size];

	//Lightness method
	for(int i = 0; i < (Size - 4); i++) {

		grayImage[i] = (max( max(imageData[3*i], imageData[3*i + 1] ), imageData[3*i + 2])
		              + min( min(imageData[3*i], imageData[3*i + 1] ), imageData[3*i + 2])) / 2;
	}

	temp1.saveImage(grayImage, "grayTiffany_lightnessMethod.raw",512,512,1);
	temp1.freeMemory(grayImage);

	//Average method
	unsigned char *grayImage2 = new unsigned char [Size];
	for(int i = 0; i < (Size - 4); i++) {

		grayImage2[i] = (imageData[3*i] + imageData[3*i + 1] + imageData[3*i + 2])/ 3;
	}
	temp1.saveImage(grayImage2, "grayTiffany_AverageMethod.raw",512,512,1);
	temp1.freeMemory(grayImage2);

	//Luminosity method
	unsigned char *grayImage3 = new unsigned char [Size];
	for(int i = 0; i < (Size - 4); i++) {

		grayImage3[i] = (0.21*int(imageData[3*i]) + 0.72*int(imageData[3*i + 1]) + 0.07*int(imageData[3*i + 2]));
	}
	temp1.saveImage(grayImage3, "grayTiffany_LuminosityMethod.raw",512,512,1);

	temp1.freeMemory(grayImage3);
	cout << "Gray Image created";

}




//************************************************************************************************




void imageProcesAlgo::RGB2CMYK(unsigned char *imageData, char imageName[],
			  int imageHeight, int imageWidth) {

	imageProcesAlgo temp1;

	int Size = imageHeight * imageWidth;
	unsigned char *cmykImage = new unsigned char [Size*3];

	//CMY-(K) color space representation
	for(int i = 0; i < (Size - 4); i++) {

		cmykImage[3*i] = 255 - imageData[3*i];
		cmykImage[3*i + 1] = 255 - imageData[3*i + 1];
		cmykImage[3*i + 2] = 255 - imageData[3*i + 2];
	}

	temp1.saveImage(cmykImage, imageName, imageHeight, imageWidth,3);
	temp1.separatePlanes(cmykImage, imageHeight, imageWidth);
	temp1.freeMemory(cmykImage);
	cout << "CMYK Image created";
}




//************************************************************************************************



void imageProcesAlgo::separatePlanes(unsigned char *imageData, int imageHeight, int imageWidth) {

	//Separating the 3 planes
	imageBasicOps temp1;
    int Size = imageHeight * imageWidth;

	unsigned char *plane1 = new unsigned char[Size];
	for (int i = 0; i < Size - 2; i++) {
		plane1[i] = imageData[3*i];
	}
	temp1.saveImage(plane1, "plane1.raw", imageHeight, imageWidth, 1);
	temp1.freeMemory(plane1);

	unsigned char *plane2 = new unsigned char[Size];
	for (int i = 0; i < Size - 2; i++) {
		plane2[i] = imageData[3*i + 1];
	}
	temp1.saveImage(plane2, "plane2.raw", imageHeight, imageWidth, 1);
	temp1.freeMemory(plane2);

	unsigned char *plane3 = new unsigned char[Size];
	for (int i = 0; i < Size - 2; i++) {
		plane3[i] = imageData[3*i + 2];
	}
	temp1.saveImage(plane3, "plane3.raw", imageHeight, imageWidth, 1);
	temp1.freeMemory(plane3);

	cout << "Planes separated" << endl;

}




//************************************************************************************************



vector< vector <unsigned char> > imageProcesAlgo::separatePlane(unsigned char *imageData, int imageHeight,
									 		   int imageWidth, int planeNum) {

	//Separating the plane
	imageProcesAlgo temp1;
    int Size = imageHeight * imageWidth;

	unsigned char *plane = new unsigned char[Size];
	for (int i = 0; i < Size - 2; i++) {
		plane[i] = imageData[3*i + planeNum -1];
	}

	vector < vector<unsigned char> > img;
	unsigned char temp;


	for(int i = 0; i < imageWidth; i++) {
		img.push_back(vector <unsigned char>());

   		for(int j = 0; j < imageHeight; j++) {

       		temp = plane[i*imageHeight + j];
           	img[i].push_back(temp);
   		}
	}
	return img;

}



//************************************************************************************************




void imageProcesAlgo::BilinInter(unsigned char *imgData, int imgHeight, int imgWidth,
								 int newImgHeight, int newImgWidth) {

	imageProcesAlgo temp1;

	int Size = imgHeight * imgWidth;
	unsigned char* newImg = new unsigned char[newImgWidth*newImgWidth*3];

	double ratioX = double(imgHeight) / newImgHeight;
	double ratioY = double(imgWidth) / newImgWidth;

	double newX, newY, deltaX, deltaY;

	int tempX, tempY;

	vector< vector <unsigned char> > plane1 = temp1.separatePlane(imgData, imgHeight, imgWidth, 1);
	vector< vector <unsigned char> > plane2 = temp1.separatePlane(imgData, imgHeight, imgWidth, 2);
	vector< vector <unsigned char> > plane3 = temp1.separatePlane(imgData, imgHeight, imgWidth, 3);

	for(int i = 0; i<newImgWidth-1; i++) {
		for(int j = 0; j<newImgHeight-1; j++) {
			newX = j * ratioX;
			newY = i * ratioY;

			tempX = floor(newX);
			tempY = floor(newY);

			deltaX = newX - tempX;
			deltaY = newY - tempY;

			newImg[i*newImgHeight*3 + j*3] = (1 - deltaX) * (1 - deltaY) * plane1[tempY][tempX]
										+ (deltaX) * (1 - deltaY) * plane1[tempY][tempX + 1]
										+ (1 - deltaX) * (deltaY) * plane1[tempY + 1][tempX]
										+ (deltaX) * (deltaY) * plane1[tempY + 1][tempX + 1];

			newImg[i*newImgHeight*3 + j*3 + 1] = (1 - deltaX) * (1 - deltaY) * plane2[tempY][tempX]
										+ (deltaX) * (1 - deltaY) * plane2[tempY][tempX + 1]
										+ (1 - deltaX) * (deltaY) * plane2[tempY + 1][tempX]
										+ (deltaX) * (deltaY) * plane2[tempY + 1][tempX + 1];

			newImg[i*newImgHeight*3 + j*3 + 2] = (1 - deltaX) * (1 - deltaY) * plane3[tempY][tempX]
										+ (deltaX) * (1 - deltaY) * plane3[tempY][tempX + 1]
										+ (1 - deltaX) * (deltaY) * plane3[tempY + 1][tempX]
										+ (deltaX) * (deltaY) * plane3[tempY + 1][tempX + 1];

		}
	}

	temp1.saveImage(newImg, "BilinInter_Airplane.raw", newImgHeight, newImgWidth, 3);
	temp1.freeMemory(newImg);

	cout << "bilinear Interpolation done!!" << endl;


}
