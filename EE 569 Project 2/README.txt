//***********************************************************************
// EE569 Homework 1, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// All code tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Submission Date: 4th March, 2016
//***********************************************************************


This is the README file for Homework 2

(All the images required for the programs have been placed in the respective folders)

-------------------------------Question 1a------------------------------------------
In the Question 1 folder, compile all the files and run the Question_1a.cpp file with the following arguments:
program_name input_image.raw circle_image.raw square_image.raw [ImgWidth = 256] [ImgHeight = 256]

input_image_name.raw  --- name of the input image
circle_image.raw      --- name to be assigned to the circlular warped image
square_image.raw      --- name to be assigned to the reverse square warped image
[ImgWidth = 256]      --- Width of the image
[ImgHeight = 256]     --- Height of the image

e.g, panda.raw CircleWarpPanda.raw ReverseSquareWarp_Panda.raw 512 512

The images required to be placed in this folder are:
 puppy.raw, panda.raw, tiger.raw



------------------------------Question 1b------------------------------------------
In the Question 1b folder, compile all the files and run the Question_1b.cpp file with the following arguments:
program_name left.raw middle.raw right.raw output.raw [ImgWidth = 256] [ImgHeight = 256]

left.raw            --- name of the input image
middle.raw          --- name to be assigned to the circlular warped image
right.raw           --- name to be assigned to the reverse square warped image
output.raw          --- name to be assigned to the output stitched image
[ImgWidth = 256]    --- Width of the image
[ImgHeight = 256]   --- Height of the image

e.g, left.raw middle.raw right.raw final_stitch.raw 480 640

The images required to be placed in this folder are:
left.raw middle.raw right.raw



------------------------------Question 2a-------------------------------------------
In the Question 2b folder, compile all the files and run the Question_2b.cpp file with the following arguments:

program_name input_image.raw fixedthresh.raw randThresh.raw dither.raw FourLevel.raw [ImgWidth = 256] [ImgHeight = 256] [Threshold = 127] [order = 8]
 
 where,
 input_image.raw   --- name of the input image
 fixedthresh.raw   --- name to be assigned to the fixed thresholding output image
 randThresh.raw    --- name to be assigned to the random thresholding output image
 dither.raw        --- name to be assigned to the ordered dithered image
 FourLevel.raw     --- name to be assigned to the four-level dithered output image
 [ImgWidth = 256]  --- Width of the image
 [ImgHeight = 256] --- Height of the image
 [Threshold = 127] --- Threshold intensity level
 [Order = 8]       --- Order of the Bayer Matrix (Acceptable values are 2, 4, 8)

e.g, colorchecker.raw colorcheckerFixedThresh.raw colorcheckerRandThresh.raw colorchecker_dither_8.raw Fourcolorchecker_dither_8.raw 512 512 127 8

The images required to be placed in this folder are:
colorchecker.raw


------------------------------Question 2b-------------------------------------------
In the Question 2b folder, compile all the files and run the Question_2b.cpp file with the following arguments:

program_name input_image.raw output.raw [ImgWidth = 256] [ImgHeight = 256] [Threshold = 127] [dithering = 1]

where,
input_image.raw   --- name of the input image
fixedthresh.raw   --- name to be assigned to the output image
[ImgWidth = 256]  --- Width of the image
[ImgHeight = 256] --- Height of the image
[dithering]       --- Error diffusion technique to be selected
			Available values are:
			1-> Floyd Steinberg algorithm with normal scanning
                        2-> Floyd Steinberg algorithm with serpentine scanning
                        3-> Jarvis, Judice and Ninke algorithm
                        4-> Stucki algorithm

e.g, colorchecker.raw FS_output.raw 512 512 127 1

The images required to be placed in this folder are:
colorchecker.raw



------------------------------Question 2c-------------------------------------------
In the Question 2c folder, compile all the files and run the Question_2c.cpp file with the following arguments:

program_name input_image.raw output.raw [ImgWidth = 256] [ImgHeight = 256] [Threshold intensity colour image(for each channel)] [ Options = 1]


where,
input_image.raw       --- name of the input image
output.raw            --- name to be assigned to the output image
[ImgWidth = 256]      --- Width of the image
[ImgHeight = 256]     --- Height of the image
[Threshold intensity] --- Threshold intensity for each channel
[Options]             --- Type of colour halftoning technique to be used
			  Available option are:
                           1-> Separable Error Diffusion
                           2-> MBVQ-based Error diffusion

e.g, flower.raw Separable_flower.raw 700 700 220 250 127 1

The images required to be placed in this folder are:
flower.raw


------------------------------Question 3 a,b,c-------------------------------------------
In the Question 3a folder, compile all the files and run the Question_3a_b_c.cpp file with the following arguments:

program_name input_image.raw output_image.raw [ImgWidth = 256] [ImgHeight = 256] [Operation]

where,
input_image.raw       --- name of the input image
output.raw            --- name to be assigned to the output image
[ImgWidth = 256]      --- Width of the image
[ImgHeight = 256]     --- Height of the image
[operation]           --- Morphological operation to be performed
                            1 -> shrinking and counting
                            2 -> thinning
                            3 -> skeletonizing

e.g, stars.raw stars_final 640 480 1

The images required to be placed in this folder are:
stars.raw, jigsaw_1.raw, jigsaw_2.raw


------------------------------Question 3d-------------------------------------------
In the Question 3a_b_c folder, compile all the files and run the Question_3a.cpp file with the following arguments:

program_name input_image.raw output.raw [ImgWidth = 256] [ImgHeight = 256]

where,
input_image.raw       --- name of the input image
output.raw            --- name to be assigned to the output image
[ImgWidth = 256]      --- Width of the image
[ImgHeight = 256]     --- Height of the image

e.g, board.raw output_image 372 372

The images required to be placed in this folder are:
board.raw

---------------------------------------------------------------------------------------


