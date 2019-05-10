#ifndef _PARENT_
#define _PARENT_
class Parent {
private:
  int id;
  int totalTeachers;
  int numTeachersToSee;
  bool *teachersToSee;
  bool *updated;
public:
  Parent (int,int);
  bool updateComplete() const;
  bool wantsToSeeTeacher(int) const;
  bool seeTeacher(int);
  int getId() const;
  ~Parent ();
};
#endif
