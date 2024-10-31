# TO USE:
# In the terminal in the directory with your make file
# Type "make" to build the executable
# Type "make run" to run the executable
# Type "make clean" to remove the executable

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall

# Includes

# YOU NEED TO UPDATE THESE
INCLUDES = -I "C:\Users\liver\Documents\CSC_1300\Labs\Lab8\curl-8.6.0_3-win64-mingw\include" \
		   -I "C:\Users\liver\Documents\CSC_1300\Labs\Lab8\json\include"

# Library directories
LDFLAGS = -L "C:\Users\liver\Documents\CSC_1300\Labs\Lab8\curl-8.6.0_3-win64-mingw\lib"

# Libraries
LIBS = -lcurl

# Source files
SRCS = lab8.cpp

# Executable
TARGET = lab8_run

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) $(INCLUDES) $(LIBS) $(LDFLAGS) -o $(TARGET)

# Run
run: 
	lab8_run

# Clean
clean:
	del $(TARGET)