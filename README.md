# Secondary-Education-Parent-Updating-Simulation

A program that simulates a date of teachers updating secondary education student's parents about their kid's progress.
The updating takes place in a classromm with a specific amount of teachers.The parents want to be updated from some
(not necessary all) from them.The teachers each parent is going to see are chosen randomly.The parents are waiting at the 
entrance of the classromm forming a queue.When a new parent comes, he goes to the end of the queue.When a teacher becomes available,
the parent who is waiting in the queue and is the first one that wants to be updated from that teacher, gets removed from the queue 
and meets that teacher.When his update from the teacher is done,the teacher becomes available again and the parent goes to the end of the queue.
Randomly, a parent may try to steel and return to the start of the queue.Then, other parents start complaining and get him to the end of the queue.
This was a university project for the Object Oriented Programming course at Winter Semester 2018.

## Compilation:
```
make
```

## Execution:
```
./askisi2
```

## Remove Object Files:
```
make clean
```
