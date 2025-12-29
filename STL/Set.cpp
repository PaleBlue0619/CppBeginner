# include<set>
# include<iostream>
using namespace std;

int main(void){
    set<int> s{1,2,3,4};
    s.insert(5); // 新增元素
    s.find(3); // 查询函数
    for (auto itr=s.begin();itr!=s.end();itr++){
        cout<<*itr<<endl;
    } // 遍历迭代
    s.erase(s.begin()); // 删除元素
    cout << s.size() << endl; // 获取元素个数
    cout << s.empty() << endl; // 判断是否为空
    return 0;
}