//***********************************************************************
// EE569 Homework 1, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 2a
// Submission Date: 4th February, 2016
//***********************************************************************

#include "imageProcesAlgo.h"

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



 void imageProcesAlgo::imgHistData(unsigned char *plane, char name[]) {

	map<unsigned char, int> temp;

	int Size = imgHeight * imgWidth;

	for(int j = 0; j<256; j++){
            unsigned char k = j;
			temp[k] = 0;
		}

	for(int i =0; i<Size; i++) {
		for(int j = 0; j<256; j++) {
            unsigned char k = j;
			if(plane[i] == k)
				temp[k] = temp[k] + 1;
		}
	}

	ofstream histFile(name);

      for(int i = 0; i<256; i++){
        unsigned char k = i;
      	histFile << int(k) << "," << temp[k] << endl;
      	//cout << int(k) << endl;
      }
    histFile.close();

      //return temp;
}



//***************************************************************************************



 map<unsigned char, int> imageProcesAlgo::imgHistData(unsigned char *plane, char name[], int dummy) {

	map<unsigned char, int> temp;

	int Size = imgHeight * imgWidth;

	for(int j = 0; j<256; j++){
            unsigned char k = j;
			temp[k] = 0;
		}

    //cout << "Flag 2" << endl;
	for(int i =0; i<Size; i++) {
		for(int j = 0; j<256; j++) {
            unsigned char k = j;
			if(plane[i] == k)
				temp[k] = temp[k] + 1;
		}
	}

	//cout << "Flag 3" << endl;

	ofstream histFile(name);

      for(int i = 0; i<256; i++){
        unsigned char k = i;
      	histFile << int(k) << "," << temp[k] << endl;
      	//cout << int(k) << endl;
      }
      histFile.close();

      return temp;
}



//************************************************************************************************************




void imageProcesAlgo::histEq1(unsigned char *img) { // Transfer function (CDF) method

	int h1 = this->imgHeight;
    int w1 = this->imgWidth;

	imageProcesAlgo temp1;
	temp1.setDimensions(h1, w1);

	int Size = (h1 * w1);

	unsigned char *plane1 = temp1.separatePlanes(img, 1);
	unsigned char *plane2 = temp1.separatePlanes(img, 2);
	unsigned char *plane3 = temp1.separatePlanes(img, 3);

	map<unsigned char, int> planeMap1 = temp1.imgHistData(plane1, "originalHist1.csv", 1);
	map<unsigned char, int> planeMap2 = temp1.imgHistData(plane2, "originalHist2.csv", 1);
	map<unsigned char, int> planeMap3 = temp1.imgHistData(plane3, "originalHist3.csv", 1);

	unsigned char *eqImage = new unsigned char[imgWidth*imgHeight*3];

	map<unsigned char, double> planeProbMap1, planeProbMap2, planeProbMap3;
	map<unsigned char, double> planeProbMap1_1, planeProbMap2_2, planeProbMap3_3;
	map<unsigned char, unsigned char> planeNewMap1, planeNewMap2, planeNewMap3;

    cout << "\n\n";

	for(int i = 0; i<256; i++) {
		unsigned char k = i;
		planeProbMap1[k] = double(planeMap1[k]) / Size;
		planeProbMap2[k] = double(planeMap2[k]) / Size;
		planeProbMap3[k] = double(planeMap3[k]) / Size;
		//cout << planeProbMap1[k]<< endl;
	}


	for(int i = 0; i<256; i++) {
		unsigned char i1 = i;
		for(int j = 0; j<=i; j++) { //Calculating cumulative probability
			unsigned char j1 = j;
			planeProbMap1_1[i1] = planeProbMap1_1[i1] + planeProbMap1[j1];
			planeProbMap2_2[i1] = planeProbMap2_2[i1] + planeProbMap2[j1];
			planeProbMap3_3[i1] = planeProbMap3_3[i1] + planeProbMap3[j1];

		}
		//cout << planeProbMap1_1[i1] << endl;
	}


	for(int i = 0; i<256; i++) {
        unsigned char i1 = i;
		planeNewMap1[i1] = int(floor(planeProbMap1_1[i1] * 255));
		planeNewMap2[i1] = int(floor(planeProbMap2_2[i1] * 255));
		planeNewMap3[i1] = int(floor(planeProbMap3_3[i1] * 255));
		//cout << int(planeNewMap1[i1]) << endl;
	}


	for(int l = 0; l<256; l++) {
		unsigned char k = l;
		for(int i = 0; i<imgHeight; i++) {
			for(int j = 0; j<imgWidth; j++) {
				if(plane1[i * imgWidth + j] == k)
					eqImage[i * imgWidth* 3 + j*3] = planeNewMap1[k];
				if(plane2[i * imgWidth + j] == k)
					eqImage[i * imgWidth * 3 + j * 3 + 1] = planeNewMap2[k];
				if(plane3[i * imgWidth + j] == k)
					eqImage[i * imgWidth * 3 + j * 3 + 2] = planeNewMap3[k];

			}
		}
	}

    unsigned char *newPlane1 = temp1.separatePlanes(eqImage, 1);
	unsigned char *newPlane2 = temp1.separatePlanes(eqImage, 2);
	unsigned char *newPlane3 = temp1.separatePlanes(eqImage, 3);


	temp1.imgHistData(newPlane1, "Hist_Method1_plane1.csv");
	temp1.imgHistData(newPlane2, "Hist_Method1_plane2.csv");
	temp1.imgHistData(newPlane3, "Hist_Method1_plane3.csv");


	temp1.saveImage(eqImage, "HistEqualizedImg_Method1.raw", 3);

	temp1.freeMemory(eqImage);
	temp1.freeMemory(newPlane1);
	temp1.freeMemory(newPlane2);
	temp1.freeMemory(newPlane3);
	temp1.freeMemory(plane1);
	temp1.freeMemory(plane2);
	temp1.freeMemory(plane3);


}


//*****************************************************************************************************




void imageProcesAlgo::histEq2(unsigned char *img) {   // Bucket Fill Algorithm


    int h1 = this->imgHeight;
    int w1 = this->imgWidth;

	imageProcesAlgo temp1;
	temp1.setDimensions(h1, w1);

	int n = ceil ((double(imgHeight * imgWidth)) / 256 );

	//cout << "n= " << n << endl;

	unsigned char *eqImage = new unsigned char[imgWidth*imgHeight*3];

	for(int i = 0; i<imgHeight; i++) {
		for(int j = 0; j<imgWidth; j++) {
			eqImage[i*imgWidth*3 + j*3] = img[i*imgWidth*3 + j*3];
			eqImage[i*imgWidth*3 + j*3 + 1] = img[i*imgWidth*3 + j*3 + 1];
			eqImage[i*imgWidth*3 + j*3 + 2] = img[i*imgWidth*3 +j*3 + 2];
		}
	}

	multimap<unsigned char, int> theMap1, theMap2, theMap3;
	unsigned char f1, f2, f3;

	//cout << "Flag 2" << endl;

	for(int i = 0; i<imgHeight; i++) {
		for(int j = 0; j<imgWidth; j++) {
				f1 = img[i*imgWidth*3 + j*3 ];
				f2 = img[i*imgWidth*3 + j*3 + 1];
				f3 = img[i*imgWidth*3 + j*3 + 2];
				theMap1.insert(make_pair(f1, (i*imgWidth*3 + j*3 )));
				theMap2.insert(make_pair(f2, (i*imgWidth*3 + j*3 + 1)));
				theMap3.insert(make_pair(f3, (i*imgWidth*3 + j*3 + 2)));
			}
		}


	//cout << "Flag 3" << endl;

	multimap<unsigned char, int> :: iterator it;
		unsigned char t1 = 0, t2 = 0, t3 = 0;
		int y, c1, c2, c3;
    	for (it = theMap1.begin(); it!= theMap1.end(); ++it,++c1) {
            if(c1%n == 0)
                t1 = t1+1;
            y = (*it).second;
            eqImage[y] = t1;
    	}

    	for (it = theMap2.begin(); it!= theMap2.end(); it++,++c2) {
            if(c2%n == 0)
                t2 = t2 + 1;
            y = (*it).second;
            eqImage[y] = t2;
    	}

    	for (it = theMap3.begin(); it!= theMap3.end(); it++,++c1) {
            if(c1%n == 0)
                t3 = t3 + 1;
            y = (*it).second;
            eqImage[y] = t3;
    	}


    //cout << "Flag 4" << endl;

    unsigned char *newPlane1 = temp1.separatePlanes(eqImage, 1);
	unsigned char *newPlane2 = temp1.separatePlanes(eqImage, 2);
	unsigned char *newPlane3 = temp1.separatePlanes(eqImage, 3);


	temp1.imgHistData(newPlane1, "Hist_Method2_plane1.csv");
	temp1.imgHistData(newPlane2, "Hist_Method2_plane2.csv");
	temp1.imgHistData(newPlane3, "Hist_Method2_plane3.csv");

	temp1.transferFunc(newPlane1, "Cumulative_Method2_plane1.csv");
	temp1.transferFunc(newPlane2, "Cumulative_Method2_plane2.csv");
	temp1.transferFunc(newPlane3, "Cumulative_Method2_plane3.csv");

	temp1.saveImage(eqImage, "HistEqualizedImg_Method2.raw", 3);

	temp1.freeMemory(eqImage);
	temp1.freeMemory(newPlane1);
	temp1.freeMemory(newPlane2);
	temp1.freeMemory(newPlane3);



}




//*******************************************************************************************





void imageProcesAlgo::transferFunc(unsigned char *plane, char name[]) {


    int h1 = this->imgHeight;
    int w1 = this->imgWidth;

	imageProcesAlgo temp1;
	temp1.setDimensions(h1, w1);

	map<unsigned char, double> temp;

	int Size = imgHeight * imgWidth;

	for(int j = 0; j<256; j++){
            unsigned char k = j;
			temp[k] = 0;
		}

	for(int i =0; i<Size; i++) {
		for(int j = 0; j<256; j++) {
            unsigned char k = j;
			if(plane[i] == k)
				temp[k] = temp[k] + 1;
		}
	}

	for(int j = 0; j<256; j++) {
            unsigned char k = j;
            temp[k] = (double(temp[k])/(double(imgHeight*imgWidth)))*255;
		}

	double sum[256];
    for(int i = 0; i<256; i++){
        sum[i] = 0;
    }

	ofstream histFile(name);
      sum[0] = temp[0];
      histFile << 0 << "," << int((sum[0])) << endl;
      for(int i = 1; i<256; i++){
        unsigned char k = i;
        sum[i] = sum[i-1] + temp[k];
      	//histFile << int(k) << "," << int(((double(sum))/(double(imgHeight*imgWidth)))*255) << endl;
      	histFile << int(k) << "," << int((sum[i])) << endl;
      	//cout << int(k) << endl;
      }
    histFile.close();

}


//*******************************************************************************************

