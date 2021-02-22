# super-jingjing-journey
#### demo用于测试docker容器间的IPC通信

1. run_share1.sh启动容器1，作为共享内存提供者(--ipc=shareable)
2. run_share2.sh启动容器2，作为共享内存使用者(--ipc=container:ipc_container1)
3. sh脚本中注意修改image_id和src_path
4. 两个cpp利用Makefile编译成可执行程序，既可以在宿主机上编译，也可在容器内编译
5. 容器1中进入/home/src，执行./share1，将数据写入共享内存
6. 容器2中进入/home/src，执行./share2，从共享内存中读数据
