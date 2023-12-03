# C++(进阶)

## 一些术语和概念

### 耦合和解耦

**耦合**

​	通俗地说，耦合就是一个系统的各个部分之间彼此关联、互相影响的程度。当系统内部的各个部分之间耦合度较高时，它们的行为会更加紧密地相互关联，但也更加复杂、难以控制。相反，当各个部分之间的耦合度较低时，它们的行为会更加独立，但也会导致系统的整体性能较差

**解耦**

​	减少耦合的过程，使得模块或组件之间的依赖尽可能小。这样可以使得代码更加模块化、灵活、易于维护和扩展

**总结**

​	在紧密耦合的程序中，代码的修改可能会对整个程序产生影响，而在低耦合的程序中，各个组件之间的依赖关系更加松散，更容易扩展和维护

## 一些库

### std::string

**大小问题**	每个std::string对象大小固定，由编辑器所决定

## 命名空间

### std

#### predicate

```
判断式,返回bool类型,c
```

## 处理机制

### terminate()和set_terminate()

```
C++中，异常不可以忽略，当异常找不到匹配的catch字句时，会调用系统的库函数terminate()(在头文件中)，默认情况下，terminate()函数调用标准C库函数abort()使程序终止而退出。当调用abort函数时，程序不会调用正常的终止函数，也就是说，全局对象和静态对象的析构函数不会执行。

通过使用标准的set_terminate()函数，可以设置自己的terminate()函数。自定义的terminate()函数不能有参数，而且返回值类型为void。另外，terminate函数不能返回也不能抛出异常，它必须终止程序。如果terminate函数被调用，这就意味着问题已经无法解决了。

terminate被调用的情况：
1.当发送一个异常，并且构造函数产生异常
2.当发送一个异常，或者析构函数产生异常
3.一个静态对象的构造或者析构发送一个异常
4.以atexit注册的函数发生异常的时候
5.自定义一个异常，但是实际上没有异常产生的时候
6.调用缺省的unexcepted()函数时候
```

### 快速退出

```
C++程序中有以下几种推出方式:terminate abort exit

terminate: 实际上是c++语言中异常处理的一部分(包含在<exception>头文件中).一般而言，没有被捕获的异常就会被terminate函数调用.只要C++程序中出现了非程序员预期的行为，都有可能导致terminate的调用.而terminate函数在默认情况下,是去调用abort函数的.

abort:不会调用任何的析构函数，默认情况下会想合乎POSIX标准的系统抛出一个信号:SIGABRT.abort是系统在毫无办法的下下策——终止进程,会造成一些问题.

exit:属于正常退出的范畴。
```

### try、throw和catch关键字

```C++
#include <iostream>
using namespace std;
int main()
{
    double m = 1, n = 0;
    try {
        cout << "before dividing." << endl;
        if (n == 0)
            throw - 1;  //抛出int型异常
        else if (m == 0)
            throw - 1.0;  //拋出 double 型异常
        else
            cout << m / n << endl;
        cout << "after dividing." << endl;
    }
    catch (double d) {
        cout << "catch (double)" << d << endl;
    }
    catch (...) {
        cout << "catch (...)" << endl;
    }
    cout << "finished" << endl;
    return 0;
}
//运行结果
//before dividing.
//catch (...)
//finished

代码中,对两个数进行除法计算,其中除数为0.可以看到以上三个关键字,程序的执行流程是先执行try包裹的语句块,如果执行过程中没有异常发生,则不会进入任何catch包裹的语句块,如果发生异常,则使用throw进行异常抛出,再由catch进行捕获,throw可以抛出各种数据类型的信息,代码中使用的是数字,也可以自定义异常class.catch根据throw抛出的数据类型进行精确捕获（不会出现类型转换）,如果匹配不到就直接报错,可以使用catch(...)的方式捕获任何异常（不推荐）.当然,如果catch了异常,当前函数如果不进行处理,或者已经处理了想通知上一层的调用者,可以在catch里面再throw异常.
    
有时候,程序员在定义函数的时候知道函数可能发生的异常,可以在函数声明和定义时,指出所能抛出异常的列表
int fun() throw(int,double,A,B,C){...};


```

### C++标准异常类exception

![image-20230913141106368](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230913141106368.png)

```

异常						描述
std::exception			该异常是所有标准 C++ 异常的父类。
std::bad_alloc			该异常可以通过 new 抛出。
std::bad_cast			该异常可以通过 dynamic_cast 抛出。
std::bad_typeid			该异常可以通过 typeid 抛出。
std::bad_exception		这在处理 C++ 程序中无法预期的异常时非常有用。
std::logic_error		理论上可以通过读取代码来检测到的异常。
std::domain_error		当使用了一个无效的数学域时，会抛出该异常。
std::invalid_argument	当使用了无效的参数时，会抛出该异常。
std::length_error		当创建了太长的 std::string 时，会抛出该异常。
std::out_of_range		该异常可以通过方法抛出，例如 std::vector 和 std::bitset<>::operator[]()。
std::runtime_error		理论上不可以通过读取代码来检测到的异常。
std::overflow_error		当发生数学上溢时，会抛出该异常。
std::range_error		当尝试存储超出范围的值时，会抛出该异常。
std::underflow_error	当发生数学下溢时，会抛出该异常。
```

#### noexcept

```
noexcept 编译期完成声明和检查工作.noexcept 主要是解决的问题是减少运行时开销. 运行时开销指的是编译器需要为代码生成一些额外的代码用来包裹原始代码,当出现异常时可以抛出一些相关的堆栈stack unwinding错误信息, 这里面包含错误位置、错误原因、调用顺序和层级路径等信息.当使用noexcept声明一个函数不会抛出异常候, 编译器就不会去生成这些额外的代码, 直接的减小的生成文件的大小, 间接的优化了程序运行效率.

noexcept 标识符有几种写法: noexcept、noexcept(true)、noexcept(false)、noexcept(expression)、throw() .

其中 noexcept 默认表示 noexcept(true).
当 noexcept 是 true 时表示函数不会抛出异常,
当 noexcept 是 false 时表示函数可能会抛出异常.
throw()表示函数可能会抛出异常, 不建议使用该写法, 应该使用 noexcept(false), 因为 C++20 放弃这种写法

noexcept 函数用来检查一个函数是否声明了 noexcept, 如果声明了noexcept(true)则返回true, 如果声明了noexcept(false)则返回false
```







## 内存管理

### 内存泄漏

```
概念:一般我们常说的内存泄漏是指堆内存的泄漏.堆内存是指程序从堆中分配的,大小任意的(内存块的大小可以在程序运行期决定)内存块,使用完后必须显式释放的内存.应用程序般使用malloc、realloc、 new等函数从堆中分配到块内存,使用完后,程序必须负责相应的调用free或delete释放该内存块,否则,这块内存就不能被再次使用,我们就说这块内存泄漏了

避免内存泄露的几种方式
1.计数法:使用new或者malloc时,让该数+1,delete或free时,该数-1,程序执行完打印这个计数,如果不为0则表示存在内存泄露
2.一定要将基类的析构函数声明为虚函数
3.对象数组的释放一定要用delete []
4.有new就有delete，有malloc就有free，保证它们一定成对出现
```

##### 基类析构声明虚函数原因

```
若用base *p = new derive,则除了调用基类构造函数,还会调用派生类构造函数生成一个派生类对象,此时若基类析构函数不是虚函数,当delete p时,只会调用基类析构函数,因为对于delete只知道p是base类型的指针,只会调用base的析构函数释放p指针而derive析构函数没有执行,导致申请的内存空间没有被释放也没有被指针指向产生内存泄漏;若base析构声明为虚函数时,执行delete就会检查虚表内容,而指向derive的析构函数的虚指针存放在虚表里,编译器就会根据虚表逐条执行析构函数

原理
当父类析构函数用虚函数形式声明时,子类中的虚构函数相当于是对父类析构函数的重写,故而子类虚函数表中会存放子类析构函数的地址,而用父类对象指向子类对象并析构时,会检查虚表中是否存在析构函数,若存在就会执行,所以若父类析构函数没有虚函数声明,则子类析构函数就不会存放在子类虚表中,导致子类空间没有被释放产生内存泄漏
```

###### 基类虚析构时子类和基类结构

![image-20230829123815418](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230829123815418.png)

![image-20230829124117026](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230829124117026.png)

###### 基类没有虚析构时子类和基类结构

![image-20230829123925288](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230829123925288.png)

![image-20230829123942023](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230829123942023.png)

### 声明和定义

```
代码执行遇到函数时编译器会首先查找函数的定义，若没找到就会去找函数的声明，若定义和声明都没有编译器就会做隐式声明
//编译器只会做一种隐式声明：int 函数名(int,int);(只会隐式声明返回值为int)
```

### 头文件

#### 性质

```
1. 头文件只是声明，不占内存；在编译时会被合并到源文件
2. 头文件和其它C语言文件一样可以引用其它文件，可以写预处理块但是不要出现具体语句
3. 可以在头文件中定义宏函数，其本质上还是一个声明
4. 各个头文件相互独立，标准头文件之间不存在相互包含关系
5. 头文件可以重复引用，但是相当于只导入一次
6. 从C语法角度讲完全可以在头文件中写任何东西，因为#include在作用上和Ctrl-C + Ctrl-V等效——但是这样时不推荐的；头文件的作用就是更好的组织代码

何时使用
1. 结构体的定义
2. 函数声明，变量声明，宏定义，常数定义等
3. 当源代码不便公布时使用头文件提供接口
4. 在大项目中需要多文件联合编译
```

#### 库和头文件

```
库可以包含头文件，头文件不能包含库
t
```



### 宏定义

```
C++三种预处理：宏定义、文件包含、条件编译
宏定义是替换，不做计算，也不做表达式求解。
“宏定义”也称“宏替换”，“宏”
```



## 函数

### main函数

```
main函数是否必须存在？
每一个C++程序都必须要有main函数,因为main函数是C/C++程序的入口点,若没有main函数,则程序的初始化和其他函数结果的调用就无法正常进行

main函数调用前
1.设置栈指针,初始化静态static变量和global全局变量,即.data(数据段)的内容
2.将未初始化部分的全局变量赋初值,即对BSS段内容进行赋值
3.全局对象初始化,在main前调用构造函数,即执行main前的一些代码
4.将main的参数传入main函数,正式调用main函数
5.__attribute__((constructor))
	__attribute__可用于为函数或者数据声明赋属性值。给函数分配属性的主要目的是为了让编译程序可以优化处理。分配给函数的属性位于函数原型的声明中
	
	__attribute__((constructor)) 先于main()函数调用
	__attribute__((destructor))  在main()函数后调用
	
main函数调用后
1.全局对象的析构函数
2.__attribute__((destructor))
```

### function

```
std::function是一个函数包装器,该函数包装器模板能包装任何类型的可调用实体,如普通函数,函数对象,lamda表达式等.包装器可拷贝,移动等,并且包装器类型仅仅依赖于调用特征,而不依赖于可调用元素自身的类型.std::function是C++11的新特性.
std::function对象实例可被拷贝和移动,并且可以使用指定的调用特征来直接调用目标元素.当std::function对象实例未包含任何实际可调用实体时,调用该std::function对象实例将抛出std::bad_function_call异常

头文件<function>

模板类声明
template<class _Rp, class ..._ArgTypes>
class _LIBCPP_TEMPLATE_VIS function<_Rp(_ArgTypes...)>
    : public __function::__maybe_derive_from_unary_function<_Rp(_ArgTypes...)>,
      public __function::__maybe_derive_from_binary_function<_Rp(_ArgTypes...)>
{ ... }

std::function对象实例不允许进行==和!=比较操作,std::function模板类实例最终调用成员函数_Rp operator()(_ArgTypes...) const进而调用包装的调用实体

```

#### 示例

```C++
class Base {
public:
  int a;
  int b;

  void display() {
    std::cout << "Base display" << std::endl;
  }
  
  static void count() {
    std::cout << "Base Count" << std::endl;
  }
};

bool func(int a) {
  std::cout << "func pointer " << a << std::endl;
}

int main() {
  function<bool(int)>p1 = func;
  p1(10);
    
  Base base;
  function<void(void)>p2 = bind(&Base::display,&base);
  Base base;
  (base.*p2)();
  
  function<void(void)>p3 = &Base::count;
  p3();

  return 0;
}
```

### bind与lambda

```C++
头文件	<functional>
```

#### bind

```
概念:bind可以看作一个通用的函数适配器，它接受一个可调用对象，生成一个新的可调用对象来适应原对象的参数列表,其将可调用对象与其参数一起绑定,绑定后的结果用function封存

作用	1.将可调用对象和其参数绑定成一个仿函数	2.只绑定部分参数,减少可调用对象传入的参数

语法:auto newCallable = bind(callable,arg_list);
	//当调用newCallable时会调用callable并将参数列表arg_list中的对应参数传给callable
	//参数列表中的参数也可以是占位符,通过placeholders::_n调用,n为整数
	
总结
1.预绑定的参数是以值传递的形式,不预绑定的参数要用std::placeholders(占位符)的形式占位,从_1开始,依次递增,是以引用传递的形式;
2.std::placeholders表示新的可调用对象的第几个参数,而且与原函数的该占位符所在位置的进行匹配;
3.bind绑定类成员函数时,第一个参数表示对象的成员函数的指针,第二个参数表示对象的地址,这是因为对象的成员函数需要有this指针.并且编译器不会将对象的成员函数隐式转换成函数指针,需要通过&手动转换;
4.std::bind的返回值是可调用实体,可以直接赋给std::function.
```

#### lambda

```
概念:lambda表达式就是一段可用代码,主要适用于只用到一两次的简短代码段,lambda是匿名代码,保证了不会被不安全	访问,即自定义一个函数并且可将函数作为参数给其他函数调用

语法:[captures](paramas)->trailing-return-type{body}//返回值类型可以省略,默认int 
    
    [captures]<tparams>(paramas)lambda-specifiers{body}
	含义:完整的lambda表达式,包含了lambda的所有成分
	[captures](paramas)trailing-return-type{body}
	含义:常量lambda表达式,捕获的变量都是常量,不能在lambda表达式的body中修改
	[captures](paramas){body}
	含义:和上式类似,但lambda的函数返回值可以用函数体推导出来
	[captures]lambda-specifiers{body}
	含义:lambda函数无参数,但是可以添加lambda-specifiers
参数介绍
	captures 捕获列表，lambda可以把 上下文变量以值或弓|用的方式捕获,在body中直接使用
	tparams 模板参数列表(C+ + 20引入),让lambda可以像模板函数一样被调用
	params 参数列表，有一点需要注意,在c++14之后允许使用auto左右参数类型
	lambda-specifiers lambda说明符,一些可选的参数,这里比较常用的参数就是mutable和exception
	trailing-return-type 返回值类型,一般可以省略掉,由编译器来推导
	body 函数体，函数的具体逻辑。
捕获方式
	[] 不捕获任何外围参数
	[=] 按值的方式捕获所有变量
	[&] 按引用的方式捕获所有变量
	[=, &a] 除了变量a之外，按值的方式捕获所有局部变量，变量a使用引用的方式来捕获。这里可以按引用捕获多个，例如 [=, &a, &b,&c]。这里注意，如果前面加了=，后面加的具体的参数必须以引用的方式来捕获，否则会报错。
	[&, a] 除了变量a之外，按引用的方式捕获所有局部变量，变量a使用值的方式来捕获。这里后面的参数也可以多个，例如 [&, a, b, c]。这里注意，如果前面加了&，后面加的具体的参数必须以值的方式来捕获。
	[a, &b] 以值的方式捕获a，引用的方式捕获b，也可以捕获多个。
	[this] 在成员函数中，也可以直接捕获this指针，其实在成员函数中，[=]和[&]也会捕获this指针。
```

### 回调函数

**定义**

​	回调函数是一种特殊的函数，它作为参数传递给另一个函数，并在被调用函数执行完毕后被调用。回调函数通常用于事件处理、异步编程和处理各种操作系统和框架的API。

**基本概念**

​	1、回调：指被传入到另一个函数的函数

​	2、异步编程：指在代码执行时不会阻塞程序运行的方式。

​	3、事件驱动：指程序的执行是由外部事件触发而不是顺序执行的方式

**使用场景**

​	回调函数是一种常见的编程技术，它可以在异步操作完成后调用一个预定义的函数来处理结果。回调函数通常用于处理事件、执行异步操作或响应用户输入等场景。

​	回调函数的作用是将代码逻辑分离出来，使得代码更加模块化和可维护。使用回调函数可以避免阻塞程序的运行，提高程序的性能和效率。另外，回调函数还可以实现代码的复用，因为它们可以被多个地方调用。

```
回调函数的使用场景包括：

事件处理：回调函数可以用于处理各种事件，例如鼠标点击、键盘输入、网络请求等。
异步操作：回调函数可以用于异步操作，例如读取文件、发送邮件、下载文件等。
数据处理：回调函数可以用于处理数据，例如对数组进行排序、过滤、映射等。
插件开发：回调函数可以用于开发插件，例如 WordPress 插件、jQuery 插件等。

回调函数是一种非常灵活和强大的编程技术，可以让我们更好地处理各种异步操作和事件。
```

**实现方法**

1、函数指针

​	函数指针是一个变量，它存储了一个函数的地址。当将函数指针作为参数传递给另一个函数时，另一个函数就可以使用这个指针来调用该函数。

2、函数对象

​	除了函数指针，还可以使用函数对象来实现回调函数。函数对象是一个类的实例，其中重载了函数调用运算符 ()。当将一个函数对象作为参数传递给另一个函数时，另一个函数就可以使用这个对象来调用其重载的函数调用运算符

3、匿名函数/lambda表达式

​	Lambda表达式是一个匿名函数，可以作为参数传递给其他函数或对象。在C++11之前，如果想要传递一个函数作为参数，需要使用函数指针或者函数对象。但是这些方法都比较繁琐，需要显式地定义函数或者类，并且代码可读性不高。使用Lambda表达式可以简化这个过程，使得代码更加简洁和易读

**优点**

​	1、提高代码的复用性和灵活性：回调函数可以将一个函数作为参数传递给另一个函数，从而实现模块化编程，提高代码的复用性和灵活性。

​	2、解耦合：回调函数可以将不同模块之间的关系解耦，使得代码更易于维护和扩展。

​	3、可以异步执行：回调函数可以在异步操作完成后被执行，这样避免了阻塞线程，提高应用程序的效率。

**缺点**

​	1、回调函数嵌套过多会导致代码难以维护：如果回调函数嵌套层数过多，代码会变得非常复杂，难以维护。

​	2、回调函数容易造成竞态条件：如果回调函数中有共享资源访问，容易出现竞态条件，导致程序出错。

​	3、代码可读性差：回调函数的使用可能会破坏代码的结构和可读性，尤其是在处理大量数据时。

**小结**	代码灵活、易于扩展，但是不易于阅读、容易出错。

## 指针

### 函数指针

```C++
概念:与变量一样,函数在内存中也有自己的固定位置,函数指针指向函数在内存中的固定空间,对于一般函数来说,函数名就是函数的指针
    
语法
   	int(*funcptr)(参数列表);
	int(*const funcptr)(参数列表);
	const int(*funcptr);//该指针所指向函数返回值是常量
注:函数指针指向的函数其参数列表元素类型必须与函数指针相同
作用:将函数作为参数传入另一个函数
```

### 字符串指针和用指针存储数组首地址

```
字符串指针实质为字符串常量指针,即char *p = "...";
这里定义了一个指针指向字符串,但程序没有给"..."分配空间,故而该字符串被系统分配到常量区,即全局(静态)变量区,而常量一旦初始化后就不能再修改值,故而p相当于一个字符串常量

char p[] = "...";则是编译器在栈上创建一个字符串p,把abcd从常量区复制到p,修改p[0]就是修改一个局部变量,这是允许的.
char *ptr = p;则是把数组首元素地址传递给指针ptr,通过ptr解引用访问数组元素就可以修改元素值
```

### 数组指针和指针数组

```
数组指针:可理解为数组的指针,指一个指针变量指向数组的首地址
指针数组:可理解为指针的数组,指一个数组存储的全是指针变量

注:
1.数组指针强调的是指向一个数组的指针,故而在声明指针时不能直接定义为类似int (*p)[] = {}; 因为p是指向长度为[]的数组的指针,[]也为p的步长,即表示p指向整个数组而不是某一个元素,故而要通过数组名初始化数组指针则必须通过显示类型转换,因为数组名会被隐式转换为指针,指向数组第一个元素,而不是指向整个数组
2.指针数组强调的是存储指针的数组,故而可以直接定义为类似int *p[] = {指针1,指针2,..};
```

![image-20230828225951816](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230828225951816.png)

## 动态内存的分配与释放

### new/delete

```
C++的三种new:plain new\nothrow new\placement new

plain new:普通的new,空间分配失败时,抛出异常std::bad_alloc而不是返回null
空间分配失败:通过try{}catch(...){}处理
语法:类型 *指针名 = new 类型
	
nothrow new:空间分配失败时,返回null而不是抛出异常std::bad_alloc
空间分配失败:判断指针是否null
语法:类型 *指针名 = new(nothrow) 类型

placement new:是重载operator new的一个标准、全局的版本,不能被自定义的版本代替,允许再一块已经分配成功的内存上重新构造对象或对象组,其不用担心分配是否成功,其唯一作用是调用对象的构造函数,这种重载是为了解决时间要求比较高且长时间运行不希望被打断的问题

原型:void *operator new(size_t,void*p)throw(){return p;}
注意
1.placement new主要用途是反复使用一块较大的动态分配内存来构造不同类型的对象或其他数组
2.placement new构造起来的对象数组,要显示调用他们的析构函数销毁(析构函数不释放对象内存),故而不能使用delete,因为placement new构造的对象或数组大小不一定等于原来分配的内存大小,delete会造成内存泄漏或者之后释放内存时出现运行错误
```

#### placement new例子

```
class MyClass {…};

MyClass * p=new MyClass;

这里的new实际上是执行如下3个过程:
1.调用operator new分配内存
2.调用构造函数生成类对象
3.返回相应指针

operator new就像operator+一样,是可以重载的,但是不能在全局对原型为void operator new(size_t size)这个原型进行重载,一般只能在类中进行重载.如果类中没有重载operator new,那么调用的就是全局的::operator new来完成堆的分配.同理,operator new[]、operator delete、operator delete[]也是可以重载的,一般你重载了其中一个,那么最好把其余三个都重载一遍.
placement new是operator new的一个重载版本,只是我们很少用到它.如果你想在已经分配的内存中创建一个对象,使用new是不行的.也就是说placement new允许你在一个已经分配好的内存中（栈或堆中）构造一个新的对象.原型中void*p实际上就是指向一个已经分配好的内存缓冲区的的首地址.
```

#### 实现原理

```
1、 new简单类型直接调用operator new分配内存
而对于复杂结构,先调用operator new分配内存,然后在分配的内存上调用构造函数
对于简单类型,new[]计算好大小后调用operator new.
对于复杂数据结构,new[]先调用operator new[]分配内存,然后在p的前四个字节写入数组大小n,然后调用n次构造函数,针对复杂类型,new[]会额外存储数组大小.
① new表达式调用一个名为operator new(operator new[])函数,分配一块足够大的、原始的、未命名的内存空间；
② 编译器运行相应的构造函数以构造这些对象,并为其传入初始值.
③ 对象被分配了空间并构造完成,返回一个指向该对象的指针.

2、 delete简单数据类型默认只是调用free函数;复杂数据类型先调用析构函数再调用operator delete;针对简单类型,delete和delete[]等同.假设指针p指向new[]分配的内存.因为要4字节存储数组大小,实际分配的内存地址为[p-4],系统记录的也是这个地址.delete[]实际释放的就是p-4指向的内存.而delete会直接释放p指向的内存,这个内存根本没有被系统记录,所以会崩溃.

3、 需要在 new [] 一个对象数组时,需要保存数组的维度,C++ 的做法是在分配数组空间时多分配了 4 个字节的大小,专门保存数组的大小,在 delete [] 时就可以取出这个保存的数,就知道了需要调用析构函数多少次了
```



#### delete、delete[]、allocator的作用

```
1.new一个动态数组时,[]中数据必须是整数
2.new动态数组返回元素类型指针,而不是数组类型
3.delete[]时,数组中的元素按照逆序的顺序进行销毁
4.new在内存分配上有局限性,new的机制是将内存分配和对象构造组合在一起,同样的,delete也是将对象析构和内存释放组合在一起的.allocator将这两部分分开进行,allocator申请一部分内存,不进行初始化对象,只有当需要的时候才进行初始化操作
```

### malloc/free

```
函数原型:extern void *malloc(unsigned int num_bytes);
功能:分配长度为num_bytes的字节内存块,若成功返回被分配指针,失败返回NULL
头文件:<malloc.h>或<alloc.h>//二者内容完全一致

语法:指针名 = (类型*)malloc(长度大小);

malloc分配内存空间在使用完毕后需手动释放,调用free();

注:被free回收的内存空间会首先被ptmalloc使用双链表保存起来,当用户下一次申请内存的时候,会尝试从这些内存中寻找合适的返回.这样就避免了频繁的系统调用,占用过多的内存资源.因此,ptmalloc会尝试对小块内存进行合并,避免过多的内存碎片
```

##### 实现原理

```
1、 在标准C库中,提供了malloc/free函数分配释放内存,这两个函数底层是由brk、mmap、，munmap这些系统调用实现的;

2、 brk是将「堆顶」指针向高地址移动,获得新的内存空间,mmap是在进程的虚拟地址空间中（堆和栈中间，称为文件映射区域的地方）找一块空闲的虚拟内存.这两种方式分配的都是虚拟内存,没有分配物理内存.在第一次访问已分配的虚拟地址空间的时候,发生缺页中断,操作系统负责分配物理内存,然后建立虚拟内存和物理内存之间的映射关系

3、 malloc小于128k的内存,使用brk分配内存,将「堆顶」指针往高地址推;malloc大于128k的内存,使用mmap分配内存,在堆和栈之间找一块空闲内存分配;brk分配的内存需要等到高地址内存释放以后才能释放,而mmap分配的内存可以单独释放.当最高地址空间的空闲内存超过128K（可由M_TRIM_THRESHOLD选项调节）时,执行内存紧缩操作（trim）.在上一个步骤free的时候,发现最高地址空闲内存超过128K,于是内存紧缩.

4、 malloc是从堆里面申请内存,也就是说函数返回的指针是指向堆里面的一块内存.操作系统中有一个记录空闲内存地址的链表.当操作系统收到程序的申请时,就会遍历该链表,然后就寻找第一个空间大于所申请空间的堆结点,然后就将该结点从空闲结点链表中删除,并将该结点的空间分配给程序.
```



### new/delete与malloc/free

```
相同点:都可以用于内存的动态申请

不同点
1.new是C++运算符,malloc是C/C++语言标准库函数,故而new支持重载
2.new自动计算分配内存空间大小,malloc要手工计算
3.new是类型安全的,malloc不是,即new会检查数据类型是否匹配,而malloc不会检查
4.new给类对象分配内存空间时,调用operator new的标准库函数分配足够内存空间并调用相关对象的构造函数,delete则会调用相关对象的析构函数,后通过operator delete的标准库函数释放该对象所用内存,而malloc没有相关调用
5.new不需要头文件支持,malloc需要
6.new封装了malloc,故而可以使用free但不会调用析构函数
7.new返回具体的类型指针,malloc返回void*,所以必须进行强制类型转换

有了malloc/free还需要new/delete的原因
因为malloc/free是标准库函数,是已经编译的代码,故而不能再添加对象构造和析构的功能,故而需要new/delete

注:理论上可以用delete释放malloc申请的内存空间,但不能保证每个C++程序运行时正常
```



## 类对象的创建和调用时机

```C++
#代码块
int main() {
	cout << "classes are creating" << endl;
	myclass tempclass1;
	myclass tempclass2(1);
	myclass tempclass3(tempclass2);

	cout << endl;

	cout << "use existing class" << endl;
	useclass1(tempclass1);
	useclass2(tempclass1);
	useclass3(move(tempclass1));


	cout << endl;

	cout << "use temp class" << endl;
	useclass1(myclass());
	useclass2(myclass(1));
	useclass3(myclass(1));
}

//定义类
class myclass {
public:
	myclass() {
		cout << "normall construction and the dest is " << this << endl;
		num = 0;
	}

	myclass(int i) {
		cout << "parament construction and the dest is " << this << endl;
	}

	myclass(const myclass& temp):num(temp.num) {
		cout << "deep copy has done and " << this << " copys " << &temp << endl;
	}

	~myclass() {
		cout << this << " has been deleted" << endl;
	}
private:
	int num;
};
//函数定义
void useclass1(myclass temp) {
	cout << " func1 use class and the class is " << &temp << endl;
}

void useclass2(const myclass &temp) {
	cout << " func2 use class by left cite and the class is " << &temp << endl;
}

void useclass3(myclass &&temp) {
	cout << " func3 use class by right cite and the class is " << &temp << endl;
}

#输出
classes are creating
normall construction and the dest is 00000025DB4FF6C4	//普通构造
parament construction and the dest is 00000025DB4FF6E4	//自定义构造
deep copy has done and 00000025DB4FF704 copys 00000025DB4FF6E4	//自定义拷贝构造

use existing class
//值传递调用类对象 
deep copy has done and 00000025DB4FF7E4 copys 00000025DB4FF6C4
func1 use class and the class is 00000025DB4FF7E4
00000025DB4FF7E4 has been deleted
   
func2 use class by left cite and the class is 00000025DB4FF6C4	//左值引用类对象
func3 use class by right cite and the class is 00000025DB4FF6C4	//右值引用类对象

use temp class
//值传递调用临时对象
normall construction and the dest is 00000025DB4FF824
func1 use class and the class is 00000025DB4FF824
00000025DB4FF824 has been deleted
//左值引用调用临时对象
parament construction and the dest is 00000025DB4FF864
func2 use class by left cite and the class is 00000025DB4FF864
00000025DB4FF864 has been deleted
//右值引用调用临时对象
parament construction and the dest is 00000025DB4FF884
func3 use class by right cite and the class is 00000025DB4FF884
00000025DB4FF884 has been deleted
//析构已有对象
00000025DB4FF704 has been deleted
00000025DB4FF6E4 has been deleted
00000025DB4FF6C4 has been deleted
```

#### lambda表达式的情况

```C++
#代码块
auto mybda1 = [](myclass temp) {
		cout << "use lambda and the dest is " << &temp << endl;
	};
auto mybda2 = [](const myclass &temp) {
		cout << "use lambda by left cite and the dest is " << &temp << endl;
	};
auto mybda3 = [](myclass &&temp) {
		cout << "use lambda by right cite and the dest is " << &temp << endl;
	};


#输出
//调用已有对象
//值传递
deep copy has done and 0000008089B5FC34 copys 0000008089B5FA54
use lambda and the dest is 0000008089B5FC34
0000008089B5FC34 has been deleted
//左值引用与右值引用
use lambda by left cite and the dest is 0000008089B5FA54
use lambda by right cite and the dest is 0000008089B5FA54

//调用临时对象
//值传递
parament construction and the dest is 0000008089B5FC74
use lambda and the dest is 0000008089B5FC74
0000008089B5FC74 has been deleted
//左值引用
parament construction and the dest is 0000008089B5FCB4
use lambda by left cite and the dest is 0000008089B5FCB4
0000008089B5FCB4 has been deleted
//右值引用
parament construction and the dest is 0000008089B5FCD4
use lambda by right cite and the dest is 0000008089B5FCD4
0000008089B5FCD4 has been deleted
```



## C++11

### 智能指针

#### 概念

```
C++11引入了3个智能指针类型
1.std::unique_ptr<T>:独占资源所有权的指针
2.std::shared_ptr<T>:共享资源所有权的指针
3.std::weak_ptr<T>:共享资源的观察者,需要和std::shared_ptr一起使用,不影响资源的生命周期

std::auto_ptr已被废弃
```

#### std::unique_ptr<T>

```
概念:当我们独占资源的所有权的时候,可以使用std::unique_ptr对资源进行管理,离开unique_ptr对象的作用域时,会自动释放资源.

性质:unique_ptr以模板类形式提供,unique_ptr<T>定义在头文件<memory>,T为指针所指数据类型

创建指针
1.std::unique_ptr<int> p1();//创建空指针
2.std::unique_ptr<int> p2(nullptr);//创建空指针
3.std::unique_ptr<int> p3(new int);//创建指针并指明指向
```

##### 移动构造函数

```
基于unique_ptr类型指针不共享各自拥有的堆内存,因此 C++11标准中的unique_ptr模板类没有提供拷贝构造函数，只提供了移动构造函数

std::unique_ptr<int> p4(new int);
std::unique_ptr<int> p5(p4);//错误，堆内存不共享
std::unique_ptr<int> p5(std::move(p4));//正确，调用移动构造函数
注:对于调用移动构造函数的p4和p5来说,p5将获取p4所指堆空间的所有权,而p4将变成空指针(nullptr)


```

##### 释放内存

```
默认情况下,unique_ptr指针采用 std::default_delete<T>方法释放堆内存.可以自定义符合实际场景的释放规则.
和shared_ptr指针不同,为 unique_ptr自定义释放规则,只能采用函数对象的方式

//自定义的释放规则
struct myDel
{
    void operator()(int *p) {
        delete p;
    }
};
std::unique_ptr<int, myDel> p6(new int);
//std::unique_ptr<int, myDel> p6(new int, myDel());
```

![image-20230814142812893](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230814142812893.png)



#### std::shared_ptr<T>

```
概念:shared_ptr<T>(其中T表示指针指向的具体数据类型)的定义位于<memory>头文件,并位于std命名空间中

性质:多个shared_ptr智能指针可以共同使用同一块堆内存.并且,由于该类型智能指针在实现上采用的是引用计数机制,即便有一个shared_ptr指针放弃了堆内存的“使用权”(引用计数减1),也不会影响其他指向同一堆内存的shared_ptr指针(只有引用计数为 0 时,堆内存才会被自动释放)

创建语法
1.std::shared_ptr<int> p1;//不传入任何实参
2.std::shared_ptr<int> p2(nullptr);//传入空指针 nullptr
3.std::shared_ptr<int> p3(new int(10));//指向一块存有10这个int类型数据的堆内存空间
4.std::shared_ptr<int> p3 = std::make_shared<int>(10);//make_shared<T>,模板函数,用于初始化智能指针
```

##### 拷贝构造函数和移动构造函数

```
//调用拷贝构造函数
std::shared_ptr<int> p4(p3);//或者 std::shared_ptr<int> p4 = p3;
注:p3和p4都是shared_ptr类型的智能指针,因此可以用p3来初始化p4,由于p3是左值,因此会调用拷贝构造函数.需要注意的是,如果p3为空智能指针,则p4也为空智能指针,其引用计数初始值为0;反之,则表明p4和p3指向同一块堆内存,同时该堆空间的引用计数会加1

//调用移动构造函数
std::shared_ptr<int> p5(std::move(p4)); //或者 std::shared_ptr<int> p5 = std::move(p4);
注:对于std::move(p4)来说,该函数会强制将p4转换成对应的右值,因此初始化p5调用的是移动构造函数.另外和调用拷贝构造函数不同,用std::move(p4)初始化p5,会使得p5拥有了 p4的堆内存,而p4则变成了空智能指针
```

##### 释放内存

```
//指定 default_delete 作为释放规则
std::shared_ptr<int> p6(new int[10], std::default_delete<int[]>());

//自定义释放规则
void deleteInt(int*p) {
    delete []p;
}

//初始化智能指针，并自定义释放规则
std::shared_ptr<int> p7(new int[10], deleteInt);

借助lambda表达式,我们还可以像如下这样初始化 p7，它们是完全相同的
std::shared_ptr<int> p7(new int[10], [](int* p) {delete[]p; });
```

![image-20230814144025307](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230814144025307.png)

#### std::weak_ptr

```
概念:weak_ptr<T>(T 为指针所指数据的类型)定义在<memory>头文件,并位于std命名空间中

性质
weak_ptr定位为智能指针的一种,但该类型指针通常不单独使用(没有实际用处),只能和shared_ptr类型指针搭配使用.甚至于,我们可以将weak_ptr类型指针视为shared_ptr指针的一种辅助工具,借助 weak_ptr类型指针,我们可以获取shared_ptr指针的一些状态信息，比如有多少指向相同的shared_ptr指针、shared_ptr指针指向的堆内存是否已经被释放等等
当 weak_ptr类型指针的指向和某一shared_ptr指针相同时,weak_ptr指针并不会使所指堆内存的引用计数加1;同样当 weak_ptr指针被释放时,之前所指堆内存的引用计数也不会因此而减 1.也就是说,weak_ptr类型指针并不会影响所指堆内存空间的引用计数

创建语法
1.std::weak_ptr<int> wp1;//空指针
2.std::weak_ptr<int> wp2 (wp1);//根据已有指针创建新指针
//若wp1为空指针,则wp2也为空指针;反之,如果wp1指向某一 shared_ptr指针拥有的堆内存,则wp2也指向该块存储空间(可以访问,但无所有权)

3.std::shared_ptr<int> sp (new int);
4.std::weak_ptr<int> wp3 (sp);
//weak_ptr指针更常用于指向某一shared_ptr指针拥有的堆内存,因为在构建weak_ptr指针对象时,可以利用已有的 shared_ptr指针为其初始化
//weak_ptr类型指针不会导致堆内存空间的引用计数增加或减少
```

![image-20230814145348129](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230814145348129.png)

### 封装

#### 类成员初始化方式

```
赋值初始化,通过在函数体内进行赋值初始化;列表初始化,在冒号后使用初始化列表进行初始化.

这两种方式的主要区别在于
1.对于在函数体中初始化,是在所有的数据成员被分配内存空间后才进行的
2.列表初始化是给数据成员分配内存空间时就进行初始化,就是说分配一个数据成员只要冒号后有此数据成员的赋值表达式(此表达式必须是括号赋值表达式),那么分配了内存空间后在进入函数体之前给数据成员赋值,就是说初始化这个数据成员此时函数体还未执行

一个派生类构造函数的执行顺序如下：
① 虚拟基类的构造函数（多个虚拟基类则按照继承的顺序执行构造函数）
② 基类的构造函数（多个普通基类也按照继承的顺序执行构造函数）
③ 类类型的成员对象的构造函数（按照成员对象在类中的定义顺序）
④ 派生类自己的构造函数

方法一是在构造函数当中做赋值的操作，而方法二是做纯粹的初始化操作。我们都知道，C++的赋值操作是会产生临时对象的.临时对象的出现会降低程序的效率.
```

#### 必须使用成员列表初始化的情况

```
必须使用成员初始化的四种情况
① 当初始化一个引用成员时
② 当初始化一个常量成员时
③ 当调用一个基类的构造函数，而它拥有一组参数时
④ 当调用一个成员类的构造函数，而它拥有一组参数时

成员初始化列表做了什么
① 编译器会一一操作初始化列表，以适当的顺序在构造函数之内安插初始化操作，并且在任何显示用户代码之前；
② list中的项目顺序是由类中的成员声明顺序决定的，不是由初始化列表的顺序决定的
```

#### 可调用对象

```
满足以下条件之一就可称为可调用对象:
	1.是一个函数指针
	2.是一个具有operator()成员函数的类对象(传说中的仿函数)，lambda表达式
	3.是一个可被转换为函数指针的类对象
	4.是一个类成员(函数)指针
	5.bind表达式或其它函数对象
```

#### 临时对象



### 继承

#### 继承类中兼容性问题

```
类的兼容性指在需要基类对象的任何地方,都可以使用公有派生类的对象替代,通过公有继承,派生类得到基类除了构造和析构之外的所有成员.因此,公有派生类实际上就具有了基类的所有功能,凡是基类可以解决的,派生类都能解决

原则
1.子类对象可以当作父类对象使用,即调用父类成员函数(继承允许情况下)
2.子类对象可以直接赋值给父类对象(默认浅拷贝)
3.子类对象可以直接初始化父类对象
4.父类指针可以指向子类对象(指向范围仍是父类拥有的成员)
5.父类引用可以直接引用子类对象

注:子类继承父类,不但继承了内存空间,还拥有自己的成员函数和数据成员,故而内存上大于父类
```

##### 示例

```C++
# include <iostream>
using namespace std:
class Animal
{
public:
void sleep()
{cout<<"Animal sleep"<<endl;}
};
class Dog:public Animal
{
void bite(){cout<<"Dog bite"<<endl;}
}:
int main(int argc,char**argv)
{
//1 子类对象可以当做父类对象使用
Dog dog;
dog.sleep();//子类对象可以调用父类方法
//2 子类对象可以直接赋值给父类对象
Animal a;
a=dog;
//3子类对象可以直接初始化父类对象
Animal b=dog;
~~Dog dog1=a;~~ //父类对象不可以直接初始化子类对象
//4父类指针可以直接指向子类对象
Animal *c =new Dog;
~~Dog *dog3=new Animal;~~ //子类指针不可以指向父类对象
//5 父类引用可以直接引用子类对象
Animal &d=dog;
return 0;
}

```

### 多态

#### volatile、mutable和explicit

##### volatile

```
概念:volatile关键字是一种类型修饰符,其声明类型变量表示可以被某些编译器未知因素更改.当要求使用volatile声明的变量值时,系统总是重新从其所在内存读取数据,且所读取数据立刻被保存.与const相似,volatile也可以用来修饰指针


注
1.可以把非volatile变量赋给volatile变量,但不能把非volatile对象赋给volatile对象
2.对用户定义类型也可以用volatile
3.C++中有volatile标识符的类只能访问它的接口子集,一个由类的实现者控制的子集.用户只能用const cast来获得对类型接口的完全访问.此外,volatile会从类传递到它的类成员

语法:类型 volatile 名称;
```

##### 多线程下的volatile

```
volatile关键字使用最多的地方是多线程,当多个线程共用一个变量且每个线程对变量的操作都会影响其他变量时,该变量应该用volatile声明
因为volatile作用是防止优化编译器把变量从内存装入CPU,若变量被装入寄存器,那么两个线程可能一个用寄存器中的变量而另一个用内存中的变量,造成程序的错误执行
```

#### mutable

```
概念:C++为了突破const限制而设置的关键字,被修饰变量即使处于const函数中,也永远处于可变状态

语法:mutable 类型 名称;
```

#### explicit

```
概念:C++提供关键字explicit,可以组织不应该允许的经过转换构造函数进行的隐式转换的发生,即声明为explicit的构造函数不能再隐式构造中使用而只能显示调用

注
1.explicit只能用于类内构造函数
2.被修饰的构造函数不能发生相应的隐式类型转换

语法:explicit 返回值类型 名称(){};
```

## 内联函数与宏定义

### 概念

```
什么是内联函数?
内联函数是C++增强的特性之一,用来降低程序的运行时间,当内联函数收到编译器的指示时,即可发生内联:编译器将使用函数的定义体来替代函数调用语句,这种替代行为发生在编译阶段而非程序运行阶段

什么是宏定义?
宏定义是一种预处理器指令,它可以将一些代码段或者常量直接替换为另一些内容,在编译过程中被展开为相应的代码或值

为什么要使用内联函数?
1.宏定义使预处理指令,在预处理时把所有的宏名用宏体来替换;内联函数是函数,在编译阶段把所有调用内联函数的地方把内联函数插入
2.宏没有类型检查,无论对错都是直接替换,而内联函数在编译时进行安全检查
3.宏的编写有很多限制,如只能写一行,不能使用return控制流程等
4.宏代码无法操作类的私有数据成员
5.内联函数类似于宏的替换,但不同在于实在编译阶段将函数调用处调用的函数体替换,并且在每一个调用处均会展开

注意
1.inline关键字只起到提醒作用,编译器不一定会认为是内联函数,由编译器决定是否展开
2.不加inline关键字有可能是隐式内联,C++在类内定义的所有函数都自动称为内联函数
```

### 语法

```
定义函数时,在函数最前用关键字inline即可使函数称为内联声明函数

显式内联和隐式内联
显式:inline 返回值类型 函数名(){};
隐式:类内定义的所有函数都是隐式nei'lian
```

### 一些问题

```
要求编译器展开内联函数
1.编译器开启优化:gcc -O2
2.使用attribute属性:static inline __attribute__((always_inline)) int add
_i(int a,int b);
3.使用auto_inline:#paragram auto_inline(on/off),off时关闭inline处理,否则开启


```

## typedef和define

