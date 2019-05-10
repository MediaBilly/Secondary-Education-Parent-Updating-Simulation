#include <iostream>
#include <cstdlib>
#include "classroom.h"

Classroom::Classroom(int totalTeachers) : waitingQueue(Queue(true)) , restQueue(Queue(false))
{
  //Create teachers
  this->totalTeachers = totalTeachers;
  this->teachers = new Teacher*[this->totalTeachers];
  for (int i = 0; i < this->totalTeachers; i++)
    this->teachers[i] = new Teacher(i + 1);
  std::cout << "A classroom was created." << '\n';
}

void Classroom::insertParent(Parent *par, bool insertAtWaitingQueue)
{
  if(insertAtWaitingQueue)
    this->waitingQueue.push(par);
  else
    this->restQueue.push(par);
}

void Classroom::updateParents()
{
  int num;
  Parent *par;
  //Run until all parents are updated
  while(!this->restQueue.empty() || !this->waitingQueue.empty())
  {
    //For each teacher get a parent from the queue that wants to see him(if there is at least one available) and update him
    for (int i = 0; i < this->totalTeachers; i++)
    {
      par = this->waitingQueue.popWithTeacher(i + 1);
      if(par != NULL)
      {
        this->teachers[i]->updateParent(par);
        //For each updated parent add a random amount of new ones to the waiting queue
        if(this->restQueue.getSize() > 0)
        {
          num = rand() % (this->restQueue.getSize()) + 1;
          for (int i = 0; i < num; i++)
            this->waitingQueue.push(this->restQueue.pop());
        }
      }
    }
    for (int i = 0; i < this->totalTeachers; i++)
    {
      //Each updated parent returns back to the waiting queue if he wants to be updated from other teachers too.Otherwise, he exits
      if(this->teachers[i]->hasParent())
      {
        par = this->teachers[i]->exitParent();
        if(this->waitingQueue.returnToQueue(par) == false)
          delete par;
      }
    }
  }
}

Classroom::~Classroom()
{
  for (int i = 0; i < this->totalTeachers; i++)
    delete this->teachers[i];
  delete[] this->teachers;
}
