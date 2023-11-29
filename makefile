# Compiler
CC = gcc

# Compiler Flags
CFLAGS = -Wall -Wextra -std=c99 -g

# Header Files
DEPS = movieTheaterDB.h movieTheaterDB_movie.h movieTheaterDB_actor.h fort.h helper.h

# Source Files
SRC = movieTheaterDB.c movieTheaterDB_movie.c movieTheaterDB_actor.c fort.c helper.c

# Object Files
OBJ = $(SRC:.c=.o)

# Executable Name
EXEC = movieTheaterDB

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) $(EXEC)
