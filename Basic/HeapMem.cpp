#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* 
内存泄露: 堆上的内存忘记释放，一直占用的情况
*/
void g(void){ // Step3.
    int* a = new int; // 返回一个堆空间(new 创建的变量)上的无名变量的地址
    int* b = a; // 地址变量赋值: a和b存储的内容相同, 均为堆上无名变量的地址值
    delete a; // 释放栈a所指向的无名变量 -> 此时不存在内存泄露 // Step 4.
    a = nullptr; // 地址变量赋值为空
    if (b == nullptr){
        cout << "b is nullptr" << endl;
    }else{
        cout << "b is not nullptr" << endl;
    }
}
void f(void){ // Step2.
    int x;
    int y;
    g();  // Step3.
}

int main(void){ // Step1.
    f(); 
    return 0;
} // Step6.