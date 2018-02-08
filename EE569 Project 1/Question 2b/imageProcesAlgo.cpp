//***********************************************************************
// EE569 Homework 1, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 2b
// Submission Date: 4th February, 2016
//***********************************************************************

#include "imageProcesAlgo.h"

void imageProcesAlgo::oilMaskPart1(unsigned char *img, char name[], int quantize) {


	int h1 = this->imgHeight;
    int w1 = this->imgWidth;

	imageProcesAlgo temp1;
	temp1.setDimensions(w1, h1);

	int Size = imgWidth * imgHeight;
	unsigned char *oilImage1 = new unsigned char [Size*3];

	switch(quantize) {

	    case 512: {

		unsigned char *newPlane1 = temp1.oilQuantize512(img, 1);
		unsigned char *newPlane2 = temp1.oilQuantize512(img, 2);
		unsigned char *newPlane3 = temp1.oilQuantize512(img, 3);

	    for(int i = 0; i<imgHeight; i++) {
            for(int j = 0; j<imgWidth; j++) {
                oilImage1[i*imgWidth*3 + j*3] = newPlane1[i*imgWidth + j];
                oilImage1[i*imgWidth*3 + j*3 + 1] = newPlane2[i*imgWidth + j];
                oilImage1[i*imgWidth*3 + j*3 + 2] = newPlane3[i*imgWidth + j];
            }
        }

        cout << "Quantization done" << endl;
        temp1.saveImage(oilImage1, name, 3);
        temp1.freeMemory(newPlane1);
        temp1.freeMemory(newPlane2);
        temp1.freeMemory(newPlane3);
        temp1.freeMemory(oilImage1);

        break;
	    }

        case 64: {
		unsigned char *newPlane1 = temp1.oilQuantize64(img, 1);
		unsigned char *newPlane2 = temp1.oilQuantize64(img, 2);
		unsigned char *newPlane3 = temp1.oilQuantize64(img, 3);

		for(int i = 0; i<imgHeight; i++) {
            for(int j = 0; j<imgWidth; j++) {
                oilImage1[i*imgWidth*3 + j*3] = newPlane1[i*imgWidth + j];
                oilImage1[i*imgWidth*3 + j*3 + 1] = newPlane2[i*imgWidth + j];
                oilImage1[i*imgWidth*3 + j*3 + 2] = newPlane3[i*imgWidth + j];
            }
        }

        cout << "Quantization done" << endl;
        temp1.saveImage(oilImage1, name, 3);
        temp1.freeMemory(newPlane1);
        temp1.freeMemory(newPlane2);
        temp1.freeMemory(newPlane3);
        temp1.freeMemory(oilImage1);

        break;
        }
	}


}




//***************************************************************************************




unsigned char *imageProcesAlgo::oilQuantize64(unsigned char *img, int planeNum) {


	int h1 = this->imgHeight;
    int w1 = this->imgWidth;

	imageProcesAlgo temp1;
	temp1.setDimensions(w1, h1);

	unsigned char *plane = temp1.separatePlanes(img, planeNum);
	unsigned char *oilImage1 = new unsigned char [imgWidth*imgHeight];


	unsigned int *info1 = temp1.imgHistDataPartial(plane, 0, 0, "temp1.csv",4);
	unsigned int *info2 = temp1.imgHistDataPartial(plane, info1[0], info1[1], "temp2.csv",4);
	unsigned int *info3 = temp1.imgHistDataPartial(plane, info2[0], info2[1], "temp3.csv",4);
	unsigned int *info4 = temp1.imgHistDataPartial(plane, info3[0], info3[1], "temp4.csv",4);

	//cout << info1[0] << " " << info2[0] <<" " << info3[0] <<" " << info4[0] << endl;
	//cout << info1[2] << " " << info2[2] <<" " << info3[2] <<" " << info4[2] << endl;



	for(int i = 0; i < imgWidth*imgHeight; i++) {

		if(plane[i]>=0 && plane[i] < info1[0]) {
			oilImage1[i] = info1[2];
		}

		else if(plane[i] >= info1[0] && plane[i] < info2[0]) {
			oilImage1[i] = info2[2];
		}

		else if(plane[i] >= (info2[0]) && plane[i] < info3[0]) {
			oilImage1[i] = info3[2];
		}

		else
			oilImage1[i] = info4[2];


	}

	temp1.freeMemory(plane);
	return oilImage1;


}



//***************************************************************************************




unsigned char *imageProcesAlgo::oilQuantize512(unsigned char *img, int planeNum) {


	int h1 = this->imgHeight;
    int w1 = this->imgWidth;

	imageProcesAlgo temp1;
	temp1.setDimensions(w1, h1);

	unsigned char *plane = temp1.separatePlanes(img, planeNum);
	unsigned char *oilImage1 = new unsigned char [imgWidth*imgHeight];


	unsigned int *info1 = temp1.imgHistDataPartial(plane, 0, 0, "temp1.csv", 8);
	unsigned int *info2 = temp1.imgHistDataPartial(plane, info1[0], info1[1], "temp2.csv", 8);
	unsigned int *info3 = temp1.imgHistDataPartial(plane, info2[0], info2[1], "temp3.csv", 8);
	unsigned int *info4 = temp1.imgHistDataPartial(plane, info3[0], info3[1], "temp4.csv", 8);
	unsigned int *info5 = temp1.imgHistDataPartial(plane, info4[0], info4[1], "temp5.csv", 8);
	unsigned int *info6 = temp1.imgHistDataPartial(plane, info5[0], info5[1], "temp6.csv", 8);
	unsigned int *info7 = temp1.imgHistDataPartial(plane, info6[0], info6[1], "temp7.csv", 8);
	unsigned int *info8 = temp1.imgHistDataPartial(plane, info7[0], info7[1], "temp8.csv", 8);


	//cout << info1[0] << " " << info2[0] <<" " << info3[0] <<" " << info4[0] <<" " << info5[0]<<" " << info6[0]<<" " << info7[0]<<" " << info8[0] << endl;
	//cout << info1[2] << " " << info2[2] <<" " << info3[2] <<" " << info4[2] <<" " << info5[0]<<" " << info6[0]<<" " << info7[0]<<" " << info8[0] << endl;



	for(int i = 0; i < imgWidth*imgHeight; i++) {

		if(plane[i]>=0 && plane[i] < info1[0]) {
			oilImage1[i] = info1[2];
		}

		else if(plane[i] >= info1[0] && plane[i] < info2[0]) {
			oilImage1[i] = info2[2];
		}

		else if(plane[i] >= (info2[0]) && plane[i] < info3[0]) {
			oilImage1[i] = info3[2];
		}

		else if(plane[i] >= (info3[0]) && plane[i] < info4[0]) {
			oilImage1[i] = info4[2];
		}

		else if(plane[i] >= (info4[0]) && plane[i] < info5[0]) {
			oilImage1[i] = info5[2];
		}

		else if(plane[i] >= (info5[0]) && plane[i] < info6[0]) {
			oilImage1[i] = info6[2];
		}

		else if(plane[i] >= (info6[0]) && plane[i] < info7[0]) {
			oilImage1[i] = info7[2];
		}

		else
			oilImage1[i] = info8[2];


	}

	temp1.freeMemory(plane);
	return oilImage1;


}


//***************************************************************************************



unsigned int *imageProcesAlgo::imgHistDataPartial(unsigned char *plane, int pixelValue,
												 int count2, char name[], int quantize) {

	map<unsigned char, unsigned int> planeMap;
	long int numerator = 0, denominator = 0;
	int weightedMean;
	int n = (imgWidth * imgHeight)/quantize;

	unsigned int *info1 = new unsigned int[3];

	for(int j = 0; j<256; j++) {
        unsigned char k = j;
		planeMap[k] = 0;
	}
	planeMap[pixelValue] = planeMap[pixelValue] - count2;

	//cout << "PixelValue: " << pixelValue << " "<< "count2: " << count2 << endl;
    int count1 = 0;

	for(int j = pixelValue; j<256; j++) {
    	for(int i =0; i<(imgWidth*imgHeight); i++) {
		    unsigned char k = j;
			if(plane[i] == k) {
				planeMap[k] = planeMap[k] + 1;
				count1 = count1 + 1;
				if(count1 == n + count2){
					info1[0] = j;
					break;
				}
			}
		}
		if(count1 == n + count2){
			info1[0] = j;
			break;
		}
	}


	ofstream histFile(name);

      for(int i = 0; i<256; i++){
        unsigned char k = i;
      	histFile << int(k) << "," << planeMap[k] << endl;
      	//cout << int(k) << endl;
      }
      histFile.close();


	info1[1] = planeMap[info1[0]];

	for(map<unsigned char,unsigned int>::iterator it=planeMap.begin(); it!=planeMap.end(); ++it) {
		numerator = numerator + (int(it->first) * it->second);
		denominator = denominator + it->second;
	}

	weightedMean = int(ceil(double(numerator / denominator)));
	info1[2] = weightedMean;

	return info1;
}




//***************************************************************************************



unsigned char *imageProcesAlgo::separatePlanes(unsigned char *imageData, int planeNum) {

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



unsigned char imageProcesAlgo::findFrequentPixel(unsigned char** img, int x, int y, int filtSize) {

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

	int temp = (filtSize * filtSize) / 2;
	filter.erase(filter.begin() + temp);

    int max_count = 0;

    for (int i=0; i<(filtSize * filtSize); i++) {
        int count=1;
        for (int j=i+1; j<(filtSize * filtSize - 1); j++)
            if (filter[i]==filter[j])
                count++;
        if (count>max_count)
            max_count = count;
    }

    for (int i=0; i<(filtSize * filtSize); i++) {
        int count=1;
        for (int j=i+1; j<(filtSize * filtSize - 1); j++)
            if (filter[i]==filter[j])
                count++;
        if (count==max_count)
       return filter[i];
    }


}



//***************************************************************************************




void imageProcesAlgo::oilMaskPart2(unsigned char *img, int filtSize, char name[]) {

	int h1 = this->imgHeight;
    int w1 = this->imgWidth;

	imageProcesAlgo temp1;
	temp1.setDimensions(w1, h1);

	int Size = imgHeight * imgWidth;
	int pad;
	unsigned char *filteredImg = new unsigned char[imgWidth*imgHeight*3];

	for(int i = 0; i<imgWidth*imgHeight*3; i++)
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


	unsigned char *plane1 = temp1.separatePlanes(img, 1);
	unsigned char **padImg1 = temp1.paddedImg(plane1, pad);


	unsigned char *plane2 = temp1.separatePlanes(img, 2);
	unsigned char **padImg2 = temp1.paddedImg(plane2, pad);


	unsigned char *plane3 = temp1.separatePlanes(img, 3);
	unsigned char **padImg3 = temp1.paddedImg(plane3, pad);


	for(int i = pad; i < (imgHeight + pad); i++) {
		for(int j = pad; j< (imgWidth + pad); j++) {

			filteredImg[ (i - pad)*imgWidth*3 + (j - pad)*3 ]     = temp1.findFrequentPixel(padImg1, i, j, filtSize);
			filteredImg[ (i - pad)*imgWidth*3 + (j - pad)*3 + 1 ] = temp1.findFrequentPixel(padImg2, i, j, filtSize);
			filteredImg[ (i - pad)*imgWidth*3 + (j - pad)*3 + 2 ] = temp1.findFrequentPixel(padImg3, i, j, filtSize);

		}
	}


	for (int i = 0; i < imgHeight + (2 * pad); i++)
		delete[] padImg1[i];
	delete[] padImg1;

    for (int i = 0; i < imgHeight + (2 * pad); i++)
		delete[] padImg2[i];
	delete[] padImg2;


	for (int i = 0; i < imgHeight + (2 * pad); i++)
		delete[] padImg3[i];
	delete[] padImg3;


	temp1.saveImage(filteredImg, name, 3);
	temp1.freeMemory(plane1);
	temp1.freeMemory(plane2);
	temp1.freeMemory(plane3);
	temp1.freeMemory(filteredImg);


}



//***************************************************************************************
