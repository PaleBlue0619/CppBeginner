# include<iostream>
# include<functional>
# include<string>
# include<map>
using namespace std;

template<typename T>
class divide{
    public:
        T operator()(T a, T b){return a/b;}; // operator()关键字 -> 让对象可以像函数一样被调用
};

template<typename T>
class compare{
    public:
        bool operator()(T a, T b){return a>b;};
};

template<typename T>
class calculate{
    public: 
        map<string, function<T(T,T)>> binary_operators;
};

int main(void){
    /* function可以与lambda表达式配合使用 */
    function<int(int,int)> sum = [](int a,int b){return a+b;};
    cout << sum(1,2) << endl;

    /* 复杂的使用案例 */
    // 初始化对象
    calculate<int> calc;
    // 使用lambda表达式定义函数
    auto mod = [](int a,int b){return a%b;};
    // 向对象中注册函数
    calc.binary_operators.insert(std::make_pair("+", [](int a,int b){return a+b;}));
    calc.binary_operators.insert(std::make_pair("-", [](int a,int b){return a-b;}));
    calc.binary_operators.insert(std::make_pair("*", [](int a,int b){return a*b;}));
    calc.binary_operators.insert(std::make_pair("/", divide<int>()));  // 修正：创建类的实例
    calc.binary_operators.insert(std::make_pair("%", mod));

    // 调用函数
    cout << calc.binary_operators["+"](10,2) << endl;
    cout << calc.binary_operators["-"](10,2) << endl;
    cout << calc.binary_operators["/"](10,2) << endl;
    cout << calc.binary_operators["%"](10,2) << endl;
    cout << calc.binary_operators["*"](10,2) << endl;
    return 0;
}