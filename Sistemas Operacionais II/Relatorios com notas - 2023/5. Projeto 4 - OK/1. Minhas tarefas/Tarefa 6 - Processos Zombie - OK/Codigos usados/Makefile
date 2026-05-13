CC = gcc
EXECS = zombie sigchld

all: $(EXECS)

zombie: zombie.c
	$(CC) -o $@ $?

sigchld: sigchld.c
	$(CC) -o $@ $?

clean:
	rm -f $(EXECS)

