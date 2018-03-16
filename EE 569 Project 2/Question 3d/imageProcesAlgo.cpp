//***********************************************************************
// EE569 Homework 2, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 3d
// Submission Date: 4th March, 2018
//***********************************************************************

#include "imageProcesAlgo.h"

unsigned char **imageProcesAlgo::binaryIntensity(unsigned char *img) {

	unsigned char **tempImg = new unsigned char *[imgHeight];
	for(int i = 0; i<imgHeight; i++)
		tempImg[i] = new unsigned char [imgWidth];

	for(int i = 0; i<imgHeight; i++) {
		for(int j = 0; j< imgWidth; j++) {
			if(img[i*imgWidth + j] >= 127)
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


int **imageProcesAlgo::FindTopLeftCorners(unsigned char **img) {

	int h1 = this->imgHeight;
    int w1 = this->imgWidth;

	imageProcesAlgo temp1;
	temp1.setDimensions(w1, h1);

	int **location = new int *[16];
	for(int i = 0; i<16; i++)
		location[i] = new int [2];

    for(int i = 0; i<16; i++) {
		location[i][0] = 0;
		location[i][1] = 0;
    }

	int count = 0;
	for(int i = 1; i<imgHeight-1; i++) {
		for(int j = 1; j<imgWidth-1; j++) {
			if(img[i][j] == 1) {
				unsigned char pattern = temp1.bitPattern(img, i, j);
				if(pattern == 0b10000011) {
					(location[count][0]) = i;
					(location[count][1]) = j;
					count = count + 1;
				}
			}
		}
	}

	return location;

}


//*****************************************************************************************************


int **imageProcesAlgo::FindTopRightCorners(unsigned char **img) {

	int h1 = this->imgHeight;
    int w1 = this->imgWidth;

	imageProcesAlgo temp1;
	temp1.setDimensions(w1, h1);

	int **location = new int *[16];
	for(int i = 0; i<16; i++)
		location[i] = new int [2];

	 for(int i = 0; i<16; i++) {
		location[i][0] = 0;
		location[i][1] = 0;
    }

	int count = 0;

	for(int i = 1; i<imgHeight-1; i++) {
		for(int j = 1; j<imgWidth-1; j++) {
			if(img[i][j] == 1) {
				unsigned char pattern = temp1.bitPattern(img, i, j);
				if(pattern == 0b00001110) {
					(location[count][0]) = i;
					(location[count][1]) = j;
					count = count + 1;
				}
			}
		}
	}

	return location;

}


//*****************************************************************************************************


int **imageProcesAlgo::FindBottomLeftCorners(unsigned char **img) {

    int h1 = this->imgHeight;
    int w1 = this->imgWidth;

	imageProcesAlgo temp1;
	temp1.setDimensions(w1, h1);

	int **location = new int *[20];
	for(int i = 0; i<20; i++)
		location[i] = new int [2];

	 for(int i = 0; i<20; i++) {
		location[i][0] = 0;
		location[i][1] = 0;
    }

	int count = 0;

	for(int i = 1; i<imgHeight-1; i++) {
		for(int j = 1; j<imgWidth-1; j++) {
			if(img[i][j] == 1) {
				unsigned char pattern = temp1.bitPattern(img, i, j);
				if(pattern == 0b11100000) {
					(location[count][0]) = i;
					(location[count][1]) = j;
					count = count + 1;
				}
			}
			//cout << "i: " << i << " j: " << j << endl;
		}
	}

	return location;
}


//*****************************************************************************************************



int **imageProcesAlgo::FindBottomRightCorners(unsigned char **img) {

	int h1 = this->imgHeight;
    int w1 = this->imgWidth;

	imageProcesAlgo temp1;
	temp1.setDimensions(w1, h1);

	int **location = new int *[16];
	for(int i = 0; i<16; i++)
		location[i] = new int [2];

	 for(int i = 0; i<16; i++) {
		location[i][0] = 0;
		location[i][1] = 0;
    }

	int count = 0;

	for(int i = 1; i<imgHeight-1; i++) {
		for(int j = 1; j<imgWidth-1; j++) {
			if(img[i][j] == 1) {
				unsigned char pattern = temp1.bitPattern(img, i, j);
				if(pattern == 0b00111000) {
					(location[count][0]) = i;
					(location[count][1]) = j;
					count = count + 1;
				}
			}
		}
	}

	return location;

}


//*****************************************************************************************************

void imageProcesAlgo::FindUniquePieces(unsigned char *imgData) {



	int h1 = this->imgHeight;
    int w1 = this->imgWidth;

	imageProcesAlgo temp1;
	temp1.setDimensions(w1, h1);
	int heads[16], holes[16], row = 0, col = 0, k, uniquePieces = 0, result;

	unsigned char **puzzleID = new unsigned char *[16];
	for(int i = 0; i<16; i++)
		puzzleID[i] = new unsigned char [4];

	unsigned char **binaryImg = temp1.binaryIntensity(imgData);

	for(int i = 0; i<16; i++){
		heads[i] = 0;
		holes[i] = 0;
	}

	int **topLeftCorners     = temp1.FindTopLeftCorners(binaryImg);
	int **topRightCorners    = temp1.FindTopRightCorners(binaryImg);
	int puzzleSize = topRightCorners[0][1] - topLeftCorners[0][1];

	for (k = 0; k<16; k++) {
		row = topLeftCorners[k][0];
		col = topLeftCorners[k][1];
		int t1 = 0, t2 = 0;
		if(binaryImg[row - 1][col + (puzzleSize/2)] == 1) { // Check Top edge
			puzzleID[k][0] = 1;
			t1 = t1 + 1;
		}
		else if(binaryImg[row][col + (puzzleSize/2)] == 0) {
			puzzleID[k][0] = 2;
			t2 = t2 + 1;
		}
		else if((binaryImg[row][col + (puzzleSize/2)] == 1) && (binaryImg[row - 1][col + (puzzleSize/2)] == 0))
			puzzleID[k][0] = 0;


		if(binaryImg[row + (puzzleSize/2)][col + puzzleSize + 1] == 1) { // Check right edge
			puzzleID[k][1] = 1;
			t1 = t1 + 1;
		}
		else if(binaryImg[row + (puzzleSize/2)][col + puzzleSize] == 0) {
			puzzleID[k][1] = 2;
			t2 = t2 + 1;
		}
		else if((binaryImg[row + (puzzleSize/2)][col + puzzleSize] == 1) && (binaryImg[row + (puzzleSize/2)][col + puzzleSize + 1] == 0))
			puzzleID[k][1] = 0;


		if(binaryImg[row + puzzleSize + 1][col + (puzzleSize/2)] == 1) { // Check bottom edge
			puzzleID[k][2] = 1;
			t1 = t1 + 1;
		}
		else if(binaryImg[row + puzzleSize][col + (puzzleSize/2)] == 0) {
			puzzleID[k][2] = 2;
			t2 = t2 + 1;
		}
		else if((binaryImg[row + puzzleSize + 1][col + (puzzleSize/2)] == 0) && (binaryImg[row + puzzleSize][col + (puzzleSize/2)] == 1))
			puzzleID[k][2] = 0;


		if(binaryImg[row + (puzzleSize/2)][col - 1] == 1) { // Check left edge
			puzzleID[k][3] = 1;
			t1 = t1 + 1;
		}
		else if(binaryImg[row + (puzzleSize/2)][col] == 0) {
			puzzleID[k][3] = 2;
			t2 = t2 + 1;
		}
		else if((binaryImg[row + (puzzleSize/2)][col] == 1) && (binaryImg[row + (puzzleSize/2)][col - 1] == 0))
			puzzleID[k][3] = 0;

		heads[k] = t1;
		holes[k] = t2;

	}

	/*for(int i = 0; i<16; i++) {
        cout << "Puzzle " << i+1 << endl;
		cout << "Holes: " << holes[i] << endl;
		cout << "Heads: " << heads[i] << endl;
		cout << int(puzzleID[i][0]) << " " << int(puzzleID[i][1]) << " " << int(puzzleID[i][2]) << " " << int(puzzleID[i][3]) <<"\n\n";
	}*/

	map<int, int> UniquePieceLUT;

	UniquePieceLUT[0] = 1;
	int uniqueID = 1;

	for(int i = 1; i<16; i++) {
        int flag = 0;
		for(int j = 0; j<i; j++) {

            if(holes[i] == holes[j] && heads[i] == heads[j]){
                vector<unsigned char> id1, id2, id2_mir;
                for(int k = 0; k<4; k++) {
                    id1.push_back(puzzleID[i][k]);
                    id2.push_back(puzzleID[j][k]);
                }
                id2_mir.push_back(puzzleID[j][2]);
                id2_mir.push_back(puzzleID[j][1]);
                id2_mir.push_back(puzzleID[j][0]);
                id2_mir.push_back(puzzleID[j][3]);

                result = temp1.ComparePuzzleID(id1, id2, id2_mir);
                if(result == 1){
                    UniquePieceLUT[i] = UniquePieceLUT[j];
                    //uniqueID = uniqueID + 1;
                    flag = 1;
                }
			}
        }
        if(flag == 0){
        uniqueID = uniqueID + 1;
        UniquePieceLUT[i] = uniqueID;
        }
    }

    cout << "Unique pieces: " << uniqueID << "\n\n";



    for(int i = 1; i<uniqueID + 1; i++){
        cout << "Category " << i << ": " ;
        for(int j = 0; j<16; j++){
            if(UniquePieceLUT[j] == i)
                cout << j+1 << ", ";
        }
        cout << "\n";
    }

	for(int i = 0; i< 16; i++) {
        delete[] topRightCorners[i];
        delete[] topLeftCorners[i];
    }
    delete[] topRightCorners;
    delete[] topLeftCorners;
}




//*****************************************************************************************************

int imageProcesAlgo::ComparePuzzleID(vector<unsigned char> id1,
	vector<unsigned char> id2, vector<unsigned char> id2_mir) {


    for(int i = 0; i<4; i++) {
        if((id1[0] == id2[0]) && (id1[1] == id2[1]) && (id1[2] == id2[2]) && (id1[3] == id2[3]))
            return 1; // This means the puzzle pieces match

        if((id1[0] == id2_mir[0]) && (id1[1] == id2_mir[1]) && (id1[2] == id2_mir[2]) && (id1[3] == id2_mir[3]))
            return 1; // This means the puzzle pieces match after mirroring

        rotate(id2.begin(),id2.begin()+1,id2.end());
        rotate(id2_mir.begin(),id2_mir.begin()+1,id2_mir.end());
    }
	return 0; ///This means the puzzle pieces don't match
}

//*****************************************************************************************************
