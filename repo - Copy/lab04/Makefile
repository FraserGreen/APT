.default: all

all: card

clean: rm -f card *.o

card: run.o Card.o Hand.o

	g++ -Wall -Werror -std=c++14 -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -O -c $^


