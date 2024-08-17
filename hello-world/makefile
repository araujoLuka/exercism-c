CC = gcc
CFLAGS = -Wall -g
PROGRAM = hello
OBJS = hello_world.o

all: $(PROGRAM)

$(PROGRAM): main.c $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

entire-string-flag: CFLAGS += -DENTIRE_STRING
entire-string-flag: $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)

clean:
	rm -f $(OBJS)

purge: clean
	rm -f $(PROGRAM)
