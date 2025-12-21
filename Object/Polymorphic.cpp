/* 多态的使用条件
1. 基类提供虚函数
2. 派生类覆盖基类的虚函数
3. 通过基类指针（或引用）访问各派生类对象;
*/

#include <iostream>
#include <vector>
#include <string>
#include <variant> // C++ 变体(用于储存所有可能出现的类型)
using namespace std;

// variant + std::visit 实现多态
// 1. 函数的多态
struct Printer{
    Printer() = default;
    void operator()(int i) const {std::cout << "int: " << i << std::endl;}
    void operator()(float f) const {std::cout << "float: " << f << std::endl;}
    void operator()(string s) const {std::cout << "string: " << s << std::endl;}
};
void func_variant(void){
    // 测试函数 for 函数的多态
    std::variant<int, float, string> var;   
    var = 1;
    std::visit(Printer(), var);
    var = 0.9f;
    std::visit(Printer(), var);
    var = "hello variant!";
    std::visit(Printer(), var);
}

// 2.类的多态
struct classA{
    public:
    void func(int i) const {cout<< "classA: int: " << i << endl;};
};
struct classB{
    public:
    void func(float f) const {cout<< "classB: float: " << f << endl;};
};
struct classAB{
    public:
    int value;
    void operator()(const classA& a){ a.func(value);}; // 常量引用
    void operator()(const classB& b){ b.func(value);};  
};
void class_variant(void){
    // 测试函数 for 类的多态
    std::variant<classA, classB> var;
    var = classA();
    std::visit(classAB(), var);
    var = classB();
    std::visit(classAB(), var);
}


// 2.直接使用virtual + override 实现多态
struct Ishape{
    // 多态的条件1: 基类提供虚函数   
    virtual double calArea(void) const = 0;  
    // virtual void calArea() const; // =0表示纯虚函数, 用于禁止直接创建IShape的对象 
    virtual ~Ishape(){}; // 析构函数(虚函数)
};

struct Circle: public Ishape{
    // 多态的条件2: 派生类覆盖基类的虚函数
    public:
    double radius; 
    double calArea(void) const override{
        cout << "Circle" << endl;
        return 3.14 * radius * radius;
    }
};

struct Rectangle: public Ishape{
    public:
        double height; 
        double length;
    double calArea(void) const override{
        cout << "Rectangle" << endl;
        return height * length / 2;  
    };
};

int main(void){
    // 方式1: C++17 使用 std::variant 变体实现多态
    // 1.1 函数的多态
    func_variant();
    /* 最终输出: 
    int: 1
    float: 0.9
    string: hello variant!
    */
   
    // 1.2 类的多态
    class_variant();
    /* 最终输出:
    classA: int: 0
    classB: float: 0
    */

    // 方式2: 直接使用virtual + override 实现多态
    // 初始化对象
    Circle circle;
    circle.radius = 1.0;
    Rectangle rectangle;
    rectangle.height = 1.0;
    rectangle.length = 1.0;
    // 创建一个数组对象, 将上面的所有形状的对象均存放进去
    vector<Ishape*> shapes;
    shapes.push_back(&circle);
    shapes.push_back(&rectangle);
    for (int i = 0; i < shapes.size(); i++){
        cout << shapes[i]->calArea() << endl;
    }
    /* 最终输出:
    Circle
    3.14
    Rectangle
    0.5
    */
    return 0;
}