APPLICATION=DoublyLinkedList

all:
	javac -d ./bin ./src/*

test: all
	javac -d ./bin -cp ./bin:/usr/share/java/junit4.jar ./test/*
	java -cp ./bin:/usr/share/java/junit4.jar org.junit.runner.JUnitCore Test$(APPLICATION)

run: all
	java -classpath ./bin $(APPLICATION)

clean:
	rm -rf ./bin/*

debugtest:
	javac -g -d ./bin -cp ./bin:/usr/share/java/junit4.jar ./src/*
	javac -g -d ./bin -cp ./bin:/usr/share/java/junit4.jar ./test/*
	jdb -classpath ./bin:./test:./src:/usr/share/java/junit4.jar junit.textui.TestRunner Test$(APPLICATION)
