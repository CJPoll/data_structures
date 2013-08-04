APPLICATION=LinkedList

all:
	javac -d ./bin ./src/*

test: all
	javac -d ./test -cp ./bin:/usr/share/java/junit4.jar ./test/*.java
	java -cp ./bin:/usr/share/java/junit4.jar:./test org.junit.runner.JUnitCore Test$(APPLICATION)
	rm -rf test/*.class

run: all
	java -classpath ./bin $(APPLICATION)

clean:
	rm -rf ./bin/*
