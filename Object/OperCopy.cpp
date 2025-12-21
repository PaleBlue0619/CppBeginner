# include<iostream>
# include<string>
using namespace std;

class OperCopy{
    public:
        int a;
        double b;
        string c;
        int* ptr;
        // 默认构造函数
        OperCopy(void){
            a = 0;
            b = 0.0;
            c = "";
            ptr = new int[a];
        };

        // 带参构造函数
        OperCopy(int a,double b,string c){
            this->a = a;
            this->b = b;
            this->c = c;
            ptr = new int[a];
        };

        // 深拷贝函数（this指针）
        OperCopy copyFunc(OperCopy& obj){
            a = obj.a;
            b = obj.b;
            c = obj.c;
            ptr = new int[a];
            for(int i = 0; i < a; i++){
                ptr[i] = obj.ptr[i];
            }
            return *this; // 返回对象本身
        };

        // 赋值操作符
        OperCopy& operator=(const OperCopy& obj);

        // 析构函数
        ~OperCopy(){
            delete[] ptr;
        };
};

int main(void){
    OperCopy obj1(5,5.5,"hello");
    OperCopy obj2;
    obj2 = obj1; // 此时调用赋值操作符
    return 0;
}