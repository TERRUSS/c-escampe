CC=gcc
CFLAGS=-O2 -Wall `sdl-config --cflags`
LIBS=`sdl-config --libs` -lm -lSDL_ttf
DIR=IN200
FILES=display/display.c utils/init.c movements/movements.c
HEADERS=display/display.h utils/init.h utils/types.h movements/movements.h

#Cible generique pour Linux
%: graphics.o %.c
	rm -f $@
	$(CC) $(CFLAGS) graphics.o $@.c -o $@ $(LIBS)

#Cible generique pour free BSD
.c .o: graphics.o
	rm -f $@
	$(CC) $(CFLAGS) graphics.o $@.c -o $@ $(LIBS)

graphics.o: lib/graphics.c lib/graphics.h
	rm -f lib/police.h
	touch lib/police.h
	if test -e /usr/include/SDL_ttf.h;           then echo "#define SDL_TTF_OK" > lib/police.h; fi
	if test -e /usr/include/SDL/SDL_ttf.h;       then echo "#define SDL_TTF_OK" > lib/police.h; fi
	if test -e /usr/local/include/SDL_ttf.h;     then echo "#define SDL_TTF_OK" > lib/police.h; fi
	if test -e /usr/local/include/SDL/SDL_ttf.h; then echo "#define SDL_TTF_OK" > lib/police.h; fi
	$(CC) $(CFLAGS) -c lib/graphics.c


sans_ttf:
	rm -f lib/police.h
	touch lib/police.h
	$(CC) $(CFLAGS) -c lib/graphics.c
	$(CC) $(CFLAGS) graphics.o exemple.c -o exemple $(LIBS)
	./exemple


main: main.c graphics.o $(FILES) $(HEADERS)
	$(CC) $(CFLAGS) graphics.o main.c $(FILES) -o main $(LIBS)
	./main

tar: clean
	rm -rf $(DIR)
	mkdir $(DIR)
	cp exemple.c $(DIR)
	cp lib/graphics.c $(DIR)
	cp lib/graphics.h $(DIR)
	cp lib/couleur.h $(DIR)
	cp exo1.1.c $(DIR)
	cp Makefile $(DIR)
	cp lib/*.ttf $(DIR)
	tar cvf $(DIR).tar $(DIR)
	rm -rf $(DIR)

clean:
	rm -f *core
	rm -f *.o
	rm -f lib/police.h
	rm -f exemple
	rm -f *.tar
	rm -rf $(DIR)
