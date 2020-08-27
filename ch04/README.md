

## 练习4.1

> 表达式 5 + 10 * 20 / 2 的求值结果是多少？

105。

## 练习4.2

> 根据4.12节中的表，在下述表达式的合理位置添加括号，使得添加括号后运算对象的组合顺序与添加括号前一致。
>
> * (a) *vec.begin()
> * (b) *vec.begin() + 1

```C++
*(vec.begin())
(*(vec.begin())) + 1
```

## 练习4.3

> C++语言没有明确规定大多数二元运算符的求值顺序，给编译器优化留下了余地。这种策略实际上是在代码生成效率和程序潜在缺陷之间进行了权衡，你认为这可以接受吗？请说出你的理由。

可以接受。不同意个语句修改同一个对象。

C++的目的是效率最大化，因此相信程序员。

## 练习4.4

> 在下面的表达式中添加括号，说明其求值过程及最终结果。编写程序编译该（不加括号的）表达式并输出结果验证之前的推断。
>
> 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2

((12/3)*4) + (5*15) + ((24%4)/2)

## 练习4.5

> 写出下列表达式的求值结果。

```C++
-30 * 3 + 21 / 5  // -90+4 = -86
-30 + 3 * 21 / 5  // -30+63/5 = -30+12 = -18
30 / 3 * 21 % 5   // 10*21%5 = 210%5 = 0
-30 / 3 * 21 % 4  // -10*21%4 = -210%4 = -2
```

## 练习4.6

> 写出一条表达式用于确定一个整数是奇数还是偶数。

```C++
if ( num % 2 == 0) /*...*/
```

## 练习4.7

> 溢出是何含义？写出三条将导致溢出的表达式。

数据超出表达范围

```C++
unsigned char a = 255; ++a; //0
signed char b = 127; ++b;//-128
unsigned char c = 0; --a; //255
```

## 练习4.8

> 说明在逻辑与、逻辑或及相等性运算符中运算对象的求值顺序。

* 逻辑与运算符和逻辑或运算符都是先求左侧运算对象的值再求右侧运算对象的值，当且仅当左侧运算对象无法确定表达式的结果时才会计算右侧运算对象的值。这种策略称为 **短路求值**。
* 相等性运算符未定义求值顺序。

## 练习4.9

> 解释在下面的if语句中条件部分的判断过程。
>
> ```C++
> const char *cp = "Hello World";
> if (cp && *cp)
> ```

首先判断 `cp` ，`cp` 不是一个空指针，因此 `cp` 为真。然后判断 `*cp`，`*cp` 的值是字符 'H'，非0。因此最后的结果为真。

## 练习4.10

> 为while 循环写一个条件，使其从标准输入中读取整数，遇到 42 时停止。

```C++
int i;
while(cin >> i && i != 42)
```

## 练习4.11

> 书写一条表达式用于测试4个值a、b、c、d的关系，确保a大于b、b大于c、c大于d。

```C++
a>b && b>c && c>d
```

## 练习4.12

> 假设i、j 和k 是三个整数，说明表达式 i != j < k 的含义。

这个表达式等于 `i != (j < k)`。首先得到 j < k 的结果为 true 或 false，转换为整数值是 1 和 0，然后判断 i 不等于 1 和 0 ，最终的结果为 bool 值。

## 练习4.13

> 在下述语句中，当赋值完成后 i 和 d 的值分别是多少？
>
> ```C++
> int i;   double d;
> d = i = 3.5; 
> i = d = 3.5; 
> ```

第2行，i=3；d=3.0；第3行，d=3.5；i=3

## 练习4.14

> 执行下述 if 语句后将发生什么情况？
>
> ```C++
> if (42 = i)
> if (i = 42)
> ```

第1个if判读，编译器会报错；第2个if判断，一致为true

## 练习4.15

> 下面的赋值是非法的，为什么？应该如何修改？
>
> ```C++
> double dval; int ival; int *pi;
> dval = ival = pi = 0;
> ```

pi 是指针，不能赋值给 int ，应该改为：

```C++
dval = ival = 0;
pi = 0;
```

## 练习4.16

> 尽管下面的语句合法，但它们实际执行的行为可能和预期并不一样，为什么？应该如何修改？
>
> ```C++
> if (p = getPtr() != 0)
> if (i = 1024)
> ```

条件判断总是为 true， 应该改为：

```cpp
if ((p=getPtr()) != 0)
if (i == 1024)
```

## 练习4.17

> 说明前置递增运算符和后置递增运算符的区别。

前置递增运算符将对象本身作为左值返回，而后置递增运算符将对象原始值的副本作为右值返回。

## 练习4.18

> 如果132页那个输出vector对象元素的while循环使用前置递增运算符，将得到什么结果？

将会从第二个元素开始取值，并且最后对 v.end() 进行取值，结果是未定义的。

## 练习4.19

> 假设 ptr 的类型是指向 int 的指针、vec 的类型是vector<int>、ival 的类型是int，说明下面的表达式是何含义？如果有表达式不正确，为什么？应该如何修改？
>
> ```C++
> (a) ptr != 0 && *ptr++  
> (b) ival++ && ival
> (c) vec[ival++] <= vec[ival] 
> ```

（a）判断ptr 不是一个空指针，并且ptr 当前指向的元素的值也为真，然后将ptr指向下一个元素
（b）判断 ival 的值为真，并且 (ival + 1) 的值也为真
（c）表达式有误。C++并没有规定 `<=` 运算符两边的求值顺序，应该改为 `vec[ival] <= vec[ival+1]`

## 练习4.20

> 假设 iter 的类型是 vector<string>::iterator, 说明下面的表达式是否合法。如果合法，表达式的含义是什么？如果不合法，错在何处？
>
> ```C++
> (a) *iter++;
> (b) (*iter)++;
> (c) *iter.empty();
> (d) iter->empty();
> (e) ++*iter;
> (f) iter++->empty();
> ```

* (a)合法。返回迭代器所指向的元素，然后迭代器递增。
* (b)不合法。因为vector元素类型是 string，没有 ++ 操作。
* (c)不合法。这里应该加括号。
* (d)合法。判断迭代器当前的元素是否为空。
* (e)不合法。string 类型没有 ++ 操作。
* (f)合法。判断迭代器当前元素是否为空，然后迭代器递增。

## 练习4.21

> 编写一段程序，使用条件运算符从 vector<int> 中找到哪些元素的值是奇数，然后将这些奇数值翻倍。

```C++
#include <iostream>
#include <vector>
int main()
{
    std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (auto &i : v)
    {
        i = i & 0x1 ? i * 2 : i;
    }
    for (auto i : v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

## 练习4.22

> 本节的示例程序将成绩划分为high pass、pass 和 fial 三种，扩展该程序使其进一步将 60 分到 75 分之间的成绩设定为 low pass。要求程序包含两个版本：一个版本只使用条件运算符；另一个版本使用1个或多个if语句。哪个版本的程序更容易理解呢？为什么？

第二个版本容易理解。当条件运算符嵌套层数变多之后，代码的可读性急剧下降。而if else 的逻辑很清晰。

```C++
#include <iostream>
using std::cout; using std::cin; using std::endl;
int main()
{
    for (unsigned g; cin >> g;)
    {
        auto result = g > 90 ? "high pass" : g < 60 ? "fail" : g < 75 ? "low pass" : "pass";
        cout << result << endl;
        // -------------------------
        if (g > 90)         cout << "high pass";
        else if (g < 60)    cout << "fail";
        else if (g < 75)    cout << "low pass";
        else                cout << "pass";
        cout << endl;
    }
    return 0;
}
```

## 练习4.23

> 因为运算符的优先级问题，下面这条表达式无法通过编译。根据4.12节中的表指出它的问题在哪里？应该如何修改？
>
> ```C++
> string s = "word";
> string pl = s + s[s.size() - 1] == 's' ? "" : "s" ;
> ```

加法运算符的优先级高于条件运算符。因此要改为：

```C++
string pl = s + (s[s.size() - 1] == 's' ? "" : "s") ;
```

## 练习4.24

> 本节的示例程序将成绩划分为 high pass、pass、和fail三种，它的依据是条件运算符满足右结合律。假如条件运算符满足的是左结合律，求值的过程将是怎样的？

如果条件运算符满足的是左结合律。那么

```cpp
finalgrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : "pass";
```

等同于

```cpp
finalgrade = ((grade > 90) ? "high pass" : (grade < 60)) ? "fail" : "pass";
```

假如此时 grade > 90 ，第一个条件表达式的结果是 "high pass" ，而字符串字面值的类型是 const char *，非空所以为真。因此第二个条件表达式的结果是 "fail"。这样就出现了自相矛盾的逻辑。

## 练习4.25

> 如果一台机器上 int 占 32 位、char 占8位，用的是 Latin-1 字符集，其中字符'q' 的二进制形式是 01110001，那么表达式'q' << 6的值是什么？

首先将char类型提升为int 类型，等同于 00000000 00000000 00000000 01110001 << 6，结果是 00000000 00000000 00011100 01000000，转换是十进制是7232。

## 练习4.26

> 在本节关于测验成绩的例子中，如果使用unsigned int 作为quiz1 的类型会发生什么情况？

在有的机器上，unsigned int 类型可能只有 16 位，因此结果是未定义的。

## 练习4.27

> 下列表达式的结果是什么？
>
> ```C++
> unsigned long ul1 = 3, ul2 = 7;
> (a) ul1 & ul2 
> (b) ul1 | ul2 
> (c) ul1 && ul2
> (d) ul1 || ul2 
> ```

（a）3；（b）7；（c）true；（d）true

## 练习4.28

> 编写一段程序，输出每一种内置类型所占空间的大小。

```C++
#include <iostream> 
using namespace std;
int main()
{
    cout << "bool:\t\t" << sizeof(bool) << " bytes" << endl << endl;

    cout << "char:\t\t" << sizeof(char) << " bytes" << endl;
    cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes" << endl;
    cout << "char16_t:\t" << sizeof(char16_t) << " bytes" << endl;
    cout << "char32_t:\t" << sizeof(char32_t) << " bytes" << endl << endl;

    cout << "short:\t\t" << sizeof(short) << " bytes" << endl;
    cout << "int:\t\t" << sizeof(int) << " bytes" << endl;
    cout << "long:\t\t" << sizeof(long) << " bytes" << endl;
    cout << "long long:\t" << sizeof(long long) << " bytes" << endl << endl;

    cout << "float:\t\t" << sizeof(float) << " bytes" << endl;
    cout << "double:\t\t" << sizeof(double) << " bytes" << endl;
    cout << "long double:\t" << sizeof(long double) << " bytes" << endl << endl;

    return 0;
}
```

## 练习4.29

> 推断下面代码的输出结果并说明理由。实际运行这段程序，结果和你想象的一样吗？如不一样，为什么？
>
> ```C++
> int x[10];   int *p = x;
> cout << sizeof(x)/sizeof(*x) << endl;
> cout << sizeof(p)/sizeof(*p) << endl;
> ```

第一个输出结果是 10。第二个结果是1。

## 练习4.30

> 根据4.12节中的表，在下述表达式的适当位置加上括号，使得加上括号之后的表达式的含义与原来的含义相同。
>
> ```C++
> (a) sizeof x + y      
> (b) sizeof p->mem[i]  
> (c) sizeof a < b     
> (d) sizeof f() 
> ```

```C++
(a) (sizeof x) + y      
(b) sizeof (p->mem[i]) 
(c) (sizeof a) < b     
(d) sizeof (f())
```

## 练习4.31

> 本节的程序使用了前置版本的递增运算符和递减运算符，解释为什么要用前置版本而不用后置版本。要想使用后置版本的递增递减运算符需要做哪些改动？使用后置版本重写本节的程序。

在4.5节（132页）已经说过了，**除非必须，否则不用递增递减运算符的后置版本**。在这里要使用后者版本的递增递减运算符不需要任何改动。

## 练习4.32

> 解释下面这个循环的含义。
>
> ```C++
> constexpr int size = 5;
> int ia[size] = { 1, 2, 3, 4, 5 };
> for (int *ptr = ia, ix = 0;
>     ix != size && ptr != ia+size;
>     ++ix, ++ptr) { /* ... */ }
> ```

这个循环在遍历数组 ia，指针 ptr 和 整型 ix 都是起到一个循环计数的功能。

## 练习4.33

> 根据4.12节中的表说明下面这条表达式的含义。
>
> ```C++
> someValue ? ++x, ++y : --x, --y
> ```

逗号表达式的优先级是最低的。因此这条表达式也等于：

```C++
(someValue ? ++x, ++y : --x), --y
```

如果 someValue的值为真，x 和 y 的值都自增并返回 y 值，然后丢弃 y 值，y递减并返回 y 值。如果 someValue的值为假，x 递减并返回 x 值，然后丢弃 x 值，y递减并返回 y 值。

## 练习4.34

> 根据本节给出的变量定义，说明在下面的表达式中奖发生什么样的类型转换：
>
> ```C++
> (a) if (fval)
> (b) dval = fval + ival;
> (c) dval + ival * cval;
> ```

需要注意每种运算符遵循的是左结合律还是右结合律。

* (a) fval 转换为 bool 类型
* (b) ival 转换为 float ，相加的结果转换为 double
* (c) cval 转换为 int，然后相乘的结果转换为 double

## 练习4.35

> 假设有如下的定义：
>
> ```C++
> char cval;
> int ival;
> unsigned int ui;
> float fval;
> double dval;
> ```
>
> 请回答在下面的表达式中发生了隐式类型转换吗？如果有，指出来。
>
> ```C++
> (a) cval = 'a' + 3;
> (b) fval = ui - ival * 1.0;
> (c) dval = ui * fval;
> (d) cval = ival + fval + dval;
> ```

* (a) 'a' 转换为 int ，然后与 3 相加的结果转换为 char
* (b) ival 转换为 double，ui 转换为 double，结果转换为 float
* (c) ui 转换为 float，结果转换为 double
* (d) ival 转换为 float，与fval相加后的结果转换为 double，最后的结果转换为char

## 练习4.36

> 假设 i 是int类型，d 是double类型，书写表达式 i*=d 使其执行整数类型的乘法而非浮点类型的乘法。

```C++
i *= static_cast<int>(d);
```

## 练习4.37

> 用命名的强制类型转换改写下列旧式的转换语句。
>
> ```C++
> int i; double d; const string *ps; char *pc; void *pv;
> (a) pv = (void*)ps;
> (b) i = int(*pc);
> (c) pv = &d;
> (d) pc = (char*)pv;
> ```

```C++
(a) pv = static_cast<void*>(const_cast<string*>(ps));
(b) i = static_cast<int>(*pc);
(c) pv = static_cast<void*>(&d);
(d) pc = static_cast<char*>(pv);
```

## 练习4.38

> 说明下面这条表达式的含义。
>
> ```C++
> double slope = static_cast<double>(j/i);
> ```

将 `j/i` 的结果值转换为 double，然后赋值给slope。 
