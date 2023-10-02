CXX := g++
STD := 11
CPPFLAGS := -Wall
INCLUDE := include
LIBDIR := lib
SOURCES := src/main.cpp makefile
EXECUTABLE := out/main

# OpenCV library flags and includes
OPENCV_LIBS := -lm -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc -lopencv_videoio -lopencv_objdetect
OPENCV_INCLUDE := -I/path/to/opencv_build/include
OPENCV_LIBDIR := -L/path/to/opencv_build/lib

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CXX) -std=c++$(STD) -o $@ $(CPPFLAGS) -I $(INCLUDE) -L$(LIBDIR) $(OPENCV_LIBS) src/main.cpp 

clean:
	rm -f $(EXECUTABLE)

.PHONY: clean