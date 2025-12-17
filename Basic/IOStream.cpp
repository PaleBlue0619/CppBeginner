#include <iostream>
#include <string>
using namespace std;

int wordFromKeyBoard(void){
    string input;
    cin >> input; 
    std::cin.ignore(); // 忽略换行符
    cout << input << endl;
    // cout << flush;
    return 0;
};

int lineFromKeyBoard(void){
    cout << "please input 2 lines:" << endl;
    string line;
    getline(cin, line);
    //这里程序等待你手动输入一行，按回车键结束这一行的输入
    cout << "your first input line is:" << line << endl;
    getline(cin, line);
    //这里程序等待你手动输入一行，按回车键结束这一行的输入
    cout << "your second input line is:" << line << endl;
    return 0;
}

int main(void){
    wordFromKeyBoard();
    lineFromKeyBoard();
    return 0;
};