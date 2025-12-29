# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;

int main(void){
    /* lambda 表达式相较于函数的优势在于:
    函数不能定义在别的函数内部, 而lambda表达式可以
    lambda表达式的格式:2
    [capture list] (param list) -> returnType {function body}
    · capture list: 当前作用域中的变量名称(可以是对象副本/对象引用)
    · param list: 函数参数列表, 用,隔开
    · returnType: 函数返回值类型
    · function body: 函数主体 
    */
    int a = 1;
    auto func = [&a](int b, int c) -> int {
        a = a-1;
        return a+b+c;};
    cout << func(2,3) << endl; // 5
    cout << a << endl; // 0

    // 稍微复杂的应用 -> 函数排序
    vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
    auto sortFunc = [](int a, int b) -> bool {return a>b;}; // 倒序排序lambda函数
    std::sort(vec.begin(), vec.end(), sortFunc);
    for (auto itr = vec.begin(); itr != vec.end(); itr++){
        cout << *itr << endl;
    }
    return 0;
};