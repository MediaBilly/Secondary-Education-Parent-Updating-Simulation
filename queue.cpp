#include <iostream>
#include <cstdlib>
#include "queue.h"

struct Node {
  Parent *parent;
  Nodeptr prev;
  Nodeptr next;
};

Queue::Queue(bool waitingQueue = true)
{
  this->size = 0;
  this->front = this->back = NULL;
  this->waitingQueue = waitingQueue;
}

void Queue::push(Parent *parent)
{
  Nodeptr tmp = new struct Node;
  tmp->parent = parent;
  tmp->next = NULL;
  if(this->front == NULL && this->back == NULL)//First time
  {
    tmp->prev = NULL;
    this->front = tmp;
    this->back = tmp;
  }
  else
  {
    tmp->prev = this->back;
    this->back->next = tmp;
    this->back = tmp;
  }
  this->size++;
  if(this->waitingQueue)
    std::cout << "Parent " << parent->getId() << " entered the queue" << '\n';
}

Parent* Queue::pop()
{
  Parent *ret = NULL;
  Nodeptr toDel = this->front;
  if(toDel != NULL)
  {
    ret = toDel->parent;
    this->front = this->front->next;
    if(this->front != NULL)
      this->front->prev = NULL;
    else
      this->back = NULL;
    delete toDel;
    this->size--;
  }
  return ret;
}

Parent* Queue::popWithTeacher(int teacher)
{
  Parent *ret;
  Nodeptr toDel = this->front;
  while(toDel != NULL && toDel->parent->wantsToSeeTeacher(teacher) == false)
    toDel = toDel->next;
  if(toDel == NULL)
    ret = NULL;
  else if(toDel == this->front)
    ret = this->pop();
  else
  {
    ret = toDel->parent;
    toDel->prev->next = toDel->next;
    if(toDel == this->back)
      this->back = toDel->prev;
    else
      toDel->next->prev = toDel->prev;
    delete toDel;
    this->size--;
  }
  if(this->waitingQueue && ret != NULL)
    std::cout << "Parent " << ret->getId() << " left the queue to see teacher " << teacher << '\n';
  return ret;
}

bool Queue::returnToQueue(Parent *parent)
{
  if(parent->updateComplete())
  {
    std::cout << "Parent " << parent->getId() << " saw all the teachers that he wanted to see.So he exits the classroom." << '\n';
    return false;
  }
  if(this->waitingQueue)
  {
    if(rand() % 2 == 0)
    {
      std::cout << "Parent " << parent->getId() << " tried to steal from the waiting queue and enter the front." << '\n';
      std::cout << "Other parents:Hey, where do you think you are going, get to the back of the queue!" << '\n';
    }
    else
      std::cout << "Parent " << parent->getId() << " restfully entered the back of the queue." << '\n';
  }
  this->push(parent);
  return true;
}

bool Queue::empty() const
{
  return this->size == 0;
}

int Queue::getSize() const
{
  return this->size;
}

Queue::~Queue()
{
  Nodeptr toDel;
  while (this->front != NULL)
  {
    toDel = this->front;
    this->front = this->front->next;
    delete toDel;
  }
}
