#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "public.hpp"

int main() {
    int shm_id = get_shm(BASE_ID);
    printf("get shm_id: %d\n", shm_id);
    if (shm_id == -1) {
        printf("get_shm error: %s\n", strerror(errno));
        return -1;
    }

    int* read_val = (int*) shmat(shm_id, NULL, 0);
    
    printf("share2 is reading: %d\n", *read_val);
    
    // usleep(1 * 60 * 1000 * 1000);  //sleep 1 min

    shmdt(read_val);

    return 0;
}