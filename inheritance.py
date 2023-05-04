// Jabu9
// Parents And Children In Python Inheritance

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int main()
{
  // Parent, Child1, Child2, Granchild1, Grandchild2
	int P, C1, C2, G1, G2;
  
	P = fork();
	if (P==0) {
		printf("I am the process Child1 and my pid is %d.\n", getpid());
		
    G1 = fork();
		if (G1==0) {
		    printf("I am the process GrandChild1 and my pid is %d. My parent is process Child1 and it has the following pid %d.\n", getpid(), getppid());
		}
	}
	
  else {
		C1 = fork();
		if (C1 == 0) {
			printf("I am the process Child2 and my pid is %d.\n",getpid());
			
      G2 = fork();
    		if (G2==0) {
    		    printf("I am the process GrandChild2 and my pid is %d. My parent is process Child2 and it has the following pid %d.\n", getpid(),getppid());
    		}
		}
		else {
      while(wait(NULL)>0);
				printf("I am the Parent process and my pid is %d. Both my children finished their execution.", getpid());
			}
		}

	return 0;
}
