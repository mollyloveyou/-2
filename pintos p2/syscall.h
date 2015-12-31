#ifndef USERPROG_SYSCALL_H
#define USERPROG_SYSCALL_H

void syscall_init (void);

//add by sjl for syscall
int sys_exit (int status);
//add end

#endif /* userprog/syscall.h */
