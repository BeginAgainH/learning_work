# C++ STL

## 概念

**什么是容器**	容器是用于存储其他对象并负责管理其所容纳对象内存的对象

**什么是容器库**	容器库是类模板与算法的汇集，允许程序员简单地访问常见数据结构

**容器库的类别**	1、顺序容器库	2、关联容器库	3、无序关联容器库

**容器库的职能**	容器管理为其元素分配的内存空间，并提供成员函数来直接访问或通过迭代器（具有类似于指针的属性的对象）访问

## 顺序容器库

### array

**性质**	array是一个聚合类型，其语义等同于保有一个C风格数组作为其唯一非静态数据成员的结构体。与C风格数组不同，它不会自动退化成T*。他能作为聚合类型初始化，只要有至多N个能转换成T的初始化容器：std::array<int,3>a={1,2,3};

**注意**

​	1、array默认非空且进行交换的复杂度是线性的

​	2、当array长度为0时，array.begin() == array.end()有某个唯一值

​	3、在零长array上调用front()和back()是未定义的

**头文件**	`<array>`		

**模板定义**

```
template<class T,std::size_t N>
struct array;
```

**成员类型**

| 成员类型        | 定义              |
| --------------- | ----------------- |
| value_type      | T                 |
| size_type       | std::size_t       |
| difference_type | std::ptrdiff_t    |
| reference       | value_type&       |
| const_reference | const value_type& |
| pointer         | value_type*       |
| const_pointer   | const value_type* |

**成员函数**

```
隐式定义的
 	构造函数：初始化array
    析构函数：销毁array每一个元素
    operator=：以来自另一个array的每个元素重写array的对应元素

成员函数（public）
    元素访问
        std::array<T,N>::at(size_type pos);	返回位于指定位置pos的元素的引用，有边界检查，若不存在抛出std::out_of_range异常
        std::array<T,N>::operator[](size_type pos);	返回位于指定位置pos的元素的引用，无边界检查
        std::array<T,N>::front();	返回容器首元素的引用
        std::array<T,N>::back();	返回容器最后一个元素的引用
        std::array<T,N>::data();	返回指向作为元素存储工作的底层数组的指针，返回的指针使得范围 [data(), data() + size()) 始终是有效范围，即使容器为空（此时 data() 不可解引用）；若size()==0，data()可能不返回空指针

    迭代器
        std::array<T,N>::begin()，std::array<T,N>::cbegin()	返回指向首元素的迭代器
        std::array<T,N>::end()，std::array<T,N>::cend()	返回指向末尾元素的迭代器
        std::array<T,N>::rbegin()，std::array<T,N>::crbegin()	返回指向起始的逆向迭代器
        std::array<T,N>::rend()，std::array<T,N>::crend()	返回指向末尾的逆向迭代器

    容量
        std::array<T,N>::empty();	检查容器是否为空，是返回true，否则返回false
        std::array<T,N>::size();	返回容器中元素个数，即std::distance(begin(),end())
        std::array<T,N>::max_size();	返回可容纳元素数量的最大值，因为每个array大小固定

    操作（复杂度都与容器大小成线性）
        std::array<T,N>::swap(array &other);	将容器内容与other交换
        std::array<T,N>::fill(const T& value);	将给定值value赋给容器中的所有元素
        
非成员函数
	==;!=;<;<=;>;>=;<=>;的重载	按字典顺序比较array中的值（即逐个比较对应位置的两个array的值）//复杂度与容器大小成线性
		<=>	larr 与 rarr 中的首对不等价元素的相对顺序，如果有这种元素；否则是 larr.size() <=> rarr.size()
	
	template< std::size_t I, class T, std::size_t N >
	T& get( std::array<T,N>& a ) noexcept;	从array提取第I个元素
	
	template< class T, std::size_t N >
	void swap( std::array<T, N>& lhs,
           	std::array<T, N>& rhs );	交换lhs和rhs两个容器内容//复杂度与容器大小成线性
           	
辅助类
	//tuple_size
	template< class T, std::size_t N >
    struct tuple_size< std::array<T, N> > :
        std::integral_constant<std::size_t, N>
        { };	
    提供作为编译时常量表达式访问std::array中元素数量的方法
    示例
    	template<class T>
        void test(T t)
        {
            int a[std::tuple_size<T>::value]; // 能用于编译时
            std::cout << std::tuple_size<T>::value << '\n';
        }
    
    //tuple_element
    //仍有疑问
    template< std::size_t I, class T, std::size_t N >
    struct tuple_element<I, std::array<T, N> >; 
    使用tuple接口，提供array元素类型的编译时带下标访问，成员类型type，定义为array的元素类型
    可能的实现
        template<std::size_t I, class T>
        struct tuple_element;

        template<std::size_t I, class T, std::size_t N>
        struct tuple_element<I, std::array<T,N> >
        {
            using type = T;
        };
```

