# include<iostream>
# include<vector>
using namespace std;

struct Bar{
    public:
        string symbol;
        double open;
        double high;
        double low;
        double close;
        int* ptr = nullptr; // 指针变量
    public:
        // 构造函数
        Bar(){}; // 默认构造函数 -> 这里如果不写会报错
        Bar(string symbol, double open, double high, double low, double close):
            symbol(symbol), open(open), high(high), low(low), close(close){};
        // 拷贝函数(浅拷贝+ptr深拷贝)
        Bar(const Bar &bar):
            symbol(bar.symbol), open(bar.open), high(bar.high), low(bar.low), close(bar.close), ptr(new int(*bar.ptr)){};
        ~Bar(){}; // 析构函数
};


/*
C++ STL 库中的迭代器分为:
正向迭代器begin()&end()，和反向迭代器rbegin()&rend()
*/

int main(void){
    /* Case-1 vector<int> */
    // 初始化动态数组
    int size = 10;
    vector<int> v;
    v.reserve(size);
    for (int i = 0; i < size; i++){
        v.push_back(i*i);
    };

    // 使用正向迭代器遍历动态数组
    // 这里的auto关键字实际上指代的是vector<int>::iterator类型
    for (auto itr = v.begin(); itr != v.end(); itr++){
        *itr -=1; // 数组中的元素赋值
        cout << *itr << endl; // 使用解指针拿到每一个数组中的元素
    };
    // 使用反向迭代器遍历动态数组
    for (auto itr = v.rbegin(); itr != v.rend(); itr++){
        cout << *itr << endl;
    };


    /* Case-2 vector<Object> */
    int objSize = 10;
    vector<Bar> objs(objSize); // 创建vector数组
    // 使用正向迭代器遍历动态数组
    for (auto itr = objs.begin(); itr != objs.end(); itr++){
        *itr = Bar("BTC", 1.0, 2.0, 3.0, 4.0);
    };

    // 使用反向迭代器遍历动态数组
    for (auto itr = objs.rbegin(); itr != objs.rend(); itr++){
        cout << itr->symbol << endl;
    }; 

    /* Case-3 范围for循环 ->类似Java中的增强for循环 */
    for (auto &obj : objs){ // 引用循环 -> 修改obj中的元素会影响objs
        obj.symbol = "AAPL";
        cout << obj.symbol << endl;
    };
    for (auto obj : objs){ // 拷贝循环 -> 修改obj中的元素不会影响objs
        cout << obj.symbol << endl;
    };

    return 0;
}