CC=g++
CFLAGS=-lcrypt -lm -O2 -std=c++11 -pipe -DONLINE_JUDGE -Wall -Wextra -g
SRC=$(wildcard *.cpp)
BIN=$(patsubst %.cpp, %, $(SRC))
all:
	echo Compiling ${SRC}
	${CC} ${CFLAGS} ${SRC} -o ${BIN}
