COMPILE = g++ -std=c++20 -pedantic-errors -Wall -g -I ./include/

SFML = -lsfml-graphics -lsfml-window -lsfml-system

SPATH = ./src/
OPATH = ./obj/
BPATH = ./bin/

.PHONY : clean
.PHONY : run
.PHONY : gitupdate
.PHONY : open

OBJS = $(OPATH)point.o $(OPATH)segment.o $(OPATH)borders.o $(OPATH)panel.o $(OPATH)board.o $(OPATH)snake.o $(OPATH)game.o $(OPATH)snake_game.o

snakeGame : $(OBJS)
	$(COMPILE) $(OBJS) $(SFML) -o $(BPATH)snake_game.out

$(OPATH)snake_game.o : $(OPATH)game.o
	$(COMPILE) $(SFML) -c $(SPATH)snake_game.cpp -o $(OPATH)snake_game.o

$(OPATH)game.o : $(OPATH)snake.o $(OPATH)board.o
	$(COMPILE) $(SFML) -c $(SPATH)game.cpp -o $(OPATH)game.o

$(OPATH)snake.o : $(OPATH)segment.o $(OPATH)board.o
	$(COMPILE) $(SFML) -c $(SPATH)snake.cpp -o $(OPATH)snake.o

$(OPATH)board.o : $(OPATH)borders.o $(OPATH)panel.o
	$(COMPILE) $(SFML) -c $(SPATH)board.cpp -o $(OPATH)board.o

$(OPATH)borders.o : $(OPATH)point.o
	$(COMPILE) $(SFML) -c $(SPATH)borders.cpp -o $(OPATH)borders.o

$(OPATH)segment.o : $(OPATH)point.o
	$(COMPILE) $(SFML) -c $(SPATH)segment.cpp -o $(OPATH)segment.o

$(OPATH)panel.o : $(OPATH)point.o
	$(COMPILE) $(SFML) -c $(SPATH)panel.cpp -o $(OPATH)panel.o

$(OPATH)point.o : 
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
