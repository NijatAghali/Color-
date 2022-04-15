SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
LIBS = -lm
all : prog

%.o : %.c
	gcc -c $^ -o $@

prog : $(OBJECTS)
	gcc $(OBJECTS) -o prog $(LIBS)
clean :
	rm $(OBJECTS) prog
archive :
	rm $(OBJECTS) prog
	tar -czvf archive.tgz *.c *.h
