VERSION = alpha
CXXFLAGS=-g -std=c++0x -Wall -pedantic
#PATHTOSFML=/usr/local/SFML-2.2
PATHTOSFML=
EXEC=KeyboardDash

all : KeyboardDash

KeyboardDash : main.o 
	g++ *.o -o ${EXEC}_${VERSION} -L${PATHTOSFML}/lib -lsfml-system -lsfml-graphics -lsfml-network -lsfml-audio -lsfml-window
	rm *.o

*.o : *.cpp
	g++ -c *.cpp 

clean :
	rm -f *.o
	rm -f ${EXEC}_${VERSION}
