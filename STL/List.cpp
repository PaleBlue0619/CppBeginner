# include<iostream>
# include<list>
using namespace std;

int main(void){
    // 链表list的创建
    list<int> l;

    /* 增删改查函数 */
    // 增函数
    l.push_back(1);
    cout << l.size() << endl; // 1
    l.resize(5); // 链表扩容函数
    cout << l.size() << endl; // 5 -> 此时为[1 0 0 0 0]
    list<int> l1 = {1,3,5};
    l.insert(l.end(), l1.begin(), l1.end()); // 将l1插入到l的末尾

    // 查函数
    cout << l.front() << endl; // 访问第一个元素
    cout << l.back() << endl; // 访问最后一个元素
    cout << l.empty() << endl;  // 判断链表是否为空
    cout << l.size() << endl;    // 当前长度
    // cout << l.max_size() << endl; // 最大长度 -> 会输出天文数字

    // 改函数
    l.assign(5, 1); // 赋值函数

    // 删函数
    l.pop_front();
    l.pop_back();
    l.erase(l.begin());
    for (auto &i: l){
        cout << i << endl;
    }
    l.erase(l.begin(), l.end()); // 等于直接清空.clear()
    return 0;
}