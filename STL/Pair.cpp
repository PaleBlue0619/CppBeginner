#include <iostream>
#include <utility> // 使用std::pair需要引入头文件utility
using namespace std;

int main(void){
    pair<int, string> myPair;
    myPair.first = 10;
    myPair.second = "Hello World";
    cout << myPair.first << " " << myPair.second;
}