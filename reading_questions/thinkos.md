## Chapter 1


### Compilation

1) Give an example of a feature common in interpreted languages that is rare in compiled languages.

Dynamic types are supported by interpreted languages, but not in compiled languages.

2) Name two advantages of static typing over dynamic typing.

allows you to catch errors before you run your code, safer than runtime erros

3) Give an example of a static semantic error.

errors that can be checked without actually understanding the program

4) What are two reasons you might want to turn off code optimization?

can change bugs and make them "appear or disappear", cut down on compile time

5) When you run `gcc` with `-S`, why might the results look different on different computers?

assembly code, looks different with different architechtures

6) If you spell a variable name wrong, or if you spell a function name wrong, the error messages you get might look very different.  Why?

so that you can understand what you did wrong.


7) What is a segmentation fault?

if you try to read or write an incorrect location in memory

## Chapter 2


### Processes

1) Give a real-world example of virtualization (ideally not one of the ones in the book).

The Netflix Delivery service makes it seem like I have access to every DVD out there, but those same DVDs are also brought to countless other people.

2) What is the difference between a program and a process?

A process is a software object that represents a running program and a program. All of the information that a program uses is stored in a data structure that is a process.

3) What is the primary purpose of the process abstraction?  What illusion does the process abstraction create?

The primary purpose of abstraction is so that users can interact with complex systems without knowing all of the details. This abstraction creates the illusion that there are a ton of CPUs and that the network that a machine is on is all of the networks.

4) What is the kernel?

The kernel is the part of the operating system that creates most of the core capabilities, like threading.

5) What is a daemon?

A daemon is a process that runs in the background and provides operating system services.

## Chapter 3


### Virtual memory
## Chapter 3


### Virtual memory

1) The Georgian alphabet has 33 letters.  How many bit are needed to specify a letter?

log233

2) In the UTF-16 character encoding, the binary representation of a character can take up to 32 bits. Ignoring the details of the encoding scheme, how many different characters can be represented?

4294967296

3) What is the difference between "memory" and "storage" as defined in Think OS?

Memory is used to store short-term data, typically kept in the RAM, and is volatile, so it is lost when the computer shuts down. Storage is used for long-term storage, kept in the physical drive, and non-volatile.

4) What is the difference between a GiB and a GB?  What is the percentage difference in their sizes?

A GiB is a gibibyte and a GB is a gigabyte, 2^30 and 10^9 bytes respectively. They have a 7% difference in size.

5) How does the virtual memory system help isolate processes from each other?

"a process cannot access data belonging to another process, because there is no virtual address it can generate that maps to physical memory allocated to another proces"

6) Why do you think the stack and the heap are usually located at opposite ends of the address space?

This allows them to grow in directions away from each other as they expand.

7) What Python data structure would you use to represent a sparse array?

Dictionary

8) What is a context switch?

A context switch is the mechanism that allows the operating system to to interrupt a running process, save its state, and run another process.

In this directory, you should find a subdirectory named `aspace` that contains `aspace.c`.  Run it on your computer and compare your results to mine.

Address of main is 0x40057d
Address of global is 0x60104c
Address of local is 0x7fffa0899044
Address of p is 0x2463010
  
1) Add a second call to `malloc` and check whether the heap on your system grows up (toward larger addresses).

Yes

2) Add a function that prints the address of a local variable, and check whether the stack grows down. 

No

3) Choose a random number between 1 and 32, and allocate two chunks with that size.  
How much space is there between them?  Hint: Google knows how to subtract hexadecimal numbers.

32 in decimal and 0x20 in hexadecimal


## Chapter 4


### Files and file systems

1) What abstractions do file systems provide?  Give an example of something that is logically true about files systems but not true of their implementations.

File systems provide the abstraction that a file's name maps to its contents and that files are a sequence of bytes. Abstractly, file systems are byte-based, whereas the actual implementation of persistent storage is block-based.

2) What information do you imagine is stored in an `OpenFileTableEntry`?

?????????????????

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?

Running other processes while waiting for a new block to be stored in memory, reading multiple blocks at once, prediciting future block reads and begin loading before requested, storing written files in memory and later writting to a disk which allows for file modification before block loading, and the os also keeps a copy of recently used blocks in memory allowing for faster use.

4) Suppose your program writes a file and prints a message indicating that it is done writing. Then a power cut crashes your computer.  After you restore power and reboot the computer, you find that the file you wrote is not there.  What happened?

The file was still in the stages of buffering. When a program write a file, the OS stores that in memory and writes it onto a block later. This is done for the sake of efficiency, but it is not great in this situation.

5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?

A FAT can find empty files to be written faster than a UNIX inode, but because the files are not held continuously they are slower. I used [this resource](http://web.cs.ucla.edu/classes/fall10/cs111/scribe/11a/)

6) What is overhead?  What is fragmentation?

Overhead is the amount of space that the data structure allocator uses. Framentation is chunks of unused space.

7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?

It allows for abstraction in other systems which can make them easier to understand and work with because you don't have to understand the small details. It could be bad because it might not be true for everything and might cause certain errors.

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.  
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then 
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).  
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).


## Chapter 5


### Bits and bytes

1) Suppose you have the value 128 stored as an unsigned 8-bit number.  What happens if you convert 
it to a 16-bit number and accidentally apply sign extension?

2) Write a C expression that computes the two's complement of 12 using the XOR bitwise operator. 
Try it out and confirm that the result is interpreted as -12.

3) Can you guess why IEEE floating-point uses biased integers to represent the exponent rather than a
sign bit or two's complement?

4) Following the example in Section 5.4, write the 32-bit binary representation of -13 in single precision 
IEEE floating-point.  What would you get if you accidentally interpreted this value as an integer?

5) Write a function that takes a string and converts from lower-case to upper-case by flipping the sixth bit.  
As a challenge, you can make a faster version by reading the string 32 or 64 bits at a time, rather than one
character at a time.  This optimization is made easier if the length of the string is a multiple of 4 or 8 bytes.



## Chapter 6


### Memory management

1) Which memory management functions would you expect to take constant time?  Which ones take time proportional to the size of the allocated chunk?

2) For each of the following memory errors, give an example of something that might go wrong:

a) Reading from unallocated memory.

b) Writing to unallocated memory.

c) Reading from a freed chunk.

d) Writing to a freed chunk.

e) Failing to free a chunk that is no longer needed.


3) Run

    ps aux --sort rss

to see a list of processes sorted by RSS, which is "resident set size", the amount of physical 
memory a process has.  Which processes are using the most memory?

4) What's wrong with allocating a large number of small chunks?  What can you do to mitigate the problem?

If you want to know more about how malloc works, read 
[Doug Lea's paper about dlmalloc](http://gee.cs.oswego.edu/dl/html/malloc.html)



## Chapter 7


### Caching

1) What happens if a program writes a new value into the program counter?

2) What is the fundamental problem caches are meant to solve?

3) If cache access time is 1 ns and memory access time is 10 ns, what is the average
access time of a program with hit rate 50%?  How about 90%?

4) The book gives several examples of programming language features, like loops, that tend 
to improve locality in the access pattern of instructions and/or data.  Can you think of other examples?  
Or counter-examples that might decrease locality?

5)  If you refactor a program to improve locality, would you say the program is "cache aware"?  Why not?

6) See if you can estimate the cost of a memory cache by comparing the prices of two similar CPUs with 
different cache sizes.

7) Why are cache policies generally more complex at the bottom of the memory hierarchy?

8) Can you think of a strategy operating systems could use to avoid thrashing or recover when it occurs?

Run the cache code on your laptop or another computer and see if you can infer the cache size and block size.  
If you can find the technical specifications for your computer, see if your inferences are right.

1) In this directory you should find a subdirectory named `cache` that contains `cache.c` and supporting files.  Read `cache.c`, then run `make` and `./cache`.

2) Run `python graph_data.py` to see the results.  What can you infer about the cache structure on your computer?


## Chapter 8


### Multitasking

1) What is the kernel's most basic task?

2) When an interrupt occurs, what part of the hardware state is saved by hardware?

3) What is the difference between an interrupt and a context switch?

4) Give an example of an event that might cause a process to move from the blocked to the ready state.

5) Why might a scheduler want to give higher priority to an I/O bound process?

When I make French toast, I usually make a batch of 12 slices.  But my griddle only has room for 8 slices.  Each piece of toast has to cook for 5 minutes on each side.  How can I schedule 12 slices onto 8 "cores" to minimize the elapsed time to cook all 12 slices?  (Note: this question is not hypothetical; this is really how I make French toast.)



## Chapter 9


### POSIX threads and mutexes

As you read Chapter 9, you should compile and run the example code.  By the nature of multi-threaded programs, you results will probably be different from mine, possibly in interesting ways.

1) Why does each thread have its own stack?

2) What does the `gcc flag -lpthread` do?

3) What does the argument of `pthread_exit` do?

4) Normally the same thread that created a thread also waits to join it.  What happens if another thread tries to join a thread it did not create?

5) What goes wrong if several threads try to increment a shared integer at the same time?

6) What does it mean to "lock a mutex"?



## Chapter 10


### Condition variables

1) What does it mean to say that a data structure is thread safe?

2) In the circular buffer implementation of a queue, why is the maximum number of elements in the queue `n-1`,
if `n` is the size of the array?

3) If there is no mutex to protect the queue, give an example of a sequence of steps that could leave
the queue in an inconsistent state.

4) When a thread calls cond_wait, why does it have to unlock the mutex before blocking?

5) When a thread returns from cond_wait, what do we know is definitely true?  What do we think is probably true?

6) What happens if you signal a condition variable when there are no waiting threads?

7) Do you have to lock the mutex to signal a condition variable?

8) Does the condition have to be true when you signal a condition variable?


 
## Chapter 11


### Semaphores in C
