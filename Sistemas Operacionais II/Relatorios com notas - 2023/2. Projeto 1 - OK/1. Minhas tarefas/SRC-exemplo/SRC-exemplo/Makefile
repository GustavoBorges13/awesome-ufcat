CC = cc
LIBS = -lpthread
FLAGS = -O -w
EXECS = exemplo

all: $(EXECS)

exemplo: exemplo.c
	$(CC) $(FLAGS) -o $@ $? $(LIBS)

clean:
	rm -f $(EXECS)
