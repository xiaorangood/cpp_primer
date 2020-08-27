# 第4章 表达式

- 表达式是通过**运算符（operator）**将一个或多个**运算对象（operand）**组成，对表达式求值获得一个**结果（result）**
- 字面值和变量是嘴贱大的**表达式（expression）**



## 基础

### 基本概念

- 根据运算对象格式，运算符分为：一元运算符（unary operator）、二元运算符（binary operator）、三元运算符
- 运算符的组合规则：优先级（precedence）、结合律（associativity）、运算对象求值顺序（order of evaluation）
- **重载运算符（overloaded operator）**：运算符作用于类类型时，用户可以自行定义其含义；但**运算对象的个数、优先级和结合律无法改变**

### 左值和右值

- 当一个对象被用作右值时，用的是对象的值（内容）
- 当一个对象被用作左值时，用的是对象的身份（在内存中的位置）
- `p`指针的类型是`int *`，解引用运算符生成左值，`decltype(*p)`的结果是`int &`；取地址运算符生成右值，`decltype(&p)`的结果是`int **`



## 算数运算符

- 整数相除的结果还是整数，直接舍弃商的小数部分，**一律向零取整**
- 除法运算对象符号相同商为正，否则商为负
- 取模运算符的操作对象必须是整数
- 取余运算要是的等式`(m/n)*n +m%n`的结果与`m`的数值相等
  - `m%n = m - (m/n)*n`
  - `(-m)%n = (-m)-((-m)/n)*n = -(m-(m/n)*n) = -(m%n)`
  - `m%(-n) = m-(m/(-n))*(-n) = m-(m/n)*n = m%n`
  - **结论：用两个数的真值取余，若m为正，则结果为余数；若m为负数，则结果为余数取反**



## 逻辑和关系运算符

- 逻辑运算符和关系运算符的返回值都是布尔型
- 逻辑运算符的**短路求值**：先算左侧运算符对象，再求右侧运算符对象的值
- 比较运算时，除非比较对象时布尔类型，否则不要使用布尔字面值`true`和`false`作为运算对象



## 赋值运算符

- 赋值运算赋的结果时它的左侧运算对象，并且时一个左值
- 赋值运算符满足右结合律
- `a = b = 0`等价于`a = (b = 0)`；先`b`赋值0，然后用`b`赋值`a`
- 任何复合赋值运算符等价于`a = a op b`



## 递增和递减运算符

- 两种形式：前置版本和后置版本
- 前置版本：将运算对象加1（或减1），然后将改变后的对象作为求值结果；对象本身作为左值返回
- 后置版本：将运算对象加1（或减1），但求值结果是运算对象改变之前那个值的副本；求值副本作为右值返回
- `*pbeg++`等价于`*(pbeg++)`



## 成员访问运算符

- `ptr->mem`等价于`(*ptr).mem`
- 箭头运算赋作用与一个指针类型的运算对象，结果是一个左值



## 条件运算符

- 条件运算符（?:）允许我们把简单的if-else逻辑嵌入到单个表达式中，条件运算符的使用形式：`cond ? exp1 : exp2`
- 条件运算符可以嵌套，但层级多了可读性急剧下降
- 使用`<<`输出比较结果时，需要将整个条件运算符号用括号包围。



## 位运算符

- 位运算作用于整数的运算对象，并把运算对象堪称是二进制的集合
- 二进制位或者向左移（`<<`）或者向右移（`>>`），移出边界之外的位被舍弃掉
- 左移在右侧插入值为0的二进制位
- 右移无符号数，在左侧插入值为0的二进制位；右移有符号数，在左侧插入符号位的副本的二进制位
- `char`类型的运算对象首先提升成`int`类型



## sizeof运算符

- sizeof运算符返回一个表达式或者一个类型名字所占的字节数
- 返回数值是一个`size_t`类型
- sizeof运算符的运算对象的两种形式：（1）`sizeof (type)`；（2）`sizeof expr`
- 对**数组**执行sizeof运算符得到整个数组所占空间的大小；等价于对数组中所有元素各执行sizeof运算并求和；**sizeof运算不会把数组转换成指针处理**
- 对**类**执行sizeof运算，返回该类类型固定部分的大小
- sizeof运算赋返回值是一个**常量表达式**，可以用来其结果声明数组的维度



## 逗号运算符

- 含有两个运算对象，按照从左向右的顺序依次求值
- 运算结果是右侧表达式的值



## 类型转换

- **隐式转换**是自动执行的，无需程序员介入

### 隐式类型转换

- 整型提升（integral promotion）
  - 比`int`类型小的整数值（包括布尔值、`char`类型）转换为`int`类型
  - 较大的`char`类型，提升成`int`, `unsigned int`, `long`, `unsigned long`, `long long`, `unsigned long long`中能容纳原类型的最小类型
- 无符号与有符号运算对象的转换
  - 无符号类型**不小于**带符号类型，则**带符号类型=>无符号类型**
  - 无符号类型**小于**带符号类型
    - 有符号类型**能容纳无符号类型**所有数值，则将**无符号类型=>有符号类型**
    - 有符号类型**不能容纳无符号类型**所有数值，则将**有符号类型=>无符号类型**
- **数组转换为指针**，（当数组被用作decltype关键字参数，或作为取地址符（&）、sizeof及typeid等运算符的运算对象时，转换不发生）
- **指针转换**
  - 常量整数值`0`和字面值`nullptr`可以转换成**任意指针**
  - 指向**任意非常量的指针**能转换为`void *`
  - 指向**任意对象的指针**能转换为`const void*`
- 在条件中，**非布尔类型**转换成**布尔类型**
- 指向**非常量**的指针/引用，可以转换成相应的**常量类型**的指针/引用
- 类类型可以定义类型转换，不能每次只能执行一次类类型转换

### 显示类型转换

- 强制类型转换的形式：`cast-name<type>(expression);`
  - `type`为目标类型
  - `expression`是要转换的值
  - `cast-name`包括**static-cast**，**dynamic_cast**，**const_cast**和**reinterpret_cast**
- static_cast
  - 任何具有明确定义的类型转换，只要不把话**底层const**，都可以使用
  - 可以用于找回存在于`void*`指针：`double d; void *p = &d; double *dp = static_cast<double*>(p);`
- const_cast
  - 只能改变运算对象的底层cosnt，去掉cosnt心智
  - const_cast只能去掉表达式的常量属性，不能改变表达式类型；编译器不再组织对该对象的写操作
  - const_cast常用于有函数重载的上下文
- reinterpret_cast：为运算对象的位模式提供较低层次上的重新解释；必须牢记真实对象的类型
- dynamic_cat：支持允许时类型识别

### 旧式的类型转换

- 函数形式的强制类型转换：`type (expr);`
- C语言风格的强制类型转转换：`(type) expre;`



## 运算符优先级表

| 运算符                                                       | 结合律                                                       | 功能                                                         | 用法                                                         | 分类                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| `::`<br />`::`<br />`::`                                     | 左<br />左<br />左                                           | 全局作用域<br />类作用域<br />命名空间作用域                 | `::name`<br />`class::name`<br />`namespace::name`           |                                                              |
| `.`<br />`->`<br />`[]`<br />`()`<br />`()`                  | 左<br />左<br />左<br />左<br />左                           | 成员选择<br />成员选择<br />下标<br />函数调用<br />类型构造 | `object.member`<br />`poiner->member`<br />`expr[expr]`<br />`name(expr_list)`<br />`type(expr_list)` |                                                              |
| `++`<br />`--`<br />`typeid`<br />`typeid`<br />`explicit cast` | 右<br />右<br />右<br />右<br />右                           | **后置**递增运算<br />**后置**递减运算<br />类型ID<br />运行时类型ID<br />类型转换 | `lvalue++`<br />`lvalue--`<br />`typeid(type)`<br />`typeid(expr)`<br />`cast_name<type>(expr)` | 递增运算符<br />递减运算符<br /><br /><br />                 |
| `++`<br />`--`<br />`~`<br />`!`<br />`-`<br />`+`<br />`*`<br />`&`<br />`()`<br />`sizeof` | 右<br />右<br />右<br />右<br />右<br />右<br />右<br />右<br />右<br />右 | **前置**递增运算符<br />**前置**递减运算符<br />位求反<br />逻辑非<br />一元负号<br />一元正号<br />解引用<br />取地址<br />类型转换<br />对象的大小 | `++lvalue`<br />`--lvalue`<br />`~expr`<br />`!expr`<br />`-expr`<br />`+expr`<br />`*expr`<br />`&lvalue`<br />`(type) expr`<br />`sizeof type` | 递增运算符<br />递减运算符<br />位运算符<br />逻辑运算符<br />算术运算符<br />算术运算符<br /><br /><br /><br />sizeof运算符 |
| `sizeof`<br />`sizeof...`<br />`new`<br />`new []`<br />`delete`<br />`delete []`<br />`noexcept` | 右<br />右<br />右<br />右<br />右<br />右<br />右           | 类型的大小<br />参数包的大小<br />创建对象<br />创建数组<br />释放对象<br />释放数组<br />不抛出异常 | `sizeof(type)`<br />`siezof...(name)`<br />`new type`<br />`new type[size]`<br />`delete expr`<br />`delete [] expr`<br />`noecept(expr)` |                                                              |
| `->*`<br />`.*`                                              | 左<br />左                                                   | 指向成员选择的指针<br />指向成员选择的指针                   | `ptr->*ptr_to_member`<br />`obj.*ptr_to_member`              |                                                              |
| `*`<br />`/`<br />`%`                                        | 左<br />左<br />左                                           | 乘法<br />除法<br />取模（取余）                             | `expr*expr`<br />`expr/expr`<br />expr%expr                  | 算术运算符<br />算术运算符<br />算术运算符                   |
| `+`<br />`-`                                                 | 左<br />左                                                   | 加法<br />减法                                               | `expr + expr`<br />`expr - expr`                             | 算术运算符<br />算术运算符                                   |
| `<<`<br />`>>`                                               | 左<br />左                                                   | 向左移动<br />向右移动                                       | `expr << expr`<br />`expr >> expr`                           | 位运算符<br />位运算符                                       |
| `<`<br />`<=`<br />`>`<br />`>=`                             | 左<br />左<br />左<br />左                                   | 小于<br />小于等于<br />大于<br />大于等于                   | `expr < expr`<br />`expr <= expr`<br />`expr > expr`<br />`expr >= expr` | 关系运算符<br />关系运算符<br />关系运算符<br />关系运算符   |
| `==`<br />`!=`                                               | 左<br />左                                                   | 相等<br />不相等                                             | `expr == expr`<br />`expr != expr`                           | 关系运算符<br />关系运算符                                   |
| `&`                                                          | 左                                                           | 位与                                                         | `expr & expr`                                                | 位运算符                                                     |
| `^`                                                          | 左                                                           | 位异或                                                       | `expr ^ expr`                                                | 位运算符                                                     |
| `|`                                                          | 左                                                           | 位或                                                         | `expr | expr`                                                | 位运算符                                                     |
| `&&`                                                         | 左                                                           | 逻辑与                                                       | `expr && expr`                                               | 逻辑运算符                                                   |
| `||`                                                         | 左                                                           | 逻辑或                                                       | `expr || expr`                                               | 逻辑运算符                                                   |
| `? :`                                                        | 右                                                           | 条件                                                         | `expr ? expr : expr`                                         | 条件运算符                                                   |
| `=`                                                          | 右                                                           | 赋值                                                         | `lvalue = expr`                                              | 赋值运算符                                                   |
| `*=`, `/=`, `%=`<br />`+=`, `-=`<br />`<<=`,`>>=`<br />`&=`, `|=`, `^=` | 右                                                           | 复合赋值                                                     | `lvalue += expr`等                                           | 赋值运算符                                                   |
| throw                                                        | 右                                                           | 抛出异常                                                     | `throw expr`                                                 |                                                              |
| `,`                                                          | 左                                                           | 逗号                                                         | `expr, expr`                                                 | 逗号运算符                                                   |
