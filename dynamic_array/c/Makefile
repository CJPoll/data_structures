CC = gcc
CFLAGS = -Werror -Wall -c  
LDFLAGS = -Werror -Wall
LOADLIBES = -lgsl

SOURCEDIR = ./src/
SOURCES = dynamic_array.c
TESTSRCS = dynamic_array_test.c

OBJECTDIR = ./obj/
OBJECTFILES = $(SOURCES:.c=.o)
OBJECTS = $(foreach OBJECT, $(OBJECTFILES), $(OBJECTDIR)$(OBJECT));

EXECDIR = ./bin/
EXECUTABLE = dynamic_array

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
	$(CC) $(LDFLAGS) $^ ~/local/lib/libcunit.a -o $(EXECDIR)$@

test: tests
	./bin/tests

clean:
	-rm ./bin/* ./obj/* ./test/*.o
