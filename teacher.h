#ifndef _TEACHER_
#define _TEACHER_
#include "parent.h"
class Teacher {
private:
  int id;
  bool available;
  Parent *curParent;
public:
  Teacher(int);
  ~Teacher();
  int getId() const;
  bool hasParent() const;
  bool updateParent(Parent*);
  Parent* exitParent();
};
#endif
