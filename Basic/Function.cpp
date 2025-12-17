#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T, typename U>
// 使用T作为C++的模板类型, 用于接收<>中的多个传入类型
bool isEqual(const T& a, const U& b){
    return a == b;
}

// recursive function
/* 欧几里得法求解最大公约数 */
int Euclid(int m, int n){
    if (n == 0){ return m;}
    if (n == 1){ return 1;}
    return Euclid(n, m % n);
}

int main(void){
    // Function 
    /* 1. Template Usage (Java's Generics)*/
    int obj1 = 1;
    double obj2 = 1.0;
    std::cout << "是否相等: "+std::to_string(isEqual(obj1, obj2)) << std::endl;

    /* 2. Recursive Function */
    std::cout << "最大公约数为: "+std::to_string(Euclid(15360, 90)) << std::endl;
    return 0;
}