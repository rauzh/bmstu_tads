CC=gcc
CFLAGS= -std=c99 -Wall -Werror -Wextra -pedantic -Wvla -Iinc
SOURCES=src/main.c src/read_print.c src/list_stack.c src/array_stack.c src/sort.c src/operations.c
OBJS=$(SOURCES:.c=.o)
EXECUTABLE=app.exe

app.exe: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

.c.o:
	$(CC) -c $(CFLAGS) $< -o $@

clear:
	rm -f src/*.o *.exe


