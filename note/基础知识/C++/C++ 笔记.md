#   C++笔记

## 	概念

### C++编译过程

```
编译+连接:预编译处理(.c) －> 编译、优化程序（.s）－>汇编程序(.obj、.o、.a、.ko) －> 链接程序（.exe、.elf、.axf等）
编译把文本形式的源代码翻译成机器语言并形成目标文件
连接把目标文件操作系统的启动代码和库文件组织起来形成可执行文件

C++三大特性:封装,继承,多态
```



```
单引号是char 字符型， 双引号是string 字符串型
```



```
类与对象
对象（Object）是一个应用系统中的用来描述客观事物的实体，是有特定属性和行为（方法）的基本运行单位。是类的一个特殊状态下的实例。对象可以是一个实体、一个名词、一个可以想象为有自己标识的任何东西，可以概括来说：万物皆对象
类和对象之间是抽象与具体的关系。类是一个模板是对一类事物的抽象描述，而对象用于表示现实中该事物的个体。类是在对象之上的抽象，对象则是类的具体化，是类的实例。类必须通过对象才可以使用，而对象中的属性和行为必须在类中定义。

什么是封装,为什么封装
封装是实现面向对象程序设计的第一步，封装就是将数据或函数等集合在一个个的单元中（我们称之为类）。被封装的对象通常被称为抽象数据类型
封装的作用在于保护或者防止代码（数据）被我们无意中破坏。在面向对象程序设计中数据被看作是一个中心的元素并且和使用它的函数结合的很密切，从而保护它不被其它的函数意外的修改
```



```
1字 = 2B = 16bit//1字=2字节=16位/比特
字:计算机一次性能够处理数据的位数//CPU处理
```



```
语句、定义不需要分号结尾，声明需要分号结尾语句,if、for、while都是语句，所以{}本身是语句的一部分.定义:void func() {}声明:结构体的定义是声明，所以需要分号结尾。

形参（形式参数）
在函数定义中出现的参数可以看做是一个占位符，它没有数据，只能等到函数被调用时接收传递进来的数据，所以称为形式参数，简称形参。
实参（实际参数）
函数被调用时给出的参数包含了实实在在的数据，会被函数内部的代码使用，所以称为实际参数，简称实参。

int sum(int m, int n)//m,n为形参		main(){int a,b;		sum(a,b);}//a,b为实参
```



```
编程步骤：源码->编译器->目标代码->链接程序(启动代码+库代码)->可执行代码
#:表示预处理操作

C++程序执行时,内存分为四大区:代码区,全局区,栈区,堆区//不同分区存放数据赋予不同生命周期,以更灵活编程

-- 程序运行前区域//初始化栈指针,全局对象,data段内容,调用构造函数,传参
代码区:共享,只读,存放CPU二进制机器指令
全局区:存放全局\静态变量,程序结束后操作系统管理数据释放

常量:字符串常量/const修饰的常量
-- 程序运行后区域//析构函数在main后执行
栈区:编译器自动分配释放,存放函数的参数值和局部变量等//返回局部变量地址会导致错误,因为编译器在函数调用一次后会自动释放程序运行而开辟的栈区
堆区:由程序员分配并释放,new可以将数据开辟到堆区

堆和栈的区别
申请方式不同:
	栈由系统自动分配。
	堆是自己申请和释放的。
申请大小限制不同:
	栈顶和栈底是之前预设好的，栈是向栈底扩展，大小固定，可以通过ulimit -a查看，由ulimit -s修改。
	堆向高地址扩展，是不连续的内存区域，大小可以灵活调整。
申请效率不同:
	栈由系统分配，速度快，不会有碎片。
	堆由程序员分配，速度慢，且会有碎片。
```



```
BSS段: 用来存放程序中未初始化的全局变量的一块内存区域
数据段: 通常是指用来存放程序中已初始化的全局变量的一块内存区域。数据段属于静态内存分配。
代码段: 通常是指用来存放程序执行代码的一块内存区域。这部分区域的大小在程序运行前就已经确定，并且内存区域通常属于只读, 某些架构也允许代码段为可写，即允许修改程序。在代码段中，也有可能包含一些只读的常数变量，例如字符串常量等。

堆: 是用于存放进程运行中被动态分配的内存段，它的大小并不固定，可动态扩张或缩减
栈: 栈又称堆栈,是用户存放程序临时创建的局部变量，也就是说我们函数括弧“{}”中定义的变量（但不包括static声明的变量，static意味着在数据段中存放变量）。除此以外，在函数被调用时，其参数也会被压入发起调用的进程栈中，并且待到调用结束后，函数的返回值也会被存放回栈中。由于栈的先进先出特点，所以栈特别方便用来保存/恢复调用现场。从这个意义上讲，我们可以把堆栈看成一个寄存、交换临时数据的内存区

栈就像我们去饭馆里吃饭，只管点菜（发出申请）、付钱、和吃（使用），吃饱了就走，不必理会切菜、洗菜等准备工作和洗碗、刷锅等扫尾工作，他的好处是快捷，但是自由度小。
堆就象是自己动手做喜欢吃的菜肴，比较麻烦，但是比较符合自己的口味，而且自由度大。
```



```
‘0’		0对应的ASCII码，其值为48
“0”		字符串常量。双引号括起来的都属于字符串
‘\0’	空字符（NULL）对应的ASCII码，即‘\0’=NULL
 0 		数字
```



```
结构体对齐
1.结构体内成员按照声明顺序存储,第一个成员地址和整个结构体地址相同.
2.未特殊说明时，按结构体中size最大的成员对齐(若有double成员，按8字节对齐).
```



```
内存和存储:你口里吃花生就CPU在处理数据，硬盘容量(存储容量)大小就是你的口袋大小（能放多少花生），内存大小就是你的手的大小（一次能抓多少出来）

内存泄漏:指你向系统申请分配内存进行使用(new)，可是使用完了以后却不归还(delete)，结果你申请到的那块内存你自己也不能再访问（也许你把它的地址给弄丢了），而系统也不能再次将它分配给需要的程序。一个盘子用尽各种方法只能装4个果子，你装了5个，结果掉倒地上不能吃了。
//堆会产生内存泄漏,因为堆的资源由程序员控制,栈不会因为栈 中资源由编译器自动管理


内存溢出:指程序在申请内存时，没有足够的内存空间供其使用，出现out of memory；比如申请了一个integer,但给它存了long才能存下的数，那就是内存溢出。
```



## 内存

### 位域

#### 定义

```
有些信息在存储时，并不需要占用一个完整的字节，而只需要占一个或几个二进制位。
例如在存放一个开关量时，只有0和1两种状态，只需要用一位二进制位即可。为了节省存储空间，并且为了让处理变得更便捷，C语言又提供了一种数据结构，称为“位域”或者“位段”。所谓位域，就是把一个字节中的二进制位划分为不同的区域，并说明每个区域的位数。每个域都有一个域名，允许程序中按照域名进行操作。这样就可以把几个不同的对象用一个字节的二进制位域来表示。
```

#### 结构

```
struct <位域结构名>
{
   ...
   <类型说明符> <位域名> : <位域长度> // 位域列表
   ...
};

eg.
struct Demo
{
 int a : 8;
 int b : 2;
 int c : 4;
};


位域变量的说明也与结构体变量的说明方式相同，可以采用先定义后说明、同时定义说明、直接说明这三种方式
eg.
方式1：
struct Demo
{
 int a : 8;
 int b : 2;
 int c : 4;
}demo1;
方式2：
struct Demo
{
 int a : 8;
 int b : 2;
 int c : 4;
};
struct Demo demo1;
方式3：
typedef struct Demo
{
 int a : 8;
 int b : 2;
 int c : 4;
}De;
De demo1;
这三种方式中的demo1均为Demo的变量，且占两个字节，其中位域a占8bit，位域b占2bit，位域c占4bit。

```



### 一些知识点

```
位域的sizeof
1.如果相邻位域字段的类型相同，且其位宽之和小于类型的sizeof大小，则后面的字段将紧邻前一个字段存储，直到不能容纳为止； 
2.如果相邻位域字段的类型相同，但其位宽之和大于类型的sizeof大小，则后面的字段将从新的存储单元开始，其偏移量为其类型大小的整数倍； 
3.如果相邻的位域字段的类型不同，则各编译器的具体实现有差异，VC6采取不压缩方式，Dev-C++采取压缩方式； 
4.如果位域字段之间穿插着非位域字段，则不进行压缩； 
5.整个结构体的总大小为最宽基本类型成员大小的整数倍
```



### 内存对齐

#### 原因

```
尽管内存是以字节为单位，但是大部分处理器并不是按字节块来存取内存的.它一般会以双字节,四字节,8字节,16字节甚至32字节为单位来存取内存，我们将上述这些存取单位称为内存存取粒度

假如没有内存对齐机制，数据可以任意存放，现在一个int变量存放在从地址1开始的联系四个字节地址中，该处理器去取数据时，要先从0地址开始读取第一个4字节块,剔除不想要的字节（0地址）,然后从地址4开始读取下一个4字节块,同样剔除不要的数据（5，6，7地址）,最后留下的两块数据合并放入寄存器.这需要做很多工作
```

#### 内存对齐规则

```
每个特定平台上的编辑器都有自己的默认"对齐系数".gcc中默认#pragma pack(n),n=1,2,4,8,16来改变这一系数

相关概念
数据类型自身对齐值：基本数据类型的自身所占空间大小。
指定对齐值：使用#pragam pack(value)时，指定的对齐值value。
结构体或类的自身对齐值：其中成员对齐值最大的那个值。
结构体和类的有效对齐值：自身对其值和指定对其值中较小的那个值

有效对齐值的确定
当未明确指定时，以结构体中最长的成员的长度为其有效值
当用#pragma pack(n)指定时，以n和结构体中最长的成员的长度中较小者为其值。
当用__attribute__ ((__packed__))指定长度时，强制按照此值为结构体的有效对齐值

对齐规则
1.对于结构体的各个成员，第一个成员的偏移量是0，排列在后面的成员其当前偏移量必须是当前成员类型的整数倍
2.结构体内所有数据成员各自内存对齐后，结构体本身还要进行一次内存对齐，保证整个结构体占用内存大小是结构体内最大数据成员的最小整数倍
3.如程序中有#pragma pack(n)预编译指令，则所有成员对齐以n字节为准(即偏移量是n的整数倍)，不再考虑当前类型以及最大结构体内类型
```

#### 一些数据的存储规则

```
变量后面加冒号然后加数字表示位域,也就是说着代表按位来存放的,不是按字节,这是计算机为了节约空间的一种方式.
eg. unsigned short i:8;//虽然short类型占16位但是依旧按8位大小存储变量i
```



## 命名空间

```
只能全局范围定义
可以嵌套
开放的,可随时加入新成员
命名空间中的函数可以在命名空间定义外实现(又称定义)
```



## 技巧

```
cin的小技巧
#cin，cout效率比较低，是因为先把要输出的东西存入缓冲区与C语言中的stdio同步后，再输出，导致效率降低，而这段语句的作用是取消缓冲区同步，直接使用，由此可节省时间，使效率与scanf与printf相差无几。

ios::sync_with_stdio(false);
可以将cin和scanf的效率相匹敌
//cin慢是有原因的，其实默认的时候，cin与stdin总是保持同步的，也就是说这两种方法可以混用，而不必担心文件指针混乱，同时cout和stdout也一样，两者混用不会输出顺序错乱。正因为这个兼容性的特性，导致cin有许多额外的开销，如何禁用这个特性呢？只需一个语句std::ios::sync_with_stdio(false);，这样就可以取消cin于stdin的同步了。

static const auto io_sync_off = [](){
    ... ...
}();
这个乍一看很像是函数，但是前后又是[]又是()的，是Lambda表达式即匿名函数。
Lambda表达式是C++11引入的特性，是一种描述函数对象的机制，它的主要应用是描述某些具有简单行为的函数。Lambda也可以称为匿名函数。
故上式等价于	static const auto function() {
    			... ...
			}
			static const auto io_sync_off = function();

2.std::ios::sync_with_stdio(false);
iostream默认是与stdio关联在一起的，以使两者同步，因此消耗了iostream不少性能。C++中的std :: cin和std :: cout为了兼容C，保证在代码中同时出现std :: cin和scanf或std :: cout和printf时输出不发生混乱，所以C++用一个流缓冲区来同步C的标准流。通过std :: ios_base :: sync_with_stdio函数设置为false后可以解除这种同步，让std :: cin和std :: cout不再经过缓冲区，iostream的性能就会提高了很多倍。因此，当解除同步之后，注意不要与scanf和printf混用以免出现问题。

3.std::cin.tie(nullptr);
nullptr是c++11中的关键字，表示空指针
NULL是一个宏定义，在c和c++中的定义不同，c中NULL为（void*)0,而c++中NULL为整数0
nullptr是一个字面值常量，类型为std::nullptr_t,空指针常数可以转换为任意类型的指针类型。在c++中（void *）不能转化为任意类型的指针，即 int *p=(void*)是错误的，但int *p=nullptr是正确的。原因是对于函数重载：若c++中 （void *）支持任意类型转换，函数重载时将出现问题。下列代码中fun(NULL)将不能判断调用哪个函数

void fun(int i){cout<<"1";};
void fun(char *p){cout<<"2";};
int main()
{
fun(NULL);        //输出1，c++中NULL为整数0
fun(nullptr);     //输出2，nullptr 为空指针常量。是指针类型
}

```



## 输入和输出

```
scanf和cin:在scanf元素的类型我们已经告知了，机器不用再去查找元素类型，scanf需要自己写格式，是一种格式化输入。而在cin元素类型由机器自己查找，cin是字符流输入，需要先存入缓冲区再输入。

用法和上一种类似，但是读取的istream是作为参数is传进函数的。读取的字符串保存在string类型的str中。
```



```
保留小数位数
#include<iomanip>
cout<<fixed<<setprecision(n)<<...
//在fixed<<setprecision(n)<<之后输出的数据保留n位小数
```



```
getline()
getline是C++标准库函数；它有两种形式，一种是头文件< istream >中输入流成员函数；一种在头文件< string >中普通函数；
它遇到以下情况发生会导致生成的本字符串结束：
(1)到文件结束，(2)遇到函数的定界符，(3)输入达到最大限度。
在< string >中的getline函数有四种重载形式：
istream& getline (istream&  is, string& str, char delim);
istream& getline (istream&& is, string& str, char delim);
istream& getline (istream&  is, string& str);
istream& getline (istream&& is, string& str);
函数的变量：
is ：表示一个输入流，例如 cin。
str ：string类型的引用，用来存储输入流中的流信息。
delim ：char类型的变量，所设置的截断字符；在不自定义设置的情况下，遇到’\n’，则终止输入
例:getline(cin,string s,'.');存入一串数据流至string s中保存,遇到'.'就停止:若输入数据为11.22.33.,则依次向s中输入了三个字符串分别为11,22,33,s更新了3次,最终s为33
注:使用while(getline(cin,string))时getline输入数据在string中当while结束时该区域自动释放,string为空
```



## 运算符

```
&:取址运算符		*:间接寻址运算符

>>和<<:二进制右移和左移相应位数
4<<2  表示4的二进制数100左移两位
变为10000转化为十进制就是16
4>>2 表示4的二进制数100右移两位
变为1转化为是十进制就是1
简单的记就是
<<6   表示为*2的六次方
同理
>>6   表示为/2的六次方
i<<=1:左移赋值运算。 变量i左移1位，结果仍然保存到变量i

```

### 双冒号

```
（1）表示“域操作符”
例：声明了一个类A，类A里声明了一个成员函数void f()，但没有在类的声明里给出f的定义，那么在类外定义f时，就要写成void A::f()，表示这个f()函数是类A的成员函数。

（2）直接用在全局函数前，表示是全局函数 
例：在VC里，你可以在调用API 函数里，在API函数名前加：：

（3）表示引用成员函数及变量，作用域成员运算符
```



## 变量和函数

```
参数默认值:若一个函数参数有默认值,则这个参数之后的每个参数都要有默认值
函数的声明:typedef 函数名(形参);		函数的实现(又称定义):typedef 函数名(形参){};
	//函数声明有默认参数则函数实现就不能有默认参数,声明和实现只能有一个有默认参数
占位参数:typedef 函数名(typedef);//调用函数时必须有一个参数否则函数实现失败

函数重载:1.同一作用域2.函数名相同3.函数参数类型/个数/顺序不同(其一即可) //函数返回值不可作重载条件
```

#### 定义和声明

```
变量的定义（definition）用于为变量分配存储空间，还可以为变量指定初始值。在程序中，变量有且仅有一个定义。
声明（declaration）用于向程序表明变量的类型和名字。

定义也是声明:当定义变量的时候我们声明了它的类型和名字。可以通过使用extern声明变量名而不定义它。不定义变量的声明包括对象名、对象类型和对象类型前的关键字extern。

extern关键字:通过使用extern关键字声明变量名而不定义它.extern声明不是定义,也不分配存储空间.事实上它只是说明变量定义在程序的其他地方.程序中变量可以声明多次,但只能定义一次.

只有当声明也是定义时,声明才可以有初始化式,因为只有定义才分配存储空间.初始化式必须要有存储空间来进行初始化.如果声明有初始化式,那么它可被当作是定义,即使声明标记为extern.

extern int i; //声明，不是定义
int i; //声明，也是定义 
```



## 一些关键字

### size和sizeof

```
size(str)输出str长度,sizeof(str)输出str大小
```

### sort和qsort

```

```

### alignas和alignof

```
alignof可以计算出类型的对齐方式，alignas可以指定结构体的对齐方式。
```

```
// alignas 生效的情况
struct Info {
  uint8_t a;
  uint16_t b;
  uint8_t c;
};

std::cout << sizeof(Info) << std::endl;   // 6  2 + 2 + 2
std::cout << alignof(Info) << std::endl;  // 2

struct alignas(4) Info2 {
  uint8_t a;
  uint16_t b;
  uint8_t c;
};
//地址分别取每个成员变量大小和对齐大小二者较小值的整数倍(每个成员变量地址起始值)
std::cout << sizeof(Info2) << std::endl;   // 8  4 + 4
std::cout << alignof(Info2) << std::endl;  // 4

// alignas 失效的情况

struct Info {
  uint8_t a;
  uint32_t b;
  uint8_t c;
};

std::cout << sizeof(Info) << std::endl;   // 12  4 + 4 + 4
std::cout << alignof(Info) << std::endl;  // 4

struct alignas(2) Info2 {
  uint8_t a;
  uint32_t b;
  uint8_t c;
};

std::cout << sizeof(Info2) << std::endl;   // 12  4 + 4 + 4
std::cout << alignof(Info2) << std::endl;  // 4

```



### new/delete和malloc/free

```
new关键字:程序员为函数数据开辟分配一个堆区并由程序员释放
	返回值:new关键字返回的是指针
		//int *p = new int(10);返回的是整形变量10的地址
		//int *p = new int[10];返回有10个元素的int类型的地址首地址
	释放堆区:delete p;//释放10的空间		delete []p;//释放数组的空间

前者是C++运算符，后者是C/C++语言标准库函数
new自动计算要分配的空间大小，malloc需要手工计算
new是类型安全的，malloc不是。
new调用名为operator new的标准库函数分配足够空间并调用相关对象的构造函数，delete对指针所指对象运行适当的析构函数；然后通过调用名为operator delete的标准库函数释放该对象所用内存。后者均没有相关调用
后者需要库文件支持，前者不用
new是封装了malloc，直接free不会报错，但是这只是释放内存，而不会析构对象

malloc和free是标准库函数，支持覆盖;new和delete是运算符，支持重载。
malloc仅仅分配内存空间，free仅仅回收空间，不具备调用构造函数和析构函数功能，用malloc分配空间存储类的对象存在风险；new和delete除了分配回收功能外，还会调用构造函数和析构函数。

malloc和free返回的是void类型指针（必须进行类型转换），new和delete返回的是具体类型指针。
```



## 指针和引用

```
指针是一个变量(*p)，存储的是一个地址，引用(&p)跟原来的变量实质上是同一个东西，是原变量的别名
指针可以有多级，引用只有一级
指针在初始化后可以改变指向，而引用在初始化之后不可再改变
sizeof指针得到的是本指针的大小，sizeof引用得到的是引用所指向变量的大小

***指针可以为空，引用不能为NULL且在定义时必须初始化

当把指针作为参数进行传递时，也是将实参的一个拷贝传递给形参，两者指向的地址相同，但不是同一个变量，在函数中改变这个变量的指向不影响实参，而引用却可以。
引用本质是一个指针，同样会占4字节内存；指针是具体变量，需要占用存储空间（，具体情况还要具体分析）。
引用在声明时必须初始化为另一变量，一旦出现必须为typename refname &varname形式；指针声明和定义可以分开，可以先只声明指针变量而不初始化，等用到时再指向具体变量。
引用一旦初始化之后就不可以再改变（变量可以被引用为多次，但引用只能作为一个变量引用）；指针变量可以重新指向别的变量。
不存在指向空值的引用，必须有具体实体；但是存在指向空值的指针。

野指针:没有初始化的指针,故不知道指针会指向哪一片内存
故:不要返回函数局部变量的指针或引用,不然会导致内存泄漏

在编译器看来, int a = 10; int &b = a; 等价于 int * const b = &a; 而 b = 20; 等价于 *b = 20; 自动转换为指针和自动解引用
```



```
指针常量:typedef * const p;//指针所指向值可变,但指向地址不可变
常量指针:const typedef *p;//指针所指向值不可变,但指向地址可变

int *p[10]表示指针数组，强调数组概念，是一个数组变量，数组大小为10，数组内每个元素都是指向int类型的指针变量。
//即存储指针的数组
int (*p)[10]表示数组指针，强调是指针，只有一个变量，是指针类型，不过指向的是一个int类型的数组，这个数组大小是10。
//即返回的是指向大小为10的int类型数组的首地址指针
int *p(int)是函数声明，函数名是p，参数是int类型的，返回值是int *类型的。

int (*p)(int)是函数指针，强调是指针，该指针指向的函数具有int类型参数，并且返回值是int类型的。
```

```
auto：在块作用域、命名作用域、循环初始化语句等等 中声明变量时，关键词auto用作类型指定符。

const:修饰符

想要拷贝元素：for(auto x:range)
想要修改元素 : for(auto &&x:range)
想要只读元素：for(const auto& x:range)

auto
auto即 for(auto x:range) 这样会拷贝一份range元素，而不会改变range中元素；但是！（重点) 使用for(auto x:vector)时得到一个proxy class,操作时会改变vector本身元素。应用：for(bool x:vector)
auto& 	当需要修改range中元素，用for(auto& x:range)

当vector返回临时对象，使用auto&会编译错误，临时对象不能绑在non-const l-value reference （左值引用）需使用auto&&,初始化右值时也可捕获

const auto&
当只想读取range中元素时，使用const auto&,如：for(const auto&x:range),它不会进行拷贝，也不会修改range

const auto
当需要拷贝元素，但不可修改拷贝出来的值时，使用 for(const auto x:range)，避免拷贝开销

```



## 判断语句

```
if和else if
if后可跟else if,else if后要以else结尾
```



## 循环

```
for遍利字符串
	string s;
	for(char a:s)相当于for( int i = 0; i < s.length(); i++)
{ 
	s[i]....	
}//此时对s[i]操作通过a进行
```



## 引用

```
基本语法:&别名 = 原名
		int a = 10;	int &b = a;
注意事项:必须初始化,即int &b = __;为必须操作且初始化后不能再改变所指向数据即类似于指针常量
		//int &b = a;后,b = c;就为赋值操作而不是引用
		//引用传递和地址传递效果一样但是更为简洁
		//int swap(int &a,int &b){
			int temp = a;//相当于
			a = b;
			b = temp;
用途:函数参数,函数返回值
	函数返回值:若引用作为函数的返回值则函数可作为左值即被赋值
	
#引用的本质为一个指针常量
	int& ref = a;系统会自动转换为 int * const ref = &a;指针常量指向不可改但指向的值可改
	故 ref = 20;系统会自动转换为 *ref = 20;

常量引用:修饰形参,防止误操作//函数形参列表中加const
```



## 数据

### 概念

```
质数:除1和其本身外不能被其他数所整除的数
质因子:能整除给定正整数的质数
```



### 转换输入的数据

```
hex:十进制 oct:八进制	dec:十进制
cout<<hex<<obj;//将obj中数据转为十进制并输出
cin>>hex>>obj;//将输入数据转为十进制并存入obj
```



### 	数字常量基数

```
第一位:1~9 基数为十进制

第二位:第一位为0时,1~7为八进制

前两位:0x或0X,为十六进制
```

### 		  	转换输出整形类型

```
cout<<dec 输出转为10进制		cout<<hex 输出转为十六进制	cout<<oct输出转为八进制

小数点后零不删：cout.setf()

cout默认输出小数点后6位
printf("%.nf")//保留n位小数

#include<iomanip>  setprecision()和fixed进行精度控制和补0
需要保留几位小数，就将 setprecision(n) 的括号里n换成几
上面的语句写一次就够了，对之后的数字都有效
函数 setprecision() 控制输出流的输出精度（精度控制采用四舍五入）
注意：setprecision单独使用是控制有效位数的，与fixed合用才是控制小数点后位数的
#cout<<fixed<<setprecision(5)<<a;//输出 0.12300
#cout<<setprecision(5)<<a<<endl;//输出 0.123

```

### 数据转换

```
string转int: int b = char a - '0';
int 转string:string num = to_string(int b);

大小写转换:大写转小写:char a+32  小写转大写:char a-32//ASCII表中小写大于大写之32
		 tolower(),将大写转小写,头文件<cctype>
		 toupper(),将小写转大写,头文件<cctype>
		 
int,double和float

double/float->int:取整数部分#低精度无法向高精度转,高精度向低精度转,直接截取相应部分
```

### 随机数

```
rand();//生成随机数
rand()%max+n;//生成[n,max]内的随机数
number = (rand()%(maxValue - minValue +1)) + minValue;//在上述公式中，minValue 是范围内的最小值，而 maxValue 则是范围内的最大值。例如，要获得 10〜18 的随机数，可以使用以下代码给变量 number 赋值
const int MIN_VALUE = 10;
const int MAX_VALUE = 18;
number = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
在上述代码中，（MAX_VALUE - MIN_VALUE + 1）的值为 9，这是目标范围内整数的个数。余数运算符（％）返回的值是 0〜8 的数字，再用它加上 MIN_VALUE（也就是 10），即可获得 10〜18 的随机数。
```



## 面向对象

```
类：规定数据+操作部分=>封装
对象：通过类创建，是抽象类的实例化

面向对象：先设计类，再设计使用类的对象
面向对象三大特性:封装,继承,多态
==>类：设计理念 对象：设计的产品

封装:将属性和行为作为一个整体,表现生活中的事务并对属性和行为加以权限控制
	访问权限:1.公共public 2.保护protected 3.私有private
			public:成员在类内和类外可以访问
			protected:成员类内可以访问但类外不行,儿子可以访问父亲中的保护内容
			private:成员类内可以访问但类外不行,儿子不可以访问父亲中的私有内容
			#访问private成员只能通过public接口访问
			
STRUCT和CLASS区别:STRUCT默认权限公有,CLASS默认权限私有

CLASS Person{
	public:
		Person(){
		cout<<"调用构造函数"<<endl;
		};
		~Person(){
		cout<<"调用析构函数"<<endl;
		};
	protected:
	private:
	}
```



### 	对象的初始化和清理

```
构造函数:类名(){}
		构造函数没有返回值也不写void,函数名与类名相同,可有参数故可重载,程序在调用对象时会自动构造,无需手动调用且只调用一次 
		调用规则:若用户定义有构造函数,编译器不提供默认无参构造,但会提供默认拷贝构造
				若用户定义有拷贝构造,编译器不提供其他构造函数
				
        拷贝构造函数 类名(const 类名 &参数){};//拷贝&参数的属性到当前所用
        	编译器默认拷贝构造函数:
        		Person(const Person & p){
        			m_age = p.m_age;//即编译器默认拷贝构造只做一个简单的值拷贝
        		}
        	拷贝构造函数的调用时机
        		使用一个已经创建完毕的对象来初始化一个新对象
        		void test01(){
        			Person p1(20);
        			Person p2(p1);}
        		值传递的方式给函数参数传值
        		void dowork(Person p){
        			
        		}
        		void test02(){
        			Person p;
        			dowork(p); 
        		}
        		以值方式返回局部对象
        		Person dowork2(){
        			Person p;
        			return p;	//return p不是直接返回p而是创建一个和p值一样的对象并返回 
        		}
        		void test03(){
        			Person p = dowork2();
        		}
        		
        	深拷贝与浅拷贝
        		浅拷贝:简单赋值拷贝
        		深拷贝:在堆区重新申请空间进行拷贝
        		//浅拷贝会重复释放堆区,故要用深拷贝解决问题
        		//如果属性有在堆区开辟,一定要自己提供拷贝构造函数来防止浅拷贝问题
        
        括号法:
        	Person p1;//默认构造函数
        	Person p2(10);//有参构造函数
        	Person p3(p2);//拷贝构造函数
        	#调用默认构造函数不要用(),否则系统会使接下来的函数调用认为是一个函数声明而不是一个创建对象声明
        显示法:
        	Person p1;//默认构造函数
        	Person p2 = Person(10);//有参构造函数
        	Person p3 = Person(p2);//拷贝构造函数
        	#Person(10)单拎出来为匿名对象,当前执行完成后系统会立即回收匿名对象
        	#利用拷贝构造函数初始化匿名函数会出错,编译器会认为是实例化一个新的对象声明而造成重定义
        隐式法:
        	Person p1;//默认构造函数
        	Person p2 = 10;//有参构造函数,==Person p2 = Person(10);
        	Person p3 = p2;//拷贝构造函数,==Person p3 = Person(p2);
        	
        
	析构函数:~类名(){}
		析构函数没有返回值也不写void,函数名与类名相同并前有~,不可有参数故不能重载,程序在对象销毁前会自动析构,无需手动调用且只调用一次
	#构造和析构都必有,如果程序员不提供则编译器会自动提供一个空的构造和析构函数
	
	默认情况下,编译器至少给一个类添加三个函数:默构,默析,默拷(对属性进行拷贝)
	
初始化列表
	class Person{
		public:
			int A;
			int B;
			构造函数初始化//传统初始化操作
			Person p(int a, int b){
				A = a;
				B = b;}
			初始化列表初始化
			Person(int a, int b):A(a),B(b){}
			
		private
	}
	
类对象作为类成员:
	构造顺序:当其他类对象作为本类成员,构造时候先构造类对象,再构造类自身
	析构顺序:与构造顺序相反
	
静态成员:成员变量和函数前加上static
	静态成员变量:所有对象共享一份数据,在编译阶段分配内存,类内声明,类外初始化,不单独属于任何对象,故不占对象存储空间//类外初始化时static可去掉但需加上类名作用域调用
			例:int A为类内静态成员变量->初始化: int 类名::A = 值;
			//共享数据指其他地方对成员变量进行修改时所有对象调用该成员的值都为改变后的值
		静态成员变量访问方式
			对象访问:对象名.变量名
			类名访问:类名::变量名
	静态成员函数:所有对象共享一个函数,静态成员函数只能访问静态成员变量
		静态成员函数访问方式
			对象访问:对象名.函数名
			类名访问:类名::函数名
```



### 继承

#### 类内存特点

```
类内无任何成员变量时，默认为1字节
类内成员遵循内存的对齐补齐规则（与结构体的对齐补齐一样）
函数不占内存(存在代码段)
有继承关系时，父类的成员变量也属于类内寸的一部分，但是C++标准并没有明确规定派生类的对象在内存中如何分布（也就是说基类部分和派生类的成员不一定是连续存储的）
```

#### 影响类大小的因素

```
有关:普通成员变量,虚函数,继承(单一/多重/重复/虚)
无关:静态成员变量,静态成员函数及普通成员函数
```

#### 继承中的内存关系

```
继承之后子类独自开辟了一块内存空间,存储了基类的数据成员(无论公私或保护),但子类并没有继承父类的使用方法(父类的函数),而是直接使用,因为成员方法直存在代码段
```

#### 经典类的大小

```
空类:空类大小为1,因为虽然没有成员但是空类依旧可以实例化,故而空类会占据内存大小为1的空间(编辑器优化为1)

继承空类:该类大小为其自身成员大小之和,虽然继承了空类但是空基类在被继承之后子类就会优化基类1字节大小,节省空间大小,提高运行效率

一般类的大小:成员声明的顺序不同,类的内存构造也不同
eg.
class base1
{
private:
    char a;
    int b;
    double c;
};
class base2
{
private:
    char a;
    double b;
    int c;
};
base 1类对象的大小为16(4+4+8)字节，而base 2类对象的大小为24(8+8+8字节，因为不同的声明顺序，居然造成了8字节的空间差距，因此，我们将来在自己声明类时，一定要注意到内存对齐问题，优化类的对象空间分布。
```



### 	对象模型和指针

```
成员变量和成员函数分开储存
空对象占用存储空间为1,因为编译器会为每个空对象分配1B空间,为了区分空对象占用空间位置,故每个空对象都有一个独一无二的内存地址 
//只有非静态成员变量属于类对象,占有类对象空间大小

this指针:指向被调用的成员函数所属对象
	用途:1.形参和成员变量同名时可用this指针区分(解决名称冲突)	2.类的非静态成员函数中返回对象本身时可用return *this(返回对象本身用*this)
	#类对象作返回值时,若是值返回,则每次返回的都是创建的新的对象但是值相同,若返回的是引用,则每次返回的都是同一个对象
		Person PersonA(Person &p){};//返回新对象		Person &PersonA(Person &p){};//返回同一个对象	
	#空指针依旧可以调用成员函数	
	
const修饰成员函数:常函数内不可修改,成员属性声明时加关键字mutable后在常函数中依然可以修改,常对象只能调用常函数
	#普通函数可以修改属性,故常对象不能调用
	#this指针本质:类名* const this;//为一指针常量,不可修改指向但可以修改指向的值
	#故用const修饰成员函数实际上就是用const修饰this指针,就变为const 类名* const this,此时指向和指向值都无法改变
```



### 	友元

```
友元关键字:friend
友元可以访问类中的私有成员
类中声明友元类:在权限之前通过friend class 类名;
类中声明友元类的函数:在权限之前friend typedef 类名::函数名();
```



### 	运算符重载

```
通过成员函数进行运算符重载
	类名 operator运算符(类名 &自定义对象名){};//实际上是定义一个名为运算符的成员函数,并在之后使用运算符且参数符合时进行调用从而实现运算符的重载
通过全局函数进行运算符重载
	typedef operator运算符(类名 &自定义对象名,类名 &自定义对象名){};//实际上是定义一个名为运算符的函数,并在之后使用运算符且参数符合时进行调用从而实现运算符的重载
	#以运算符"+"为例,Person p3 = p1 + p2;本质为Person p3 = p1.operator(p2)/operator(p1,p2) //成员函数重载/全局函数重载
	#运算符重载中的函数重载:定义函数时的参数不同即可,与之前类似
	
	#对于内置数据类型的表达式的运算符不能重载,如1+1(int+int)
	#不要滥用运算符重载
	
	#对自增自减运算符重载时,通过占位符来区分前置和后置
```



## 迭代器(STL)

```
标准模板库:广义分为容器,算法,迭代器->提高代码复用性
细分:容器,算法,迭代器,仿函数,适配器(配接器),空间配置器

容器:各种数据结构，如vector、list、deque、set、map领,用来存放数据。
算法:各种常用的算法。如sort、find、copy.for_each等
迭代器:扮演了容器与算法之间的胶合剂。
仿函数:行为类似函数，可作为算法的某种策略。
适配器:一种用来修饰容器或者仿函数或迭代器接口的东西。
空间配置器:负责空间的配置与管理。

序列式容器:强调值的排序,序列式容器中的每个元素均有固定的位置
关联式容器:二叉树结构,各元素间无严格的物理意义上的顺序关系

#include<algorithm> //标准算法头文件
质变算法:是指运算过程中会更改区间内的元素的内容。例如拷贝，替换，删除等等
非质变算法:是指运算过程中不会更改区间内的元素内容，例如查找、计数、遍历、寻找极值等等

#每种容器有专门的迭代器,类似于指针
正向迭代器
	容器类名::iterator 迭代器名;
常量正向迭代器
	容器类名::const_iteraor迭代器名;
反向迭代器
	容器类名::const_reverse_iterator;

迭代器++操作
	正向++指向容器中的后一个元素,反向++指向容器中的前一个元素

###
使用迭代器访问容器时,声明迭代器后必须进行相应的访问,因为声明后不使用迭代器进行访问而用其他访问如删除元素或移动元素等会修改容器的内在状态，这会使得原本指向被移动元素的迭代器失效，也可能同时使其他迭代器失效
```

![image-20230223183153613](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230223183153613.png)



### Auto

```
根据后面的值,来自己推测前面的类型是什么,相当于一个自动的迭代器
auto的作用就是为了简化变量初始化,如果这个变量有一个很长很长的初始化类型,就可以用auto代替

#auto声明的变量必须初始化,因为auto根据后面的值来推测变量类型
故函数和模板参数不能被声明为auto
#因为auto是一个占位符,并不是一个他自己的类型,因此不能用于类型转换或其他一些操作,如sizeof和typedef
#定义在一个auto序列的变量必须始终推导成同一类型
	auto x1 = 5, x2 = 5.0, x3='r';  // This is too much....we cannot combine like this


```



### 	容器

```
序列式容器:强调值的排序,序列式容器中的每个元素均有固定的位置
关联式容器:二叉树结构,各元素间无严格的物理意义上的顺序关系
```



### string类

```
引用头文件#include<string>，string类型为字符串类型
#string是一个类,内部封装了char *,管理这个字符串,是一个char*型的容器

string assign(s.begin(),s.begin()+n)//将s从开始共n个元素赋值给当前string
string assign(s,n)//将s从第n+1个元素开始到末尾的元素赋值给当前string

string类型数字转int型需减'0'，int类型转string调用to_string
size()返回字符串长度,sizeof()返回所占空间大小

substr() 函数用于从 string 字符串中提取子字符串，它的原型为：
string substr (size_t pos = 0, size_t len = npos) const;
pos 为要提取的子字符串的起始下标，len 为要提取的子字符串的长度。

c_str()：生成一个const char*指针，指向以空字符终止的数组,string s.c_str()即指向s这个字符串//c_str()返回一个客户程序可读不可改的指向字符数组的指针，不需要手动释放或删除这个指针
```

![image-20230301132010869](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230301132010869.png)

![image-20230301133919861](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230301133919861.png)

![image-20230301134554788](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230301134554788.png)

![image-20230301134617725](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230301134617725.png)

![image-20230301134632808](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230301134632808.png)

![image-20230301134653075](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230301134653075.png)

![image-20230301134709150](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230301134709150.png)





### 	Vector容器

```
#include<vector>
vector实为不用初始化制定大小的边长的单端数组,使用尾插法//vector可动态扩展

#vector容器若无嵌套可视作一维数组,若嵌套则几层就为几维数组,每个vector::iterator xx;返回的都是当前所处维数首位指针
#故若为vector<vector<int>> v;可视为二维数组,vector::iterator v1 = v.begin();返回的是行地址,vector::iterator v2 = (*v1).begin();返回的是每行首位元素的地址

vector元素类型为int,则初始化为0;若为string,默认初始化为空字符串'\0'
	vector<int> v1;
	vector<father> v2;
	vector<string> v3;
	vector<vector<int> >;  //注意空格。这里相当于二维数组int a[n][n];
	vector<int> v5 = { 1,2,3,4,5 }; //列表初始化,注意使用的是花括号
	vector<string> v6 = { "hi","my","name","is","lee" };
	vector<int> v7(5, -1); //初始化为-1,-1,-1,-1,-1。第一个参数是数目，第二个参数是要

初始化的值
	vector<string> v8(3, "hi");
	vector<int> v9(10); //默认初始化为0,大小为10
	vector<int> b(a, a+5); //将数组a[]从下标0-5赋值给vector b
	vector<int> b(a.begin(),a.begin()+i);//将vector a从begin()开始共i个元素给b
	
添加元素
	v1.push_back(i),元素被加在数组尾
	vector.insert(pos,elem),在迭代器pos指定的位置之前插入一个新元素elem,返回表示新插入元素位置的迭代器
	vector.insert(pos,n,elem),在迭代器pos指定的位置之前插入n个元素elem,返回第一个插入元素的位置
	vector.insert(pos,first,last),在迭代器pos指定位置之前插入其他容器(不限于vector)中[first,last)区域的所有元素,并返回表示第一个新插入元素位置的迭代器
	vector.insert(pos,initlist),在迭代器pos指定的位置之前插入初始化列表并返回第一个新插入元素位置的迭代器
	vector& operator=(const vector& vec);//重载等号操作符
	assign(beg,end);//将[beg,end)区间中的数据拷贝赋值给本身
	assign(n,elem);//将n个elem拷贝赋值给本身
	vector>empalce (const_iterator pos, args...);//在指定位置之前添加数据,每次只能添加一个,效率比insert高
	
删除元素
	pop_back(),删除最后一个元素,容器大小减1但容量不变
	erase(pos),删除pos指定位置元素,返回下一个元素的位置迭代器,大小减1,容量不变
	swap(beg),pop_back(),用swap交换要删除的元素和最后一个元素位置,再删除
	erase(beg,end),删除区间内所有元素,返回最后一个被删元素指向的下一个元素位置的迭代器
	remove(),删除容器中和指定元素值相等的元素,返回指向最后要给被删元素的下一个位置的迭代器,不改变容器大小和容量
	clear(),容器大小置零

vector对象操作vector<int>a
	a.assign(b.begin(),b.begin()+3),b为向量，将b的0~2个元素构成向量赋给a
	a.assign(4,2),a只含4个元素,每个元素为2
	a.back(),返回最后一个元素	a.front(),返回第一个元素
	a.begin(),返回第一个元素指针 	a.end(),返回最后一个元素指针
	a.size(),返回a元素个数
	a.capacity(),返回a可容纳元素个数
	a.resize(n,m),a中元素调为n个,值为m,若m缺失,只随机
	a.swap(b),a与b元素整体交换
	a.reserve(n),增加a容量至n
	
多维vector//第一层vector相当于总的大vector,每次可以插入小一层的任意大小vector(支持范围内)
例:ctor<vector<int>> my_vec;
	vector<int> inser_vec = {1,2,3,4,5};
	my_vec.push_back(inser_vec);
	vector<int>::iterator it = my_vec[0].begin();
	cout <<*it;

#多维vector对第一层vector进行size()时返回的是所含小vector个数
```

```
emplace_back() 和 push_back() 的区别，就在于底层实现的机制不同。push_back() 向容器尾部添加元素时，首先会创建这个元素，然后再将这个元素拷贝或者移动到容器中（如果是拷贝的话，事后会自行销毁先前创建的这个元素）；而 emplace_back() 在实现时，则是直接在容器尾部创建这个元素，省去了拷贝或移动元素的过程。//emplace_back效率更高
```



### 	Deque容器

```
deque可视作双端数组
```

![image-20230313221945830](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230313221945830.png)

```
begin()	返回指向容器中第一个元素的迭代器。
end()	返回指向容器最后一个元素所在位置后一个位置的迭代器，通常和 begin() 结合使用。
rbegin()	返回指向最后一个元素的迭代器。
rend()	返回指向第一个元素所在位置前一个位置的迭代器。
cbegin()	和 begin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
cend()	和 end() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
crbegin()	和 rbegin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
crend()	和 rend() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
size()	返回实际元素个数。
max_size()	返回容器所能容纳元素个数的最大值。这通常是一个很大的值，一般是 232-1，我们很少会用到这个函数。
resize()	改变实际元素的个数。
empty()	判断容器中是否有元素，若无元素，则返回 true；反之，返回 false。
shrink _to_fit()	将内存减少到等于当前元素实际所使用的大小。
at()	使用经过边界检查的索引访问元素。
front()	返回第一个元素的引用。
back()	返回最后一个元素的引用。
assign()	用新元素替换原有内容。
push_back()	在序列的尾部添加一个元素。
push_front()	在序列的头部添加一个元素。
pop_back()	移除容器尾部的元素。
pop_front()	移除容器头部的元素。
insert()	在指定的位置插入一个或多个元素。
erase()	移除一个元素或一段元素。
clear()	移出所有的元素，容器大小变为 0。
swap()	交换两个容器的所有元素。
emplace()	在指定的位置直接生成一个元素。
emplace_front()	在容器头部生成一个元素。和 push_front() 的区别是，该函数直接在容器头部构造元素，省去了复制移动元素的过程。
emplace_back()	在容器尾部生成一个元素。和 push_back() 的区别是，该函数直接在容器尾部构造元素，省去了复制移动元素的过程。
```



### 	Stack容器

```
栈容器,先进后出
```

![image-20230301135328046](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230301135328046.png)

### 	Queue容器

```
队列容器,先进先出
```

![image-20230301135412857](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230301135412857.png)



### 	List容器

```
链表容器,物理存储单元上非连续但逻辑存储上连续
```

![image-20230301135520023](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230301135520023.png)



![image-20230301135531883](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230301135531883.png)

![image-20230301135541577](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230301135541577.png)

![image-20230301135602514](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230301135602514.png)

![image-20230301135611831](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230301135611831.png)

![image-20230301135622465](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230301135622465.png)



### 	Map容器

![image-20230303154917773](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230303154917773.png)

![image-20230303155144471](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230303155144471.png)

```
T1,T2分别对应key值和索引值,mp为容器名
Map中所有元素都为pair,插入数据都需为对组
unordered_map为无序map,在头文件unordered_map中

[]操作符在map的用法
	map[key];可以直接查找key在map中对应的索引值,亦可以通过map[key]逻辑上存储key并统计key的频度而不需要检查key是否在map中
	因为若key不在map中则返回的索引值为零,此时要想逻辑上插入map只用map[key]+=1;即可//map[key]++或++map[key]也可
```

![image-20230303160639807](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230303160639807.png)

![image-20230303160104608](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230303160104608.png)



![image-20230303162511029](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230303162511029.png)

```
map每一对数据类型为pair,pair是一种模版类型.每个pair可以存储两个值.这两种值无限制。也可以将自己写的struct的对象放进去
```

![image-20230303160141131](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230303160141131.png)

```
 begin()         返回指向map头部的迭代器

     clear(）        删除所有元素

     count()         返回指定元素出现的次数, (帮助评论区理解： 因为key值不会重复，所以只能是1 or 0)

     empty()         如果map为空则返回true

     end()           返回指向map末尾的迭代器

     equal_range()   返回特殊条目的迭代器对

     erase()         删除一个元素

     find()          查找一个元素

     get_allocator() 返回map的配置器

     insert()        插入元素

     key_comp()      返回比较元素key的函数

     lower_bound()   返回键值>=给定元素的第一个位置

     max_size()      返回可以容纳的最大元素个数

     rbegin()        返回一个指向map尾部的逆向迭代器

     rend()          返回一个指向map头部的逆向迭代器

     size()          返回map中元素的个数

     swap()           交换两个map

     upper_bound()    返回键值>给定元素的第一个位置

     value_comp()     返回比较元素value的函数

```

### Set容器

```
概念:可以理解为一个集合且容器中元素有且只有一个//插入,删除,查找等复杂度均为对数集
#大多数编译器以红黑树实现
内部元素有序:可去重,排序操作
#map和set封装了二叉树
头文件<set>

#unordered_map在存储j,r时会对换二者位置,无论存储顺序为什么,存储之后二者顺序相反//不知道为什么

begin	指定受控序列的开头。
bucket	获取键值的存储桶编号。
bucket_count	获取存储桶数。
bucket_size	获取存储桶的大小。
cbegin	指定受控序列的开头。
cend	指定受控序列的末尾。
clear	删除所有元素。
containsC++20	检查 unordered_set 中是否包含具有指定键的元素。
count	查找与指定键匹配的元素数。
emplace	添加就地构造的元素。
emplace_hint	添加就地构造的元素，附带提示。
empty	测试元素是否存在。
end	指定受控序列的末尾。
equal_range	查找与指定键匹配的范围。
erase	移除指定位置处的元素。
find	查找与指定键匹配的元素。
get_allocator	获取存储的分配器对象。
hash_function	获取存储的哈希函数对象。
insert	添加元素。
key_eq	获取存储的比较函数对象。
load_factor	对每个存储桶的平均元素数进行计数。
max_bucket_count	获取最大的存储桶数。
max_load_factor	获取或设置每个存储桶的最多元素数。
max_size	获取受控序列的最大大小。
rehash	重新生成哈希表。
size	对元素数进行计数。
swap	交换两个容器的内容。
unordered_set	构造容器对象。

unordered_set::operator=	复制哈希表。
```



## 排序

```
Sort排序
	#include<algorithm>头文件
	它有三个参数sort(begin, end, cmp)，其中begin为指向待sort()的数组的第一个元素的指针，end为指向待sort()的数组的最后一个元素的下一个位置的指针，cmp参数为排序准则，cmp参数可以不写，如果不写的话，默认从小到大进行排序
	
```

​	
