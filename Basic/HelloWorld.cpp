#include <iostream>
using namespace std;

int main() {
    /* I/O */ 
    cout << "Hello, World!" << endl;

    /* Basic DataType */
    double var0 = 1.0;
    long long var1 = 1000000000;

    return 0;
}

class myClass{
    // 空参构造函数
    myClass() = default;
    // 成员函数声明
    int func(int a, int b);
};

// 具体内容
int myClass::func(int a, int b){
    #include <cmath> // 高性能数值类型
    return a + b;
};
