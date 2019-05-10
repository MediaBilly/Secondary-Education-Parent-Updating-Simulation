#ifndef _CLASSROOM_
#define _CLASSROOM_
#include "parent.h"
#include "teacher.h"
#include "queue.h"
class Classroom {
private:
  int totalTeachers;
  int totalParents;
  Teacher **teachers;
  Queue waitingQueue;//Queue with parents waiting to be updated
  Queue restQueue;//Queue wiht parents that will be added later to the waiting queue
public:
  Classroom (int);
  void insertParent(Parent*,bool);
  void updateParents();
  ~Classroom ();
};
#endif
