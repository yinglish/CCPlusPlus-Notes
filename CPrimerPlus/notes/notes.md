笔记直接参考pdf电子书，有时间的话后续再用自己的话总结一次；复习时，首先参照每章开头的you will learn对照，不懂的点要细看，注释部分要看，然后就是看关键概念和总结。


# 1 Getting Ready

You will learn:

1. C's history and features
2. The steps needed to write a program
3. A bit about compilers and linkers
4. C standards

 C的特点：快，紧凑，可移植

 The spirit of C:

 1. Trust the programmer.

 2. Don't prevent the programmer from doing what needs to be done.

 3. Keep the language small and simple.

 4. Provide only one way to don an operation.

 5. Make it fast, even if is not guaranteed to be portable.

 编程的7个步骤：Define the program objectives; Design the program; Write the code; Compile; Run the program; Test and debug the program; Maintain and modify the program.

 Windows程序程序运行时输出屏幕一闪而过：使用getchar(); 如果程序接受输入，则使用两个getchar();

 **总结**

 C语言强大，简明，它流行的原因是因为它有好的工具对硬件进行操作，也很容易移植，C语言是编译型语言，有编译器和链接器将源代码转化为可执行的代码。


 # 2 Introducing C

 You will learn:

 =, main(), printf(), Putting together a simple C program, Creating integer-valued variables, assigning them values, and displaying those values onscreen, The newline character, How to include comments in your programs, create programs containing more than one function, and find program errors， what keywords are.

  C语言中变量的声明问题：C99之前必须位与程序的开头

  C语言设计为变量需要声明的理由：变量声明在一起便于抓住代码主题，思考需要声明的变量促使提前规划，防止因拼写带来的不易查找的错误。

  老式的C代码：无参函数不加void，函数用的是声明而非原型（C90）之前，不要再采用。

Program State的理解：某个时间点时所有变量值的集合。

几个关键字的含义与用法：extern, inline, static, register, restrict, volatile, _Alignas, _Alignof, _Bool, _Complex, _Generic, _Imaginary, _Noreturn, _Static_assert, #_Thread_local

保留标识符：以下划线开头以及标准库函数。

# 3 Data and C

You will learn:

* int, short, long, unsigned, char, float, double, _Bool, _Complex, _Imaginary
* sizeof
* scanf







