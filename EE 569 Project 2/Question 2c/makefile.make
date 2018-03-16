
#Macros
OBJS = Question_2b.o imageBasicOps.o imageProcesAlgo.o
cc = g++
DEBUG = -g
CFLAGS = -c
OUTPUTFOLDERS = p3_2b_output

# List of Arguments
ARGS1 = ee569_hw2_images/colorchecker.raw FS_dither_normal.raw 512 512 127 1
ARGS2 = ee569_hw2_images/colorchecker.raw FS_dither_serpentine.raw 512 512 127 2
ARGS3 = ee569_hw2_images/colorchecker.raw JJN_dither.raw 512 512 127 3
ARGS4 = ee569_hw2_images/colorchecker.raw Stucki_dither.raw 512 512 127 4

# Code execution and running
all: Question_2b_exe run

Question_2b_exe: $(OBJS)
	@echo "Linking the code"
	$(cc) $(OBJS) -o Question_2b_exe

Question_2b.o: Question_2b.cpp
	@echo "Compiling Question_2b.cpp in progress"
	$(cc) $(CFLAGS) Question_2b.cpp

imageBasicOps.o: imageBasicOps.h imageBasicOps.cpp
	$(cc) $(CFLAGS) imageBasicOps.cpp

imageProcesAlgo.o: imageProcesAlgo.h imageProcesAlgo.cpp
	$(cc) $(CFLAGS) imageProcesAlgo.cpp

clean:
	@echo "Cleaning folder by deleting object and executable files"
	rm -rf $(OUTPUTFOLDERS)
	rm -rf *.o Question_2b_exe  *.raw *.out


run:
	@echo "Deleting all output folders"
	rm -rf $(OUTPUTFOLDERS)
	@echo "Running the executable files"
	mkdir $(OUTPUTFOLDERS)
	./Question_2b_exe $(ARGS1)
	./Question_2b_exe $(ARGS2)
	./Question_2b_exe $(ARGS3)
	./Question_2b_exe $(ARGS4)