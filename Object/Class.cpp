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
};

struct Teacher{
    /* 采用Java的方式进行类的构造: 即成员变量与成员方法分离 */
    public: // 公有成员变量
        string name;
        int age;
    private: // 私有成员变量
        long long sbPoint;
    public: // 公有成员方法
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
};


int main(void){
    // 通过类初始化对象
    Student stuObj0;
    Student stuObj1;
    Teacher zwgObj;

    // 成员变量赋值
    stuObj0.userId = 42019004;
    stuObj0.name = "Maxim";
    stuObj0.age = 18;
    // 类赋值(C++中允许一整个类中每一个成员变量对另外相同类中的对应成员变量赋值)
    stuObj1 = stuObj0; // 赋值完之后, 此时stuObj0 与 stuObj1 两个对象之间依然独立！
    zwgObj.name = "MASHUZHONG";
    zwgObj.age = -1;
    zwgObj.setSbPoint(99999999);

    // 查看变量属性
    cout << "Student name: " << stuObj1.name << endl; 
    cout << "Student age: " << stuObj1.age << endl;
    cout << "Teacher name: " << zwgObj.name << endl;
    cout << "sbPoint: " << zwgObj.getSbPoint() << endl;
    return 0;
}
