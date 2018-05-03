GOP: GOP.o GAME.o PLAYER.o TABLE.o CARD.o
    g++ -o GOP GOP.o PLAYER.o TABLE.o CARD.o

GOP.o: Source.cpp
    g++ -c Source.cpp

GAME.o: GAME.cpp GAME.h
    g++ -c GAME.cpp

PLAYER.o: PLAYER.cpp PLAYER.h
    g++ -c PLAYER.cpp

TABLE.o: TABLE.cpp TABLE.h
    g++ -c TABLE.cpp

CARD.o: CARD.cpp CARD.h
    g++ -c CARD.cpp