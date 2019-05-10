#ifndef _QUEUE_
#define _QUEUE_
#include "parent.h"
typedef struct Node *Nodeptr;
class Queue {
private:
  int size;
  Nodeptr front;
  Nodeptr back;
  bool waitingQueue;
public:
  Queue (bool);
  ~Queue ();
  void push(Parent*);//Adds a new parent to the queue
  Parent* pop();//Removes front parent from the queue
  Parent* popWithTeacher(int);//Removes a parent that wants to see a specific teacher from the queue
  bool returnToQueue(Parent*);//Returns false if the parent was updated from all wanted teachers
  bool empty() const;
  int getSize() const;
};
#endif
