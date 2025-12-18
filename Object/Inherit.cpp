#include<iostream>
#include<string>
using namespace std;

class Country{ // 父类-1 // 这里可以用struct, 也可以用class
    public:
        string name;
    private:
        double sbPoint;
    public:
        void func(void){cout << "Base Function1" << endl;};
        void setName(string nameStr);
        double getSbPoint(void) const;
        void setSbPoint(double sbPointDouble);
};
void Country::setName(string nameStr){name = nameStr;};
double Country::getSbPoint(void) const{return sbPoint;};
void Country::setSbPoint(double sbPointDouble){sbPoint = sbPointDouble;};

struct People{ // 父类-2 // 这里可以用struct, 也可以用class
    public:
        int num;
    public:
        int func(void){cout << "Base Function2" << endl;};
        int getNum(void) const {return num;};
        void setNum(int numInt){num = numInt;}; 
};

// 子类继承父类(C++允许多继承)
struct China : public Country, public People{ // 这里可以用class, 也可以用struct
    public:
        int func(void){
            cout << "Derived Function" << endl;
            return 0;
        };
};

int main(void){
    /* 初始化对象*/
    Country nation; // 父类-1
    nation.setSbPoint(20.0);
    nation.setName("USA");

    People human; // 父类-2
    human.setNum(10000000);

    China chn; // 子类(同时继承父类-1 & 父类-2)
    chn.setSbPoint(0.0);
    chn.setName("China");

    /* 分别调用父类&子类的同名方法 */
    nation.func(); // Base Function1
    human.func();   // Base Function2
    chn.func();     // Derived Function
    return 0;
}