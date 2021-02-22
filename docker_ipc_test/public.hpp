#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define IPC_DIR     "/tmp"
#define BASE_ID     12000

int create_shm(int key, unsigned int size) {

	// key_t key = ftok(IPC_DIR, key_id);
	int shmID = shmget(key, size, IPC_CREAT | IPC_EXCL | 0666);
	if (-1 == shmID) {
		if (EEXIST == errno) {
			//LOGD("search shm has exist\n");
			shmID = shmget(key, 0, 0);
			shmctl(shmID, IPC_RMID, NULL);

			shmID = shmget(key, size, IPC_CREAT | IPC_EXCL | 0666);
			if (-1 == shmID) {
				printf("shared memory alloc failed\n");
			}
		} else {
			printf("shared memory create failed\n");
		}
	}

	return shmID;
}


int get_shm(int key) {
	// key_t key = ftok(IPC_DIR, key_id);
	return shmget(key, 0, 0);
}