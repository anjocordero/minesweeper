all: mine_sweeper.out

mine_sweeper.out: main.o board.o game.o check.o
	gcc -g -Wall -o mine_sweeper.out main.o board.o game.o check.o
	
main.o: main.c board.h
	gcc -g -Wall -c -o main.o main.c
	
board.o: board.c board.h
	gcc -g -Wall -c -o board.o board.c
	
game.o: game.c game.h board.h check.h
	gcc -g -Wall -c -o game.o game.c

check.o: check.c check.h board.h
	gcc -g -Wall -c -o check.o check.c

clean:
	rm *.out *.o
