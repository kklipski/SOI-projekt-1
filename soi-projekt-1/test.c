#include </usr/include/lib.h>
#include </usr/include/stdio.h>
#include </usr/include/stdlib.h>

int getprocnr(int proc_id);

int main(int argc, char* argv[]) 
{
  int result, i;
  if(argc == 1) printf("Nie podano identyfikatora procesu!\n");
  else
  {
    int userInput = atoi(argv[1]);
    for(i=0; i<=10; i++)
    {
      result=getprocnr(userInput+i);
      if(result != -1) printf("Indeks procesu o pid: %d, to: %d\n", userInput+i, result);
      else printf("Procesu o pid: %d, nie ma w tablicy! Kod bledu: %d\n", userInput+i, errno);
    }
  }
  return 0;
}

int getprocnr(int proc_id)
{
  message msg;
  msg.m1_i1=proc_id;
  return (_syscall(0, 78, &msg));
}
