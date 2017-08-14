# <img src="https://www.holbertonschool.com/assets/holberton-logo-simplified-71b02868461c07d54553e4a7cc05d1926681a6755cc19030b0458f2d70ae9909.png" width="30"> Monty Project (0x18: C - Stacks, Queues - LIFO, FIFO)

**Authors: [Thomas Wang](https://www.linkedin.com/in/thomaspwang/) and [Larry Madeo](https://www.linkedin.com/in/larry-madeo-904a7129/)**

<img src ="https://pbs.twimg.com/media/CFYYWy6UEAE9Ow-.png" width
="300">

## Monty

### Synopsis
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Table of Contents

* [Resources](#resources)
* [What students should learn from this project](#what-students-should-learn-from-this-project)
* [Requirements](#requirements)
* [Compilation](#compilation)
* [Tests](#tests)
* [Project Breakdown](#project-breakdown)

## Resources

<p>Read <a href="https://www.google.com/webhp?sourceid=chrome-instant&amp;rlz=1C1CHFX_enUS688US688&amp;ion=1&amp;espv=2&amp;ie=UTF-8#q=stack%20and%20queue">Google</a>, <a href="http://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files-in-c">How do I use extern to share variables between source files in C?</a>, and <a href="https://github.com/blog/2104-working-with-submodules">Working with submodules</a>.</p>

## What students should learn from this project

At the end of this project you are expected to be able to explain to anyone, without the help of Google:
- What is LIFO and FIFO
- What is a stack, and when to use it
- What is a queue, and when to use it
- What are the common implementations of stacks and queues
- What are the most common use cases of stacks and queues
- What is the proper way to use global variables
- How to work with git submodules

## Requirements

<ul>
<li>Allowed editors: <code>vi</code>, <code>vim</code>, <code>emacs</code></li>
<li>All your files will be compiled on Ubuntu 14.04 LTS</li>
<li>Your programs and functions will be compiled with <code>gcc 4.8.4</code> using the flags <code>-Wall</code> <code>-Werror</code> <code>-Wextra</code> <code>and -pedantic</code></li>
<li>All your files should end with a new line</li>
<li>A <code>README.md</code> file, at the root of the folder of the project is mandatory</li>
<li>Your code should use the <code>Betty</code> style. It will be checked using <a href="https://github.com/holbertonschool/Betty/blob/master/betty-style.pl">betty-style.pl</a> and <a href="https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl">betty-doc.pl</a></li>
<li>You allowed to use a maximum of one global variable</li>
<li>No more than 5 functions per file</li>
<li>You are allowed to use the C standard library</li>
<li>The prototypes of all your functions should be included in your header file called <code>monty.h</code></li>
<li>Don&#39;t forget to push your header file</li>
<li>All your header files should be include guarded</li>
<li>You are expected to do those tasks in the order shown in the project</li>
<li>The repository <code>monty</code> should be added as a submodule to your <code>holbertonschool-low_level_programming</code> repository, under the name <code>0x18-stacks_queues_lifo_fifo</code></li>
<li>Please use those data structures for this project:</li>
</ul>

<pre><code>/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
</code></pre>

<pre><code>/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
</code></pre>

## Compilation

<ul>
<li>Your code will be compiled this way:</li>
</ul>

<pre><code>$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
</code></pre>

## Tests

We strongly encourage you to work all together on a set of tests

## Project Breakdown

### 1. push, pall (Mandatory)

<p>Implement the <code>push</code> and <code>pall</code> opcodes.</p>
<p><strong>Monty byte code files</strong></p>

<p>Files containing Monty byte codes usually have the <code>.m</code> extension. Most of the industry uses this standard but it is not required by the specification of the language.
There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:</p>

<pre><code>julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$
</code></pre>

<p>Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:</p>

<pre><code>julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$
</code></pre>

<p><strong>The monty program</strong></p>

<ul>
<li>Usage: <code>monty file</code></li>
<li>where <code>file</code> is the path to the file containing Monty byte code</li>
<li>If the user does not give any file or more than one argument to your program, print <code>USAGE: monty file</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
<li>If, for any reason, it&#39;s not possible to use read the file, print <code>Error: Can&#39;t open file &lt;file&gt;</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code>

<ul>
<li>where <code>&lt;file&gt;</code> is the name of the file</li>
</ul></li>
<li>If the file contains an invalid instruction, print <code>L&lt;line_number&gt;: unknown instruction &lt;opcode&gt;</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code>

<ul>
<li>where <line_number> is the line number where the instruction appears. Line numbers always start at 1</li>
</ul></li>
<li>The monty program runs the bytecodes line by line and stop if:

<ul>
<li>it executed properly every line of the file</li>
<li>or it finds an error in the file</li>
<li>or an error occured</li>
</ul></li>
<li>If you can&#39;t malloc anymore, print <code>Error: malloc failed</code>, followed by a new line, and exit with status <code>EXIT_FAILURE</code>. You have to use <code>malloc</code> and <code>free</code> and are not allowed to use any other function from <code>man malloc</code></li>
</ul>

<p><strong>The push opcode</strong></p>

<p>The opcode <code>push</code> pushes an element to the stack.</p>

<ul>
<li>Usage: <code>push &lt;int&gt;</code></li>
<li>where <code>&lt;int&gt;</code> is an integer</li>
<li>if <code>&lt;int&gt;</code> is not an integer or if there is no argument to <code>push</code>, print the message <code>L&lt;line_number&gt;: usage: push integer</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code>

<ul>
<li>where <line_number> is the line number in the file</li>
</ul></li>
<li>You don&#39;t have to deal with overflows. Use the <code>atoi</code> function</li>
</ul>

<p><strong>The pall opcode</strong></p>

<p>The opcode <code>pall</code> prints all the values on the stack, starting from the top of the stack.</p>

<ul>
<li>Usage <code>pall</code></li>
<li>Format: see example</li>
<li>If the stack is empty, don&#39;t print anything</li>
</ul>

<pre><code>julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ ./monty bytecodes/00.m
3
2
1
julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$
</code></pre>

### 2. pint (Mandatory)
<p>Implement the <code>pint</code> opcode.</p>
<p>The opcode <code>pint</code> prints the value at the top of the stack, followed by a new line.</p>

<ul>
<li>Usage: <code>pint</code></li>
<li>If the stack is empty, print <code>L&lt;line_number&gt;: can&#39;t pint, stack empty</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
</ul>

<pre><code>julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ cat bytecodes/06.m 
push 1
pint
push 2
pint
push 3
pint
julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ ./monty bytecodes/06.m 
1
2
3
julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ 
</code></pre>

### 3. pop (Mandatory)
<p>Implement the <code>pop</code> opcode.</p>
<p><strong>The pop opcode</strong></p>

<p>The opcode <code>pop</code> removes the top element of the stack.</p>

<ul>
<li>Usage: <code>pop</code></li>
<li>if the stack is empty, print <code>L&lt;line_number&gt;: can&#39;t pop an empty stack</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
</ul>

<pre><code>julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ cat bytecodes/07.m 
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ ./monty bytecodes/07.m 
3
2
1
2
1
1
julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ 
</code></pre>

### 4. swap (Mandatory)
<p>Implement the <code>swap</code> opcode.</p>
<p><strong>The swap opcode</strong></p>

<p>The opcode <code>swap</code> swaps the top two elements of the stack.</p>

<ul>
<li>Usage: <code>swap</code></li>
<li>If the stack is less than two element long, print <code>L&lt;line_number&gt;: can&#39;t swap, stack too short</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
</ul>

<pre><code>julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ cat bytecodes/09.m 
push 1
push 2
push 3
pall
swap
pall
julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ ./monty bytecodes/09.m 
3
2
1
2
3
1
julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ 
</code></pre>

### 5. add (Mandatory)
<p>Implement the <code>add</code> opcode.</p>
<p><strong>The add opcode</strong></p>

<p>The opcode <code>add</code> adds the top two elements of the stack.</p>

<ul>
<li>Usage: <code>add</code></li>
<li>If the stack is less than two element long, print <code>L&lt;line_number&gt;: can&#39;t add, stack too short</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
<li>The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

<ul>
<li>the top element of the stack contains the result</li>
<li>the stack is one element shorter</li>
</ul></li>
</ul>

<pre><code>julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ cat bytecodes/12.m 
push 1
push 2
push 3
pall
add
pall

julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ ./monty bytecodes/12.m 
3
2
1
5
1
julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$
</code></pre>

### 6. nop (Mandatory)
<p>Implement the <code>nop</code> opcode.</p>
<p><strong>The nop opcode</strong></p>

<p>The opcode <code>nop</code> doesn&#39;t do anything.</p>

<ul>
<li>Usage: <code>nop</code></li>
</ul>