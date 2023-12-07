#include "MyList.h"
//#include <iostream>
#include <stdio.h>


int main()
{
  TList<int> a;
  a.PushBegin(1);
  a.PushEnd(2);
  a.PushBegin(3);
  a.PushEnd(4);  
  a.PushBegin(5);
  a.PushEnd(6);

  for (auto i = a.begin(); i != a.end(); ++i)
    printf("%d\n", *i);
  printf("\n\n");
  TList<int> b = a;

  for (auto i = a.begin(); i != a.end(); ++i)
    printf("%d\n", *i);
  printf("\n\n");


  for (auto i : a)
    printf("%d\n", i);
  printf("\n\n");
  //std::list<int> c;

  //c.push_front(1);
  //c.push_back(2);
  //c.push_front(3);
  //c.push_back(4);
  //c.push_front(5);
  //c.push_back(6);

  //for (auto i = c.begin(); i != c.end(); ++i)
  //  printf("%d\n", *i);
  //printf("\n\n");
  //  std::cout << *i <<std::endl;
}