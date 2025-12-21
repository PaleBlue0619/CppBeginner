#include<iostream>
#include<string>
using namespace std;

struct Origin{
    public:
    int param0;
    double param1;
    string param2;

    Origin() {cout << "Origin()" << endl;}; // 默认构造函数
    Origin(int param_0, double param_1): 
        param0(param_0), param1(param_1){ // 初始化带参构造函数（参数数量=2）
            cout << "Origin(" << param_0 << ", " << param_1 << ")" << endl;
    }

    Origin(int param_0, double param_1, string param_2):
        param0(param_0), param1(param_1), param2(param_2){ // 初始化带参构造函数（参数数量=3）
        cout << "Origin(" << param_0 << ", " << param_1 << ", " << param_2 << ")" << endl;
    }
    
    ~Origin() {cout << "~Origin()" << endl;}; // 析构函数
};

struct staticVar{
    static int a;
    int b;
    double c;
    staticVar(double k){ // 初始化方式
        this->a++;
        b = a;
        c = k;
    }
};
int staticVar::a = 0; // 静态变量必须在类外赋值（链接器要求）

int main(void){
    // 初始化构造函数
    Origin ori = Origin(1, 2.0, "3"); // 栈上初始化对象
    Origin *oriPtr = new Origin(1, 2.0); // 堆上初始化对象
    Origin *arrOri = new Origin[5]; // 堆上初始化对象数组
    delete oriPtr;  // 释放对象 -> 调用析构函数
    delete [] arrOri; // 释放堆上对象数组 -> 调用析构函数

    // 静态变量初始化
    int iter = 10;
    for (int i = 0; i < iter; i++){
        staticVar s = staticVar(i);
        cout << "a = " << s.a << " b = " << s.b << " c = " << s.c << endl;
    };
    return 0;
}
