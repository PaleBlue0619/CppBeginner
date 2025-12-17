#include <iostream>
#include <cstdio> 
#include <tuple>
#include <cstdlib>  // 添加system函数支持
using namespace std;


namespace X{
    void start(void){
        cout << "nameSpace of X's start func" << endl;
    };
    void end(void){
        cout << "nameSpace of X's end func" << endl;
    }
};

namespace Y{
    void start(void){
        cout << "nameSpace of Y's start func" << endl;
    };
    void end(void){
        cout << "nameSpace of Y's end func" << endl;
    }
};

int main(void){
    /* 调用方式1: namespace::func的方式进行调用 */
    X::start();
    Y::end();

    /* 调用方式2: using namespace xxx;进行调用 */
    using namespace X;
    start();
    end();

    /* Example */
    std::cout << "Hello World!" << std::endl;
    using namespace std; // 使用std标准模板库
    cout << "Hello World! (by Using Std NameSpace)" << endl;
    return 0;
}