#include <stdio.h>

int main() {
  int *i_p               = 0;
  int const *ic_p        = 0;
  int *const i_pc        = 0;
  int const *const ic_pc = 0;

  #if 0
  i_p = i_p;
  ic_p = ic_p;
  i_pc = i_pc;
  ic_pc = ic_pc;
  #endif

  i_p = i_pc;
  ic_p = i_p;
  ic_p = i_pc;
  ic_p = ic_pc;

  #if 0
  int **i_p_p               = 0;
  int const **ic_p_p        = 0;
  int *const *i_pc_p        = 0;
  int const *const *ic_pc_p = 0;
  #endif

  typedef int *T;
  typedef int const *U;
  T *i_p_p         = 0;
  U *ic_p_p        = 0;
  T const *i_pc_p  = 0;
  U const *ic_pc_p = 0;

  i_pc_p = i_p_p;
  ic_pc_p = ic_p_p;

  printf("to turn off warning... %p %p %p %p\n",
         (void *)i_p, (void *)ic_p, (void *)i_pc, (void *)ic_pc);
  printf("to turn off warning... %p %p %p %p\n",
         (void *)i_p_p, (void *)ic_p_p, (void *)i_pc_p, (void *)ic_pc_p);


  return 0;
}
