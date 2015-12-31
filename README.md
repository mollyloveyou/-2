# pintos-p2-code
p2
task&ideas:

1.进程终止信息。需要实现传递给process_execute()的格式正确的输出。

2.参数传递。现在的Pintos不支持用户程序的正确参数传递。事实上，main()函数初始完毕后并解析完所有的用户命令后，会调用run_action()函数，又如果检测到用户输入了”run”，则调用run_task()运行改程序，进一步调用process_wait()来等待process_execute()完成任务。其中process_execute()的参数列表中只定义了一个变量const char *file_name，就是说它只接收用户程序的文件名为参数，我们需要做的事情是完善它的参数接受列表，使之成为第一个参数为文件名、后面为程序使用参数的形式。
另外，原有的代码会分配一个中断页框if_，这个if_就是用来把本次程序执行的信息传递给中断处理机制让中断来运行程序的。pintos的命令行语句长度最大为128字节。

3.系统调用。在syscall.c中只提供了handles这样的功能，然而查看了该函数后，发现它只是输出了一句”system call!”来告诉开发人员现在进行到了系统调用中，随即退出了当前线程，根据Guide里面接下来的描述，我们需要在syscall.c中添加13个要完成的系统调用，分别为halt, exit, exec, wait, create, remove, open, filesize, read, write, seek, tell及close。其中的前四个为syscall部分，后面九个都与filesys有关。


4.禁止对可执行文件的写功能。由于Pintos没有实现在运行某程序时，它所打开的文件不被修改的功能，很可能因为被其他程序修改而造成意想不到的后果。在file.c的struct file中已经为file定义了bool deny_write的属性以判断是否不允许被写，同时提供了file_deny_write()和file_allow_write()的接口。我们需要在适当地方调用这两个函数以控制文件允许/不允许被写。

5.处理地址指针越界。在五部分任务开始前我曾经提到了用户虚拟空间和内存虚拟空间所在的地址范围，为了保证在各态能够正确地访问对应的内容，比如向内核态传递了一个地址指正，这个指针为空或者指向的位置比PHYS_BASE低的情况，我们需要对指针进行越界处理
