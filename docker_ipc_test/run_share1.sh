image_id=2fdf93c10b4e
src_path=/media/server/E/RWJ/docker_ipc_test

docker run\
    -it\
    --ipc=shareable\
    -v ${src_path}:/home/src\
    --name ipc_container1\
    ${image_id}  /bin/bash