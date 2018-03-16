//***********************************************************************
// EE569 Homework 2, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 2c
// Submission Date: 4th March, 2018
//***********************************************************************

#include "imageProcesAlgo.h"

void imageProcesAlgo::SeparableErrorDiffusion(unsigned char *imgData, unsigned char *threshold, char name[]) {

	int h1 = this->imgHeight;
    int w1 = this->imgWidth;

	imageProcesAlgo temp1;
	temp1.setDimensions(w1, h1);

	float error = 0, valueOld = 0, valueNew = 0;

	float ***ditherImg = new float**[imgHeight];
	for (int i = 0; i<imgHeight; i++) {
		ditherImg[i] = new float *[imgWidth];
		for(int j = 0; j<imgWidth; j++)
			ditherImg[i][j] = new float[3];
	}

	for(int i = 0; i<imgHeight; i++) {
		for(int j = 0; j<imgWidth; j++) {
			for(int k = 0; k<3; k++) {
				ditherImg[i][j][k] = imgData[i*imgWidth*3 + j*3 + k];
			}
		}
	}

	cout << "Flag 1" << endl;
	unsigned char *finalImage = new unsigned char[imgWidth * imgHeight * 3];
	for(int i = 0; i<imgHeight * imgWidth * 3; i++)
        finalImage[i] = 0;

    for(int i = 0; i<imgHeight-1; i++) {
		for(int j = 1; j<imgWidth-1; j++) {
			for(int k = 0; k<3; k++) {
				valueOld = ditherImg[i][j][k];
				if(valueOld >= threshold[k])
                	valueNew = 255;
            	else
                	valueNew = 0;
				ditherImg[i][j][k] = valueNew;

				error = (valueOld - valueNew);
				ditherImg[i][j + 1][k]     = ditherImg[i][j + 1][k]     + float(error*0.4375);
				ditherImg[i + 1][j - 1][k] = ditherImg[i + 1][j - 1][k] + float(error*0.1875);
				ditherImg[i + 1][j][k]     = ditherImg[i + 1][j][k]     + float(error*0.3125);
				ditherImg[i + 1][j + 1][k] = ditherImg[i + 1][j + 1][k] + float(error*0.0625);
			}
		//cout << "i: " << i << " j: " << j << endl;
		}
	}

	cout << "Separable Error diffusion with Floyd Steinberg dithering implemented!\n" << endl;

	for(int i = 0; i<imgHeight; i++) {
		for(int j = 0; j<imgWidth; j++) {
				finalImage[i*imgWidth*3 + j*3] = ditherImg[i][j][0];
				finalImage[i*imgWidth*3 + j*3 + 1] = ditherImg[i][j][1];
				finalImage[i*imgWidth*3 + j*3 + 2] = ditherImg[i][j][2];
		}
	}

	for(int i = 0; i<imgHeight; i++) {
		for(int  j = 0; j<imgWidth; j++)
			delete[] ditherImg[i][j];
		delete[] ditherImg[i];
	}
	delete[] ditherImg;

	temp1.saveImage(finalImage, name, 3);
	temp1.freeMemory(finalImage);



}

//*****************************************************************************************************


void imageProcesAlgo::MBVQ_FloydSteinberg(unsigned char *imgData, char name[]) {

    int h1 = this->imgHeight;
    int w1 = this->imgWidth;

	imageProcesAlgo temp1;
	temp1.setDimensions(w1, h1);

	float error = 0, valueOld[3];
	unsigned char R1, G1, B1;
	unsigned char *valueNew = new unsigned char[3];

	float ***ditherImg = new float**[imgHeight];
	for (int i = 0; i<imgHeight; i++) {
		ditherImg[i] = new float *[imgWidth];
		for(int j = 0; j<imgWidth; j++)
			ditherImg[i][j] = new float[3];
	}

	unsigned char *finalImage = new unsigned char[imgWidth * imgHeight * 3];
	for(int i = 0; i<imgHeight * imgWidth * 3; i++)
        finalImage[i] = 0;

	unsigned char ***originalImg = temp1.image3D(imgData);

	for(int i = 0; i<imgHeight; i++) {
		for(int j = 0; j<imgWidth; j++) {
			for(int k = 0; k<3; k++) {
				ditherImg[i][j][k] = originalImg[i][j][k];
			}
		}
	}

	for(int i = 0; i<imgHeight-1; i++) {
		for(int j = 1; j<imgWidth-1; j++) {

			valueOld[0] = ditherImg[i][j][0];
			valueOld[1] = ditherImg[i][j][1];
			valueOld[2] = ditherImg[i][j][2];

			R1 = originalImg[i][j][0];
			G1 = originalImg[i][j][1];
			B1 = originalImg[i][j][2];

			valueNew = temp1.pyramidMBVQ(R1, G1, B1, valueOld[0], valueOld[1],valueOld[2]);
			//valueNew = temp1.pyramidMBVQ(valueOld[0], valueOld[1],valueOld[2], valueOld[0], valueOld[1],valueOld[2]);

			for(int k = 0; k<3; k++) {
                ditherImg[i][j][k] = valueNew[k];

                error = float(valueOld[k] - valueNew[k]);
                ditherImg[i][j + 1][k]    = ditherImg[i][j + 1][k]     + float(error*0.4375);
                ditherImg[i + 1][j - 1][k] = ditherImg[i + 1][j - 1][k]  + float(error*0.1875);
                ditherImg[i + 1][j][k]     = ditherImg[i + 1][j][k]     + float(error*0.3125);
                ditherImg[i + 1][j + 1][k] = ditherImg[i + 1][j + 1][k]  + float(error*0.0625);

			}
		}
	}

    cout << "MBVQ with Floyd Steinberg dithering implemented!" << endl;

	for(int i = 0; i<imgHeight; i++) {
		for(int j = 0; j<imgWidth; j++) {
				finalImage[i*imgWidth*3 + j*3] = ditherImg[i][j][0];
				finalImage[i*imgWidth*3 + j*3 + 1] = ditherImg[i][j][1];
				finalImage[i*imgWidth*3 + j*3 + 2] = ditherImg[i][j][2];
				//cout << "i: " << i << " j: " << j << endl;
		}
	}

    cout << "Flag44" << endl;

	for(int i = 0; i<imgHeight; i++) {
		for(int  j = 0; j<imgWidth; j++)
			delete[] originalImg[i][j];
		delete[] originalImg[i];
	}
	delete[] originalImg;

	for(int i = 0; i<imgHeight; i++) {
		for(int  j = 0; j<imgWidth; j++)
			delete[] ditherImg[i][j];
		delete[] ditherImg[i];
	}
	delete[] ditherImg;

	delete[] valueNew;

	temp1.saveImage(finalImage, name, 3);
	temp1.freeMemory(finalImage);
}



//*****************************************************************************************************

unsigned char *imageProcesAlgo::pyramidMBVQ(unsigned char R1, unsigned char G1, unsigned char B1,
											float R2, float G2, float B2 ) {

	int h1 = this->imgHeight;
    int w1 = this->imgWidth;

	imageProcesAlgo temp1;
	temp1.setDimensions(w1, h1);

	unsigned char* rgbTriple;

	if((R1 + G1) > 255) {
		if((G1 + B1) >255) {
			if((R1 + G1 + B1) > 510)
				rgbTriple = temp1.CMYW(R2, G2, B2);
			else
				rgbTriple = temp1.MYGC(R2, G2, B2);
		}
		else
			rgbTriple = temp1.RGMY(R2, G2, B2);
	}
	else {
		if((G1 + B1) <= 255){
			if((R1 + G1 + B1) <= 255)
				rgbTriple = temp1.KRGB(R2, G2, B2);
			else
				rgbTriple = temp1.RGBM(R2, G2, B2);
		}
		else
			rgbTriple = temp1.CMGB(R2, G2, B2);
	}

	return rgbTriple;

}

//*****************************************************************************************************

unsigned char *imageProcesAlgo::CMYW( float R2, float G2, float B2) {

	float distC, distM, distY, distW, minDist;

	unsigned char* rgbTriple = new unsigned char[3];

	distC = pow(R2, 2)         + pow((G2 - 255), 2) + pow((B2 - 255), 2);
	distM = pow((R2 - 255), 2) + pow(G2, 2)         + pow((B2 - 255), 2);
	distY = pow((R2 - 255), 2) + pow((G2 - 255), 2) + pow(B2, 2);
	distW = pow((R2 - 255), 2) + pow((G2 - 255), 2) + pow((B2 - 255), 2);

	minDist = min(distC, min(distM, min(distY, distW)));

	if(minDist == distC)
		rgbTriple = C;
	else if(minDist == distM)
		rgbTriple = M;
	else if(minDist == distY)
		rgbTriple = Y;
	else
		rgbTriple = W;

	return rgbTriple;
}

//*****************************************************************************************************

unsigned char *imageProcesAlgo::MYGC(float R2, float G2, float B2) {

	float distM, distY, distG, distC, minDist;

	unsigned char *rgbTriple = new unsigned char[3];

	distC = pow(R2, 2)         + pow((G2 - 255), 2) + pow((B2 - 255), 2);
	distM = pow((R2 - 255), 2) + pow(G2, 2)         + pow((B2 - 255), 2);
	distY = pow((R2 - 255), 2) + pow((G2 - 255), 2) + pow(B2, 2);
	distG = pow(R2, 2)         + pow((G2 - 255), 2) + pow(B2, 2);

	minDist = min(distC, min(distM, min(distY, distG)));

	if(minDist == distC)
		rgbTriple = C;
	else if(minDist == distM)
		rgbTriple = M;
	else if(minDist == distY)
		rgbTriple = Y;
	else
		rgbTriple = G;

	return rgbTriple;
}

//*****************************************************************************************************

unsigned char *imageProcesAlgo::RGMY(float R2, float G2, float B2) {

	float distM, distY, distG, distR, minDist;

	unsigned char* rgbTriple = new unsigned char[3];

	distR = pow((R2 - 255), 2) + pow(G2, 2)         + pow(B2, 2);
	distM = pow((R2 - 255), 2) + pow(G2, 2)         + pow((B2 - 255), 2);
	distY = pow((R2 - 255), 2) + pow((G2 - 255), 2) + pow(B2, 2);
	distG = pow(R2, 2)         + pow((G2 - 255), 2) + pow(B2, 2);

	minDist = min(distR, min(distM, min(distY, distG)));

	if(minDist == distR)
		rgbTriple = R;
	else if(minDist == distM)
		rgbTriple = M;
	else if(minDist == distY)
		rgbTriple = Y;
	else
		rgbTriple = G;

	return rgbTriple;
}

//*****************************************************************************************************


unsigned char *imageProcesAlgo::RGBM(float R2, float G2, float B2) {

	float distM, distB, distG, distR, minDist;

	unsigned char* rgbTriple = new unsigned char[3];

	distR = pow((R2 - 255), 2) + pow(G2, 2) + pow(B2, 2);
	distM = pow((R2 - 255), 2) + pow(G2, 2) + pow((B2 - 255), 2);
	distB = pow(R2, 2) + pow(G2, 2) + pow((B2 - 255), 2);
	distG = pow(R2, 2) + pow((G2 - 255), 2) + pow(B2, 2);

	minDist = min(distR, min(distM, min(distB, distG)));

	if(minDist == distR)
		rgbTriple = R;
	else if(minDist == distM)
		rgbTriple = M;
	else if(minDist == distB)
		rgbTriple = B;
	else
		rgbTriple = G;

	return rgbTriple;
}

//*****************************************************************************************************


unsigned char *imageProcesAlgo::KRGB(float R2, float G2, float B2) {

	float distK, distB, distG, distR, minDist;

	unsigned char* rgbTriple = new unsigned char[3];

	distR = pow((R2 - 255), 2) + pow(G2, 2) + pow(B2, 2);
	distK = pow(R2, 2) + pow(G2, 2) + pow(B2, 2);
	distB = pow(R2, 2) + pow(G2, 2) + pow((B2 - 255), 2);
	distG = pow(R2, 2) + pow((G2 - 255), 2) + pow(B2, 2);

	minDist = min(distR, min(distK, min(distB, distG)));

	if(minDist == distR)
		rgbTriple = R;
	else if(minDist == distK)
		rgbTriple = K;
	else if(minDist == distB)
		rgbTriple = B;
	else
		rgbTriple = G;

	return rgbTriple;
}

//*****************************************************************************************************


unsigned char *imageProcesAlgo::CMGB(float R2, float G2, float B2) {

	float distM, distB, distG, distC, minDist;

	unsigned char* rgbTriple = new unsigned char[3];

	distC = pow(R2, 2) + pow((G2 - 255), 2) + pow((B2 - 255), 2);
	distM = pow((R2 - 255), 2) + pow(G2, 2) + pow((B2 - 255), 2);
	distB = pow(R2, 2) + pow(G2, 2) + pow((B2 - 255), 2);
	distG = pow(R2, 2) + pow((G2 - 255), 2) + pow(B2, 2);

	minDist = min(distC, min(distM, min(distB, distG)));

	if(minDist == distC)
		rgbTriple = C;
	else if(minDist == distM)
		rgbTriple = M;
	else if(minDist == distB)
		rgbTriple = B;
	else
		rgbTriple = G;

	return rgbTriple;
}

//*****************************************************************************************************

