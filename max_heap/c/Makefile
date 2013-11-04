CC = gcc
CFLAGS = -Werror -Wall -c -std=c99
LDFLAGS = -Werror -Wall
LOADLIBES = -lgsl

SOURCEDIR = ./src/
SOURCES = max_heap.c dynamic_array.c
TESTSRCS = max_heap_test.c

OBJECTDIR = ./obj/
OBJECTFILES = $(SOURCES:.c=.o)
OBJECTS = $(foreach OBJECT, $(OBJECTFILES), $(OBJECTDIR)$(OBJECT));

EXECDIR = ./bin/
EXECUTABLE = max_heap

TESTDIR = ./test/
TESTOBJFILES = $(TESTSRCS:.c=.o)
TESTOBJECTS = $(foreach TESTOBJECT, $(TESTOBJFILES), $(TESTDIR$)$(TESTOBJECT))

.PHONY : clean

all: $(OBJECTS)

$(TESTDIR)%.o: $(TESTDIR)%.c
	$(CC) $(CFLAGS) -g $^ -o $@

$(OBJECTDIR)%.o: $(SOURCEDIR)%.c
	$(CC) $(CFLAGS) -g $^ -o $@

tests: $(TESTOBJECTS) $(OBJECTS) 
	$(CC) $(LDFLAGS) $^ /usr/local/lib/libcunit.a -o $(EXECDIR)$@

test: tests
	./bin/tests

clean:
	-rm ./bin/* ./obj/* ./test/*.o
