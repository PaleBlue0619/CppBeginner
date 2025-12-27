# include<iostream>
# include<vector>
using namespace std;

int main(void){
    // 创建字符串
    string s = "Hello World!";
    string t = "Akihabara";
    
    // 基本函数
    cout << s.size() << endl; // 字符串长度
    cout << s.empty() << endl; // 是否为空字符串
    cout << s.substr(0, 5) << endl; // 截取子字符串
    cout << s.find("World") << endl; // 查找是否有子串
    cout << s.replace(0, 5, "Nice") << endl; // 替换字符串
    return 0;
}