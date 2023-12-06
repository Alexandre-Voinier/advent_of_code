CC = g++
SOURCE = checkFile.cpp File.cpp Directory.cpp parser.cpp main.cpp
CFLAGS = -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -pedantic-errors -Werror -g -std=c++20

TARGET = day7

all: ${TARGET}

${TARGET}: ${SOURCE}
	${CC} ${CFLAGS} -o ${TARGET} ${SOURCE}

leak: ${TARGET}
	valgrind --leak-check=yes -s ./${TARGET} input.txt 

clean:
	${RM} ${TARGET}

