## Effective notes

**naming conventions**

lhs: left-hand side  rhs: right-hand side

### 1 让自己习惯C++

**item 1: View C++ as a federation of languages**

联邦的组成：C, Object-Oriented C++, Template C++, STL

**item 2: Prefer consts, enums, and inline to #defines**

/#define问题：类型问题，调试追踪问题

const: const常量定义式通常放在头文件中（传递）；class类的常量：作用域限制于class内，为了确保只有一个应当定义为static。注意类内的static只是一个声明，并非定义，若要使用，还需在使用前，函数外进行定义。
```C++
class A
{
private:
    const static int a = 9; // g++ 5.4.0允许在类内完成初值设定，有些编译器不允许，则可用enum hack技巧替代相关功能
    static int count;
public:
    void get_a() {cout << "a: " << a << endl;}
    void get_count() {cout << "count: " << count << endl;}
};
int A::count = 10; // 置于实现文件内
int main()
{
    A a;
    a.get_a();
    a.get_count();
    return 0;
}
```

enum hack: 有些像#define，不能取地址，指针与引用不能指向

```C++
class GamePlayer
{
private:
    enum {NumTurns = 5};
    int scores[NumTurns];
}
```

像函数的宏：可以用模板内联函数取代

* 对于单纯的常量，用const对象或enums替代#define
* 对行似函数的宏，最好改用inline函数替换

**item 03: use const whenever possible**

const iterator, const_iterator, const const_iterator.

关于类中成员函数的const：

* 编译器是 bitwise constness的，即只要声明为const的函数就不能有赋值动作。有些函数能通过bitwise constness测试，但通过该函数得到的值在通过一些操作后能改变函数成员值

* logical constness: const的成员函数可以修改成员内的某些bits只要客户端看不出来，但是编译器是支持bitwise constnest的，如何处理，`mutable`关键字的使用！

* 运用const成员对象实现其对应的non-const对象：需要两次类型转换（static_cast和const_cast）,前者是为了调用const成员函数，后者是将结果转化为非const的。不要用const成员函数调用non-const成员函数实现！

**item 04: Make sure that objects are initialized before they're used**

* 成员初始化发生在构造函数调用之前，对于非内置类型，初始化调用其相关的构造函数，如果在函数体内对其进行赋值操作，则会调用赋值操作符函数，影响效率。所以使用成员初始化列表。对于内置类型，效率一样（并不会默认初始化），但还是最好放在初始化列表中，避免未定义的行为。

* 对于有多个构造函数，且有一些不使用初始化列表不影响效率的可以至于一个私有函数中，供构造函数调用

* 成员初始化顺序：与初始化列表的顺序无关

* 非局部静态变量的初始化顺序问题：如何确保使用某静态变量之前其被初始化？搬到函数内返回其引用，讲全局静态转化成了局部静态，而该函数调用期间，首次遇到该对象定义之前时被初始化。

* 为内置类型进行手工的初始化
* 构造函数最好使用初始化列表，但成员初始化顺序并不取决于此
* 为免除“跨编译单元之初始化顺序”问题，请以local static对象替换non-local static对象

### 2 Constructor, Destructor, and Assignment Operators

**item 05: Know what functions C++ silently writes and calls**

* 编译器可以自动添加default构造函数，copy构造函数，copy assignment操作符，以及析构函数

**item 06: Explicitly disallow the use of compiler-generated functions you do not want**

* 将相应的成员函数声明为private并且不予实现，或继承类似的基类

**item 07: Declare destructors virtual in polumorphic base classes**

* polymorphic base classes应该声明一个virtual析构函数。如果class带有任何virtual函数，它就应该拥有一个virtual虚析构函数。
* classes的设计目的如果不是作为base classes，或不是为了多态性，就不该声明virtual函数

**item 08: Prevent exceptions from leaving destructors**

* 析构函数绝对不应该吐出异常。如果一个被析构函数调用的函数可能抛出异常，析构函数应该捕捉任何异常，然后吞下它们或结束程序
* 如果客户需要对某个操作函数运行期间抛出的异常做出反应，那么class应该提供一个普通函数执行该操作

**item 09: Never call virtual functions during construction or destruction**

* 在构造和析构期间不要调用virtual函数，因为这类调用从不下降至derived class

**item 10: Have assignment operators return a reference to *this**

**item 11: Handle assignment to self in operator=**

* 确保当对象自我赋值时operator=有良好行为。其中技术包括“来源对象”和“目标对象”的地址，精心周到的语句顺序，以及copy-and-swap
* 确定任何对象如果操作一个以上的对象，而其中多个对象时同一个对象时，其行仍然正确

**item 12: 复制对象时勿忘其每一个成分**

* copying函数应该确保复制“对象内所有成员变量”及“所有base class成分”
* 不要尝试以某个copying函数实现另一个copying函数。应该将共同机能放进第三个函数中，并由两个copying函数共同调用

## 3 资源管理

**item 13: Use objects to manage resources**

* 为防止资源泄露，请使用RAII对象，他们在构造函数中获得资源并在析构函数中释放资源
* 两个常被使用的RAII class分别是trl::shared_ptr和auto_ptr。前者通常是最佳选择，因为其copy行为比较直观。若选择auto_ptr，复制动作会使它指向null。

**item 14: Think carefully about copying behavior in resource-managing classes**

* 复制RAII对象必须一并复制它所管理的资源，所以资源的copying行为决定RAII对象的copying行为
* 普遍而常见的RAIIclass copying行为是：抑制copying，施行引用计数法。

**item 15: Provide access to raw resources in resource-managing classes**

* APIs往往要求访问原始资源，所以每一个RAII class应该提供一个“取得其所管理之资源”的办法
* 对原始资源的访问可能经由显示转换或隐士转换。一般而言显示转换比较安全，但隐士转换对客比较方便

**item 16: Use the same form in corresponding uses of new and delete**

**item 17: Store newed objects in smart pointers in standalone statements**

* 以独立语句将newed对象置于智能指针内。如果不这样做，一旦异常被抛出，有可能导致难以察觉的资源泄露

## 4 设计与声明

**item 18: Make interfaces easy to use correctly and hard to use incorrecty**

**item 19: Treat class design as type design**

* class的设计就是type的设计。在定义一个新type之前，请确定你已经考虑过本条款覆盖的所有讨论的主题

**item 20: Prefer pass-by-reference-to-const to pass-by-value**

* 尽量以pass-by-reference-to-const替换pass-by-value。前者通常比较高效，并可避免切割问题
* 以上规则并不适用于内置类型，以及STL的迭代器和函数对象。对它们而言pass-by-value往往比较适当

**Don't try to return a reference when you must return an object**

* 绝不要返回pointer或reference指向一个local stack对象，或返回reference指向一个heap-allocated对象，或返回pointer或reference指向一个local static对象而有可能同时需要多个这样的对象。

**item 22: Declare data members private**

* 切记将成员变量声明为private。这可赋予客户访问数据一致性、可细微划分访问控制、允诺约束条件获得保证，并提供class作者以充分的实现弹性。
* protected并不比public更具封装性

**item 23: Prefer non-member, non-friend functions to member functions**

* 宁可拿non-member non-friend函数替换member函数。这样做可以增加封装性、包裹弹性和机能扩张性

**item 24: 若所有参数皆需要类型转换，请为此采用non-member函数**

* 如果你需要为某个函数的所有参数（包括this指针所指的那个隐喻参数）进行类型转换，那么这个函数必须是个non-member

**item 25：考虑写出一个不抛异常的swap函数**


## 5 实现

**item 26：尽可能延后变量定义式的出现时间**

* 尽可能延后变量定义式的出现。这样做可增加程序的清晰度并改善程序效率

**item 27: 尽量少做转型动作**

* 如果可以，尽量避免转型，特别是在注重效率的代码中避免dynamic_cast。如果有个设计需要转型动作，试着发展无需转型的替代设计
* 如果转型是必要的，试着将它隐于某个函数背后。客户随后可以调用该函数，而不需要将转型放进他们自己的代码内。
* 宁可使用C++style（新式）转型，不要使用旧式转型。前者很容易便是出来，而且也比较有着分门别类的执掌

**item 28: 避免返回handles指向对象内部成分**

* 避免返回handles（包括reference，指针，迭代器）指向对象内部。遵守这个条款可增加封装性，帮助const成员函数的行为像个const，并将发生dangling handles的可能性降至最低

**item 29: 为”异常安全“而努力是值得的**

* 异常安全函数即使发生异常也不会泄露资源或允许任何数据结构败坏。这样的函数可分为三种可能的保证：基本型，强烈型，不抛异常型
* ”强烈保证“往往能够以copy-and-swap实现出来，但”强烈“并非对所有函数都可实现或具备显示意义
* 函数提供的”异常安全“通常最高只等于其所调用之各个函数的”异常安全保证”中的最弱者

**item 30: 透彻了解inlining的里里外外**

* 将大多数inlining限制在小型、被频繁调用的函数身上。这可使日后的调试过程和二进制升级更容易，也可使潜在的代码膨胀问题最小化，使程序的速度提升机会最大化
* 不要只因为function templates出现在头文件，就将它们声明为inline。

**item 30: 将文件间的编译依存关系降至最低**








