//***********************************************************************
// EE569 Homework 2, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 2a
// Submission Date: 4th March , 2018
//***********************************************************************

#include "imageProcesAlgo.h"

void imageProcesAlgo::FixedThreshold(unsigned char *imgData, unsigned char threshold, char name[]) {

	int h1 = this->imgHeight;
    int w1 = this->imgWidth;

	imageProcesAlgo temp1;
	temp1.setDimensions(w1, h1);

	int Size = imgWidth*imgHeight;
	unsigned char *newImg = new unsigned char[Size];

	for(int i = 0; i<Size; i++) {
		if(imgData[i] >= threshold)
			newImg[i] = 255;
		else
			newImg[i] = 0;
	}

	temp1.saveImage(newImg, name, 1);
	temp1.freeMemory(newImg);

}


//*****************************************************************************************************


void imageProcesAlgo::RandomThreshold(unsigned char *imgData, char name[]) {

	int h1 = this->imgHeight;
    int w1 = this->imgWidth;

	imageProcesAlgo temp1;
	temp1.setDimensions(w1, h1);

	int Size = imgWidth*imgHeight;
	unsigned char *newImg = new unsigned char[Size];

	for(int i = 0; i<Size; i++) {
		unsigned char randomThreshold = rand() % 256;
		if(imgData[i] >= randomThreshold)
			newImg[i] = 0;
		else
			newImg[i] = 255;
	}

	temp1.saveImage(newImg, name, 1);
	temp1.freeMemory(newImg);

}

//*****************************************************************************************************


void imageProcesAlgo::OrderedDither(unsigned char*imgData, char name[], int order) {

	int h1 = this->imgHeight;
    int w1 = this->imgWidth;

	imageProcesAlgo temp1;
	temp1.setDimensions(w1, h1);

	int Size = imgWidth*imgHeight;
	unsigned char *newImg = new unsigned char[Size];

	int **matrix = temp1.BayerIndexMatrix(order);
    cout << "\n";
	for(int i = 0; i<order; i++){
		for(int j = 0; j<order; j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
    cout << "Flag 2" << endl;
	unsigned char T[order][order];

	for(int i = 0; i<order; i++) {
		for(int j = 0; j<order; j++) {
			T[i][j] = floor(double((255*(matrix[i][j] + 0.5))/(order*order)));
			cout << int(T[i][j]) << " ";
		}
		cout << endl;
	}

	cout << "Flag 3" << endl;


	for(int i = 0; i<imgHeight; i++) {
		for(int j = 0; j<imgWidth; j++) {
			if(imgData[i*imgWidth + j] > T[i%order][j%order])
				newImg[i*imgWidth + j] = 255;
			else
				newImg[i*imgWidth + j] = 0;
		}
	}


	for (int i = 0; i<order; i++)
		delete[] matrix[i];
	delete matrix;

	temp1.saveImage(newImg, name, 1);
	temp1.freeMemory(newImg);
}



//*****************************************************************************************************

void imageProcesAlgo::FourLevelOrderedDither(unsigned char*imgData, char name[], int order) {

	int h1 = this->imgHeight;
    int w1 = this->imgWidth;

	imageProcesAlgo temp1;
	temp1.setDimensions(w1, h1);

	int Size = imgWidth*imgHeight;
	unsigned char *newImg = new unsigned char[Size];

	int **matrix = temp1.BayerIndexMatrix(order);
    cout << "\n";
	for(int i = 0; i<order; i++){
		for(int j = 0; j<order; j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
    cout << "Flag 2" << endl;
	unsigned char T[order][order];

	for(int i = 0; i<order; i++) {
		for(int j = 0; j<order; j++) {
			T[i][j] = floor(double((255*(matrix[i][j] + 0.5))/(order*order)));
			cout << int(T[i][j]) << " ";
		}
		cout << endl;
	}

	cout << "Flag 3" << endl;


	for(int i = 0; i<imgHeight; i++) {
		for(int j = 0; j<imgWidth; j++) {
			if(imgData[i*imgWidth + j] > T[i%order][j%order])
				newImg[i*imgWidth + j] = 255;
			else if((imgData[i*imgWidth + j] <= T[i%order][j%order]) && (imgData[i*imgWidth + j] > double(0.667*T[i%order][j%order])))
				newImg[i*imgWidth + j] = 170;
            else if((imgData[i*imgWidth + j] > double(0.333*T[i%order][j%order])) && (imgData[i*imgWidth + j] <= double(0.667*T[i%order][j%order])))
				newImg[i*imgWidth + j] = 85;
            else
				newImg[i*imgWidth + j] = 0;
		}
	}


	for (int i = 0; i<order; i++)
		delete[] matrix[i];
	delete matrix;

	temp1.saveImage(newImg, name, 1);
	temp1.freeMemory(newImg);
}

//*****************************************************************************************************

int **imageProcesAlgo::BayerIndexMatrix(int order) {

	int h1 = this->imgHeight;
    int w1 = this->imgWidth;

	imageProcesAlgo temp1;
	temp1.setDimensions(w1, h1);

	int **indexMatrix = new int *[order];
		for(int i = 0; i<order; i++)
			indexMatrix[i] = new int [order];

	int temp, n = order/2;


	for(int i = 0; i<order; i++) {
		for(int j = 0; j<order; j++){
			if((i < n) && (j < n))
				temp = 1;
			else if((i < n) && (j >= n))
				temp = 2;
			else if((i >= n) && (j < n))
				temp = 3;
			else
				temp = 0;

			switch(order){

				case 2: {
					indexMatrix[i][j] = temp;
					break;
				}

				case 4:{
				    int **I = temp1.BayerIndexMatrix(2);
					indexMatrix[i][j] = 4*I[i%2][j%2] + temp;
					for (int i = 0; i<2; i++)
                        delete[] I[i];
                    delete I;
					break;
				}

				case 8:{
				    int **I = temp1.BayerIndexMatrix(4);
					indexMatrix[i][j] = (4*I[i%4][j%4] + temp);
					for (int i = 0; i<4; i++)
                        delete[] I[i];
                    delete I;
					break;
				}

			}
		}

	}
	return indexMatrix;
}

//*****************************************************************************************************
