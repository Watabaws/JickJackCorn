#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>


int main(){
	int rand_id = open("/dev/random", O_RDWR);

	int rannum[10];
	int i, dun_gon_worked;

	for(i = 0;i < 10; i++){
		int dun_gon_worked = read(rand_id, &rannum[i], 4);
		if(dun_gon_worked == -1){
			printf("error reading! %s\n", strerror(errno));
		}
		printf("original_array[%d]: %d\n", i, rannum[i]);
	}

	int ftw = open("the_array", O_CREAT | O_WRONLY, 0744);
	printf("\n\nWriting to our file!\n\n");
	dun_gon_worked = write(ftw, rannum, sizeof(rannum));
	if(dun_gon_worked == -1){
		printf("error writing! %s\n", strerror(errno));
	}

	int ftr = open("the_array", O_RDONLY);
	int new_randnum[10];
	printf("Reading from our file! \n\n");
	dun_gon_worked = read(ftr, new_randnum, sizeof(new_randnum));
	if(dun_gon_worked == -1){
		printf("error reading! %s\n", strerror(errno));
	}

	for(i = 0; i < 10; i++){
		printf("new_array[%d]: %d\n", i, new_randnum[i]);
	}
}
