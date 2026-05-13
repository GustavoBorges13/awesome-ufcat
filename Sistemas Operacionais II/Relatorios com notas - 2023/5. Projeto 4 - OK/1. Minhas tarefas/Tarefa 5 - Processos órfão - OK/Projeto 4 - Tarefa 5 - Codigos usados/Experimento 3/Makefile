CC = gcc
LDFLAGS = -L/usr/pkg/lib
CFLAGS = -I/usr/pkg/include
LIBS = -lpthread
FLAGS = -O -w
EXECS = fork-ex fork-ex-10pid threads ctrlc multiwriter_single_reader server client status-control-forks

all: $(EXECS)

fork-ex: fork-ex.c
	$(CC) -o $@ $?

fork-ex-10pid: fork-ex-10pid.c
	$(CC) -o $@ $?

ctrlc: ctrlc.c
	$(CC) -o $@ $? $(LDFLAGS) $(CFLAGS)

multiwriter_single_reader: multiwriter_single_reader.c
	$(CC) -o $@ $? $(LDFLAGS) $(CFLAGS)

server: server.c
	$(CC) $(CFLAGS) -o server server.c

client: client.c
	$(CC) $(CFLAGS) -o client client.c

status-control-forks: status-control-forks.c
	$(CC) $(CFLAGS) -o status-control-forks status-control-forks.c

clean:
	rm -f $(EXECS)