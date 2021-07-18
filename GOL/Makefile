#Makefile

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99

OBJ = main.o matrix.o
DEP = ${OBJ:.o=.d}

ALL: main

main: ${OBJ}

clean:
	${RM} ${OBJ} ${DEP} *~
	${RM} main

-include ${DEP}

# END
