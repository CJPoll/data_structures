CC = gcc
CFLAGS = -Werror -Wall -c -std=c99
LDFLAGS = -Werror -Wall
LOADLIBES = -lgsl

SOURCEDIR = ./src/
SOURCES = dynamic_array.c stack.c
TESTSRCS = stack_tests.c

OBJECTDIR = ./obj/
OBJECTFILES = $(SOURCES:.c=.o)
OBJECTS = $(foreach OBJECT, $(OBJECTFILES), $(OBJECTDIR)$(OBJECT));

EXECDIR = ./bin/
EXECUTABLE = stack

TESTDIR = ./test/
TESTOBJFILES = $(TESTSRCS:.c=.o)
TESTOBJECTS = $(foreach TESTOBJECT, $(TESTOBJFILES), $(TESTDIR$)$(TESTOBJECT))

.PHONY : clean

all: $(OBJECTS)
	echo $(TESTOBJECTS)

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
