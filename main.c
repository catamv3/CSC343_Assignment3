/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h> 
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h> 
  
int main() { 
 
 //create an arry of size 20
 int arr [20];
 int arrsize=sizeof(arr)/sizeof(int);
 
 //variables to keep track of of start/finish pointers in the array
 int start, end;
 //variable to store computed minimum of the whole array.
 int arrayMinimum;
 
 
 //fill array with 20 randomly genetated integers
 srand(time(NULL));
 for(int i = 0; i < arrsize; i++){
     arr[i] = rand() % 10 + 1;
 }
 
 //prints out the array with a seperation to help visualize items stored in the array.
 for(int i =0; i < arrsize; i++){
     if(i == arrsize/2){
         printf("\n\n\n");
     }
     printf("%d.\t%d\n", i,arr[i]);
 }
 
 //create a pipe 
 int fd[2];
 if(pipe(fd) == -1){
     return 1; 
 }
 //create process id variable to track which process is which. 
 int id = fork();
 if(id == -1){
     return 1; 
 }
 
 //if the child process, start from middle array
 if(id == 0){
     start = arrsize/2;
     end = arrsize;
 }else{ //if it's the parent process, begin at the beginning of the array
     start = 0;
     end = arrsize;
 }
 
 //loop through each mini array and compare values to determine the minimum. 
 int min = arr[start];
 for(int i = start; i < end; i++){
     if(arr[i] < min){
         min = arr[i];
     }
 }
 
 //put data from child process into correct pipe
 if(id == 0){
     close(fd[0]);
     write(fd[1], &min, sizeof(min));
     close(fd[1]);
     printf("child's process id is  %d\n",getpid());
 }else{
     //in the aprent process, read the data written by the file process. 
     int childMin;
     close(fd[1]);
     read(fd[0],&childMin, sizeof(childMin));
     close(fd[0]);
     printf("parent's process id is  %d\n",getpid());
     printf("Minimum value from the child process is %d\n",childMin );
     
     printf("Minimum value from the parent process is %d\n", min);
    //calculate minimum value across whole array 
    if(childMin < min){
        arrayMinimum= childMin;
    } else {
        arrayMinimum= min;
    }
    printf("Minimum number of whole array:\t%d\n", arrayMinimum);
     wait(NULL);   
 }
    
  
 
return 0;
}
