#include <iostream>
#include <cstdlib>
#include <ctime>
#include "classroom.h"
#include "parent.h"

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  int N,K,L;
  Parent *par;
  std::cout << "Number of teachers:";
  std::cin >> N;
  std::cout << "Number of parents:";
  std::cin >> K;
  //Create classroom wiht N teachers
  Classroom classroom(N);
  //Create Parents.L of them(L is random beteen 1 and totalParents) are inserted to the waiting queue.The rest of them are inserted to the rest queue to be inserted later to the waiting queue.
  L = rand() % K + 1;
  for (int i = 0; i < K; i++)
  {
    par = new Parent(i+1,N);
    classroom.insertParent(par,i < L);
  }
  classroom.updateParents();
  return 0;
}
