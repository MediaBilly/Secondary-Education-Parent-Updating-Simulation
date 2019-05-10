#include <iostream>
#include <cstdlib>
#include "parent.h"

Parent::Parent(int id,int teachers)
{
  int num;
  this->id = id;
  this->totalTeachers = teachers;
  this->teachersToSee = new bool[this->totalTeachers];
  this->numTeachersToSee = 0;
  this->updated = new bool[this->totalTeachers];
  std::cout << "A parent with id " << this->id << " was created.He wants to see teachers ";
  //Decide which teachers to see
  for (int i = 0; i < this->totalTeachers; i++)
  {
    if(rand() % 2 == 1)
    {
      this->teachersToSee[i] = true;
      this->numTeachersToSee++;
      std::cout <<  i + 1 << " ";
    }
    else
      this->teachersToSee[i] = false;
    this->updated[i] = false;
  }
  if(this->numTeachersToSee == 0)//At least see 1 teacher
  {
    num = rand() % this->totalTeachers;
    this->teachersToSee[num] = true;
    this->numTeachersToSee++;
    std::cout << num + 1 << " ";
  }
  std::cout << '\n';
}

bool Parent::updateComplete() const
{
  return this->numTeachersToSee == 0;
}

bool Parent::wantsToSeeTeacher(int teacher) const
{
  return this->teachersToSee[teacher - 1] && !this->updated[teacher - 1];
}

bool Parent::seeTeacher(int teacher)
{
  if(teacher <= 0 || teacher > this->totalTeachers || this->teachersToSee[teacher - 1] == false || (this->teachersToSee[teacher - 1] == true && this->updated[teacher - 1] == true))
    return false;
  this->updated[teacher - 1] = true;
  this->numTeachersToSee--;
  std::cout << "Parent " << this->id << " sees teacher " << teacher << '\n';
  return true;
}

int Parent::getId() const
{
  return this->id;
}

Parent::~Parent()
{
  std::cout << "Destroyed parent " << this->id << '\n';
  delete[] this->teachersToSee;
  delete[] this->updated;
}
