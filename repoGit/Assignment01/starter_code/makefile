.default: all

all: project

clean: rm -f project *.o

project: main.o Node.o NodeList.o PathSolver.o

	g++ -Wall -Werror -std=c++14 -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -O -c $^


