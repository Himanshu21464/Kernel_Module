There are total 2 files: Diff.patch and a testcase program to check weather our syscall is working or not.


STEP-1: add a syscall entry in syscalls_64.tbl in which is located at "kernelbuild/linux-5.19.10/arch/x86/entry/syscalls/syscalls_64.tbl

STEP-2: Define the syscall "kernel_2D_memcpy" in kernel/sys.c file
STEP-3: Compile the kernel and reboot it.

STEP-4: Compile the testcase program file ("Kernel_2d_memcpy.c" in my case) with gcc.

STEP-5: Run the executable file and it will print the Matrices after using copy_from_user and copy_to_user.
>Data of Matrix B should be copied in Matrix A using the syscall we defined earlier.


------------------------------------------------------------------------------

SYSCALL_DEFINE working:

	1. it takes two matrices, A and B with the no. of rows and column
	2. theres is a 2d array with same no. of rows and column to use the kernel space and user space
	3. copy_from_user copy the data from user space to kernel space and return error if not successful.
	4. copy_to_user copy the data from kernel space to user space and return error if not successful.
	5. whole syscall will return 0 for successful execution and non zero for unsuccessful execution.
	
