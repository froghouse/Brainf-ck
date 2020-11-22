# Define project with parameters
compiler = g++-10
cpp_ver = -std=c++2a
optimize = -O3
project = bf
libs = 
includes = 
compiler_line = $(compiler) $(cpp_ver) $(optimize) $(libs) $(includes)

main.o: main.cpp
	$(compiler_line) -c main.cpp

bf.o: bf.cpp
	$(compiler_line) -c bf.cpp

all: main.o bf.o
	$(compiler) -o $(project) main.o bf.o

clean:
	rm $(project) *.o
