#include <iostream>
#include "teacher.h"

Teacher::Teacher(int id)
{
  this->id = id;
  this->available = true;
  this->curParent = NULL;
  std::cout << "Created teacher " << this->id << '\n';
}

int Teacher::getId() const
{
  return this->id;
}

bool Teacher::hasParent() const
{
  return !(this->available);
}

bool Teacher::updateParent(Parent *par)
{
  if(this->available == false)
    return false;
  this->curParent = par;
  this->curParent->seeTeacher(this->id);
  this->available = false;
  return true;
}

Parent* Teacher::exitParent()
{
  Parent *par = this->curParent;
  this->available = true;
  this->curParent = NULL;
  std::cout << "Parent " << par->getId() << " left teacher " << this->id << "'s office" << '\n';
  return par;
}

Teacher::~Teacher()
{
  std::cout << "Destroyed teacher " << this->id << '\n';
}
