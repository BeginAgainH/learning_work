# C++(进阶)

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



## 数据类型

### 共用体和枚举类型

#### union

```C++
概念:联合,又称为共用体,C提供的类似于C++强制类型转换,是一种特殊的类,可有多个数据成员
    
1.任意时刻联合中只能由一个成员可以有值,该成员赋值后,联合中其他成员变为未定义状态,故而定义一个union对象时分配的内存空间大小为其最大成员的大小
2.与类相似,联合可以指定成员访问权限,默认public
3.联合的所有成员共享内存空间,即起始地址相同

union 名称{
	类型 名称;
    类型 名称;
    ...
}

联合可以指定成员长度
联合定义{
    类型 名称:长度;
}
```

#### enum

```
概念:枚举类型是C++中的一种派生数据类型,它是由用户定义的若干枚举常量的集合
目的:枚举类型的主要目的是增加程序的可读性,枚举类型最常见用处就是用来描述状态量

性质
1.枚举变量的值只能取枚举常量表中所列的值,就是整型数的一个子集
2.枚举变量占用内存的大小与整型数相同
3.枚举变量只能参与赋值和关系运算以及输出操作,参与运算时用其本身的整数值

语法:enum<类型>{<枚举常量表>};

应用举例:
enum color_set1 {RED, BLUE, WHITE, BLACK}; // 定义枚举类型color_set1
enum week {Sun, Mon, Tue, Wed, Thu, Fri, Sat}; // 定义枚举类型week

注意
1.枚举常量代表该枚举类型的变量可能取的值,编译系统为每个枚举常量指定一个整数值,默认状态下,这个整数就是所列举元素的序号,序号从0开始.可以在定义枚举类型时为部分或全部枚举常量指定整数值,在指定值之前的枚举常量仍按默认方式取值,而指定值之后的枚举常量按依次加1的原则取值.各枚举常量的值可以重复
enum fruit_set {apple, orange, banana=1, peach, grape}//枚举常量apple=0,orange=1, banana=1,peach=2,grape=3
enum week {Sun=7, Mon=1, Tue, Wed, Thu, Fri, Sat};//枚举常量Sun,Mon,Tue,Wed,Thu,Fri,Sat的值分别为7、1、2、3、4、5、6

2.枚举常量只能以标识符形式表示,而不能是整型、字符型等文字常量.
enum letter_set {'a','d','F','s','T'}; //枚举常量不能是字符常量
enum year_set{2000,2001,2002,2003,2004,2005}; //枚举常量不能是整型常量
修改
enum letter_set {a, d, F, s, T};
enum year_set{y2000, y2001, y2002, y2003, y2004, y2005};

3.枚举变量可以直接输出但不能直接输入
4.不能直接将常量赋值给枚举变量
5.不同类型的枚举变量之间不能相互赋值
6.枚举变量的输入输出一般都采用switch语句将其转换为字符或字符串;枚举类型数据的其他处理也往往应用switch语句,以保证程序的合法性和可读性
```

##### 示例

```C++
enum color_set1 {RED, BLUE, WHITE, BLACK} color1, color2;
enum color_set2 { GREEN, RED, YELLOW, WHITE} color3, color4;

color3=RED;           //将枚举常量值赋给枚举变量
color4=color3;        //相同类型的枚举变量赋值，color4的值为RED
int  i=color3;        //将枚举变量赋给整型变量，i的值为1
int  j=GREEN;         //将枚举常量赋给整型变量，j的值为0

//比较同类型枚举变量color3，color4是否相等
if (color3==color4) cout<<"相等"；
//输出的是变量color3与WHITE的比较结果，结果为1
cout<< color3<WHITE;

cout<< color3;         //输出的是color3的整数值，即RED的整数值1
```



### static的用法和作用

```
1.隐藏:当同时编译多个文件时,所有未加static前缀的全局变量和函数都具有全局可见性
2.保持变量内容持久,存储在静态数据区的变量会在程序刚开始运行时就完成初始化,也是唯一一次初始化.共有两种变量存储在静态数据区:全局变量和static变量,不过static可以控制变量可见范围(只在static作用域内可见)
3.static变量默认初始化为0,在静态数据区中所有字节默认值都为0x00

4.类中static成员
	1)函数体内static变量作用范围为该函数体,不同于auto变量,该变量内存只分配一次,故而其值在下次调用时仍维持上次的值
	2)在模块内的static全局变量可以被模块内所有函数访问,但不能被模块外函数访问
	3)模块内的static函数之刻碑该模块内的其它函数调用,这个函数的使用范围被限制在声明它的模块内
	4)在类中的static成员变量属于整个类所拥有,对类的所有对象只有一份拷贝
	5)在类中的static函数属于整个类所有,这个函数不接收this指针,只能访问类的static成员变量
	6)staitc类对象必须在类外进行初始化,static修饰的变量先于类对象存在,所以static修饰的变量要在类外初始化
	7)由于static修饰的类成员属于类而不是对象,故而static类成员函数没有this指针,this是指向对象本体的指针,static没有,故而static类成员函数只能访问static类成员变量
	8)static成员函数不能被virtual修饰,static成员不属于任何对象,而virtual没有任何实际意义,静态成员函数没有指针,虚函数的实现是为每一个对象分配一个vptr指针,vptr指针由this指针调用;
	虚函数调用关系
	this->vptr->ctable->virtual function
```

#### static初始化的时机

```
初始化只有一次,但是可以多次赋值,在主程序之前,编译器已经为其分配好了内存

静态局部变量和全局变量一样,数据都存放在全局区域，所以在主程序之前,编译器已经为其分配好了内存,但在C和C++中静态局部变量的初始化节点又有点不太一样.在C中,初始化发生在代码执行之前,编译阶段分配好内存之后,就会进行初始化,所以我们看到在C语言中无法使用变量对静态局部变量进行初始化,在程序运行结束,变量所处的全局内存会被全部回收。

而在C++中,初始化时在执行相关代码时才会进行初始化,主要是由于C++引入对象后,要进行初始化必须执行相应构造函数和析构函数,在构造函数或析构函数中经常会需要进行某些程序中需要进行的特定操作,并非简单地分配内存.所以C++标准定为全局或静态对象是有首次用到时才会进行构造,并由atexit()来管理.在程序结束,按照构造顺序反方向进行逐个析构.所以在C++中是可以使用变量对静态局部变量进行初始化的
```

### const关键字的作用

```
1.阻止一个变量被改变,可以使用const关键字.在定义该const变量时,通常需要对它进行初始化,因为以后就没有机会再去改变它了
2.对指针来说,可以指定指针本身为const,也可以指定指针所指的数据为const,或二者同时指定为const
3.在一个函数声明中,const可以修饰形参,表明它是一个输入参数,在函数内部不能改变其值
4.对于类的成员函数,若指定其为const类型,则表明其是一个常函数,不能修改类的成员变量,类的常对象只能访问类的常成员函数
5.对于类的成员函数,有时候必须指定其返回值为const类型,以使得其返回值不为“左值”
6.const成员函数可以访问非const对象的非const数据成员、const数据成员,也可以访问const对象内的所有数据成员
7.非const成员函数可以访问非const对象的非const数据成员、const数据成员,但不可以访问const对象的任意数据成员
8.一个没有明确声明为const的成员函数被看作是将要修改对象中数据成员的函数,而且编译器不允许它为一个const对象所调用.因此const对象只能调用const成员函数
9.const类型变量可以通过类型转换符const_cast将const类型转换为非const类型
10.const类型变量必须定义的时候进行初始化,因此也导致如果类的成员变量有const类型的变量,那么该变量必须在类的初始化列表中进行初始化;
11.对于函数值传递的情况，因为参数传递是通过复制实参创建一个临时变量传递进函数的，函数内只能改变临时变量，但无法改变实参。则这个时候无论加不加const对实参不会产生任何影响。但是在引用或指针传递函数调用中，因为传进去的是一个引用或指针，这样函数内部可以改变引用或指针所指向的变量，这时const 才是实实在在地保护了实参所指向的变量。因为在编译阶段编译器对调用函数的选择是根据实参进行的，所以，只有引用传递和指针传递可以用是否加const来重载。一个拥有顶层const的形参无法和另一个没有顶层const的形参区分开来。
```

### C++四种强制类型转换

##### const_cast

```
1.const_cast只针对指针、引用
2.cosnt_cast的大部分使用主要是将常量指针转换为长指针,常指针指向的空间内容不允许被修改,但是使用const_cast进行强制转换就可以修改
3.const_cast只能调节类型限定符,不能改变基本类型
```

###### 示例

```C++
#普通指针
	const int* p = new int(1);
	//int* d = p;//错误原因：const int*类型不能赋值或者初始化int*类型的实体
	*const_cast<int*>(p) = 50;
	cout << *p << endl;//50

	int* d = const_cast<int*>(p);
	*d = 100;
	cout << *p << endl;//100

	//char* dd = const_cast<char*>(p)//错误原因：const_cast只能调节类型限定符，不能更改基础类型


#引用
    int a = 10;
	const int& b = a;
	//b = 20;//错误原因：常量引用，不允许修改值
	//int& c = b;//错误，和常量指针不允许给普通指针赋值或者初始化一样

	int& c = const_cast<int&>(b);
	c = 20;
	cout << a << endl;//20

	const_cast<int&>(b) = 30;
	cout << a << endl;//30

#this指针
class Test 
{
public:
	Test() {}
	void fun()const//此时this指针相当于const Test* const this
	{
		//this->val1 = 10;//错误
		const_cast<Test*>(this)->val1 = 10;//OK
	}
private:
	int val1;
	int val2;
};

```

##### static_cast

```
1.static_cast的使用基本等价于隐式转换的一种类型转化运算符,可使用于需要明确隐式转换的地方.就相当于把隐式转换给明确写了出来而已.
2.可以用于低风险的转换:一般只要编译器能自己进行隐式转换的都是低风险转换,一般平等转换和提升转换都是低风险的转换,如:
	①整形和浮点型
	②字符与整形
	③转换运算符
	④空指针转换为任何目标类型的指针
3.不可以用于风险较高的转换,如
	①不同类型的指针之间互相转换
	②非指针类型和指针类型之间的相互转换
	③不同类型的引用之间的转换
```

###### 示例

```C++
class Base 
{
public:
	Base() {}
	~Base() {}
};
class Son:public Base
{
public:
	Son() {}
	~Son() {}
};

int main()
{
	char c_a = 0;
	int i_a = 0;
	float f_a = 0;
	double d_a = 1.111111;
	void* v_ptr = NULL;
	int* i_ptr = new int(1);
	char* c_ptr = new char(1);

	//下面部分没有报错，可以运行，但是平时不允许这样写，除非自己很明确自己在干什么
	//从高字节数到低字节数的转换平常肯定是不允许这样用的，因为将一个多字节的内容转换到少字节，非常容易丢失数据
	char c_sc = static_cast<char>(i_a);
	c_sc = static_cast<char>(f_a);
	c_sc = static_cast<char>(d_a);

	//类似于下面的转换不允许，因为两个不同的指针类型之间不允许相互转换
	//int* i_scptr = static_cast<int*>(c_ptr);//报错

	//下面的指针类型转换允许
	int* i_scptr = static_cast<int*>(v_ptr);
	void* v_scptr = static_cast<void*>(i_ptr);


	//下面的可取，只不过有时候精度可能会降低而已，比如float转换为int，被视为低风险
	float f_sc = static_cast<float>(i_a);
	int i_sc = static_cast<int>(c_a);
	cout << i_sc << endl;


	//父类指针和派生类指针的指向问题
	Base* bptr1 = new Base();
	Son* sptr1 = new Son();
	Base* bptr;
	Son* sptr;
	bptr = new Son();    //语句1   正确，基类指针指向派生类实体
	//sptr = new Base();//语句2   错误，派生类指针指向父类
	bptr = static_cast<Base*>(sptr1);//等同于语句1，正确
	sptr = static_cast<Son*>(bptr1); //等同于语句2，但是不安全，平时使用也不会使派生类指针指向基类,会出现访问越界，有时候会崩溃，有时候我们却没办法发现
	//对于派生类指针指向基类，会用另一个强制转换dynamic_cast
	
	return 0;
}

```



##### dynamic_cast

```
1.用于具有虚函数的基类与派生类之间的指针或引用的转换
2.基类必须具有虚函数.dynamic_cast是运行时类型信息（RTTI）,而这个信息是存储与类的虚函数表关系紧密的信息,只有一个类定义了虚函数,才会有虚函数表.运行时检查,转型不成功则返回一个空指针,非必要不使用dynamic_cast,因为有额外的开销.

常用的转换方式
基类指针或引用转派生类指针（必须使用dynamic_cast）
派生类指针或引用转基类指针（可以使用dynamic_cast,但是更推荐用static_cast）
```

###### 示例

```C++
class Base 
{
public:
	Base() { b_val = 1; }
	~Base() {}
	virtual void fun() {}
	int b_val;
};

class Son :public Base
{
public:
	Son() { s_val = 2; }
	~Son() {}
	int s_val;
};

int main()
{
	Base* b_ptr = new Base();
	Son* s_ptr = dynamic_cast<Son*>(b_ptr);

	return 0;
}

```



##### reinterpret_cast

```

```

### String和char*

```
string继承自basic_string,其实是对char*进行了封装,封装的string包含了char*数组,容量,长度等等属性.

string可以进行动态扩展,在每次扩展的时候另外申请一块原空间大小两倍的空间（2*n）,然后将原字符串拷贝过去,并加上新增的内容.
```

### 模板

```
模板的定义并不是真正定义了一个函数或者类，而是编译器根据程序员缩写的模板和形参来自己写出一个对应的版本，这个过程叫做模板实例化。编译器形成的版本通常称为模板的实例。
编译器为程序员生成对应版本的具体过程类似宏替换

由于编译器并不会直接编译模板本身，所以模板的定义通常放在头文件
```

#### 非类型模板参数

```
顾名思义，模板参数不是一个类型而是一个具体的值，这个值是一个常量表达式
当一个模板被实例化时，非类型参数被用户提供的或者编译器推断出的值所替代。正因为模板在编译阶段编译器为我们生成一个对应的版本，所以其值应该能够编译时确定，那么他应该是一个常量或者常量表达式。

template <size_t N, size_t M>
int str_compare(const char (&str1)[N], const char (&str2)[M])
{
    return strcmp(str1,str2);
}

str_compare("hello","nihao")

没有用<>来传递模板参数。这是因为编译器在编译阶段已经帮助我们计算好了应该开辟多大空间的数组。我们也可以指定长度。N，M只是隐式的传入进去。

编译器也可以自动帮助我们推断参数时什么类型，从而不用显示的调用模板函数，对于上面的compare函数，我们可以这样调用，前提时保证参数类型相同。

compare(10,20);

```



#### 别名模板

```
别名模板是 C++11 中的新特性。别名模板提供了一种方法，可以给一个类型家族起一个方便的名字。下面的代码片段给出了类模板 Matrix 的定义。

template <typename T, int Line, int Col>
class Matrix { ... };
Martix 需要三个模板形参，类型参数 T，非类型参数 Line 和 Col

为了代码的可读性，我想给出两种特殊的矩阵：Square 和 Vector，分别表示行数和列数相等的矩阵，和行数为 1 的矩阵。类型别名可以帮助实现这样的想法：

template <typename T, int Line>
using Square = Matrix<T, Line, Line>; // (1)

template <typename T, int Line>
using Vector = Matrix<T, Line, 1>;    // (2)

关键字 using（(1) 和 (2)）声明了类型别名。虽然模板 Matrix 可以在三个维度 T、Line 和 Col 中进行参数化，但类型别名 Square 和 Vector 将参数化减少到两个维度 T 和 Line。从这个角度来看，别名模板能够为部分绑定的模板创建直观的名称。

使用 Square 和 Vector 简单直观：
Matrix<int, 5, 3> ma;
Square<double, 4> sq;
Vector<char, 5> vec;
```

#### 模板形参

```
概念:模板形参可以是类型,非类型,模板

类型:
	std::vector<int> myVec;
	std::map<std::string, int> myMap;
	std::lock_guard<std::mutex> myLockGuard;
	
非类型:左值引用,nullptr,指针值,枚举类型的值,整型值,浮点型值（C++20）
	整型值是最常用的非类型形参。典型的例子 是std::array，因为在编译时必须指定 std::array 的大小。
	std::array<int, 3> myArray{1, 2, 3};
	
模板:
	template <typename T, template <typename, typename> class Cont >      // (1)
	class Matrix
	{
	public:
    	explicit Matrix(std::initializer_list<T> inList) : data(inList)   // (2)
    	{
    	    for (auto d : data) std::cout << d << " ";
    	}
    	int getSize() const
   	 	{
  	      return data.size();
		}
	private:
    	Cont<T, std::allocator<T>> data;                                  // (3)                               
	};
	Matrix 是一个简单的类模板，可以通过 std::initializer_list（(2)）进行初始化。Matrix 可以与 std::vector（(4) 和 (5)）或 std::list（(6)）一起使用，以保存其值。到目前为止，没有什么特别之处。
	(1) 声明了一个类模板，它有两个模板形参，第一个是元素的类型，第二个代表容器。我们仔细看看第二个形参：template <typename, typename> class Cont>。这意味着第二个模板形参应该是一具有两个模板形参的模板。第一个模板形参是容器存储的元素的类型，第二个模板形参是标准模板库的容器所默认的分配器。甚至分配器也有一个默认值，比如在 std::vector 的情况下。分配器取决于元素的类型。
	(3) 展示了分配器在这个内部使用的容器中的用法。Martix 可以使用所有的容器，这些容器的类型是：container<type of the elements, allocator of the elements>。std::vector、std::deque、std::list等序列容器是如此。std::array 和 std::forward_list 会失败，因为 std::array 需要一个额外的非类型来在编译时指定其大小，而 std::forward_list 不支持 size 函数。
```



#### 变参数模板

```
template<typename... _Args>
void emplace_front(_Args&&... __args);
可以看到里面模板参数是template<typename... _Args>，其实这个就是变参数模板，然后它的参数也是比较特别的_Args&&... __args，去除右值引用的话，它就是一个可变参数

c++11中新增加了一项内容，叫做变参数模板，所谓变参数模板，顾名思义就是参数个数和类型都可能发生变化的模板，要实现这一点，那就必须要使用模板形参包。
模板形参包是可以接受0个或者n个模板实参的模板形参，至少有一个模板形参包的模板就可以称作变参数模板，所以说白了，搞懂了模板形参包就明白变参数模板了，因为变参数模板就是基于模板形参包来实现的
```

##### 模板形参包

```
性质:变参数模板的基础
概念:模板形参包主要出现在函数模板和类模板中，目前来讲，模板形参包主要有三种，即:非类型模板形参包、类型模板形参包、模板模板形参包
```

###### 非类型模板形参包

```
基本语法:template<类型 ... args>
这里的非类型是针对typename和class关键字来的，都知道模板使用typename或者class关键字表示它们后面跟着的名称是类型名称，而这里的形参包里面类型其实表示一个固定的类型，所以这里其实不如叫做固定类型模板形参包

对于上述非类型模板形参包而言，类型选择一个固定的类型，args其实是一个可修改的参数名，如
template<int ... data> xxxxxx;
注:这个固定的类型是有限制的，标准c++规定，只能为整型、指针和引用

1.非类型模板形参包类型是固定的，但参数名跟普通函数参数一样，是可以修改的；
2.传递给非类型模板形参包的实参不是类型，而是实际的值。

用法:
	template<class type, int age0, int ... age>
	void printAmt(int &iSumAge){
    	iSumAge += age0;
    	//这里sizeof ... (age)是计算形参包里的形参个数，返回类型是std::size_t，后续同理
    	if ( (sizeof ... (age)) > 0 )
    	{
        //这里的age...其实就是语法中的一种包展开，这个后续会具体说明
        printAmt<type, age...>(iSumAge);
    	}
	}
	int main()
	{
    	int sumAge = 0;
    	printAmt<int,1,2,3,4,5,7,6,8>(sumAge);
    	cout << "the sum of age is " << sumAge << endl;
    	return 0;
	}
```

###### 类型模板型参包

```
基本语法:typename|class ... Args
typename关键字和class关键字都可以用于在模板中声明一个未知类型,只是在以前template<typename type>的基础上加了一个省略号,改成了可变形参包而已,该可变形参包可以接受无限个不同的实参类型

作用:提供通用型接口,但是具体输出并不事先直到

void xprintf()
{
    cout << endl;
}

template<typename T, typename... Targs>
void xprintf(T value, Targs... Fargs)
{
    cout << value << ' ';
    if ( (sizeof ...(Fargs)) > 0 )
    {
        //这里调用的时候没有显式指定模板，是因为函数模板可以根据函数参数自动推导
        xprintf(Fargs...);
    }
    else
    {
        xprintf();
    }
}

int main()
{
    xprintf("小明个人信息:", "小明", "男", 35, "程序员", 169.5);
    return 0;
}
输出:小明个人信息: 小明 男 35 程序员 169.5
```

###### 模板模板形参包

```
基本语法:template<形参列表>class ... Args(可选)
形参包本身它也是一个模板
```

#### 递归

**模板特化对于模板递归的作用**

​	由于模板内部有一个无限的递归，即便知道在运行是不会调用其他代码块，在编译时，编译器也需要知道其他块中有哪些代码会无休止被调用

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

