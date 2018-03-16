//***********************************************************************
// EE569 Homework 2, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 1b
// Submission Date: 4th March, 2018
//***********************************************************************

#include "imageProcesAlgo.h"

unsigned char *imageProcesAlgo::BilinInter(unsigned char ***plane, double x, double y) {
	// imgData : The original input image
	// x: x coordinate in new image, which is to be interpolated
	// y: y coordinate in new image, which is to be interpolated

	unsigned char *newPixelValue = new unsigned char[3];

	int tempY = floor(x);
	int tempX = floor(y);

	/*if(x >= 511) {
        tempX = tempX - 1;
        tempY = tempY - 1;
	}*/
	double deltaX = x - tempY;
	double deltaY = y - tempX;

	for(int i = 0; i<3; i++){

	newPixelValue[i] = (1 - deltaX) * (1 - deltaY) * plane[tempX][tempY][i]
				  + (deltaX) * (1 - deltaY) * plane[tempX][tempY + 1][i]
				  + (1 - deltaX) * (deltaY) * plane[tempX + 1][tempY][i]
				  + (deltaX) * (deltaY) * plane[tempX + 1][tempY + 1][i];
				  //cout << i;

	}

	return newPixelValue;
}



//*****************************************************************************************************



double *imageProcesAlgo::HmatrixMultiply1(double r, double c) {

	double invHmatrix[3][3] = { {5.93574612e-01,  -1.18161093e-01,   1.13810691e+02},
								{-1.46431303e-02,   4.39553548e-01,  -1.73736135e+02},
								{-2.65245643e-05,  -4.22235087e-04,   1.00000000e+00} };


	double *newCoords = new double[2];

	double w     = r*invHmatrix[2][0] + c*invHmatrix[2][1] + invHmatrix[2][2];
	newCoords[0] = (r*invHmatrix[0][0] + c*invHmatrix[0][1] + invHmatrix[0][2]) / w ; // rows
	newCoords[1] = (r*invHmatrix[1][0] + c*invHmatrix[1][1] + invHmatrix[1][2]) / w ; // columns

	/*double w     = c*invHmatrix[2][0] + r*invHmatrix[2][1] + invHmatrix[2][2];
	newCoords[1] = (c*invHmatrix[0][0] + r*invHmatrix[0][1] + invHmatrix[0][2]) / w ; // rows
	newCoords[0] = (c*invHmatrix[1][0] + r*invHmatrix[1][1] + invHmatrix[1][2]) / w ; // columns*/

	return newCoords;
}


//*****************************************************************************************************



double *imageProcesAlgo::HmatrixMultiply2(double r, double c) {

	double invHmatrix[3][3] = { {2.72080308e+01,   7.84501789e+00,  -9.03502312e+03},
								{2.47651339e-02,   3.05513203e+01,  -3.08702441e+04},
								{-1.01013995e-03,   2.32888902e-02,   1.00000000e+00} };



	double *newCoords = new double[2];

	double w     = r*invHmatrix[2][0] + c*invHmatrix[2][1] + invHmatrix[2][2];
	newCoords[0] = (r*invHmatrix[0][0] + c*invHmatrix[0][1] + invHmatrix[0][2]) / w ; // rows
	newCoords[1] = (r*invHmatrix[1][0] + c*invHmatrix[1][1] + invHmatrix[1][2]) / w ; // columns

	return newCoords;
}


//*****************************************************************************************************



double *imageProcesAlgo::HmatrixMultiply3(double r, double c) {

	double invHmatrix[3][3] = { {7.43203726e-01,   2.19345675e-02,   4.27355074e+01},
  								{-3.41738900e-02,   8.81984449e-01,  -4.27152335e+02},
                                {-3.65773069e-04,   5.01592257e-05,   1} };



	double *newCoords = new double[2];

	double w     = r*invHmatrix[2][0] + c*invHmatrix[2][1] + invHmatrix[2][2];
	newCoords[0] = (r*invHmatrix[0][0] + c*invHmatrix[0][1] + invHmatrix[0][2]) / w ; // rows
	newCoords[1] = (r*invHmatrix[1][0] + c*invHmatrix[1][1] + invHmatrix[1][2]) / w ; // columns

	return newCoords;
}



//*****************************************************************************************************


void imageProcesAlgo::Stitch(unsigned char *leftImg, unsigned char *middleImg, unsigned char *rightImg, char name[]) {

	int h1 = this->imgHeight;
    int w1 = this->imgWidth;

	imageProcesAlgo temp1, temp2;
	int w2 = 5*w1;
	int h2 = 2*h1;

	temp2.setDimensions(w2, h2);
	temp1.setDimensions(w1, h1);

	cout << "w1: " << w1 << " w2: " << w2 << " h1: " << h1 << " h2: " << h2 << endl;

	unsigned char *finalImg = new unsigned char[w2*h2*3];

	cout << "flag 1" << endl;

	unsigned char ***leftImg2   = temp1.image3D(leftImg);
	unsigned char ***rightImg2  = temp1.image3D(rightImg);
	unsigned char ***middleImg2  = temp1.image3D(middleImg);

    for(int i = 0; i<w2*h2*3; i++)
		finalImg[i] = 0;



	double *newCoords;
	unsigned char *newPixelValue;

    for(int i = 0; i<h2; i++) {
		for(int j = 0; j<w2; j++) {
			newCoords = temp2.HmatrixMultiply1(i, j);

			if(newCoords[0]>=1 && newCoords[1]>=1 && newCoords[0]<=(h1 - 2) && newCoords[1]<=(w1 - 2)) {

				//cout << "i: " << i << " j: " << j << endl;
				newPixelValue = temp2.BilinInter(leftImg2, newCoords[1], newCoords[0]);
				finalImg[(i + 300)*w2*3 + (j)*3] = newPixelValue[0];
				finalImg[(i + 300)*w2*3 + (j)*3 + 1] = newPixelValue[1];
				finalImg[(i + 300)*w2*3 + (j)*3 + 2] = newPixelValue[2];

				delete[] newPixelValue;
			}
		}
	}

	for(int i = 0; i<h2; i++) {
		for(int j = 0; j<w2; j++) {
			newCoords = temp2.HmatrixMultiply2(i, j);

			if(newCoords[0]>=1 && newCoords[1]>=1 && newCoords[0]<=(h1 - 2) && newCoords[1]<=(w1 - 2)) {

				newPixelValue = temp2.BilinInter(rightImg2, newCoords[1], newCoords[0]);
				finalImg[(i + 300)*w2*3 + j*3] = newPixelValue[0];
				finalImg[(i + 300)*w2*3 + j*3 + 1] = newPixelValue[1];
				finalImg[(i + 300)*w2*3 + j*3 + 2] = newPixelValue[2];

				delete[] newPixelValue;
			}
		}
	}

	for(int i = 0; i<h1; i++){
        for(int j = 0; j<w1; j++){
            finalImg[(i + 300)*w2*3 + (j+800)*3]     = middleImg[(i)*imgWidth*3 + j*3];
            finalImg[(i + 300)*w2*3 + (j+800)*3 + 1] = middleImg[(i)*imgWidth*3 + j*3 + 1];
            finalImg[(i + 300)*w2*3 + (j+800)*3 + 2] = middleImg[(i)*imgWidth*3 + j*3 + 2];
        }
	}



	/*for(int i = 0; i<h2; i++) {
		for(int j = 0; j<w2; j++) {
			newCoords = temp2.HmatrixMultiply3(i, j);

			if(newCoords[0]>=1 && newCoords[1]>=1 && newCoords[0]<=(h1 - 2) && newCoords[1]<=(w1 - 2)) {

				//cout << "i: " << i << " j: " << j << endl;
				newPixelValue = temp2.BilinInter(middleImg2, newCoords[1], newCoords[0]);
				finalImg[(i)*w2*3 + (j)*3] = newPixelValue[0];
				finalImg[(i)*w2*3 + (j)*3 + 1] = newPixelValue[1];
				finalImg[(i)*w2*3 + (j)*3 + 2] = newPixelValue[2];

				delete[] newPixelValue;
			}
		}
	}*/






	cout << "Flag 5" << endl;

	delete[] newCoords;

	temp1.freeMemory3D(leftImg2);
	temp1.freeMemory3D(rightImg2);
	temp1.freeMemory3D(middleImg2);
	temp2.saveImage(finalImg, name, 3);
	temp2.freeMemory(finalImg);


}


//*****************************************************************************************************
