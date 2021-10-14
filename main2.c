#include  <stdio.h>
#include <stdlib.h>
#include  <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>

#define   MAX_COUNT  200

void  ChildProcess(int pid);                /* child process prototype  */
void  ParentProcess(int child);               /* parent process prototype */

void  main(void)
{
     pid_t  pid;
     int i;
     int j;
     for(i = 0; i < 2; i++){
       pid = fork();
       if(pid == 0)
         ChildProcess(i);
       else if(pid > 0){
         while(wait(NULL) != -1 ||errno != ECHILD){
           j = wait(NULL);
           ParentProcess(j);
         }
       }
       else
         printf("Error in Fork\n");
     }
}

void  ChildProcess(int pid)
{
     int number;
     int sleep_time;
     srand(time(NULL));
     number = rand() % 31;
     sleep_time = rand() % 11;
  
     int   i;
     int pidID = getpid();
     int parentID = getppid();
      //Child Prcess 1
     if(pid == 0){
       printf("This is the First Child Process\n");
       for (i = 0; i < number; i++){
         printf("Child Process:%d is going to sleep!\n", pidID);
         sleep(sleep_time);
         printf("Child Process:%d is awake!\nWhere is my Parent:%d", pidID);
         printf("Where is my Parent:%d\n", parentID)
       }
       exit(0);
     }
  
     //Child Process 2
     else if(pid == 1){
       printf("This is the Second Child Process\n");
       for (i = 0; i < number; i++){
         printf("Child Process:%d is going to sleep!\n", pidID);
         sleep(sleep_time);
         printf("Child Process:%d is awake!\nWhere is my Parent:%d", pidID);
         printf("Where is my Parent:%d\n", parentID)
       }
       exit(0);
     }
  
     /*
     for (i = 1; i <= MAX_COUNT; i++)
          printf("   This line is from child, value = %d\n", i);
     printf("   *** Child process is done ***\n");
     */
}

void  ParentProcess(int child)
{
     
     printf("Child Process:%d has completed", child);
     /*
     int   i;
  
     for (i = 1; i <= MAX_COUNT; i++)
          printf("This line is from parent, value = %d\n", i);
     printf("*** Parent is done ***\n");
     */
}