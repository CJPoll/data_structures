COMPILER=gcc
CFLAGS=-Werror -Wall -c
LDFLAGS=-Werror -Wall

SOURCEDIR=./src/
SOURCES=linked_list.c stack.c

OBJECTDIR=./obj/
OBJECTFILES=$(SOURCES:.c=.o)

OBJECTS=$(foreach OBJECT, $(OBJECTFILES), $(OBJECTDIR)$(OBJECT))

EXECUTABLE=./bin/stack

.PHONY : clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(COMPILER) $(LDFLAGS) $(OBJECTS) -o $@

$(OBJECTDIR)%.o : $(SOURCEDIR)%.c
	$(COMPILER) $(CFLAGS) $< -o $@

clean:
	rm edit $(OBJECTS)
