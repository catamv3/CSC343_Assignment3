Michael Catalanotti
CSC 343
Assignment 3
2/23/25
1. When a process creates a new process using the fork() operation, which of the following state is shared which are not between the parent process and the child process? Explain your answers couple of sentences.
When a process creates a new process using fork, shared memory segments are the only states
shared between the child and parent process. Respectively, when fork() is called on a process,
the child process will still have access to the parents shared memory segments–such as file descriptors.
Alternatively, the child process does not have access to either the parents heap or stack.
Once a child process is created, memory is allocated to the child process for a unique stack/heap.


2. Discuss Apple’s mobile iOS and android operating system services for concurrent processing. Discuss three major complications that concurrent processing adds to an operating system. 
	
In computing, concurrent processing refers to a system's ability to divide its resources 
to several tasks “seemingly” at the same time. While these processes are handled within milliseconds
of each other, this architectural approach significantly allows computers to handle several 
tasks nearly simultaneously. To provide this functionality, there are three major complications 
that multitasking adds to an OS. First off, the OS must be able to synchronize the exchange of data 
between various aspects of the system. Should an OS fail to guarantee to connect data produced 
with other areas of the system it is needed, the entire system  fails to achieve concurrency. 
As iPhones/Androids increase their hardware, this provides more difficulty for an OS to securely 
and reliably interact with all parts of the system. Furthermore, switching between current processes 
causes significant overhead–the energy required to manages all devices. When computing large amounts 
of data, these smaller mobile systems must implement performance algorithms or use efficient hardware
to maintain a consistent performance. The more a CPU is used, the greater the strain on the batteries
of these devices. Lastly,  where switching from one process to another requires a lot of energy on
the system, this at least assumes the processes have full access to the system resources. 
Evidently, more often than not, this is not the case as several processes are fighting one
another for a single system resource. The last complexity of concurrent programming is to 
ensure appropriate ways processes can access system resources and at the necessary time, 
while still sticking to a schedule of other necessary processes.
