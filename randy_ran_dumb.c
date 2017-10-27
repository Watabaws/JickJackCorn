#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>


int main(){
	int rand_id = open("~/dev/random", O_RDWR);

	int rannum[10];
	int i, dun_gon_worked;
	for(i = 0;i < 10; i++){
		int dun_gon_worked = write(rand_id, &rannum[i], 4);
		if(dun_gon_worked == -1){
			printf("errror! %s\n", strerror(errno));
		}
		printf("%d: %d\n", i, rannum[i]);
	}
}
