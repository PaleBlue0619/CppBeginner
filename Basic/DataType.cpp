#include <iostream>
#include <cstdio> 
#include <tuple>
#include <cstdlib>  // 添加system函数支持
using namespace std;
int getType(void){
    /* 数据类型 */
    auto iTuple = std::tuple<int, float>(2.0, 1);
    auto iList = std::initializer_list<int>{1, 2, 3, 4, 5};
    
    // 空指针常量
    int a = 2025;
    int* ptr = nullptr;
    ptr = &a;
    int arr[5] = {1, 2, 3, 4, 5};
    int* arrPtr = &arr[0];

    // C++中类似Java的行为要用指针
    int* ptr1 = new int(100);
    int* ptr2 = ptr1;  // ptr2指向同一个内存
    ptr2 = nullptr;  // 可以设为空
    ptr2 = new int(200);  // 可以指向新内存
    return 0;
}

void modifyByReferece(int& num){
    /* 引用参数: 可以直接修改原始对象 */
    num = 100; // 直接修改原始变量
};

void modifyByPointer(int* num){
    /* 指针参数: 需要解引用 */
    if (num){ // 检查是否为空指针
        *num = 100; // 解引用后修改
    }
}

void modifyByValue(int num){
    /* 值传递: 创建变量的副本 */
    num = 100; 
}

int transfer(void){
    /* 类型引用与传递 */
    int a = 1;
    int* ptr = &a; // 创建指针
    int& b = a; // 创建引用(别名)
    int c = a; // 创建副本
    int d = *ptr; // 通过指针传递值(解引用)
    /* 
    此时: 
    a: int
    b: int: a的别名
    c: int: a的副本
    ptr: 指针 → a
    d: 通过指针加解引用 → ptr → a:int 
    */

    b = 222;
    c = 333;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    cout << "c=" << c << endl;
    cout << flush;  // 刷新输出缓冲区
    return 0;
}

int transform(void){
    /* 类型转换 */
    int a = 1;
    float b = (float) a;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    cout << flush;

    int i = static_cast<int> (b);
    cout << "i=" << i << endl;
    cout << flush;
    return 0;
}


int main(void){
    int res = getType();
    int res1 = transfer();
    int res2 = transform(); 
    return 0;
}