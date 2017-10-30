#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>


// reads and returns a single integer from /dev/random
int generate_random(){
  int i, rand_id;
  rand_id = open("/dev/random", O_RDWR);
  int success = read(rand_id, &i, sizeof(int));
  close(rand_id);
  return i; 
	}

int main(){

  // fill array with random ints and print them out
  printf("generate random numbers:\n");
  int rannum[10];
  int i;
  for(i = 0;i < 10; i++){
    rannum[i] = generate_random();
    printf("%d: %d\n", i, rannum[i]);
  }
  
  //create new file and write contents of array to that file
  int dun_gon_worked;
  int ftw = open("the_array", O_CREAT | O_WRONLY, 0744);
  printf("\n\nWriting to our file!\n\n");
  dun_gon_worked = write(ftw, rannum, sizeof(rannum));
  if(dun_gon_worked == -1){ // check that file was written to without errors
    printf("error writing! %s\n", strerror(errno));
  }
  close(ftw);

  // read array file and copy its contents to a new array, then print the new array for verification
  int ftr = open("the_array", O_RDONLY);
  int new_randnum[10];
  printf("Reading from our file! \n\n");
  dun_gon_worked = read(ftr, new_randnum, sizeof(new_randnum));
  if(dun_gon_worked == -1){
    printf("error reading! %s\n", strerror(errno));
  }
  close(ftr);
  
  for(i = 0; i < 10; i++){
    printf("new_array[%d]: %d\n", i, new_randnum[i]);
  }
}

