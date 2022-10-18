all: main

main: Game.h Guess.h Mystery.h Player.h Pool.h Highscore.h main.cpp
	g++ -Wall Game.h Guess.h Mystery.h Player.h Pool.h Highscore.h main.cpp -o main.out
	./main

Game.o: Game.h
	g++ -c Game.h

Guess.o: Guess.h
	g++ -c Guess.h

Highscore.o: Highscore.h
	g++ -c Highscore.h

Mystery.o: Mystery.h
	g++ -c Mystery.h

Player.o: Player.h
	g++ -c Player.h

Pool.o: Pool.h
	g++ -c Pool.h

main.o: main.cpp
	g++ -c main.cpp







clean:
	rm -rf *o main Tests Fighter_Test Weapons_Test