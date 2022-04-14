#include  <stdio.h>
#include <stdlib.h>
#include  <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>

#define   MAX_COUNT  200

void  ChildProcess(int pid);                /* child process prototype  */
void  ParentProcess(int child);             /* parent process prototype */

void  main(void)
{
     pid_t  pid;
     pid_t  pid2;
     int i;
     int j;
     int status;
     for (i = 0; i < 2; i++){
       if(i == 0){
         pid = fork();
         if(pid != 0){
           status = wait(NULL);
           ParentProcess(status);
         }
         ChildProcess(pid);
       }
       else if(i == 1 && pid != 0){
         if(pid != 0){
           pid2 = fork();
           status = wait();
           ParentProcess(status);
         }
         ChildProcess(pid2);
       }
     }
     /**
     pid = fork();
     if(pid != 0){
       pid2 = fork();
       status = wait();
       ParentProcess(status);
     }
  
      ChildProcess(pid);
      ChildProcess(pid2);
      **/

     /**
     for(i = 0; i < 2; i++){
       pid = fork();
       if(pid == 0)
         ChildProcess(i);
       else if(pid > 0){
           ParentProcess(status);
         }
       else{
         printf("Error in Fork\n");
       }
     }
     **/
}

void  ChildProcess(int pid)
{
     int number;
     int sleep_time;
     srand(time(NULL));
     number = (rand() % 31) + 1;
     sleep_time = (rand() % 10)+1;
  
     int   i;
     int pidID = getpid();
     int parentID = getppid();
    
     if(pid == 0){
      for (i = 0; i < number; i++){
          printf("Child Process:%d is going to sleep!\n", pidID);
          sleep(sleep_time);
          printf("Child Process:%d is awake!\n", pidID);
          printf("Where is my Parent:%d\n", parentID);
        
        exit(1);
      }
     }
    
     //Child Process 2
     else {
       printf("This is the Second Child Process\n");
       for (i = 0; i < number; i++){
         printf("Child Process:%d is going to sleep!\n", pidID);
         sleep(sleep_time);
         printf("Child Process:%d is awake!\n", pidID);
         printf("Where is my Parent:%d\n", parentID);
       }
       exit(1);
     }
  
     /*
     for (i = 1; i <= MAX_COUNT; i++)
          printf("   This line is from child, value = %d\n", i);
     printf("   *** Child process is done ***\n");
     */
}

void  ParentProcess(int status)
{
     //wait(&status);
     printf("Child Process:%d has completed\n", status);
     /*
     int   i;
  
     for (i = 1; i <= MAX_COUNT; i++)
          printf("This line is from parent, value = %d\n", i);
     printf("*** Parent is done ***\n");
     */
}