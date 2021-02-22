#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "public.hpp"

#define SHM_SIZE    1 * 1024 * 1024

static int shm_id;

void signal_handle(int sig_no, siginfo_t * sig_info, void *context) {
    printf("share1 got signal: %d\n", sig_no);

    shmctl(shm_id, IPC_RMID, NULL);
}

int main() {
    //设置中断函数处理
    struct sigaction act;
    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = signal_handle;
    sigemptyset(&act.sa_mask);

    sigaction(SIGINT, &act, NULL);
    sigaction(SIGQUIT, &act, NULL);
    sigaction(SIGSEGV, &act, NULL);
    
    //创建共享内存
    shm_id = create_shm(BASE_ID, SHM_SIZE);
    printf("create shm_id: %d\n", shm_id);

    //写入数据
    int* write_val = (int*) shmat(shm_id, NULL, 0);
    *write_val = 11111;
    printf("share1 is writing: %d\n", *write_val);

    //挂起
    usleep(1 * 60 * 60 * 1000 * 1000);  //sleep 1 hour

    return 0;
}
