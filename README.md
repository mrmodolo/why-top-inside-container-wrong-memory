# Why top and free inside containers don't show the correct container memory

[Why top and free inside containers don't show the correct container memory](https://ops.tips/blog/why-top-inside-container-wrong-memory/)

Go through the reason why free and top show the host's memory instead of container memory.
by Ciro S. Costa - Oct 12, 2018

## Below are some changes to work on Ubuntu 20.04 with swap

docker run --rm  --interactive --tty --memory "$((1024 * 1024 * 10))" ubuntu

## How the top and free tools gather memory statistics
strace -f free 2>&1 | less

echo "$((1024 * 1024 * 10))" >/sys/fs/cgroup/memory/custom-group/memory.limit_in_bytes
echo "$((1024 * 1024 * 10))" >/sys/fs/cgroup/memory/custom-group/memory.memsw.limit_in_bytes

root@ur:~# cgexec -g memory:/custom-group ./a.out
allocating: 20MB
remaining	19
remaining	18
remaining	17
remaining	16
remaining	15
remaining	14
remaining	13
remaining	12
remaining	11
Morto

## Resource Management Guide
[memory](https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/6/html/resource_management_guide/sec-memory)

## An introduction to bpftrace for Linux
https://opensource.com/article/19/8/introduction-bpftrace

## Everything You Need to Know about Linux Containers, Part I: Linux Control Groups and Process Isolation
https://www.linuxjournal.com/content/everything-you-need-know-about-linux-containers-part-i-linux-control-groups-and-process

