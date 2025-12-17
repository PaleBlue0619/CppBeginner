#include <iostream>
#include <string>
using namespace std;
 
int main(void){
    int a = 3;
    int b = 4;

    // 关系运算
    bool c = a > b;
    cout << boolalpha << c << endl;
    c = a > b || a != 0;
    cout << c << endl;
 
    // 字符相等
    char d = '%';
    bool is_char_equal = (d == '%');
    cout << "is char equal ? " << is_char_equal << endl;
 
    //字符串相等
    string str("abcdefg123456");
    bool is_str_equal = (str == "abcdefg123456");
    cout << "is string equal ? " << is_str_equal << endl;
    return 0;
}