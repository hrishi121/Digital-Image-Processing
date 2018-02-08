//***********************************************************************
// EE569 Homework 1, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 3a
// Submission Date: 4th February, 2016
//***********************************************************************


#include "imageProcesAlgo.h"

unsigned char *imageProcesAlgo::separatePlanes(unsigned char *imageData, int planeNum) {

    if(planeNum == 0)
        return imageData;

    int Size = imgHeight * imgWidth;

	unsigned char *plane = new unsigned char[Size];
	for (int i = 0; i < imgHeight; i++) {
        for(int j = 0; j<imgWidth; j++){
            plane[i*imgWidth + j] = imageData[i*imgWidth*3 + j*3 + planeNum -1];
        }
	}

	//cout << " Plane created " << endl;

    return plane;

}



//***************************************************************************************



unsigned char **imageProcesAlgo::paddedImg(unsigned char *imgData, int pad) {

	vector < vector<unsigned char> > img;
	unsigned char temp;


	for(int i = 0; i < imgHeight; i++) {
		img.push_back(vector <unsigned char>());

   		for(int j = 0; j < imgWidth; j++) {

       		temp = imgData[i*imgWidth + j];
           	img[i].push_back(temp);
   		}
	}


	// dynamically create array of pointers of size M
	unsigned char** A = new unsigned char*[imgHeight + (2 * pad)];

	// dynamically allocate memory of size N for each row
	for (int i = 0; i < (imgHeight + (2 * pad)); i++)
		A[i] = new unsigned char[(imgWidth + (2 * pad))];

	// Assign values to allocated memory


	// This is for assign to the middle portion only
	for (int i = 0; i < imgHeight; i++)
		for (int j = 0; j < imgWidth; j++)
			A[i + pad][j + pad] = img[i][j];


	//This is to assign values to left and right edges
	for(int i = 0; i< imgHeight; i++) {
		for(int j = 0; j< pad; j++) {
			A[i + pad][j] = img[i][0];
			A[i + pad][imgWidth + (2 * pad) - 1 - j] = img[i][imgWidth - 1];
		}
	}


    // This is to assign values to top and bottom edges
	for(int i = 0; i< pad; i++) {
		for(int j = 0; j<imgWidth+ (2 * pad); j++) {
			A[i][j] = A[pad][j];
			A[imgHeight + (2 * pad) - 1 - i][j] = A[imgHeight + pad - 1][j];
		}
	}

	return A;

}






//***************************************************************************************




unsigned char imageProcesAlgo::findMedian(unsigned char** img, int x, int y, int filtSize) {

	vector<unsigned char> filter;
	int pad;

	if(filtSize == 3)
		pad = 1;
	else if(filtSize == 5)
		pad = 2;
	else if(filtSize == 7)
		pad = 3;
	else if(filtSize == 9)
		pad = 4;
	else
		pad = 5;



	for(int i = 0; i<filtSize; i++) {
		for(int j = 0; j<filtSize; j++) {
		filter.push_back(img[x + i - pad][y + j - pad]);
		}
	}

	//int temp = (filtSize * filtSize) / 2;
	//filter.erase(filter.begin() + temp);

	sort(filter.begin(), filter.end());

	//int temp2 = (filter[temp] + filter[temp-1]) / 2;
	unsigned char median = filter[(filtSize*filtSize) / 2];

	return median;

}



//***************************************************************************************




unsigned char *imageProcesAlgo::filter(unsigned char *noisyImg, int planeNum, int filtSize, int filtNum, double qValue) {


	int h1 = this->imgHeight;
    int w1 = this->imgWidth;

	imageProcesAlgo temp1;
	temp1.setDimensions(h1, w1);

	int Size = imgHeight * imgWidth;
	int pad;

	unsigned char *plane = temp1.separatePlanes(noisyImg, planeNum);
	unsigned char *filteredImg = new unsigned char[imgWidth*imgHeight];

	for(int i = 0; i<imgWidth*imgHeight; i++)
		filteredImg[i] = 0;

	if(filtSize == 3)
		pad = 1;
	else if(filtSize == 5)
		pad = 2;
	else if(filtSize == 7)
		pad = 3;
	else if(filtSize == 9)
		pad = 4;
	else
		pad = 5;

	//cout << "Flag 1" << endl;

	unsigned char **padImg = temp1.paddedImg(plane, pad);

	//cout << "Flag 2" << endl;

	switch(filtNum) {

	case 1: {
				for(int i = pad; i < (imgHeight + pad); i++) {
					for(int j = pad; j< (imgWidth + pad); j++) {
						filteredImg[ (i - pad)*imgWidth + (j - pad) ]  = temp1.findMedian(padImg, i, j, filtSize);
					}
				}
				break;
   			}

   	case 2: {
				for(int i = pad; i < (imgHeight + pad); i++) {
					for(int j = pad; j< (imgWidth + pad); j++) {
						filteredImg[ (i - pad)*imgWidth + (j - pad) ]  = temp1.findMax(padImg, i, j, filtSize);
					}
				}
				break;
   			}

   	case 3: {
				for(int i = pad; i < (imgHeight + pad); i++) {
					for(int j = pad; j< (imgWidth + pad); j++) {
						filteredImg[ (i - pad)*imgWidth + (j - pad) ]  = temp1.findMin(padImg, i, j, filtSize);
					}
				}
				break;
   			}

   	case 4: {
				for(int i = pad; i < (imgHeight + pad); i++) {
					for(int j = pad; j< (imgWidth + pad); j++) {
						filteredImg[ (i - pad)*imgWidth + (j - pad) ]  = temp1.contraHarmonic(padImg, i, j, filtSize, qValue);
					}
				}
				break;
   			}

   	case 5: {
				for(int i = pad; i < (imgHeight + pad); i++) {
					for(int j = pad; j< (imgWidth + pad); j++) {
						filteredImg[ (i - pad)*imgWidth + (j - pad) ]  = temp1.findMean(padImg, i, j, filtSize);
					}
				}
				break;
   			}

	}

	for (int i = 0; i < imgHeight + (2 * pad); i++)
		delete[] padImg[i];
	delete[] padImg;


	cout << "Filtering done!" << endl;

	return filteredImg;
}




//***************************************************************************************



unsigned char imageProcesAlgo::findMax(unsigned char **img, int x, int y, int filtSize) {

	vector<unsigned char> filter;
	int pad;

	if(filtSize == 3)
		pad = 1;
	else if(filtSize == 5)
		pad = 2;
	else if(filtSize == 7)
		pad = 3;
	else if(filtSize == 9)
		pad = 4;
	else
		pad = 5;



	for(int i = 0; i<filtSize; i++) {
		for(int j = 0; j<filtSize; j++) {
		filter.push_back(img[x + i - pad][y + j - pad]);
		}
	}

	//int temp = (filtSize * filtSize) / 2;
	//filter.erase(filter.begin() + temp);

	unsigned char temp1, max1 = filter[0];
	for(int i = 1; i<filtSize*filtSize; i++) {
		temp1 = max(filter[i-1], filter[i]);
		if(max1 >= temp1)
			max1 = max1;
		else
			max1 = temp1;
	}


	return max1;
}



//***************************************************************************************



unsigned char imageProcesAlgo::findMin(unsigned char **img, int x, int y, int filtSize) {

	vector<unsigned char> filter;
	int pad;

	if(filtSize == 3)
		pad = 1;
	else if(filtSize == 5)
		pad = 2;
	else if(filtSize == 7)
		pad = 3;
	else if(filtSize == 9)
		pad = 4;
	else
		pad = 5;



	for(int i = 0; i<filtSize; i++) {
		for(int j = 0; j<filtSize; j++) {
		filter.push_back(img[x + i - pad][y + j - pad]);
		}
	}

	//int temp = (filtSize * filtSize) / 2;
	//filter.erase(filter.begin() + temp);

	unsigned char temp1, min1 = filter[0];
	for(int i = 1; i<filtSize*filtSize; i++) {
		temp1 = min(filter[i-1], filter[i]);
		if(min1 <= filter[i])
			min1 = min1;
		else
			min1 = temp1;
	}


	return min1;
}




//***************************************************************************************




unsigned char imageProcesAlgo::contraHarmonic(unsigned char **img, int x, int y, int filtSize, double qValue) {

	vector<double> filter;
	int pad;
	double numerator = 0, denominator = 0;

	if(filtSize == 3)
		pad = 1;
	else if(filtSize == 5)
		pad = 2;
	else if(filtSize == 7)
		pad = 3;
	else if(filtSize == 9)
		pad = 4;
	else
		pad = 5;



	for(int i = 0; i<filtSize; i++) {
		for(int j = 0; j<filtSize; j++) {
		filter.push_back(double(img[x + i - pad][y + j - pad]));
		}
	}

	//int temp = (filtSize * filtSize) / 2;
	//filter.erase(filter.begin() + temp);


	for(int i =0; i<filtSize*filtSize; i++){
		numerator = numerator + pow(filter[i], (qValue + 1));
		denominator = denominator + pow(filter[i], (qValue));
	}

	int temp2;
	if(qValue == 0)
		temp2 = int(floor(numerator/denominator) / (imgWidth * imgHeight));
	else if(qValue == -1)
		temp2 = int(floor(numerator/denominator) * (imgWidth * imgHeight));
	else
		temp2 = int(floor(numerator/denominator));

	unsigned char contraHarmonic1 = temp2;

	return contraHarmonic1;
}



//***************************************************************************************



unsigned char imageProcesAlgo::findMean(unsigned char **img, int x, int y, int filtSize) {

	vector<unsigned char> filter;
	int pad;

	if(filtSize == 3)
		pad = 1;
	else if(filtSize == 5)
		pad = 2;
	else if(filtSize == 7)
		pad = 3;
	else if(filtSize == 9)
		pad = 4;
	else
		pad = 5;



	for(int i = 0; i<filtSize; i++) {
		for(int j = 0; j<filtSize; j++) {
		filter.push_back(img[x + i - pad][y + j - pad]);
		}
	}

	//int temp = (filtSize * filtSize) / 2;
	//filter.erase(filter.begin() + temp);

	int sum = 0;
	for(int i =0; i<filtSize*filtSize; i++){
		sum = sum + filter[i];
	}
	unsigned char temp = sum / (filtSize*filtSize);
	return temp;

}



//***************************************************************************************



double imageProcesAlgo::findPSNR(unsigned char *originalImg, unsigned char *filteredImg, int plane) {

	int h1 = this->imgHeight;
    int w1 = this->imgWidth;

	imageProcesAlgo temp1;
	temp1.setDimensions(h1, w1);

	double psnr, mse = 0;

	unsigned char *filtPlane, *originalPlane;

	originalPlane = temp1.separatePlanes(originalImg, plane);
	filtPlane = temp1.separatePlanes(filteredImg, plane);

	for(int i = 0; i<imgHeight; i++) {
		for(int j = 0; j< imgWidth; j++) {
			mse = mse + pow((filtPlane[i*imgWidth + j] - originalPlane[i*imgWidth + j]), 2);
		}
	}

	mse = mse / (imgWidth * imgHeight);

	psnr = 10 * log10((255*255)/mse);

	temp1.freeMemory(filtPlane);
	temp1.freeMemory(originalPlane);

	return psnr;

}



//***************************************************************************************

