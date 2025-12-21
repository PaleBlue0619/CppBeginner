# include<string>
# include<iostream>
using namespace std;

class DeepCopy{
    // 当指针变量作为成员变量出现的时候, 这个类就是非平凡的类
    public:
    int a;
    double b;
    string c;
    int* ptr;

    public:
    // 浅拷贝(基本数据类型)
    DeepCopy(int a, double b, string c):
        a(a), b(b), c(c){
        cout << "Simple Constructor" << endl;
    };

    // 深拷贝(指针类型)
    DeepCopy(int a, double b, string c, int* ptr): 
        a(a), b(b), c(c), ptr(new int(*ptr)){
        cout << "Constructor with pointer" << endl;
    }
};

DeepCopy objFunc(DeepCopy obj){
    // 对象为形参 + 对象为返回类型的函数
    cout << "Inside objFunc" << endl;
    *obj.ptr += 1;
    return obj;
}

int main(){
    // 与浅拷贝相同, 深拷贝有以下三种应用场景
    // 1. 用一个对象构造另一个对象
    int x = 2025;
    int* ptr = &x;
    DeepCopy obj1(1, 2.0, "hello", ptr);
    DeepCopy obj2(obj1);

    // 2. 函数传对象类型的形参
    objFunc(obj1);
    cout << "obj1.ptr: " << *obj1.ptr << endl;  // 2026 (指针深拷贝)

    // 3. 函数返回值为对象类型
    DeepCopy obj3 = objFunc(obj1);
    cout << "obj3.ptr: " << *obj3.ptr << endl; // 2027 (指针深拷贝)
}