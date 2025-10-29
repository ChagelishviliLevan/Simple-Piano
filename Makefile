CC = gcc
CFLAGS = -Wall -Wextra
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

all: piano

piano: piano.c
	$(CC) $(CFLAGS) piano.c -o piano $(LIBS)

clean:
	rm -f piano

run: piano
	./piano