#Makefile

CC ?= gcc
CFLAGS = -Wall -Wextra -Werror -std=c99
SDL_FLAGS = -lSDL2 -lGL

OBJS = main.o matrix.o
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
