CC = g++
FLAGS = -Wall
OBJS = main.o classroom.o parent.o teacher.o queue.o

askisi2:$(OBJS)
	$(CC) $(FLAGS) -o askisi2 $(OBJS)

main.o:main.cpp
	$(CC) $(FLAGS) -o main.o -c main.cpp

classroom.o:classroom.cpp
	$(CC) $(FLAGS) -o classroom.o -c classroom.cpp

parent.o:parent.cpp
	$(CC) $(FLAGS) -o parent.o -c parent.cpp

teacher.o:teacher.cpp
	$(CC) $(FLAGS) -o teacher.o -c teacher.cpp

queue.o:queue.cpp
	$(CC) $(FLAGS) -o queue.o -c queue.cpp

.PHONY: clean

clean:
	rm -f askisi2 $(OBJS)
