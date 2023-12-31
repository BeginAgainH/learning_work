# C++(新)

## 基本概念

### 特性

```
封装,继承,多态(三大特性)
```

#### 封装

```
1.将属性和行为作为一个整体,表现生活中的事物
2.将属性和行为加以权限控制
```



### 程序流程结构

#### 基本结构(C/C++)

```
顺序结构:按顺序执行,不跳转	
选择结构:依据条件是否满足,选择性执行相应功能	(IF/SWITCH/三目运算符)
三目:1?2:3//若1真则返回2否则返回3

循环结构:若条件满足则按顺序循环执行
```

#### 选择结构

```
switch只能判断整形或者字符型,不可以是一个区间,但是switch结构清晰,效率高

switch中,若无break,则顺序执行
```

#### 循环结构

```
continue:跳过剩下未执行语句,继续下一次循环,相当于跳到本次循环尾
```

#### 跳转

```
goto:跳转到存在标记位置顺序执行之后代码(标记一般大写)
//一般不使用,避免程序流程混乱
```

### 定义与声明

```
声明:声明即指定实体的唯一名称,C++程序由各种实体组成,其声明位置即为编辑器可见位置,故只能在使用之前声明,而不能先使用再声明
定义:即为已经声明的实体进行内存分配操作

故而,声明可多次声明,而定义只能定义一次,声明是告诉编译器变量或函数的类型和名称等，定义是告诉编译器变量的值，函数具体干什么。//多次声明以最后一次声明为准
```



### 变量和常量

```
作用:给一段指定的内存空间起名,方便操作和管理

变量与常量的区别:一个可改一个不可更改

常量:#define和const
```

### 形参和实参

```
1.形参变量只有在调用时才分配内存空间,调用结束立马收回释放,故而形参只在函数内部有效
2.实参可以是常量\变量\表达式\函数等,无论实参为什么类型,调用时都需要由一个确定的值以便传递给形参,故而应先赋值\输入,使实参获得确定值,并产生一个临时变量
3.实参和形参在数量,类型,顺序上严格一致
4.函数调用发生的数据传送是单向的,即只能把实参的值传递给形参,而不能把形参的值反向传递给实参,故而函数调用中,形参的值会变而实参的值不变
5.形参和实参不是指针类型时,若函数运行,实参和形参是不同的变量,它们在内存中的不同位置,形参将实参的内容复制一份,在该函数运行结束的时候形参被释放,而实参内容不会改变

故而:函数声明和定义处的参数是形参,函数调用处的参数是实参
```



### 标识符

#### 标识符命名规则

```
1.标识符不能是关键字
2.只能由字母、数字、下划线组成
3.第一个字符必须是字母或者是下划线
4.标识符中字母区分大小写
```

### 数据类型和占用空间

```
意义:给变量分配空间时能够分配合理大小的存储空间
```

#### 整形和浮点型

```
整数类型与小数类型

浮点数:单精度(float,7位)和双精度(double,15~16位)
//编辑器默认显示6位有效数字

科学计数法:3e2 // 3 * 10^2(e后为正数,若为负数,则为3*0.1^2)
```

#### 字符和字符串类型

```
字符:char //1B		字符串:string/char */char[]

字符用单引号,字符串用双引号
```

#### 转义字符

```
水平制表:\t  占8个位置空间(输出黑窗口时) 有控制对齐的作用
```

#### 布尔类型

```
bool只有两个值:真(1)和假(0),占1B//只要非零都代表真
```



|    INT    |               4B                |
| :-------: | :-----------------------------: |
|   SHORT   |               2B                |
|   LONG    | 4B(WIN)/8B(64LINUX)/4B(32LINUX) |
| LONG LONG |               8B                |
|   FLOAT   |               4B                |
|  DOUBLE   |               8B                |

### 运算符

```
除法:取模和取整(取模也可以理解为取余)
//小数无法取模
```

#### 前置和后置

```
前置:先让变量自增或自减,再进行表达式运算
后置:先进行表达式运算,再让变量自增或自减
```

### 数组

```
定义方式
数组名 [数组长度];
数组名 [数组长度] = {值...};//若初始化数据时未全写完,编辑器会用0补齐
数组名 [] = {值...};

特点
1.放在一块连续内存空间
2.每个元素的数据类型都相同

一维数组数组名用途
1.获取数组长度//sizeof(数组名)
2.获取数组在内存中首地址
3.获取数组元素个数//size(s)
```

### 函数

#### 显示调用与隐示调用

```
显示调用:指在程序中能找到相应的调用代码,或者说手动调用的
隐式调用:指程序中找不到相应的调用代码,或者说是编译器自动调用的

类的构造函数与析构函数一般是隐式调用,但是析构与构造函数不同,构造函数只能隐式调用,而析构函数可以显示调用

注:若程序使用exit或者abort非正常退出,则不会隐式调用析构函数,这就造成对象申请的资源无法回收,从而导致操作系统的资源紧张使得程序无法运行
```



#### 定义过程

```
1.返回值类型
2.函数名
3.参数列表
4.函数体语句
5.return表达式
```

#### 默认参数

```
作用:在C++中,函数参数可以有默认值,即若不给参数传值则用默认值,若传值则用所传值
语法:返回值类型 函数名(参数 默认值,...){};

注:
1.若某个位置已经有默认值,则这个位置往后所有参数都必须有默认值
2.若函数声明有默认参数,则函数实现则不能有默认参数,否则会有二义性
```

#### 占位参数

```
作用:C++中函数的参数列表可以有占位参数,用来做占位,调用函数时必须填补该位置
语法:返回值类型 函数名(数据类型){}
```

#### 函数重载

```
作用:函数名称可以重复,提高复用性

满足条件
1.同一作用域下(作用域是程序的一个区域,分全局/局部/块/类)
2.函数名称相同
3.函数参数的类型/个数/顺序不同(满足其一)
注:函数的返回值不同不能作为重载条件
```

##### 引用作为重载条件

```
Elemtype &a和const Elemtype &a
前者和后者的区别就是对值的引用和对变量的引用的区别
引用不能直接int &a = 10,但可以const int &a = 10
因为后者执行时会转化为int ref = 10;const int *a = &ref
故而若前者作为函数参数,要调用该函数就需传入一个变量
若要调用后者,则需要传入一个值
```

##### 重载中的默认参数

```
函数重载时若参数列表有默认参数,有可能会产生二义性,故而应该避免这种含默认参数的重载方式
```



## 关键字

### SIZEOF和SIZE

```
sizeof:求出数据类型占用内存空间大小
```

## 指针

### 用途

```
通过指针间接访问内存
```

### 指针大小

```
32位为4B,64位为8B
指针存放的是单个对象的地址，所以其占用字节大小跟语言无关，而是跟寻址能力有关
```

### 空指针与野指针

```
空指针:指向内存中编号为0的空间,用于初始化指针变量,其指向内存不可访问//即int * = NULL/nullptr;
原因:0~255内存编号由系统占用,故而不可访问

野指针:指向非法内存空间的指针

注:空指针与野指针都时不能随意访问
```

### 常量指针与指针常量

```
const int *	常量指针，指向可改变，但指向的值不能变
int * const	指针常量，指向不可以改变，但指向的值可以变
```

### 值传递与地址传递

```
值传递:形参是实参的拷贝,而值传递是单向的,故而参数的值只能传入不能传出//即值传递传的是一个临时的值的副本

地址传递:,形参为指向实参的地址的指针,当对形参的指向操作时,就相当于对实参本身进行的操作,函数传递的时候只传入一个指针占用四个字节的空间.但是在函数中数据外部数据也会发生改变.
```

#### 引用传递和指针传递

```
指针传递:有一个形参向函数所属的栈拷贝数据的过程,但拷贝的数据固定4B的地址(传递地址的值,即指针大小,由系统位数决定)

引用传递:与指针传递有同样的数据拷贝过程,但是针对地址的传递,相当于为该数据所在地址起了一个别名
```



## 结构体

### 基本概念与定义语法

```
结构体是用户自定义的数据类型,允许用户存储不同类型的数据

语法
struct 结构体名{结构体成员列表};
定义方法
1.struct 结构体名 变量名;
2.struct 结构体名 变量名 = {成员1,...};
3.定义结构体时顺便创建变量
```

### 结构体数组

```
将自定义结构体放到数组中从而方便维护
```

### 结构体指针

```
利用操作符->可以通过结构体指针访问结构体属性

注:结构体指针数据类型与指向结构体一致
```

### 结构体嵌套结构体

```
所嵌套结构体可以不相同,但结构体必须完整,即有完整定义
```

## 内存管理

### 内存分区

```
C++程序执行时,内存大致分为4个区域
1.代码区(又称代码段):存放函数的二进制代码,由操作系统进行管理
2.全局区(又称数据段):存放全局变量和静态变量以及常量
3.栈区:由编辑器自动分配释放,存放函数的参数值和局部变量等
4.堆区:由程序员分配和释放,若程序员不释放,则程序结束时由操作系统回收

5.BSS段: 存储未初始化的全局变量或者静态（全局）变量。编译器给处理成0

为什么分四个区域?
不同区域赋予不同的声明周期,使编程具有更大的灵活性
```

### 程序运行

#### 程序运行前

```
程序编译,生成exe可执行文件,运行改文件前
```

##### 代码区

```
1.存放CPU执行的机器指令
2.代码区是共享的,共享的目的是对于频繁被执行的程序,只需要在内存中有一份代码
3.代码区是只读的,使其只读的原因是防止程序意外修改它的指令
```

##### 全局区

```
1.存放全局变量和静态变量
2.包含常量区,字符常量和其他常量也存放在此
3.该区域的数据在程序结束后由操作系统释放
```

#### 程序运行后

##### 栈区

```
1.栈区数据由编辑器管理
2.不要返回局部变量地址(因为局部变量生命周期与函数生命周期有关)
3.存放局部变量,形参
4.栈区数据在函数执行完后自动释放
```

##### 堆区

```
1.由程序员管理开辟和释放,若不主动释放,在程序结束时由系统回收释放
2.C++中主要利用new在堆区开辟内存
```

### 内存对齐

#### 原因

```
平台原因
不是所有的硬件平台都能访问任意地址上的任意数据的;某些硬件平台只能在某些地址处取某些特定类型的数据,否则抛出硬件异常.

性能原因
数据结构(尤其是栈)应该尽可能地在自然边界上对齐.原因在于,为了访问未对齐的内存,处理器需要作两次内存访问;而对齐的内存访问仅需要一次访问
```

#### 对齐规则

```
基本类型的对齐值就是其sizeof值

偏移需是规则整数倍,且整体大小也需为规定整数倍,不足则填充
```

##### 数据成员对齐规则

```
结构(struct或class)的数据成员,第一个数据放在偏移为0的地方,之后每个数据成员的对齐按照#program pack指定的数值和这个数据成员自身长度中较小的那个进行
```

##### 结构的整体对齐规则

```
在数据成员各自对齐之后,结构本身也要进行对齐,对齐按照#program pack指定的数值和结构中最大的成员长度中较小的那个进行
```

#### 更改编辑器缺省对齐方式

```
#program pack(n)	//编辑器将按照n个字节对齐
#program pack()		//取消自定义字节对齐方式

__attribute((aligned (n)))
让所作用的结构成员对齐在n字节自然边界上。如果结构中有成员的长度大于n，则按照最大成员的长度来对齐。
attribute((packed))
取消结构在编译过程中的优化对齐，按照实际占用字节数进行对齐。
```



## 引用

### 本质与注意事项

```
本质:引用本质是一个指针常量
用法:数据类型 &别名 = 原名(别名数据类型与原名一致)

即int &a  = b编辑器会自动转换为int* const a = &b;

注:
1.引用必须初始化
2.初始化后不可再更改
```

### 函数参数与返回值

```
引用做函数参数:函数传参时可以通过引用简化指针让形参修饰实参,从而实现修改实参的目的

引用做函数返回值:若果函数的返回值是引用,则这个函数调用可以作为左值,即返回的是函数的本体,即一个变量
注:引用做函数返回值同样遵循函数不能返回局部变量的引用这个原则
```

### 常量引用

```
作用:常量引用主要用来修饰形参,防止误操作
用法:在函数形参列表中,加const修饰形参

在使用常量引用时,编译器创建了一个临时常量来让别名能够绑定
const int &n = 常量;
相当于:const int temp = 常量;	const int &n = temp;

当n不是“常量引用”时，如果执行了类似于上面的初始化操作会带来什么样的后果？
如果n不是常量，就允许对n赋值，这样就会改变n所引用的对象的值.注意,此时绑定的对象是一个临时量而非常量,程序员既然想让n引用常量,就肯定想通过n改变常量的值，否则干什么要给 n赋值呢?如此看来,既然大家基本上不会想着把引用绑定到临时量上,C++ 语言也就把这种行为归为非法。
也就是说,不允许一个普通引用与字面值或者某个表达式的计算结果,类型不匹配的对象绑定在一起,其实就是不允许一个普通引用指向一个临时变量,只允许将“常量引用”指向临时对象.

注:
1.引用需要引用一个合法的内存空间,不能直接引用一个值,但加入const之后,就会转换为引用一个临时变量,且变量值不可修改
2.常量引用”仅对引用可参与的操作做出了限定，对于引用的对象本身是不是一个常量未作限定。因为对象也可能是个非常量，所以允许通过其他途径改变它的值

```

### 左值引用与右值引用

```
左值引用:type a = &b;
右值引用:type && a = b;

左值引用
概念:左值引用在汇编层面和普通指针相同,定义的引用必须初始化,因为引用相当于起别名,必须告诉编译器是谁的引用
故:左值引用要求右边的值必须能够获取地址

右值引用
概念:C++11新增特性,用来绑定值到右值,绑定到右值后,本来会被销毁的右值的生存期会延长至与绑定到它的右值引用的生存期
注:在汇编层面右值引用做的事情和常引用是相同的,即产生临时量来存储常量.但是,唯一一点的区别是,右值引用可以进行读写操作,而常引用只能进行读操作.
右值引用的存在并不是为了取代左值引用,而是充分利用右值(特别是临时对象)的构造来减少对象构造和析构操作以达到提高效率的目的.

总结:
1.右值引用可以理解为属性的传递,即将原有对象传递给新对象,而传递之后就对象就失去了这些属性
2.使用右值引用可以节省临时空间开辟和释放的步骤,提高运行效率,但要考虑原有对象是否需要保留所传递属性
```



## 类和对象

### 语法

```
class 类名{访问权限: 属性/行为};

C++中class默认public权限
```

### 访问权限

```
public		公共	成员类内可以访问	类外可以访问
private		私有	成员类内可以访问	子类可以访问
protected	保护	成员类内可以方位	子类不可以访问

成员属性设置为私有
1.可以自己控制读写权限
2.对于写可以检测数据的有效性
```

### struct和class的区别

```
C++中二者唯一区别是默认访问权限的区别
struct	默认公有
class	默认私有
```

### 构造函数与析构函数

#### 构造函数

```
作用:创建对象时为对象的成员属性赋值,构造函数由编辑器自动调用

语法:
1.没有返回值,不用写void
2.函数名与类名相同
3.构造函数可以有参数,能发生重载
4.创建对象时构造函数自动调用,且只会调用一次
```

##### 默认构造函数

```
又叫无参构造函数
语法:类名(){};
```

##### 有参构造函数

```
语法:类名(参数){};
```

##### 拷贝构造函数

```
语法:类名(const 类名& 对象名){};

注:若无自定义拷贝构造函数,则编辑器会提供一个克隆的拷贝构造函数,即复制构造与传入对象值一样的一个对象
```

###### 调用时机

```
1.使用一个已创建对象来初始化新的对象
2.值传递的方式给参数传参
3.以值方式返回局部对象
```

###### 深拷贝与浅拷贝

```
浅拷贝:简单的指针复制操作,两个指针指向同一个地址,没有重新开辟一个空间
问题:可能会使堆区空间重复释放,利用深拷贝解决

深拷贝:在堆区重新申请一块内存空间,进行拷贝操作
```

##### 调用方法

```
括号法
默认	类名 对象名;
有参	类名 对象名(参数);
拷贝	类名 对象名(拷贝对象名);

显示法
默认	类名 对象名;
有参	类名 对象名 = 类名(参数);
拷贝	类名 对象名 = 类名(拷贝对象名);

隐式转换法
有参	类名 对象名 = 参数;//相当于类名 对象名 = 类名(参数);
拷贝	类名 对象名 = 拷贝对象名;//相当于类名 对象名 = 类名(拷贝对象名);
```

 

#### 析构函数

```
作用:在对象销毁前系统自动调用,执行一些清理工作

语法:
1.没有返回值,不用写void,但在函数名前需加~
2.函数名与类名相同
3.析构函数不能有参数,不能发生重载
4.销毁对象时构造函数自动调用,且只会调用一次

匿名对象
类名(参数值);//当前执行结束后系统会立即回收匿名对象
```

#### 调用顺序

```
构造:先对象成员,再本类
析构:先本类,再对象成员
```

#### 初始化列表

##### 语法与作用

```
语法:构造函数():属性1(值),...{}

作用:用来初始化属性
```



### 匿名对象

#### 概念与产生场景

```
概念:匿名对象又称为临时对象

产生情况
	1.以值的方式给函数传参
		类名();//形成一个匿名对象,执行完类名()代码后,此匿名对象消失,这就是匿名对象的生命周期,用在需要传入一个对象但是又不用单独创建一个对象时
		类名 对象名 == 类名();//首先生成一个匿名对象,然后将此对象拷贝给新生成的对象,此时匿名对象的生命周期就为新生成对象的生命周期
	2.类型转换
	3.函数需要返回一个对象时;
		return *this;//此时若返回的对象为引用,则不会产生匿名对象
		return 临时对象;//此时先产生一个匿名对象拷贝临时对象作为返回值,释放临时对象
		
总结:函数返回值为一个对象（非引用）的时候会产生一个匿名对象，匿名对象根据主函数的操作决定生命周期
```

```C++
//匿名对象产生的三种场景
#include<iostream>
using namespace std;

class Point{
public:
    Point(int a,int b){
        cout << "有参构造函数被调用了1" << endl;
        this->x = a;
        this->y = b;
    }
    Point(Point &a1){
        cout << "拷贝构造函数被调用了2" << endl;
        this->x = a1.x;
        this->y = a1.y;
    }
    ~Point(){
        cout << "析构函数被调用了3" << endl;
        cout << "x=" << x << endl;
        cout << "y=" << y << endl;
    }
    Point Protset(int a){
        this->x = a;
        return *this;
        //执行 return *this; 会产生一个匿名对象，作为返回值
        //强调：如果返回值是引用，则不会产生匿名对象
    }

    Point Protset2(int a){
        Point temp(a, a);
        return temp;
        //执行 return temp;会先产生一个匿名对象,执行拷贝构造函数，作为返回值,
        //然后释放临时对象temp
    }

    //总结：函数返回值为一个对象（非引用）的时候会产生一个匿名对象，匿名对象根据主函数的操作决定生命周期

    Point& Protset3(int a){
        Point temp(a, a);
        return temp;
        //执行 return temp;不会产生匿名对象，而是会将temp的地址先赋值到引用中，
        //在释放temp的内存，此时Point&得到是一个脏数据
    }

    void PrintfA()const{
        cout << "x="<<x << endl;
        cout << "y=" << y << endl;
    }

private:
    int x;
    int y;
};


void ProtectA(){
    //生成一个匿名对象，因为用来初始化另一个同类型的对象，这个匿名对象会直接转换成新的对象，
    //减少资源消耗
    Point p1 = Point(1,1);
    /*Point p2(2, 2);
    p2 = p1.Protset(3);
    p2.PrintfA();*/
    //观察发现p2打印出正确数据,因此得出结论p1.Protset(3);返回来一个匿名对象，
    //但是这个匿名对象执行完"="之后，才会被释放
    Point p4(5, 5);
    p4=p1.Protset2(4);
    p4.PrintfA();
}

void main(){
    ProtectA();
    system("pause");
}

```



#### 匿名对象的生命周期

```
若生成的匿名对象在外部有对象等待被其实例化,此匿名对象的生命周期就变成了外部对象的生命周期;若生成的匿名对象在外部没有对象等待被其实例化,此匿名对象在生成之后就会被析构
```



### 静态成员

#### 语法

```
在相关静态成员前加上关键字static
```

#### 分类

##### 静态成员变量

```
特点
1.所有对象共享同一份数据
2.在编译阶段分配内存
3.类内声明,类外初始化
4.静态成员变量也有访问权限

语法
class 类名{public:static 数据类型 变量名};
数据类型 类名::变量名 = 值;

访问方式(无论怎么访问,都得先类外初始化)
1.通过对象
2.通过类名

语法
1.对象.变量名
2.类名::变量名
```

##### 静态成员函数

```
特点
1.所有对象共享一个函数
2.静态成员函数只能访问静态成员变量
原因:因为所有对象共享一个静态成员变量,若通过静态成员函数访问非静态成员变量,则编辑器分不清楚是访问哪一个对象的成员变量

语法
class 类名{public:static 返回值类型 函数名(){}};

访问方式
1.通过对象
2.通过类名

语法
1.对象名.函数名();
2.类名::函数名();

```

#### 对象模型的大小

##### 成员变量和成员函数分开存储

```
只有非静态成员变量属于类对象成员,而非静态成员函数,静态成员函数,静态成员变量都不占用类对象空间

空对象占用内存空间为1B:C++编辑器会给每个空对象分配一个字节的内存空间,是为了区分空对象占内存的位置

自定义一个类,其大小为零,因为类是一个类型定义,而sizeof返回的是一个实体的大小
```

#### this指针

##### 作用与性质

```
作用:this指针指向被调用的成员函数所属对象

性质
1.this指针是隐含每一个非静态成员函数的一种指针
2.this指针不需要定义,直接使用即可
3.this指针不允许修改指针指向,相当于指针常量

用途
1.当形参名和成员变量名同名时,可用this指针区分
2.在类的非静态成员函数中返回对象本身,可用return *this

//在使用返回对象本身时,成员函数注意返回值类型为类的引用,因为这样返回的是对象本身,否则
```

##### 语法

```
this->成员变量名
此时this指向就是被调用成员函数所属对象,
```

##### 空指针访问成员函数

```
注意:C++中空指针也可以访问成员函数,但是需注意是否用到this指针,若用到,需加以判断保证代码的健壮性

语法
if(this == NULL)	return;
```

##### cosnt修饰成员函数

###### 常函数

```
1.成员函数后加const后称该函数为常函数
2.常函数不可以修改成员属性//常函数的const修饰的是this指针
3.成员属性声明时加关键字mutable后,在常函数中依然可以修改
```

###### 常对象

```
1.声明对象前加const称该对象为常对象
2.常对象只能调用常函数
```

### 友元

#### 目的

```
让一个函数或者类访问另一个类中私有成员

关键字:friend
```

#### 实现

##### 方法

```
在类内用friend关键字声明相关友元,这个声明不在任何权限内
```

##### 实现方式

```
1.全局函数做友元
2.类做友元
3.成员函数做友元
```



### 运算符重载

#### 作用

```
对已有运算符进行重新定义,赋予其另一种功能,以适应不同的数据类型

注意
1.内置的数据类型的表达式的运算是不可能改变的
2.不要滥用运算符重载
```

#### 加号

```
成员函数重载+
类名 operator+(类名 &对象名){	};
本质:类名 对象名 = 对象名.operator+(对象名);

全局函数重载+
类名 operator+(类名 &对象1,类名 &对象2){  };
本质:类名 对象名 = operator+(对象1,对象2);
```

#### 左移

```
作用:输出自定义数据类型,即实现对象直接输出

成员函数重载<<
左移重载一般不会用成员函数,因为无法实现cout在左侧

全局函数重载<<
本质:operate<<(cout,对象名),简化cout<<对象名
void operate<<(ostream &cout,类名 &对象名){};//相当于间接利用cout
利用链式编程
ostream operate<<(ostream &cout,类名 &对象名){return cout;};

friend ostream& operator<<(ostream& cout, person p);

ostream &operator<<(ostream& cout, person p) {
	cout << p.num ;
	return cout;
}
```

#### 递增(递减同理)

```
前置递增
类名& operator++(){//返回引用是为了对同一个数据进行递增操作
	成员属性++;
	return *this;}
后置递增
类名 operator++(int){//int为占位符,用于区分前置和后置递增
	类名 对象名 = *this;
	this->成员属性++;
	return 对象名;}//因为返回的是局部对象,局部对象在函数调用完成后就会释放,故而返回的是对象的值,而不是引用
	
类名& operator++() {
		属性++;
		return *this;
	}

类名 operator++(int) {
		类名 对象名 = *this;
		属性++;
		return 对象名;
	}

```

#### 赋值 =

```
C++至少给类添加4个函数
1.默认构造函数
2.默认析构函数
3.默认拷贝构造函数
4.赋值运算符 operator=对值属性进行拷贝


类名& operator==(类名 &对象名){
	1.判断已有堆区是否为空
	
	属性 = new 数据类型(对象名.属性);//2.提供深拷贝
	
	return *this;}
```

#### 关系 ==

```
对比自定义数据类型

bool operator==(类名 &对象名){
	if(this->属性 == 对象名.属性)	return true;
	else return false;}
```

#### 函数调用()

```
相当于类函数

语法
类内{
public:
	operator()(参数){
		...
	}
}

类名();//调用方式

注:当类内有()重载成员时,类对象即可视为一个可调用对象,类似于仿函数
```

### 继承

#### 实现

```
class 派生类:继承方式 父类,....{};//定义类可使用被继承类中公共区域所有属性,可同时继承多个父类

好处:减少重复代码

继承类:称子类或派生类
被继承类:称父类或基类

继承的实质:继承指向对象成员的地址的指针
```

#### 继承方式

```
公共继承	父类中除了私有类其余都被继承至子类且访问权限不变
保护继承	父类中除了私有类全部都被继承至子类且访问权限变为保护
私有继承	父类中除了私有类全部都被继承至子类且访问权限变为私有
故:无论什么继承,父类
```

#### 继承中的对象模型

```
1.父类中所有非静态成员属性都会被子类所继承
2.子类虽然不能直接使用父类的私有属性,但实际上也是继承了,只是被编辑器给隐藏访问不到

//vs开发人员命令提示符
//cl /d1 reportSingleClassLayout类名 "文件名"  #打印类的对象模型

继承中的构造和析构顺序
1.构造父类
2.构造子类
3.析构顺序与构造顺序相反
```

#### 同名非静态/非静态成员访问

```
若通过子类对象访问父类中的同名成员时,需要加作用域
对象名.类名::成员;

原因
1.若子类中有与父类同名成员,则编辑器会隐藏掉父类中所有同名的成员

静态成员访问
1.通过对象名
	访问子类	对象名.成员
	访问父类	对象名.父类::成员
2.通过类名
	通过子类的类名访问	子类::父类::成员//通过子类访问父类再访问成员
	通过父类的类名访问	父类::成员
	
注:若多继承多个父类,且有相同的成员,访问时必须添加作用域以示区别
```

#### 菱形继承

```
概念:两个派生类继承同一个基类,而又有某个类同时继承这两个类,这种继承称为菱形/钻石继承

当菱形继承中两个父类拥有相同的成员时,需要加作用域以示区分,但是两份数据只需一份,故而使用虚继承解决
```

##### 虚继承

```
语法	class 类名 :virtual 继承类型 父类名{};//继承前加关键字virtual,称虚继承,被继承类称虚基类

用虚继承后,直接访问成员不加作用域亦可访问,此时相当于只有一个成员
虚继承实质就是继承了一个虚指针,该指针指向内存中成员存储位置(通过偏移量)

使用virtual,会创建一个虚函数表,里面有所有子类同名函数的地址
```

##### 通过子类访问父类虚函数



##### 通过父类访问子类虚函数



### 多态

#### 基本概念

```
实质:一个接口有多种形态

分类
静态多态:函数重载和运算符重载,复用函数名
动态多态:派生类和函数实现运行时多态

区别
静态多态的函数地址绑定早 - 编译阶段确定函数地址
动态多态的函数地址绑定晚 - 运行阶段确定函数地址

动态多态满足条件
 	1.有继承关系 2.子类要重写父类虚函数
 	//重写函数:返回值与参数列表与被重写函数完全相同
 	//在子类重写父类函数时,virtual关键字可有可无
 	
动态多态使用:父类的指针或引用指向子类对象

优点
1.代码组织结构清晰	2.可读性强	3.利于前期和后期的扩展和维护
```

#### 原理剖析

```
使用virtual,会创建一个虚函数表,里面有所有子类同名函数的地址

子类通过复写父类函数实现父类的指针或引用指向子类对象,而改变的是子类虚函数表中调用的函数的地址,父类的虚函数表则没有发生改变

虚函数表存放函数的入口地址

查看类结构
vs开发者powershell下:
cl /d1 reportSingleClassLayout类名 "文件名.cpp"
```

![image-20230728135851285](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230728135851285.png)

#### 纯虚函数和抽象类

```
纯虚函数语法:virtual 返回值类型 函数名 (参数列表) = 0;
当类中有纯虚函数时,该类也称为抽象类

抽象类特点
1.无法实例化对象	2.子类必须重写抽象类中的纯虚函数,否则也属于抽象类
```

#### 虚析构和纯虚析构

```
原因:使用多态时,若子类有属性开辟到堆区,则父类指针在释放时无法调用到子类的析构函数,导致内存泄漏
解决方式:将父类中的析构函数改为虚析构或者纯虚析构
本质:与子类复写父类函数相似

原理:


虚析构与纯虚析构共性:
1.都可解决父类指针释放子类对象问题	2.都需要有具体的函数实现
区别:若为纯虚析构,该类属于抽象类,无法实例化对象

虚析构语法:virtual ~类名(){};
纯虚析构:virtual ~类名() = 0;//类内声明		类名::~类名(){};//类外实现
```



## 文件操作

### 文本文件与二进制文件

```
C++对文件操作需包含头文件<fstream>

文本文件:以文本的ASCII码形式存储在计算机中
二进制文件:以文本的二进制形式存储在计算机中,一般用户不能直接读懂

操作文件三大类:1.ofstream	写操作 2.ifstream	读操作 3.fstream	读写操作
```

#### 文本文件

##### 写文件与读文件

```
写文件步骤
1.头文件 <fstream>
2.创建流对象 ofstream ofs;
3.打开文件	ofs.open("文件路径",打开方式);
4.写数据	ofs<<"写入的数据";//字符串流
5.关闭文件	ofs.close();
注:文件打开方式可以配合使用,通过|操作符
eg.ios::binary | ios::out


读文件步骤
1.头文件 <fstream>
2.创建流对象 ifstream ifs;
3.打开文件	ifs.open("文件路径",打开方式);
4.读数据	四种方式读取
5.关闭文件	ifs.close();

读方式
一
char buf[1024] = {0};
while(ifs>>buf){};//逐行读取文件直到结束
二
char buf[1024] = {0};
while(ifs.getline(buf,sizeof(buf))){};//逐行读取文件，每行读取sizeof(buf)个
三
string buf
while(getline(ifs,buf)){};//逐行读取文件
四
char c
while((c = ifs.get()) != EOF){};//EOF end of line,逐字读取
```

![image-20230728185130755](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230728185130755.png)

#### 二进制文件

##### 写文件与读文件

```
以二进制方式对文件进行读写操作,打开方式主要为ios::binary

写文件
二进制写文件主要利用流对象调用成员函数write
函数原型:ostream& write(const char* buffer,int len);
//buffer指向内存中一段存储空间,len是读取的字节数

写文件步骤
1.头文件 <fstream>
2.创建流对象 ofstream ofs("文件路径",ios::out | ios::binary);
3.打开文件	ofs.open("文件路径",打开方式);//可在创建流对象时就同时打开文件，第3可省略
4.写文件	ofs.write((cosnt char*)&对象,sizeof(对象));//write第一个参数必为const char*类型,故用强转
5.关闭文件	ofs.close();

读文件步骤
1.头文件 <fstream>
2.创建流对象 ifstream ifs;
3.打开文件,判断是否成功
	ifs.open("文件路径",ios::in | ios::binary);
	if(!ifs.is_open()){return};
4.写文件
	ofs.read((cosnt char*)&对象,sizeof(对象));//read第一个参数必为const char*类型,故用强转
	此时可以直接通过对象名wen'fa
5.关闭文件	ofs.close();
```



## 模板

### 概念

```
目的:建立一个通用的模具,提高复用性
概念:C++另一种编程思想为泛型编程,其主要工具就是模板

特点:	1.不可以直接使用,模板只是一个框架	2.模板的通用不是万能的
```

### 函数模板

```
作用:建立一个通用函数,其函数返回值类型和形参类型可以不具体制定,用一个虚拟的类型来代表

语法
template <typename T>
函数定义或声明
//template --声明创建模板		typename --表示其后面符号是一种数据类型,可用class代替		T --通用的数据类型,名称可以替换,通常为大写字母


使用模板方式
	1.自动数据类型推导
	2.显示指定数据类型
	
eg.交换数据 myswap();
	tempalte <typename T>
	myswap (T&a ,T&b){};
	1.myswap(a,b);
	2.myswap<int>(a,b);//指定数据类型为int
	
注意事项:1.自动类型推导,必须推导出一致的数据类型T才可以使用
			//即一次使用T只能替代一种数据类型
		2.模板必须要确定T的数据类型,才可以使用
			//即若模板函数没有指定数据类型,则调用函数时必须使用显示指定数据类型
		3.尖括号内称为模板形参,b
```

#### 普通函数与函数模板的区别

```
1.普通函数调用时可以发生自动类型转换(隐式类型转换)
2.函数模板调用时,如果利用自动类型推导,不会发生隐式类型转换
3.如果利用显示指定类型的方式,可以发生隐式类型转换
```

#### 普通函数与函数模板的调用规则

```
1.若函数模板和普通函数都可以实现,优先调用普通函数
2.可以通过空模板参数列表来强制调用函数模板//函数名<参数列表>();
3.函数模板也可以发生重载
4.如果函数模板可以产生更好的匹配,优先调用函数模板//即特殊指定的空模板参数实现存在时
```



### 类模板

```
作用:建立一个通用类,类中成员数据类型可以不具体制定,用一个虚拟的类型来代表

语法
template <typename T>
类
//template --声明创建模板		typename --表示其后面符号是一种数据类型,可用class代替		T --通用的数据类型,名称可以替换,通常为大写字母
```

#### 类模板与函数模板的区别

```
1.类模板没有自动类型推到的方式
2.类模板在参数列表中可以有默认参数
```

![image-20230731113857864](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230731113857864.png)

#### 类模板中成员函数创建时机

```
1.普通类中的成员函数一开始就可以创建
2.类模板中的成员函数在调用时才创建
```



## STL

### 基本概念

```
目的:提高代码复用性,并且建立数据结构和算法的一套标准

概念
1.全称为标准模板库
2.广义分为容器,算法和迭代器
3.容器和算法之间通过迭代器进行无缝连接
4.STL几乎所有的代码都采用了模板类或模板函数

组件:STL分为六大组件,分别为容器,算法,迭代器,仿函数,适配器(配接器),空间配置器
	1.容器:各种数据结构,如vector,list,deque,set,map等
	2.算法:各种常用的算法,如sort,find,copy,for_each等
	3.迭代器:扮演了函数与算法间的胶合剂
	4.仿函数:行为类似于函数,可作为算法的某种策略
	5.适配器:一种用来修饰容器或者仿函数或迭代器接口的东西
	6.空间配置器:负责空间的配置与管理
```

#### 容器

```
本质:将一些常用数据结构实现出来,常用数据结构如数组,链表,栈,队列等

序列式容器:强调值的排序,序列式容器中的每个元素均有固定的位置
关联式容器:二叉树结构,各元素之间没有严格的物理上的顺序关系
```

#### 算法

```
本质:通过有限的步骤,解决逻辑或数学上的问题
头文件<algorithm>

质变算法:运算过程中会更改区间内的元素和内容,如拷贝与替换等
非质变算法:运算过程中不会更改区间的元素内容,如查找,记数等
```

#### 迭代器

```
提供一种方法,使其能够依序寻访某个容器所含的各个元素,而又无需暴露该容器的内部表示方式,每个容器都有自己专属的迭代器,类似于指针操作
```

### 容器

#### vector

```
本质:可理解为一个数组
语法:vector<数据类型>容器名;
迭代其类型:vector<数据类型>::iterator = 容器名.迭代器类型();
//.begin()	起始迭代器	.end()	结束迭代器,指向容器中最后一个元素的下一个位置

与普通数组的不同:不用初始化数组大小
相同点:可实现多维操作,嵌套几层就是几维
```

##### 对容器的操作

```
初始化
	空初始化
		vector<数据类型>容器名;//数据类型可为普通数据类型和自定义数据类型即类等
	带值初始化
		vector<数据类型>容器名 = {值1,..};//列表初始化
		vector<数据类型>容器名(n);//初始化容器有n个元素,默认为0
		vector<数据类型>容器名(n,m);//初始化容器有n个元素,值为m
		vector<数据类型>容器名(数组指针ptr,ptr+n);//将数组从下表ptr到ptr+n赋值给容器
		vector<数据类型>容器名(vec.begin(),vec.begin()+i);;//将容器vec从begin()开始共i个元素给b
	注:若初始化容器数据类型为string,默认初始化为'\0',若为int,默认为0
	
添加元素
	vec.push_back(i),元素被加在数组尾
	vector.insert(pos,elem),在迭代器pos指定的位置之前插入一个新元素elem,返回表示新插入元素位置的迭代器
	vector.insert(pos,n,elem),在迭代器pos指定的位置之前插入n个元素elem,返回第一个插入元素的位置
	vector.insert(pos,first,last),在迭代器pos指定位置之前插入其他容器(不限于vector)中[first,last)区域的所有元素,并返回表示第一个新插入元素位置的迭代器
	vector.insert(pos,initlist),在迭代器pos指定的位置之前插入初始化列表并返回第一个新插入元素位置的迭代器
	vector& operator=(const vector& vec);//重载等号操作符
	assign(beg,end);//将[beg,end)区间中的数据拷贝赋值给本身
	assign(n,elem);//将n个elem拷贝赋值给本身
	vector.empalce (const_iterator pos, args...);//在指定位置之前添加数据,每次只能添加一个,效率比insert高
	
删除元素
	pop_back(),删除最后一个元素,容器大小减1但容量不变
	erase(pos),删除pos指定位置元素,返回下一个元素的位置迭代器,大小减1,容量不变
	swap(beg),pop_back(),用swap交换要删除的元素和最后一个元素位置,再删除
	erase(beg,end),删除区间内所有元素,返回最后一个被删元素指向的下一个元素位置的迭代器
	remove(),删除容器中和指定元素值相等的元素,返回指向最后要给被删元素的下一个位置的迭代器,不改变容器大小和容量
	clear(),容器大小置零

	
多维vector//第一层vector相当于总的大vector,每次可以插入小一层的任意大小vector(支持范围内)
例:ctor<vector<int>> vec;
	vector<int> inser_vec = {1,2,3,4,5};
	vec.push_back(inser_vec);
	vector<int>::iterator it = vec[0].begin();
	cout <<*it;

#多维vector对第一层vector进行size()时返回的是所含小vector个数
```





### STL函数对象

#### 函数对象

##### 概念

```
1.重载函数调用操作符的类,其对象称为函数对象
2.函数对象使用重载的()时,行为类似函数调用,也叫仿函数

本质:函数对象(仿函数)是类而不是函数
```

##### 函数对象的使用

```
1.函数对象使用时,可以向普通函数那样调用,可以有参数,可以有返回值
2.函数对象超出普通函数的概念,函数对象可以有自己的状态
3.函数对象可以作为参数传递
```

#### 谓词

##### 概念

```
1.返回bool类型的仿函数称为谓词
2.若一个operator()接受一个参数,那么叫作一元谓词
3.若一个operator()接受两个参数,那么叫作二元谓词
```

#### 内建对象函数

##### 意义

```
概念:STL内建了一些函数对象

分类:算术仿函数,关系仿函数,逻辑仿函数

用法
	1.仿函数所产生对象,用法和一般函数完全相同
	2.使用内建函数,需有头文件<functional>
```

##### 算术仿函数

```
功能描述:实现四则运算,其中只有取反是一元运算
```

![image-20230802175145024](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230802175145024.png)

##### 关系仿函数

```
功能描述:实现关系对比
```

![image-20230802180136877](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230802180136877.png)

##### 逻辑仿函数

```
功能描述:实现逻辑运算
```

![image-20230802180107077](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230802180107077.png)

#### 常用算法

##### 概述

```
算法主要由头文件<algorithm>,<functional>,<numeric>组成

<algorithm>是STL头文件中最大的一个,如比较,交换,查找,遍历操作,复制,修改等
<functional>定义了一些模板类,用以声明函数对象
<numeric>体积很小,只包括几个在序列上面进行简单数学运算的模板函数
```

##### 遍历算法

###### for_earch	遍历容器

```
参数:for_earch(iterator begin,iterator end,_func)
	begin,起始迭代器	end,遍历迭代器	_func,遍历策略
```

###### transfrom	搬运容器到另一个容器

```
参数:transform(iterator begin,iterator end,iterator begin2,_func)
	begin,起始迭代器	end,终点迭代器	begin2,目标容器开始迭代器	_func,策略

注:目标容器需要提前开辟空间
```

##### 查找算法

###### find和find_if

```
功能描述
	find:查找指定元素,找到返回指定元素的迭代器,找不到返回结束迭代器end()
	find_if:按条件查找元素,找到返回指定元素的迭代器,找不到返回结束迭代器end()
	
函数原型
	find(iterator beg,iterator end,_val);
	//beg,起始迭代器	end,终点迭代器	_val,查找的元素
	find_if(iterator beg,iterator end,_pred);
	//beg,起始迭代器	end,终点迭代器	_pred,函数或谓词,返回bool类型的仿函数
```

###### adjacent_find

```
功能描述:查找相邻重复元素,返回相邻元素的第一个位置的迭代器,若没有返回结束迭代器end()
函数原型
	adjacent_find(iterator beg,iterator end);
	//beg,起始迭代器	end,终点迭代器
```

###### binary_search

```
功能描述:查找指定元素是否存在,查到返回true,否则false,在无序列表中不可用
函数原型
	binary_search(iterator beg,iterator end,_val);
	//beg,起始迭代器	end,终点迭代器	_val,查找的元素
```

###### count和count_if

```
功能描述
	count:统计元素个数
	count_if:按条件统计元素出现个数
函数原型
	count(iterator beg,iterator end,_val)
	//beg,起始迭代器	end,终点迭代器	_val,统计的元素
	count_if(iterator beg,iterator end,_pred)
	//beg,起始迭代器	end,终点迭代器	_pred,谓词
```

##### 排序算法

###### sort

```
功能描述:对容器内元素进行排序

函数原型:sort(iterator beg,iterator end,_pred)
		//beg,起始迭代器	end,终点迭代器	_pred,排序策略,谓词,默认从小到大
```

###### random_shuffle

```
功能描述:对指定范围内元素随机调整次序

函数原型:random_shuffle(iterator beg,iterator end)
		//beg,起始迭代器	end,终点迭代器
```

###### merge

```
功能描述:两个容器元素合并且存储到另一个容器中(合并容器必须是有序的)

函数原型:merge(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest)
		//beg,起始迭代器	end,终点迭代器	dest,目标容器开始迭代器
```

###### reverse

```
功能描述:将容器内指定范围元素进行反转

函数原型:reverse(iterator beg,iterator end)
		//beg,起始迭代器	end,终点迭代器
```

##### 替换和拷贝算法

###### copy

```
功能描述:将容器内指定范围元素拷贝到另一个容器中

函数原型:copy(iterator beg,iterator end,iterator dest)
		//beg,起始迭代器	end,终点迭代器	dest,目标容器开始迭代器
```

###### replace和replace_if

```
功能描述
	replace:将容器指定范围内指定元素改为新元素
	replace_if:将指定容器内满足条件元素修改为新元素

函数原型
	replace(iterator beg,iterator end,oldvaule,newvalue);
	//beg,起始迭代器	end,终点迭代器	oldvalue,旧元素	newvalue,新元素
	replace_if(iterator beg,iterator end,_pred,newvalue);
	//beg,起始迭代器	end,终点迭代器	_pred,谓词,条件	newvalue,新元素
```

###### swap

```
功能描述:互换两个容器内的元素(容器内元素同种类型)

函数原型:swap(container c1,container c2);
		//c1,容器1	c2,容器2
```

##### 算术生成算法

###### accumulate

```
功能描述:计算区间内容器元素累计总和

函数原型:accumulate(iterator beg,iterator end,_val);
		//beg,起始迭代器	end,终点迭代器	_val,起始累加值
```

###### fill

```
功能描述:向容器中填充指定元素

函数原型:fill(iterator beg,iterator end,_val);
		//beg,起始迭代器	end,终点迭代器	_val,填充值
```

##### 结合算法

###### set_intersection

```
功能描述:求两个容器交集存到新容器中(两个容器必须有序,且新开辟容器需提前开辟空间)

函数原型:set_intersection(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest)
		//beg,起始迭代器	end,终点迭代器	dest,目标容器开始迭代器
```

###### set_union

```
功能描述:求两个容器并集存到新容器中(两个容器必须有序,且新开辟容器需提前开辟空间)

函数原型:set_union(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest)
		//beg,起始迭代器	end,终点迭代器	dest,目标容器开始迭代器
```

###### set_difference

```
功能描述:求两个容器差集存到新容器中(两个容器必须有序,且新开辟容器需提前开辟空间)

函数原型:set_difference(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest)
		//beg,起始迭代器	end,终点迭代器	dest,目标容器开始迭代器
```

