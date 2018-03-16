//***********************************************************************
// EE569 Homework 2, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 3 a,b,c
// Submission Date: 4th March, 2018
//***********************************************************************

#include "imageProcesAlgo.h"


unsigned char imageProcesAlgo::matchConditionalMask(unsigned char inputPattern, int operation) {

/*unsigned char shrinkPatterns[58] = { 0b01000000, 0b00010000, 0b00000100, 0b00000001,
								   0b10000000, 0b00100000, 0b000010000, 0b00000100,
								   0b11000000, 0b01100000, 0b00110000, 0b00011000,
								   0b00001100, 0b00000110, 0b00000011, 0b10000001,
								   0b01110000, 0b00011100, 0b00000111, 0b11000001,
								   0b10110000, 0b10100001, 0b01101000, 0b11000010,
								   0b11100000, 0b00111000, 0b00001110, 0b10000011,
								   0b11110000, 0b11100001, 0b01111000, 0b00111100,
								   0b00011110, 0b00001111, 0b10000111, 0b11000011,
								   0b10110001, 0b01101100,
								   0b11110001, 0b01111100, 0b00011111, 0b11000111,
								   0b11100011, 0b11111000, 0b00111110, 0b10001111,
								   0b11110011, 0b11100111, 0b11111100, 0b11111001,
								   0b01111110, 0b00111111, 0b10011111, 0b11001111,
								   0b11110111, 0b11111101, 0b01111111, 0b11011111
								    };*/

unsigned char shrinkPatterns[58] = {
									0b01000000, 0b00010000, 0b00000100, 0b00000001,
									0b10000000, 0b00100000, 0b00001000, 0b00000010,
									0b11000000, 0b01100000, 0b00110000, 0b00011000, 0b00001100, 0b00000110, 0b00000011, 0b10000001,
									0b11000001, 0b01110000, 0b00011100, 0b00000111,
									0b10110000, 0b10100001, 0b01101000, 0b11000010,
									0b11100000, 0b00111000, 0b00001110, 0b10000011,
									0b10110001, 0b01101100,
									0b11110000, 0b11100001, 0b01111000, 0b00111100, 0b00011110, 0b00001111, 0b10000111, 0b11000011,
									0b11110001, 0b01111100, 0b00011111, 0b11000111,
									0b11100011, 0b11111000, 0b00111110, 0b10001111,
									0b11110011, 0b11100111, 0b11111100, 0b11111001, 0b01111110, 0b00111111, 0b10011111, 0b11001111,
									0b11110111, 0b11111101, 0b01111111, 0b11011111
									};

unsigned char thinPatterns[46] = { 0b10100000, 0b00101000, 0b00001010, 0b00000101,
								 0b01110000, 0b00011100, 0b00000111, 0b10000010,
								 0b10110000, 0b10100001, 0b01101000, 0b11000010,
								 0b11100000, 0b00111000, 0b00001110, 0b10000011,
								 0b11110000, 0b11100001, 0b01111000, 0b00111100,
								 0b00011110, 0b00001111, 0b10000111, 0b11000011,
								 0b10110001, 0b01101100,
								 0b11110001, 0b01111100, 0b00011111, 0b11000111,
								 0b11100011, 0b11111000, 0b00111110, 0b10001111,
								 0b11110011, 0b11100111, 0b11111100, 0b11111001,
								 0b01111110, 0b00111111, 0b10011111, 0b11001111,
								 0b11110111, 0b11111101, 0b01111111, 0b11011111
								};
unsigned skeletonizing[40] = {
                             0b10100000, 0b00101000, 0b00001010, 0b10000010,
							 0b11000001, 0b01110000, 0b00011100, 0b00000111,
							 0b11110000, 0b11100001, 0b01111000, 0b00111100, 0b00011110, 0b00001111, 0b10000111, 0b11000011,
							 0b11110001, 0b01111100, 0b00011111, 0b11000111,
						 	 0b11100011, 0b11111000, 0b00111110, 0b10001111,
							 0b11110011, 0b11100111, 0b11111100, 0b11111001, 0b01111110, 0b00111111, 0b10011111, 0b11001111,
							 0b11110111, 0b11111101, 0b01111111, 0b11011111,
							 0b11111011, 0b11111110, 0b10111111, 0b11101111

                            };

switch(operation) {
	case 1: {
		for (int i = 0; i<58; i++) {
				if(inputPattern == shrinkPatterns[i]){
					return 1;
				}
		}
		return 0;
	}

	case 2: {
		for (int i = 0; i<46; i++) {
				if(inputPattern == thinPatterns[i]){
					return 1;
				}
		}
		return 0;
	}

	case 3: {
		for (int i = 0; i<40; i++) {
				if(inputPattern == skeletonizing[i]){
					return 1;
				}
		}
		return 0;
	}
}


}



//*****************************************************************************************************


unsigned char **imageProcesAlgo::binaryIntensity(unsigned char *img) {

	unsigned char **tempImg = new unsigned char *[imgHeight];
	for(int i = 0; i<imgHeight; i++)
		tempImg[i] = new unsigned char [imgWidth];

	for(int i = 0; i<imgHeight; i++) {
		for(int j = 0; j< imgWidth; j++) {
			if(img[i*imgWidth + j] >= 127)
				tempImg[i][j] = 1;
			else
				tempImg[i][j] = 0;
		}
	}

	return tempImg;
}

//*****************************************************************************************************


unsigned char **imageProcesAlgo::reverseBinaryIntensity(unsigned char *img) {

	unsigned char **tempImg = new unsigned char *[imgHeight];
	for(int i = 0; i<imgHeight; i++)
		tempImg[i] = new unsigned char [imgWidth];

	for(int i = 0; i<imgHeight; i++) {
		for(int j = 0; j< imgWidth; j++) {
			if(img[i*imgWidth + j] >= 220)
				tempImg[i][j] = 0;
			else
				tempImg[i][j] = 1;
		}
	}

	return tempImg;
}


//*****************************************************************************************************

unsigned char imageProcesAlgo::bitPattern(unsigned char **img, int row, int column) {

	unsigned char  neighbour[8] = {0}, mask = 0b10000000;
	unsigned char bitPattern = 0b00000000;

	neighbour[0] = img[row][column + 1];
	neighbour[1] = img[row - 1][column + 1];
	neighbour[2] = img[row - 1][column];
	neighbour[3] = img[row - 1][column - 1];
	neighbour[4] = img[row][column - 1];
	neighbour[5] = img[row + 1][column - 1];
	neighbour[6] = img[row + 1][column];
	neighbour[7] = img[row + 1][column + 1];

	for(int i = 0; i<8; i++) {
		if(neighbour[i] == 1){
			bitPattern = bitPattern | mask;
			mask = mask >> 1;
		}
		else
            mask = mask >> 1;
	}

	return bitPattern;
}

//*****************************************************************************************************

unsigned char **imageProcesAlgo::padImage(unsigned char **img) {


	int newImgHeight = imgHeight + 2;
	int newImgWidth = imgWidth  + 2;

	unsigned char **padImg = new unsigned char *[newImgHeight];
	for(int i = 0; i<newImgHeight; i++)
		padImg[i] = new unsigned char [newImgWidth];

    for(int i = 0; i<imgHeight; i++) {
		for(int j = 0; j<imgWidth; j++ ) {
         padImg[0][j] = 0;
         padImg[i + 1][j + 1] = img[i][j];
         padImg[imgHeight + 1][j] = 0;
		}
		padImg[i][0] = 0;
		padImg[i][imgWidth + 1] = 0;
    }

	return padImg;

}
//*****************************************************************************************************


unsigned char imageProcesAlgo::matchUnconditionalMask(unsigned char inputPattern) {

	int temp = 0;

	unsigned char patterns1[28] = {
                                    0b01000000, 0b00010000, // Spur
                                    0b00000010, 0b10000000, // Single 4-connection
                                    0b11000000, 0b01100000, 0b00110000, 0b00011000,
                                    0b00001100, 0b00000110, 0b00000011, 0b10000001, // L cluster
                                    0b01101000, 0b10110000, 0b10100001, 0b11000010, // 4-Connected offset

                                    0b01100100, 0b00011001, 0b01001100, 0b00010011,
                                    0b11000100, 0b00110001, 0b01000110, 0b10010001,
                                    0b11100100, 0b00111001, 0b01001110, 0b10010011 // Spur Corner Cluster
                                 };

	unsigned char patterns2[41] = {
                                    0b00111000, // Corner Cluster
                                    0b10101000, 0b10101000, 0b10001010, 0b10001010,
                                    0b00101010, 0b00101010, 0b10100010, 0b10100010, //Tee branch

									0b01010001, 0b00010101, 0b00010101, 0b01000101,
    								0b01010010, 0b01010100, 0b00100101, 0b01001001,
    								0b01010011, 0b01010101, 0b00110101, 0b01001101,
    								0b01010100, 0b10010100, 0b01000101, 0b01010001,
    								0b01010101, 0b10010101, 0b01010101, 0b01010101,
    								0b01010110, 0b11010100, 0b01100101, 0b01011001,
    								0b01010111, 0b11010101, 0b01110101, 0b01011101, // Vee branch

                                    0b10100100, 0b00101001, 0b01001010, 0b10010010  // Diagonal branch
                                   };

	unsigned char elimination[41] = {
                                    0b00111000, // Corner Cluster
                                    0b11101011, 0b10111110, 0b10111110, 0b11101011,
                                    0b10101111, 0b11111010, 0b11111010, 0b10101111, //Tee branch

									0b01010111, 0b11010101, 0b01110101, 0b01011101,
    								0b01010111, 0b11010101, 0b01110101, 0b01011101,
    								0b01010111, 0b11010101, 0b01110101, 0b01011101,
    								0b01010111, 0b11010101, 0b01110101, 0b01011101,
    								0b01010111, 0b11010101, 0b01110101, 0b01011101,
    								0b01010111, 0b11010101, 0b01110101, 0b01011101,
    								0b01010111, 0b11010101, 0b01110101, 0b01011101, // Vee branch

                                 	0b11101110, 0b10111011, 0b11101110, 0b10111011 // Diagonal branch
								};

	for (int i = 0; i<28; i++) {
		if(inputPattern == patterns1[i])
			temp = 1;
		}

	for(int i = 0; i<41; i++) {
		unsigned tempPattern = inputPattern & elimination[i];
		if(tempPattern == patterns2[i])
			temp = 1;
	}

	if (temp == 1)
		return 1;
	else
		return 0;

}

//*****************************************************************************************************

unsigned char imageProcesAlgo::matchUnconditionalMaskSkeleton(unsigned char inputPattern) {

	int temp = 0;
	unsigned char patterns1[12] = {
									0b00000001, 0b00000100, 0b01000000, 0b00010000, //Spur
    								0b00000010, 0b10000000, 0b00001000, 0b00100000, //Single 4 connection
    								0b10100000, 0b00101000, 0b10000010, 0b00001010 //L corner
								  };

	unsigned char patterns2[38] = {
    								0b00111000, 0b10000011, // Corner cluster
    								0b10101000, 0b00101010, 0b10001010, 0b10100010, //Tee Branch

								    0b01010001, 0b00010101, 0b00010101, 0b01000101,
    								0b01010010, 0b01010100, 0b00100101, 0b01001001,
    								0b01010011, 0b01010101, 0b00110101, 0b01001101,
    								0b01010100, 0b10010100, 0b01000101, 0b01010001,
    								0b01010101, 0b10010101, 0b01010101, 0b01010101,
    								0b01010110, 0b11010100, 0b01100101, 0b01011001,
    								0b01010111, 0b11010101, 0b01110101, 0b01011101, //Vee branch

									0b10100100, 0b00101001, 0b01001010, 0b10010010 //Diagonal
								  };

	unsigned char elimination[38] = {
									0b00111000, 0b10000011, // Corner cluster
    								0b10101000, 0b00101010, 0b10001010, 0b10100010,  //Tee Branch

    								0b01010111, 0b11010101, 0b01110101, 0b01011101,
   									0b01010111, 0b11010101, 0b01110101, 0b01011101,
    								0b01010111, 0b11010101, 0b01110101, 0b01011101,
    								0b01010111, 0b11010101, 0b01110101, 0b01011101,
    								0b01010111, 0b11010101, 0b01110101, 0b01011101,
    								0b01010111, 0b11010101, 0b01110101, 0b01011101,
    								0b01010111, 0b11010101, 0b01110101, 0b01011101, //Vee branch

    								0b11101110, 0b10111011, 0b11101110, 0b10111011  //Diagonal
								  };

	for (int i = 0; i<12; i++) {
		if(inputPattern == patterns1[i])
			temp = 1;
		}

	for(int i = 0; i<38; i++) {
		unsigned tempPattern = inputPattern & elimination[i];
		if(tempPattern == patterns2[i])
			temp = 1;
	}

	if (temp == 1)
		return 1;
	else
		return 0;
}

//*****************************************************************************************************


void imageProcesAlgo::shrinking(unsigned char *img, char name[]) {

	int h1 = this->imgHeight;
    int w1 = this->imgWidth;

	imageProcesAlgo temp1;
	temp1.setDimensions(w1, h1);

	unsigned char **binary = temp1.binaryIntensity(img);
	//unsigned char **binary = temp1.reverseBinaryIntensity(img);
	unsigned char *finalImage = new unsigned char[w1 * h1];

	int countStars = 0, starSizeTemp[14] = {0}, starSize[14] = {0};


	for (int k = 0; k<13; k++) {

		int temp = 0;
		unsigned char **padImg = temp1.padImage(binary);

        unsigned char **middleStage1 = new unsigned char *[imgHeight];
        for(int i = 0; i<imgHeight; i++)
            middleStage1[i] = new unsigned char [imgWidth];

        for(int i = 0; i < h1; i++){
            for(int j = 0; j < w1; j++)
            	middleStage1[i][j] = 0;
        }

        for(int i = 0; i<imgHeight; i++) {
            for(int j = 0; j<imgWidth; j++) {
                if( padImg[i+1][j+1] == 1) {
                    unsigned char inputBitPattern = temp1.bitPattern(padImg, i+1, j+1);
                    middleStage1[i][j] = temp1.matchConditionalMask(inputBitPattern, 1);
                }
            }
        }

        unsigned char **middleStage2 = temp1.padImage(middleStage1);

        for(int i = 0; i<imgHeight; i++) {
            for(int j = 0; j<imgWidth; j++) {
                if( middleStage2[i+1][j+1] == 1) {
                    unsigned char inputBitPattern = temp1.bitPattern(middleStage2, i+1, j+1);
                    binary[i][j] = temp1.matchUnconditionalMask(inputBitPattern);
                }
            }
        }

        for(int i = 0; i< imgHeight; i++)
            delete[] middleStage1[i];
        delete[] middleStage1;

        for(int i = 0; i< (imgHeight + 2); i++) {
        	delete[] middleStage2[i];
        	delete[] padImg[i];
        }
        delete[] middleStage2;
        delete[] padImg;

        for(int i = 0; i<imgHeight; i++) {
        	for(int j = 0; j<imgWidth; j++)
            	finalImage[i*imgWidth + j] = binary[i][j] * 255;
    	}

    	for(int i = 1; i<imgHeight - 1; i++) {
            for(int j = 1; j<imgWidth - 1; j++) {
                if(binary[i][j] == 1){
                    unsigned char inputBitPattern2 = temp1.bitPattern(binary, i, j);
                    if (inputBitPattern2 == 0b00000000)
                        temp = temp + 1;
                }
            }
        }
        //cout << temp << endl;
        starSizeTemp[k] = temp;

	}

	for(int i = 0; i<(imgHeight*imgWidth); i++) {
        if(finalImage[i] == 255)
            countStars = countStars + 1;
	}

	temp1.saveImage(finalImage, name, 1);
	delete[] binary;
	delete[] finalImage;

	cout << "Total Number of Stars: " << countStars << "\n\n";
    starSize[0] = starSizeTemp[0];
    //cout << starSize[0] << endl;
	for(int i = 1; i<13; i++) {
		starSize[i] = starSizeTemp[i] - starSizeTemp[i - 1];
		//cout << starSize[i] << endl;
	}

	for(int i = 0; i<13; i++) {
        cout << "Number of Stars of size " << (i + 1) << ": ";
        //cout << starSize[i] << endl;
		for(int j = 0; j<(starSize[i]); j++)
			cout << "*";
		cout << endl;
	}


}


//*****************************************************************************************************


void imageProcesAlgo::skeletonizing(unsigned char *img, char name[]) {


	int h1 = this->imgHeight;
    int w1 = this->imgWidth;

	imageProcesAlgo temp1;
	temp1.setDimensions(w1, h1);

	unsigned char **binary = temp1.reverseBinaryIntensity(img);
	unsigned char *finalImage = new unsigned char[w1 * h1];

	for (int k = 0; k<14; k++) {

		int temp = 0;
		unsigned char **padImg = temp1.padImage(binary);

        unsigned char **middleStage1 = new unsigned char *[imgHeight];
        for(int i = 0; i<imgHeight; i++)
            middleStage1[i] = new unsigned char [imgWidth];

        for(int i = 0; i < h1; i++){
            for(int j = 0; j < w1; j++)
            	middleStage1[i][j] = 0;
        }

        for(int i = 0; i<imgHeight; i++) {
            for(int j = 0; j<imgWidth; j++) {
                if( padImg[i+1][j+1] == 1) {
                    unsigned char inputBitPattern = temp1.bitPattern(padImg, i+1, j+1);
                    middleStage1[i][j] = temp1.matchConditionalMask(inputBitPattern, 3);
                }
            }
        }

        unsigned char **middleStage2 = temp1.padImage(middleStage1);

        for(int i = 0; i<imgHeight; i++) {
            for(int j = 0; j<imgWidth; j++) {
                if( middleStage2[i+1][j+1] == 1) {
                    unsigned char inputBitPattern = temp1.bitPattern(middleStage2, i+1, j+1);
                    binary[i][j] = temp1.matchUnconditionalMaskSkeleton(inputBitPattern);
                }
            }
        }

        for(int i = 0; i< imgHeight; i++)
            delete[] middleStage1[i];
        delete[] middleStage1;

        for(int i = 0; i< (imgHeight + 2); i++) {
        	delete[] middleStage2[i];
        	delete[] padImg[i];
        }
        delete[] middleStage2;
        delete[] padImg;

        for(int i = 0; i<imgHeight; i++) {
        	for(int j = 0; j<imgWidth; j++)
        		if(binary[i][j] == 0)
            		finalImage[i*imgWidth + j] = 255;
            	else
            		finalImage[i*imgWidth + j] = 0;
    	}
	}

	temp1.saveImage(finalImage, name, 1);
	delete[] binary;
	delete[] finalImage;
}

//*****************************************************************************************************


void imageProcesAlgo::thinning(unsigned char *img, char name[]) {


	int h1 = this->imgHeight;
    int w1 = this->imgWidth;

	imageProcesAlgo temp1;
	temp1.setDimensions(w1, h1);

	unsigned char **binary = temp1.reverseBinaryIntensity(img);
	unsigned char *finalImage = new unsigned char[w1 * h1];

	for (int k = 0; k<16; k++) {

		int temp = 0;
		unsigned char **padImg = temp1.padImage(binary);

        unsigned char **middleStage1 = new unsigned char *[imgHeight];
        for(int i = 0; i<imgHeight; i++)
            middleStage1[i] = new unsigned char [imgWidth];

        for(int i = 0; i < h1; i++){
            for(int j = 0; j < w1; j++)
            	middleStage1[i][j] = 0;
        }

        for(int i = 0; i<imgHeight; i++) {
            for(int j = 0; j<imgWidth; j++) {
                if( padImg[i+1][j+1] == 1) {
                    unsigned char inputBitPattern = temp1.bitPattern(padImg, i+1, j+1);
                    middleStage1[i][j] = temp1.matchConditionalMask(inputBitPattern, 2);
                }
            }
        }

        unsigned char **middleStage2 = temp1.padImage(middleStage1);

        for(int i = 0; i<imgHeight; i++) {
            for(int j = 0; j<imgWidth; j++) {
                if( middleStage2[i+1][j+1] == 1) {
                    unsigned char inputBitPattern = temp1.bitPattern(middleStage2, i+1, j+1);
                    binary[i][j] = temp1.matchUnconditionalMask(inputBitPattern);
                }
            }
        }

        for(int i = 0; i< imgHeight; i++)
            delete[] middleStage1[i];
        delete[] middleStage1;

        for(int i = 0; i< (imgHeight + 2); i++) {
        	delete[] middleStage2[i];
        	delete[] padImg[i];
        }
        delete[] middleStage2;
        delete[] padImg;

        for(int i = 0; i<imgHeight; i++) {
        	for(int j = 0; j<imgWidth; j++)
            	if(binary[i][j] == 0)
            		finalImage[i*imgWidth + j] = 255;
            	else
            		finalImage[i*imgWidth + j] = 0;
    	}

    }

    temp1.saveImage(finalImage, name, 1);
	delete[] binary;
	delete[] finalImage;

}

//*****************************************************************************************************
