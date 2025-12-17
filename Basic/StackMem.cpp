#include <iostream>
#include <string>
#include <vector>
using namespace std;

void g(void){ // Step3.
    std::cout << "g入栈" << std::endl;
    int a;
    int b;
}   // Step4.
void f(void){ // Step2.
    std::cout << "f入栈" << std::endl;
    int x = 1;
    int y = 2;
    g();  // 在栈中创建g()函数 -> 先执行为g函数中的变量创建内存, 再执行
} // Step5.
int main(void){
    /*  可以通过地址变量（指针变量）存放变量的地址 */
    int* p = new int{123};
    cout << *p << endl;
    // stack Memory 栈区Memory -> 先执行最里面的函数, 再往外执行
    f();  // Step1.
    return 0;
} // Step6.