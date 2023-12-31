# Linux笔记

```
本地linux地址:192.168.142.131 centos
```

```
centos账号:beginagain 密码:qwer1234

进入图形化界面:startx
```

```
文件权限
```

```
查看ubuntu版本:cat /proc/version


vim状态下按键
: 进入命令行模式
wq: 写入并退出		q: 退出		!q: 强制退出,不保存
nyy+p 复制当前行向下n行并粘贴
ndd 删除当前行向下n行	
命令行下/关键字+回车 查找关键字,输n就是查找下一个
命令行下set nu 显示行数

查看linux IP地址:ifconfig //inet 后就是 



终端快捷键
```

```
防火墙
CentOs
	查看防火墙状态:firewall-cmd --state
	启动防火墙:systemctl start firewalld.service
	重启防火墙:systemctl restart firewalld.service
	重新载入防火墙配置:firewall-cmd --reload
	查看对应端口是否开启:firewall-cmd --zone=public --list-3306//
	开启指定端口:firewall-cmd --zone=public --add-port=端口号/tcp --permanent
			//-zone=public 作用于为公共的  -add-port=端口号/tcp 添加tcp协议端口
			//-permanent 说明永久生效
```

## 相关命令

#### 文件或目录访问权限

```
chmod [ugoa][[+-=][rwxX]...][...]

u 表示该文件的拥有者，g 表示与该文件的拥有者属于同一个群体(group)者，o 表示其他以外的人，a 表示这三者皆是。
+ 表示增加权限、- 表示取消权限、= 表示唯一设定权限。
r 表示可读取，w 表示可写入，x 表示可执行，X 表示只有当该文件是个子目录或者该文件已经被设定过为可执行

-c : 若该文件权限确实已经更改，才显示其更改动作
-f : 若该文件权限无法被更改也不要显示错误讯息
-v : 显示权限变更的详细资料
-R : 对目前目录下的所有文件与子目录进行相同的权限变更(即以递回的方式逐个变更)

查看文件访问权限:ls -l

程序 & 让程序在后台运行
```



## 编程

### 编译步骤

```
预处理->编译->汇编->链接
hello.c-预处理->hello.i-编译->hello.s-汇编->hello.o-链接->可执行文件
.c:源文件
.i:处理源文件
.s:汇编源文件
.o:目标文件
预处理：
	1、展开宏、头文件
	2、替换条件编译
	3、删除注释、空行、空白	
编译：检查语法规则，消耗时间和系统资源最多
汇编：将汇编指令翻译为机器指令
链接：数据段合并，地址回填
	地址回填：回填链接好后main函数的地址，因为main函数包含的所有函数的位置都是相对于main函数的位置
```

![image-20230922165257567](../../pic/linux/gcc/gcc_tip.png)

### 参数

1、-I（大写i）	指定头文件所在目录

2、-c	只做预处理、编译、汇编工作

3、-g	生成调试包含调试信息

4、-On	n=0~3	编译优化，n越大优化得越多

5、Wall	提示更多警告信息

6、-D<DEF>	编译时定义宏，注意-D和<DEF>间没有空格

7、-E	生成预处理文件

8、-M	生成.c文件与头文件依赖关系以用于makefile，包括系统库的头文件

9、-MM	生成.c与头文件依赖关系以用于makefile，不包括系统库的头文件



### 静态库和共享库

**库**

概念：所谓库就是一段已经编译好的二进制代码，加上头文件就可以供别人使用。之所以使用库而不是头文件，一是可以隐藏源代码，通过库的形式封装，只留头文件；二是对于不会有很大改动的代码进行打包，减少编译的时间，使用时链接就好

**静态库**

概念：静态库即静态链接库（WIN下的.lib和Linux/Mac下的.a），之所以叫静态，是因为编译时会被直接拷贝一份复制到目标程序，这段代码在目标程序里就不会改变了

优点：编译完成后源库文件就没有作用了，目标程序没有外部依赖可以直接运行，速度快

缺点：使目标程序的体积增大

**动态库**

概念：动态库即动态链接库（WIN下的.dll，Linux下的.so和Mac下的.dylib），动态库在编译时不会被拷贝到目标程序，目标程序存储指向动态库的引用，等待程序运行时再加载动态库

优点：不会影响目标程序体积，且一个库可以被多个程序使用（故而也称为共享库）。又因为运行时才载入，对动态库修改不用重新编译整个程序

缺点：动态库使得程序依赖外部环境，若环境缺少或者库版本不正确会使程序无法运行

#### 库的创建和使用

```
基本语法：ar rcs lib库名.文件类型（根据库的类型而定，静态为a，动态为so） 制作库所用目标文件.o

头文件守卫：防止头文件被重复包含
	#ifndef _头文件名_H
	#define _头文件名_H
		...
	#endif
	//#pragma once同理

静态库
	1、将源文件生成为目标文件
	2、使用ar工具制作静态库
		ar rcs lib库名.a file.o...	//省略号表示可能的材料文件,伪代码
	3、编译静态库到可执行文件中
		gcc 源码文件名.cpp 库名.a -o 生成文件名 -I 头文件路径
		
动态库
	1、将源文件生成为目标文件（生成与位置无关的代码 -fPIC）
		gcc 源码名.cpp -o 目标文件名.o -fPIC
	2、使用gcc -shared制作动态库
		gcc -shared lib库名.so 材料目标文件
	3、编译可执行文件时，指定所使用的动态库。 -l：指定库名	-L：指定库路径（绝对路径）		
	4、运行可执行文件
		//库环境配置，否则可执行文件无法运行
		链接器：工作于链接阶段，工作时需要-l和-L
		动态链接器：工作于程序运行阶段，工作时需要提供动态库所在目录位置
			1、通过环境变量：export LD_LIBRARY_PATH=动态库路径//临时生效，终端重启环境变量失效
			
			2、永久生效：写入终端配置文件.bashrc
				1）vi ~/.bashrc
				2）写入export LD_LIBRARY_PATH=动态库路径，保存
				3）..bashrc或source .bashrc	重启终端 -->让修改后的。bashrc生效
			3、拷贝自定义动态库到/lib（标准C库所在目录）
			4、配置文件法
				1）sudo vi /etc/ld.so.conf
				2）写入动态库绝对路径 保存
				3）sudo ldconfig -v s
```



### Makefile

**规则**

 	目标：依赖

​	[一个tab缩进]	命令语句

**Makefile函数**

src = $(wildcard *.c)	//找到当前目录下所有后缀为.c的文件组成列表赋值给src

​		//src对应变量，$()对应函数调用，亦可作为取变量值，wildcard对应函数名，*.c表示函数参数

obj = $(patsubst %.c,%.o,$(src))	//把src变量里所有后缀为.c的文件替换成.o

clean：//清除规则，没有依赖条件，只有执行对象

​	-rm -rf  $(obj) 	//执行make clean后执行，强制删除$(obj)，-rm是为了防止obj有的文件已经被删除不存在，-的作用就是被删文件不存在时不报错，顺序执行结束

​	//make clean -n	输出makefile里clean命令，用于检查删除文件是否有误，并非真的执行



**自动变量(只能出现在命令位置)**

$@：表示规则中的目标

$^：表示规则中所有依赖条件

$<：表示规则中的第一个依赖条件。若将该变量应用于模式规则中，其可将依赖条件列表中的依赖一次



**模式规则**

%.o:%.c

​	gcc -c $< -o %@

**静态模式规则**

$():%.o:%.c	//表面括号内变量寻找模式规则时指定为冒号后的模式规则

​	gcc -c $< -o %@

**伪目标**

.PHONY:clean ALL

作用：

1、避免命令与目录下的文件名重复

```
clean:
	rm  -f *.o temp
如果当前目录下没有名为“clean”的文件，则rm指令会被执行。如果有的话，由于clean没有依赖文件，所以目标被认为是最新的而不去执行rm指令，伪目标可以避免这种情况
```

2、make的并行和递归执行

3、生成多个应用程序

```
在Makefile中第一个目标即最后要生成的文件，如果想在一个目录下创建多个可执行程序，可以用伪目标“all”作为第一个目标。

#sample Makefile
all : prog1 prog2 prog3
.PHONY : all
prog1 : prog1.o utils.o
	cc -o prog1 prog1.o utils.o
prog2 : prog2.o
	cc -o prog2 prog2.o
prog3 : prog3.o sort.o utils.o
	cc -o prog3 prog3.o sort.o utils.o 

make prog1/prog2/prog3可以单独生成其中一个可执行程序
```

#### make命令

1、make -B	//让所有目标重新建立

2、make -d	//选项打印调试信息

​						//| more，选择分页显示输出

3、make -C	//选项改变目录，-C后可跟生成文件存放目录

4、make -f	//将重命名 Makefile 文件，比如取名为 my_makefile 或者其它的名字，我们想让 make 将它也当成 Makefile，可以使用 -f 选项

### GDB



#### core

**core的产生**	在linux下程序不寻常退出时，内核会在当前工作目录下生成一个core文件（是一个内存映像，同时加上调试信息）。使用gdb来查看core文件，可以指示出导致程序出错的代码所在文件和行数

**core文件的生成开关和大小限制**

`ulimit -c`	可查看core文件的生成开关，若为0，则不会生成core文件

`ulimit -c filesize`	可限制core文件的大小，单位为kbyte

​	若生成信息超过限制大小，会被剪裁，从而生成一个不完整的core文件或者根本不生成

`ulimit -c unlimited`	设置core文件大小不受限制

`ulimit -c 0`	设置core文件生成关闭

`ulimit -a`	查看所有用户设置

​	**注：ulimit命令设置只对一个终端有效**

**core文件名称和生成路径**

core文件生成路径：输入可执行文件运行命令的同一路径下。若系统生成的core文件不带其它任何扩展名称，则全部命名为core；新生成的core会覆盖原有core

## IO

### 概念

```
流是什么?
	1.可以进行I/O操作的内核对象
	2.文件、管道、套接字
	3.流的入口:文件描述符(fd)
I/O操作:有关对流的读写操作

阻塞等待:线程自己发现没资源，获取不到资源，它自己先去休息了，有资源它会自己回来，而且不占用CPU
等待忙询:线程找不到资源就一直等，并且将CPU占据
睡眠:CPU告诉线程，你先去休息，过规定时间，你自己回来
挂起:CPU告诉线程你先去休息，有资源我告诉你。它会释放CPU

多路I/O是什么?
阻塞等待虽然能解决CPU利用率问题,但是在面对利用不同资源的多个I/O请求时不能很好的解决,因为I/O阻塞等待导致一个阻塞在同一时刻只能处理一个流的阻塞监听,故而引入多路I/O的概念,多路I/O既能够阻塞等待,也能够同一时刻监听多个I/O请求的状态.
总之,单线程或单进程同时检测若干个文件描述符是否符合可执行I/O操作即为
```



## 信号

![](../../pic/linux/signal/SIG_WORK_STRUCTURE.png)

**信号共性**：简单、不能携带大量信息、条件满足才发送

**信号机制**：A给B发送信号，B收到信号之前执行自己的代码，收到信号后，无论程序执行到什么位置，都要暂停运行，去处理信号，处理完毕继续执行。--类似硬件中断，异步模式，但信号是软件层面上实现的中断，早期称为“软中断”

**信号特质**：1、由于信号是通过软件方法实现，其实现手段导致信号有很强的延时性。但对于用户来说这个延时时间非常短，不易察觉

​					2、每个进程收到的所有信号，都是由内核负责发送，内核处理。



### 信号机制

**信号的本质**：信号的本质是软件层次上对中断的一种模拟，它是一种异步通信处理机制，事实上进程不知道信号何时到来

**信号种类**：1、可靠信号，又称实时信号

​					2、不可靠信号，又称为非实时信号

​					代码1~32为不可靠信号

**信号不可靠原因**：1、每次信号处理完之后，就会恢复成默认处理，这可能是调用者不希望看到的

​								2、存在信号丢失的问题

**信号的特性**

​	1、可阻塞：可以通过某些接口阻塞（暂时屏蔽）信号

​	2、可忽略：有些信号默认处理忽略，但有些信号默认处理不忽略

​	3、可捕获：可以通过一些接口来设置信号处理函数handler来处理信号，这种行为就叫捕获

​	4、默认处理：当没有设置忽略和捕获函数时，内核对信号的默认处理方式

**产生信号**：

​	1、按键产生：Ctrl+C、Ctrl+z、Ctrl+\

​	2、系统调用产生：kill、raise、abort

​	3、软件条件产生：定时器alarm

​	4、硬件异常产生：非法访问内存（段错误）、除0（浮点数例外）、内存对齐出错（总线错误）

​	5、命令产生：kill





###  信号的编号

 **linux操作系统里	kill -l查看所有信号**

![image-20230925223556262](../../pic/linux/signal/SIG_LIST.png)

​	1~31为常规信号（普通信号）	34~64为实时信号

​	**常规信号每一个信号对应一个默认事件/动作，实时信号没有默认事件/动作**



**信号四要素**：1、编号	2、名称	3、事件	4、默认处理动作

​	默认处理动作

​		Term：终止进程

​		Core：终止进程，生成Core文件（检查进程死亡原因，用于gdb调试

​		Stop：停止（暂停）进程

​		Cont：继续运行

​		Ign：忽略信号（默认即是对该种信号忽略操作）

​	**linux操作系统里 man 7 signal查看帮助文档获取每个信号相对应四要素**

```
linux常规信号
**SIGHUP：本信号在用户终端结束时发出，通常是在终端的控制进程结束时，通知同一会话期内的各个作业，这时他们与控制终端不在关联。比如，登录Linux时，系统会自动分配给登录用户一个控制终端，在这个终端运行的所有程序，包括前台和后台进程组，一般都属于同一个会话。当用户退出时，所有进程组都将收到该信号，这个信号的默认操作是终止进程。此外对于与终端脱离关系的守护进程，这个信号用于通知它重新读取配置文件。
**SIGINT：程序终止信号。当用户按下CRTL+C时通知前台进程组终止进程。
**SIGQUIT：Ctrl+\控制，进程收到该信号退出时会产生core文件，类似于程序错误信号。
SIGILL：执行了非法指令。通常是因为可执行文件本身出现错误，或者数据段、堆栈溢出时也有可能产生这个信号。
SIGTRAP：由断点指令或其他陷进指令产生，由调试器使用。
SIGABRT：调用abort函数产生，将会使程序非正常结束。
**SIGBUS：非法地址。包括内存地址对齐出错。比如访问一个4个字长的整数，但其地址不是4的倍数。它与SIGSEGV的区别在于后者是由于对合法地址的非法访问触发。
**SIGFPE：发生致命的算术运算错误。
SIGKILL：用来立即结束程序的运行。
**SIGUSR1：留给用户使用，用户可自定义。
**SIGSEGV：访问未分配给用户的内存区。或操作没有权限的区域。
**SIGUSR2：留给用户使用，用户可自定义。
**SIGPIPE：管道破裂信号。当对一个读进程已经运行结束的管道执行写操作时产生。
**SIGALRM：时钟定时信号。由alarm函数设定的时间终止时产生。
** SIGTERM：程序结束信号。shell使用kill产生该信号，当结束不了该进程，尝试使用SIGKILL信号。
SIGSTKFLT：堆栈错误。
**SIGCHLD：子进程结束，父进程会收到。如果子进程结束时父进程不等待或不处理该信号，子进程会变成僵尸进程。
SIGCONT：让一个停止的进程继续执行。
SIGSTOP：停止进程执行。暂停执行。
SIGTSTP：停止运行，可以被忽略。Ctrl+z。
SIGTTIN：当后台进程需要从终端接收数据时，所有进程会收到该信号，暂停执行。
SIGTTOU：与SIGTTIN类似，但在写终端时产生。
SIGURG：套接字上出现紧急情况时产生。
SIGXCPU：超过CPU时间资源限制时产生的信号。
SIGXFSZ：当进程企图扩大文件以至于超过文件大小资源限制时产生。
SIGVTALRM：虚拟使用信号。计算的是进程占用CPU调用的时间。
SIGPROF：包括进程使用CPU的时间以及系统调用的时间。
SIGWINCH：窗口大小改变时。
SIGIO：文件描述符准备就绪，表示可以进行输入输出操作。
SIGPWR：电源失效信号。
SIGSYS：非法的系统调用。
```

**常用信号**

```
SIGHUP：本信号在用户终端结束时发出，通常是在终端的控制进程结束时，通知同一会话期内的各个作业，这时他们与控制终端不在关联。比如，登录Linux时，系统会自动分配给登录用户一个控制终端，在这个终端运行的所有程序，包括前台和后台进程组，一般都属于同一个会话。当用户退出时，所有进程组都将收到该信号，这个信号的默认操作是终止进程。此外对于与终端脱离关系的守护进程，这个信号用于通知它重新读取配置文件。

SIGINT：程序终止信号。当用户按下CRTL+C时通知前台进程组终止进程。

SIGQUIT：Ctrl+\控制，进程收到该信号退出时会产生core文件，类似于程序错误信号

SIGBUS：非法地址。包括内存地址对齐出错。比如访问一个4个字长的整数，但其地址不是4的倍数。它与SIGSEGV的区别在于后者是由于对合法地址的非法访问触发。

SIGFPE：发生致命的算术运算错误。

SIGUSR1：留给用户使用，用户可自定义。

SIGSEGV：访问未分配给用户的内存区。或操作没有权限的区域。

SIGUSR2：留给用户使用，用户可自定义。

SIGPIPE：管道破裂信号。当对一个读进程已经运行结束的管道执行写操作时产生。

SIGALRM：时钟定时信号。由alarm函数设定的时间终止时产生。

SIGTERM：程序结束信号。shell使用kill产生该信号，当结束不了该进程，尝试使用SIGKILL信号。

SIGCHLD：子进程结束，父进程会收到。如果子进程结束时父进程不等待或不处理该信号，子进程会变成僵尸进程。
```

#### SIGCHLD

**产生条件**	1、子进程终止时	2、子进程收到SIGSTOP信号停止时	3、子进程处在停止状态，接收到SIGCONT后唤醒时

**借助SIGCHLD回收子进程**	子进程结束运行后，其父进程会收到SIGCHLD信号，该信号默认处理动作为忽略，可捕捉该信号，在捕捉函数中完成子进程状态的回收



### 信号的生命周期及其操作

**信号的生命周期**	产生信号->在进程中注册信号->在进程中注销信号->处理信号

#### 信号的注册

性质：信号注册实质上是一个位图和一个sigqueue队列

![](../../pic/linux/signal/SIG_SIGUP.png)

**非可靠信号的注册**

​	1、将非可靠信号对应比特位置1

​	2、添加sigqueue结点到sigqueue队列当中，若在添加sigqueue节点的时候，队列当中已然有了该信号的sigqueue节点，则不添加

**可靠信号的注册**

​	1、在sig位图中更改信号对应的比特位为1

​	2、不论之前sigqueue队列中是否存在该信号的sigqueue节点，都再次添加sigqueue节点到sigqueue队列当中去



#### 信号的阻塞

**阻塞方法**

​	1、信号阻塞不会干扰信号注册，但信号注册后不能立即执行

​	2、将阻塞位图与信号位图对应信号比特位置1，表示阻塞信号

​	3、进程收到并注册

​	4、进程进入内核空间并准备返回用户空间时，调用do_signal函数，信号就不会被立即处理

​	5、当信号不被阻塞时，处理信号

**sigprocmask**	

```
函数原型：int sigprocmask(int how,const sigset_t *set,sigset_t *oldset);
		how	该做的操作
        	SIG_BLOCK	设置信号为阻塞
        	SIG_UNBLOCK	解除信号阻塞
        	SIG_SETMASK	替换阻塞位图
        set	设置阻塞位图
        	SIG_BLOCK	设置某个信号为阻塞,block (new) = block (old)|set
        	SIG_UNBLOCK	解除某个信号阻塞,block (new) = block (old)&(~set)
        	SIG_SETMASK	替换阻塞位图,block (new) = set
```



#### 信号未决

**概念**：实际执行信号的处理动作称为信号递达（Delivery），信号从产生到递达之间的状态，称为信号未决（Pending）。
			进程可以选择阻塞（Block）某个信号。被阻塞的信号产生时将保持在未决状态，直到进程解除对此信号的阻塞，才执行递达的动作。注意，阻塞和忽略是不同的，只要信号被阻塞就不会递达，而忽略是、在递达之后可选的一种处理动作

**sigpending**

```
函数原型：int sigpending(sigset_t *set);	//读取当前进程的未决信号集，通过set传出
	成功返回0，否则-1
```



#### 信号的注销

**非可靠信号的注销**

​	1、信号对应比特位置0

​	2、将该信号从信号队列出队

**可靠信号的注销**

​	1、将该信号从信号队列出队

​	2、判断信号队列中是否还有相同节点

​		1）没有：信号比特位置0

​		2）还有：不更改位图中比特位



#### 信号的处理

**信号处理时机**：信号是在线程将要返回用户空间之前进行处理，返回前会检查队列是否有信号要处理

​						1、从系统调用返回

​						2、从中断中返回

**信号处理方式**：1、执行默认动作	2、忽略（丢弃）	3、捕捉（调用用户处理函数）

```
Linux内核的进程控制块PCB是一个结构体，task_struct，除了包含进程id、状态、工作目录、用户id、组id、文件描述符表外，还包含了信号相关信息，主要指阻塞信号集和未决信号集
```

**阻塞信号集（信号屏蔽字）：将某些信号加入集合，对他们设置屏蔽，当屏蔽x信号后，再收到该信号，该信号的处理将推后（解除屏蔽）**  

**未决信号集**：

​	1、信号产生，未决信号集中描述该信号的位立刻翻转为1，表信号处于未决状态。当信号被处理对应位翻转位0。这一时刻往往非常短暂

​	2、信号产生后由于某些原因（主要是阻塞）不能抵达。这类信号的集合称为未决信号集，在屏蔽解除前，信号一直处于未决状态

![](../../pic/linux/signal/SIG_SOLUTION.png)

​	**递达**：信号递送并且到达进程

​	**未决**：信号产生和递达之间的状态。主要用于阻塞（屏蔽）导致该状态

### 信号集操作函数

#### 信号集

**概念**	信号集可以用来表示一组信号，信号集被定义为一种数据结构，每个信号占用一位（64位）

**在 PCB 中有两个非常重要的信号集。一个称之为 “阻塞信号集” ，另一个称之为“未决信号集” 。这两个信号集都是内核使用位图机制来实现的。但操作系统不允许我们直接对这两个信号集进行位操作，而需自定义另外一个集合，借助信号集操作函数来对 PCB 中的这两个信号集进行修改**



**信号集结构**

```
typedef struct{
	unsigned long sig[_NSIG_WORDS];
}sigset_t;
实质为一个无符号长整形的数组
```



**信号集工作过程（以SIGINT为例）**

1、用户通过键盘CTRL+C，产生2号信号SIGINT（信号被创建）

2、信号产生但是没有被处理（未决）

 - 在内核中将所有的没有被处理的信号存储在一个集合中 （未决信号集）
	- SIGINT信号状态被存储在第二个标志位上
	- 这个标志位的值为0， 说明信号不是未决状态
    - 这个标志位的值为1， 说明信号处于未决状态

3、这个未决状态的信号需要被处理，处理之前需要和另一个信号集（阻塞信号集）进行比较

- 阻塞信号集默认不阻塞任何的信号
- 如果想要阻塞某些信号，需要用户调用系统的API

4、处理信号时和阻塞信号集中的标志位进行查询，查看信号是否被设置阻塞

- 如果没有阻塞，这个信号就被处理
- 如果阻塞了，这个信号就继续处于未决状态，直到阻塞解除，这个信号就被处理

#### 信号集操作函数

**概念**	信号集操作函数就是对自定义信号集进行操作的函数

##### SIGACTION

**sigaction**

```
头文件	<signal.h>
函数声明 int sigaction(int signum,const struct sigaction *act,struct sigaction *oldact);
	参数解析
		signum	需要捕捉的信号的编号或者宏值（信号的名称）
		act	信号捕捉后新的处理动作
		oldact	上一次对信号捕捉相关的设置，一般不使用，传递NULL
	返回值	成功返回0，失败返回-1
函数功能：检查或者改变信号的处理，即信号捕捉

sigaction结构体 
struct sigaction {
    // 函数指针，指向的函数就是信号捕捉到之后的处理函数
    // 所指函数可自定义  
    ***void     (*sa_handler)(int);
    // 不常用，同样是信号处理函数，有三个参数，可以获得关于信号更详细的信息
    void     (*sa_sigaction)(int, siginfo_t *, void *);
    // 临时阻塞信号集，在信号捕捉函数执行过程中，临时阻塞某些信号。
    // 只在当前函数执行时生效，替换当前阻塞信号集的工作，结束后原有阻塞信号集再回来
    // 防止执行sigaction时不断有新信号的加入导致死循环
    ***sigset_t   sa_mask;
    // 使用哪一个信号处理对捕捉到的信号进行处理
    ***int sa_flags;
    这个值可以是0，表示使用 sa_handler，也可以是 SA_SIGINFO 表示使用 sa_sigaction
    SA_RESTART，使被信号打断的系统调用自动重新发起
	SA_NOCLDSTOP，使父进程在它的子进程暂停或继续运行时不会收到 SIGCHLD 信号
	SA_NOCLDWAIT，使父进程在它的子进程退出时不会收到 SIGCHLD 信号，这时子进程如果退出也不会成为僵尸进程
	SA_NODEFER，使对信号的屏蔽无效，即在信号处理函数执行期间仍能发出这个信号
	SA_RESETHAND，信号处理之后重新设置为默认的处理方式
	SA_SIGINFO，使用 sa_sigaction 成员而不是 sa_handler 作为信号处理函数
    // 被废弃掉了
    void     (*sa_restorer)(void);
};
```

**sigemptyset**

```
函数声明 int sigemptyset(sigset_t *set);
	参数解析
		set	传出参数，需要操作的信号集
	函数功能：清空信号集数据，所有标志位置0
	返回值：成功返回0，失败返回-1
```

**sigfillset**

```
函数声明 int sigfillset(sigset_t *set);
	参数解析
		set	传出参数，需要操作的信号集
	函数功能：将信号集中的所有标志位置1
	返回值：成功返回0，失败返回-1
```

**sigaddset**

```
函数声明 int sigaddset(sigset_t *set,int signum);
	参数解析
		set	传出参数，需要操作的信号集
		signum 需要设置阻塞的信号
	函数功能：设置信号集中的某一个信号对应的标志位为1，表示阻塞这个信号
	返回值：成功返回0，失败返回-1
```

**sigdelset**

```
函数声明 int sigdelset(sigset_t *set,int signum);
	参数解析
		set	传出参数，需要操作的信号集
		signum 需要设置不阻塞的信号
	函数功能：设置信号集中的某一个信号对应的标志位为0，表示不阻塞这个信号
	返回值：成功返回0，失败返回-1
```

**sigismember**

```
函数声明 int sigismember(const sigset_t *set,int signum);
	参数解析
		set	需要操作的信号集
		signum 需要判断的信号
	函数功能：判断某个信号是否阻塞
	返回值：signum被阻塞返回1，不被阻塞返回0，失败返回-1
```

**sigprocmask**

```
函数声明 int sigprocmask(int how,const sigset_t *set,sigset_t *oldset);
	参数解析
		how 如何对内核阻塞信号进行处理
			SIG_BLOCK 将用户设置的阻塞信号集添加到内核中，内核中原来的数据不变
						假设内核中信号集为mask，则mask|set
			SIG_UNBLOCK 根据用户设置的数据，对内核中的数据进行解除阻塞
							mask &= ~set
			SIG_SETMASK 覆盖内核中原来的值
		set 已经初始化好的用户自定义的信号集
		oldset 保存设置之前的内核中的阻塞信号集的状态，可以是NULL
	函数功能：将自定义信号集中的数据设置到内核中（设置阻塞，解除阻塞，替换）
	返回值：成功返回0，失败返回-1，设置错误信号EFAULT、EINVAL
```

**sigpending**

```
函数声明 int sigpending(sigset_t *set);
	函数功能：获取内核中未决信号数量
	返回值：返回内核中未决信号数量
```

##### SIGNAL

**signal**

```
头文件 <signal.h>
函数声明
	typedef void (*sighandler_t)(int);
	sighandler_t signal(int signum,sighandler_t handler);
		参数解析
			signum 指明所要处理的信号类型，可以取除了SIGKILL和SIGSTOP外的任何一种信号
			handler 描述与信号相关联动作
				SIG_IGN 忽略该信号
				SIG_DFL 恢复对信号的系统默认处理，不写也是默认执行系统默认操作
函数功能：设置某一信号对应动作，等价于捕捉信号
signal()会依参数signum 指定的信号编号来设置该信号的处理函数。当指定的信号到达时就会跳转到参数handler指定的函数执行。

当一个信号的信号处理函数执行时，如果进程又接收到了该信号，该信号会自动被储存而不会中断信号处理函数的执行，直到信号处理函数执行完毕再重新调用相应的处理函数。但是如果在信号处理函数执行时进程收到了其它类型的信号，该函数的执行就会被中断。
```

**内核信号捕捉过程**

![](../../pic/linux/signal/KERNEL_CATCHSIG.png)

## 进程组和会话
