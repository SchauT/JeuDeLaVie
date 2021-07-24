#Makefile

CC ?= gcc
CFLAGS = -Wall -Wextra -std=c99 #-Werror
SDL_FLAGS = -lSDL2 -lGL

OBJS = main.o matrix.o sdl.o
BIN = main

all: $(OBJS)
	$(CC) $^ -o main $(CFLAGS) $(SDL_FLAGS)

$(BIN): $(OBJS)

clean:
	${RM} ${OBJS} ${DEP} *~
	${RM} main

cleanrun: clean
	make all

-include ${DEP}

# END
