CC = gcc
LDFLAGS = -L/usr/pkg/lib
CFLAGS = -I/usr/pkg/include
LIBS = -lpthread
FLAGS = -O -w
EXECS = fork-ex zombie semaphore threads ctrlc

all: $(EXECS)

fork-ex: fork-ex.c
	$(CC) -o $@ $?

zombie: zombie.c
	$(CC) -o $@ $?

mini-sh: mini-sh.c
	$(CC) -o $@ $?

threads: threads.c
	$(CC) -o $@ $? $(LDFLAGS) $(CFLAGS) $(LIBS) 

semaphore: semaphore.c
	$(CC) -o $@ $? $(LDFLAGS) $(CFLAGS) $(LIBS) 

ctrlc: ctrlc.c
	$(CC) -o $@ $? $(LDFLAGS) $(CFLAGS) $(LIBS) 

clean:
	rm -f $(EXECS)
