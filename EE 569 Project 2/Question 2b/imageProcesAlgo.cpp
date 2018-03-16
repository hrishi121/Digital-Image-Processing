//***********************************************************************
// EE569 Homework 2, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 2b
// Submission Date: 4th March, 2018
//***********************************************************************

#include "imageProcesAlgo.h"

unsigned char* imageProcesAlgo::FloydSteinberg1(unsigned char *imgData, int threshold) {

	double error, valueOld, valueNew;

	unsigned char *finalImage = new unsigned char[imgWidth*imgHeight];
	double *ditherFSImg = new double[imgWidth * imgHeight];


	for(int i = 0; i<imgHeight; i++) {
		for(int j = 0; j<imgWidth; j++) {
			ditherFSImg[i*imgWidth + j] = (double(imgData[i*imgWidth + j]));
		}
	}

	for(int i = 0; i<imgHeight-1; i++) {
		for(int j = 0; j<imgWidth; j++) {

			valueOld = ditherFSImg[i*imgWidth + j];
			if(valueOld >= threshold)
                valueNew = 255;
            else
                valueNew = 0;
			ditherFSImg[i*imgWidth + j] = valueNew;

			error = (valueOld - valueNew);
			ditherFSImg[i*imgWidth + j + 1]       = ditherFSImg[i*imgWidth + j + 1]       + double(error*0.4375);
			ditherFSImg[(i + 1)*imgWidth + j - 1] = ditherFSImg[(i + 1)*imgWidth + j - 1] + double(error*0.1875);
			ditherFSImg[(i + 1)*imgWidth + j]     = ditherFSImg[(i + 1)*imgWidth + j]     + double(error*0.3125);
			ditherFSImg[(i + 1)*imgWidth + j + 1] = ditherFSImg[(i + 1)*imgWidth + j + 1] + double(error*0.0625);
		}
	}

    cout << "Floyd Steinberg Algorithm with normal scanning implemented!" << endl;

	for(int i = 0; i<imgHeight; i++) {
		for(int j = 0; j<imgWidth; j++) {
			finalImage[i*imgWidth + j] = (ditherFSImg[i*imgWidth + j]);
		}
	}

	delete[] ditherFSImg;
	return finalImage;

}



//*****************************************************************************************************



unsigned char* imageProcesAlgo::FloydSteinberg2(unsigned char *imgData, int threshold) {

	double error, valueOld, valueNew;

	unsigned char *finalImage = new unsigned char[imgWidth*imgHeight];
	double *ditherFSImg = new double[imgWidth * imgHeight];

	for(int i = 0; i<imgHeight; i++) {
		for(int j = 0; j<imgWidth; j++) {
			ditherFSImg[i*imgWidth + j] = (double(imgData[i*imgWidth + j]));
		}
	}

	for(int i = 0; i<imgHeight-1; i++) {
		if(i%2 == 0) {
			for(int j = 0; j<imgWidth; j++) {

				valueOld = ditherFSImg[i*imgWidth + j];
				if(valueOld >= threshold)
                	valueNew = 255;
           		else
                	valueNew = 0;

				ditherFSImg[i*imgWidth + j] = valueNew;
				error = (valueOld - valueNew);

				ditherFSImg[i*imgWidth + j + 1]       = ditherFSImg[i*imgWidth + j + 1]       + double(error*0.4375);
				ditherFSImg[(i + 1)*imgWidth + j - 1] = ditherFSImg[(i + 1)*imgWidth + j - 1] + double(error*0.1875);
				ditherFSImg[(i + 1)*imgWidth + j]     = ditherFSImg[(i + 1)*imgWidth + j]     + double(error*0.3125);
				ditherFSImg[(i + 1)*imgWidth + j + 1] = ditherFSImg[(i + 1)*imgWidth + j + 1] + double(error*0.0625);
			}
		}

		else {
			for(int j = imgWidth - 1; j>=0; j--) {

				valueOld = ditherFSImg[i*imgWidth + j];
				if(valueOld >= threshold)
                	valueNew = 255;
           		else
                	valueNew = 0;

				ditherFSImg[i*imgWidth + j] = valueNew;
				error = (valueOld - valueNew);

				ditherFSImg[i*imgWidth + j - 1]       = ditherFSImg[i*imgWidth + j - 1]       + double(error*0.4375);
				ditherFSImg[(i + 1)*imgWidth + j + 1] = ditherFSImg[(i + 1)*imgWidth + j + 1] + double(error*0.1875);
				ditherFSImg[(i + 1)*imgWidth + j]     = ditherFSImg[(i + 1)*imgWidth + j]     + double(error*0.3125);
				ditherFSImg[(i + 1)*imgWidth + j - 1] = ditherFSImg[(i + 1)*imgWidth + j - 1] + double(error*0.0625);
			}
		}
	}

    cout << "Floyd Steinberg Algorithm with serpentine scanning implemented!" << endl;

	for(int i = 0; i<imgHeight; i++) {
		for(int j = 0; j<imgWidth; j++) {
			finalImage[i*imgWidth + j] = (ditherFSImg[i*imgWidth + j]);
		}
	}

	delete[] ditherFSImg;
	return finalImage;

}



//*****************************************************************************************************



unsigned char* imageProcesAlgo::JJN(unsigned char *imgData, int threshold) {

	double error, valueOld, valueNew;

	unsigned char *finalImage = new unsigned char[imgWidth*imgHeight];
	double *ditherFSImg = new double[imgWidth * imgHeight];


	for(int i = 0; i<imgHeight; i++) {
		for(int j = 0; j<imgWidth; j++) {
			ditherFSImg[i*imgWidth + j] = (double(imgData[i*imgWidth + j]));
		}
	}

	for(int i = 0; i<imgHeight-2; i++) {
		for(int j = 0; j<imgWidth; j++) {

			valueOld = ditherFSImg[i*imgWidth + j];
			if(valueOld >= threshold)
                valueNew = 255;
            else
                valueNew = 0;
			ditherFSImg[i*imgWidth + j] = valueNew;

			error = (valueOld - valueNew);
			ditherFSImg[i*imgWidth + j + 1]       = ditherFSImg[i*imgWidth + j + 1]       + double(error*0.1458333);
			ditherFSImg[i*imgWidth + j + 2]       = ditherFSImg[i*imgWidth + j + 2]       + double(error*0.1041667);
			ditherFSImg[(i + 1)*imgWidth + j]     = ditherFSImg[(i + 1)*imgWidth + j]     + double(error*0.1458333);
			ditherFSImg[(i + 1)*imgWidth + j + 1] = ditherFSImg[(i + 1)*imgWidth + j + 1] + double(error*0.1041667);
			ditherFSImg[(i + 1)*imgWidth + j + 2] = ditherFSImg[(i + 1)*imgWidth + j + 2] + double(error*0.0625);
			ditherFSImg[(i + 1)*imgWidth + j - 1] = ditherFSImg[(i + 1)*imgWidth + j - 1] + double(error*0.1041667);
			ditherFSImg[(i + 1)*imgWidth + j - 2] = ditherFSImg[(i + 1)*imgWidth + j - 2] + double(error*0.0625);

			ditherFSImg[(i + 2)*imgWidth + j]     = ditherFSImg[(i + 2)*imgWidth + j]     + double(error*0.1041667);
			ditherFSImg[(i + 2)*imgWidth + j + 1] = ditherFSImg[(i + 2)*imgWidth + j + 1] + double(error*0.0625);
			ditherFSImg[(i + 2)*imgWidth + j + 2] = ditherFSImg[(i + 2)*imgWidth + j + 2] + double(error*0.0208333);
			ditherFSImg[(i + 2)*imgWidth + j - 1] = ditherFSImg[(i + 2)*imgWidth + j - 1] + double(error*0.0625);
			ditherFSImg[(i + 2)*imgWidth + j - 2] = ditherFSImg[(i + 2)*imgWidth + j - 2] + double(error*0.0208333);



		}
	}

    cout << "Jarvis, Judice and Ninke Algorithm implemented!" << endl;

	for(int i = 0; i<imgHeight; i++) {
		for(int j = 0; j<imgWidth; j++) {
			finalImage[i*imgWidth + j] = (ditherFSImg[i*imgWidth + j]);
		}
	}

	delete[] ditherFSImg;
	return finalImage;

}



//*****************************************************************************************************



unsigned char* imageProcesAlgo::Stucki(unsigned char *imgData, int threshold) {

	double error, valueOld, valueNew;

	unsigned char *finalImage = new unsigned char[imgWidth*imgHeight];
	double *ditherFSImg = new double[imgWidth * imgHeight];


	for(int i = 0; i<imgHeight; i++) {
		for(int j = 0; j<imgWidth; j++) {
			ditherFSImg[i*imgWidth + j] = (double(imgData[i*imgWidth + j]));
		}
	}

	for(int i = 0; i<imgHeight-2; i++) {
		for(int j = 0; j<imgWidth; j++) {

			valueOld = ditherFSImg[i*imgWidth + j];
			if(valueOld >= threshold)
                valueNew = 255;
            else
                valueNew = 0;
			ditherFSImg[i*imgWidth + j] = valueNew;

			error = (valueOld - valueNew);
			ditherFSImg[i*imgWidth + j + 1]       = ditherFSImg[i*imgWidth + j + 1]       + double(error*0.1904762);
			ditherFSImg[i*imgWidth + j + 2]       = ditherFSImg[i*imgWidth + j + 2]       + double(error*0.0952381);
			ditherFSImg[(i + 1)*imgWidth + j]     = ditherFSImg[(i + 1)*imgWidth + j]     + double(error*0.1904762);
			ditherFSImg[(i + 1)*imgWidth + j + 1] = ditherFSImg[(i + 1)*imgWidth + j + 1] + double(error*0.0952381);
			ditherFSImg[(i + 1)*imgWidth + j + 2] = ditherFSImg[(i + 1)*imgWidth + j + 2] + double(error*0.047619);
			ditherFSImg[(i + 1)*imgWidth + j - 1] = ditherFSImg[(i + 1)*imgWidth + j - 1] + double(error*0.0952381);
			ditherFSImg[(i + 1)*imgWidth + j - 2] = ditherFSImg[(i + 1)*imgWidth + j - 2] + double(error*0.047619);

			ditherFSImg[(i + 2)*imgWidth + j]     = ditherFSImg[(i + 2)*imgWidth + j]     + double(error*0.0952381);
			ditherFSImg[(i + 2)*imgWidth + j + 1] = ditherFSImg[(i + 2)*imgWidth + j + 1] + double(error*0.047619);
			ditherFSImg[(i + 2)*imgWidth + j + 2] = ditherFSImg[(i + 2)*imgWidth + j + 2] + double(error*0.0238095);
			ditherFSImg[(i + 2)*imgWidth + j - 1] = ditherFSImg[(i + 2)*imgWidth + j - 1] + double(error*0.047619);
			ditherFSImg[(i + 2)*imgWidth + j - 2] = ditherFSImg[(i + 2)*imgWidth + j - 2] + double(error*0.0238095);



		}
	}

    cout << "Stucki's Algorithm implemented!" << endl;

	for(int i = 0; i<imgHeight; i++) {
		for(int j = 0; j<imgWidth; j++) {
			finalImage[i*imgWidth + j] = (ditherFSImg[i*imgWidth + j]);
		}
	}

	delete[] ditherFSImg;
	return finalImage;

}



//*****************************************************************************************************
