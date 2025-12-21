# include <string>
# include <iostream>
using namespace std;

/* 
知识点:
1. class 与 struct的唯一区别: class(成员默认private) struct(成员默认public)
2. const 关键字的作用: 在const成员函数中, 类的任何成员变量不可修改
*/

/* 定义类-方式1:struct */
struct Student{
    long long userId;
    string name;
    int age; 

    // C++ 与 Java 相同, 允许类有多个构造函数
    Student(){cout << "default Constructor Function of Student" << endl;}; // 无参构造函数(若没有定义, 编译器会默认合成一个构造函数)
    Student(long long userIdInt, string nameStr, int ageInt){
        userId = userIdInt;
        name = nameStr;
        age = ageInt;
        cout << "Constructor Function of Student" << endl;
    }; // 带参构造函数
    // 析构函数(当对象被销毁时自动调用 编译器自动判断这个对象的生命周期)
    ~Student(){cout << "Destructor Functions of Student" << endl;}; 
};

struct Teacher{
    /* 采用Java的方式进行类的构造: 即成员变量与成员方法分离 */
    public: // 公有成员变量
        string name;
        int age;
    private: // 私有成员变量
        long long sbPoint;
    public: // 公有成员方法
        Teacher(){cout << "default Constructor Function of Teacher" << endl;};
        Teacher(string nameStr, int ageInt, long long sbPointInt){
            name = nameStr;
            age = ageInt;
            sbPoint = sbPointInt;
            cout << "Constructor Function of Teacher" << endl;
        };
        ~Teacher(){cout << "Destructor Functions of Teacher" << endl;};
        string getName(void) const{
            return name;
        }
        void setName(string nameStr){
            name = nameStr;
        }
        long getAge(void) const{
            return age;
        }
        void setAge(int ageInt){
            age = ageInt;
        }
        /* 如果成员函数太长 -> 可以用作用域操作符将其挪至类外部 */
        long long getSbPoint(void) const;
        void setSbPoint(long long);
    private: // 私有成员方法
        long long getSbPointPrivate(void) const{
            return sbPoint;
        }
        void setSbPointPrivate(long long sbPointInt){
            sbPoint = sbPointInt;
        }
};

/* 作用域操作符 */
long long Teacher::getSbPoint(void) const{
    return sbPoint;
}
void Teacher::setSbPoint(long long sbPointInt){
    sbPoint = sbPointInt;
}

/* 定义类-方式2:class */
// class 与 struct 的唯一区别:——默认情况下:
// · class的成员变量&方法是private私有的
// · struct的成员变量&方法是public的！
class People{
    private: 
        long long sbPoint;
    public:
        string name;
        int age;
        People(){cout << "default Constructor Function of People" << endl;};
        People(string nameStr, int ageInt){
            name = nameStr;
            age = ageInt;
            cout << "Constructor Function of People" << endl;
        };
        ~People(){cout << "Destructor Functions of People" << endl;};
};
int main(void){
    /* 1. 单一对象创建*/
    // 通过类初始化对象(栈上)
    Student stuObj0(42019004, "Maxim", 18);
    Student stuObj1;
    Teacher zwgObj("MASHUZHONG", -1, 99999999);
    // 类赋值(C++中允许一整个类中每一个成员变量对另外相同类中的对应成员变量赋值)
    stuObj1 = stuObj0; // 赋值完之后, 此时stuObj0 与 stuObj1 两个对象之间依然独立！
    // 查看变量属性
    cout << "Student name: " << stuObj1.name << endl; 
    cout << "Student age: " << stuObj1.age << endl;
    cout << "Teacher name: " << zwgObj.name << endl;
    cout << "sbPoint: " << zwgObj.getSbPoint() << endl;

    /* 2. 堆上对象创建 */
    Teacher* p = new Teacher("ZHAOWEIGUO", -1, 99999999);
    // 堆上对象赋值
    p->age = 50;
    p->setSbPoint(99999999);
    // 查看堆上对象属性
    cout << "Teacher name: " << p->name << endl;
    cout << "Teacher age: " << p->getAge() << endl;
    cout << "Teacher sbPoint: " << p->getSbPoint() << endl;
    delete p;
    p = nullptr;

    /* 3. 堆上数组对象创建 */
    int arrSize = 5;
    Teacher *tchArr = new Teacher[arrSize];
    for (int i = 0; i < arrSize; i++){
        // 堆上数组对象赋值
        tchArr[i].setSbPoint(i * 10000);
        tchArr[i].name = "MASHUZHONG";
        tchArr[i].age = 58;
    };
    for (int i = 0; i < arrSize; i++){
        // 查看堆上数组对象属性
        cout << "Teacher name: " << tchArr[i].name << endl;
        cout << "Teacher age: " << tchArr[i].getAge() << endl;
        cout << "Teacher sbPoint: " << tchArr[i].getSbPoint() << endl;
        cout << endl;
    };
    delete[] tchArr;

    return 0;
}
