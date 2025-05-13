CFLAGS=`sdl2-config --cflags --libs` -lSDL2 -lSDL2_ttf

all:
	gcc periodic_table.c -o periodic_table.out $(CFLAGS)
