# include <string>
# include <iostream>
using namespace std;

/* 
知识点:
和常规的构造函数不一样，C++拷贝构造函数是一种特殊的构造函数，其应用场景主要有以下三个：
1. 由已有对象进行赋值，得到新对象
2. 向函数传递对象类型的参数时候
3. 当函数返回类型为对象的时候 -> 可以newObject(returnObject)进行拷贝
*/

struct Object{
    public:
        string name;
        Object(string nameStr):name(nameStr){
            cout<< "constructor called." << endl;
        } // 构造函数
        Object(const Object& obj):name(obj.name){
            cout<< "copy constructor called." << endl;
        } // 拷贝构造函数
        ~Object(void){ // 析构函数
            cout<< "destructor called." << endl;
        }
        void testFunc(Object obj);
        Object operFunc(Object obj);
};
void Object::testFunc(Object obj){
    cout<< "testFunc called." << endl;
    cout<< "obj.name: " << obj.name << endl;
};

Object Object::operFunc(Object obj){
    cout<< "operFunc called." << endl;
    // Object newObj(obj);
    // newObj.name = "newObj";
    // return newObj;
    obj.name = "newObj";
    cout<< "newObj.name: " << obj.name << endl;
    return obj;
}

int main(void){
    // 1. 场景1: 已有对象赋值得到新对象
    Object obj1("Object1");
    Object obj2(obj1); // 直接调用拷贝函数进行拷贝
    Object obj3 = obj1; // 和上面那种写法等价

    // 2. 场景2：给函数传递对象类型参数的时候
    Object obj4("Object4"); 
    obj4.testFunc(obj2); // 调用testFunc函数 -> 此时会将obj2对象进行拷贝进行传入 -> 但不会影响Object4自身的属性
    cout<< "obj4.name: " << obj4.name << endl; // 输出Object4
    
    // 3. 场景3：函数返回对象类型的时候
    Object newObj = obj4.operFunc(obj2); 
    return 0;
}


