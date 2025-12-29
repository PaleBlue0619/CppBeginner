# include<iostream>
# include<memory> // 引入智能指针
# include<list>
# include<vector>
# include<string>
using namespace std;

// 简单函数中使用shared_ptr智能指针
void g(void){
    shared_ptr<int> ptr = make_shared<int>(); // 手动申请一个堆上的无名变量，交给智能指针管理
    int b; 
    // 这里无需手动释放ptr指向的内存, ptr的析构函数会自动释放
}
void f(void){
    int x, y;
    g();
}

// 在类对象中使用shared_ptr智能指针
struct Object{
    public:
        string name;
        shared_ptr<int> ptr;
        Object(){};
        Object(const string &name): name(name){
            ptr = make_shared<int>(); // 手动申请一个堆上的无名变量，交给智能指针管理
        }
        ~Object(){cout << "Obj "+name+"'s destructor function maked call."<< endl;}
};

int main(void){
    /* 函数中使用shared_ptr 智能指针*/
    f();

    /* 类对象中使用shared_ptr 智能指针*/
    // 1. 创建一个对象
    shared_ptr<Object> obj = make_shared<Object>("ObjectName");
    cout << "Object name: " << obj->name << endl;
    
    // 2. 创建多个对象
    shared_ptr<list<Object>> objList = make_shared<list<Object>>();
    for(int i = 0; i < 5; i++){
        shared_ptr<Object> obj = make_shared<Object>(to_string(i));
        objList->push_back(*obj);
    }
    return 0;
}