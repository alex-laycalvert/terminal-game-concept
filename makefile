terminal-game-concept:
	g++ src/*.cpp -lncurses -o ./tgc
dev:
	g++ -g3 -Wall -Wextra -fsanitize=address,undefined src/*.cpp -lncurses -o ./tgc.dev
clean:
	rm -f ./tgc
	rm -f ./tgc.dev
	rm -f ./tgc.dev.dSYM
