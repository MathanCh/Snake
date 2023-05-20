COMPILE = g++ -std=c++20 -pedantic-errors -Wall -g -I ./include/

SFML = -lsfml-graphics -lsfml-window -lsfml-system

SPATH = ./src/
SNAKESPATH = ./src/snake/
OPATH = ./obj/
BPATH = ./bin/

.PHONY : clean
.PHONY : run
.PHONY : gitupdate
.PHONY : open

OBJS = $(OPATH)point.o $(OPATH)borders.o $(OPATH)panel.o $(OPATH)button.o $(OPATH)menu.o $(OPATH)games.o $(OPATH)game.o

SNAKEOBJS = $(OPATH)segment.o $(OPATH)snake_board.o $(OPATH)snake.o $(OPATH)snake_game.o

gameLib : $(OPATH)games.o $(OPATH)snake_game.o
	$(COMPILE) $(SFML) $(OBJS) $(SNAKEOBJS) $(SFML) -o $(BPATH)games.out

$(OPATH)games.o : $(OPATH)menu.o
	$(COMPILE) -c $(SPATH)games.cpp -o $(OPATH)games.o

$(OPATH)menu.o : $(OPATH)game.o $(OPATH)button.o
	$(COMPILE) -c $(SPATH)menu.cpp -o $(OPATH)menu.o

$(OPATH)snake_game.o : $(OPATH)game.o $(OPATH)snake_board.o $(OPATH)snake.o
	$(COMPILE) -c $(SNAKESPATH)snake_game.cpp -o $(OPATH)snake_game.o

$(OPATH)button.o : $(OPATH)borders.o
	$(COMPILE) -c $(SPATH)button.cpp -o $(OPATH)button.o

$(OPATH)game.o :
	$(COMPILE) -c $(SPATH)game.cpp -o $(OPATH)game.o

$(OPATH)snake_board.o : $(OPATH)borders.o $(OPATH)panel.o
	$(COMPILE) -c $(SNAKESPATH)snake_board.cpp -o $(OPATH)snake_board.o

$(OPATH)panel.o : $(OPATH)point.o
	$(COMPILE) -c $(SPATH)panel.cpp -o $(OPATH)panel.o

$(OPATH)borders.o : $(OPATH)point.o
	$(COMPILE) -c $(SPATH)borders.cpp -o $(OPATH)borders.o

$(OPATH)snake.o : $(OPATH)segment.o
	$(COMPILE) -c $(SNAKESPATH)snake.cpp -o $(OPATH)snake.o

$(OPATH)segment.o : $(OPATH)point.o
	$(COMPILE) -c $(SNAKESPATH)segment.cpp -o $(OPATH)segment.o

$(OPATH)point.o :
	$(COMPILE) -c $(SPATH)point.cpp -o $(OPATH)point.o

clean :
	rm -f $(OPATH)*.o $(BPATH)*.out

run :
	./$(BPATH)games.out

gitupdate :
	git add .
	git commit
	git push

open :
	gedit $(SPATH)/*.cpp
	gedit ./include/*.hpp
