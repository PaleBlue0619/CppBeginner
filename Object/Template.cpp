#include<iostream>
using namespace std;

// 模板类: 在类之前的头标识, 用于为类添加泛型 -> 实际类型只需要在需要的时候进行指定
// 功能: 解决成员函数相同但数据类型不同的代码复用问题
template<typename T1, typename T2>
struct Template{
    public:
        T1 type1;
        T2 type2;
        Template(){}; // 构造函数
        Template(T1 a, T2 b){
            type1 = a;
            type2 = b;
        };
        ~Template(){}; // 析构函数
        void add(T1 a, T2 b){
            cout << a + b << endl; 
        }
};

int main(void){
    Template<int, double> t1;
    t1.add(1, 1.1); // 2.1
    return 0;
}