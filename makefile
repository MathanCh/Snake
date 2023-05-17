COMPILE = g++ -std=c++20 -pedantic-errors -Wall -g -I ./include/

SFML = -lsfml-graphics -lsfml-window -lsfml-system

SPATH = ./src/
OPATH = ./obj/
BPATH = ./bin/

.PHONY : clean
.PHONY : run
.PHONY : gitupdate
.PHONY : open

snakeGame : snake_game.o
	$(COMPILE) $(OPATH)point.o $(OPATH)borders.o $(OPATH)board.o $(OPATH)snake.o \
	 $(OPATH)snake_game.o $(SFML) -o $(BPATH)snake_game.out

snake_game.o : snake.o board.o
	$(COMPILE) $(SFML) -c $(SPATH)snake_game.cpp -o $(OPATH)snake_game.o

snake.o : board.o
	$(COMPILE) $(SFML) -c $(SPATH)snake.cpp -o $(OPATH)snake.o

board.o : borders.o
	$(COMPILE) $(SFML) -c $(SPATH)board.cpp -o $(OPATH)board.o

borders.o : point.o
	$(COMPILE) $(SFML) -c $(SPATH)borders.cpp -o $(OPATH)borders.o

point.o : 
	$(COMPILE) -c $(SPATH)point.cpp -o $(OPATH)point.o

clean :
	rm -f $(OPATH)*.o $(BPATH)*.out

run :
	./$(BPATH)snake_game.out

gitupdate :
	git add .
	git commit
	git push

open :
	gedit $(SPATH)/*.cpp
	gedit ./include/*.hpp
