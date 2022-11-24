# OS_Assignment_2

-----------------------------------README FILE FOR THREAD SCHEDULING-------------------------------------------


1.In Thread scheduling program there are three count functions which counts from 1 to 2^32.
2.There are three THREADS - Thread_1,Thread_2,Thread_3 which call the count functions and with an apropriate scheduling policy. In this case, htere are three shceduling used=SCHED_OTHER, SCHED_FIFO, SCHED_RR
3. All these threads runs with different different priority values.
4. After runnning all the functions using thread, the time consumption in each case is stored in the ".txt" file.
5. Txt file further opened in python program to make a histogram of time-priority-scheduling of threads.
6. There is a Makefile to compile and run all the neccessary files by executing "make" command.


----------------------------------------FOR PROCESS SCHEDULING--------------------------------------------------

1. There are three Processes Doing same work i.e. compiling the base linux kenel source.
2. Each process is then shceduled with appropriate shcheduling method i.e. SCHED_OTHER, SCHED_FIFO, SCHED_RR.
3. All these Process runs with different different priority values.
4. After running each case, their time get stored in an Array.
5. At last the program creates a non-GUI Histogram using "#" characters as we are running this program in CLI Artix-linux.
 
