# include<iostream>
# include<vector>
using namespace std;

int main(void){
    // 动态数组的创建
    vector<int> arr; // 堆上创建一个动态数组, 通过指针进行管理, 动态数组名称为v
    
    // 动态数组的基本函数
    size_t size = arr.size(); // 获取动态数组的长度(size_t类型)
    cout << "arr.size() = " << size << endl; // 0
    cout << "arr.empty() = " << arr.empty() << endl; // 1
    
    // 元素添加 & 访问
    arr.push_back(1); // FIFO的Queue
    cout << "arr[0] = " << arr[0] << endl;

    // 动态数组扩容 & 查看容量
    arr.reserve(10);
    cout << "arr.capacity() = " << arr.capacity() << endl;
    // 此时如果访问arr[1]会直接报错: Assertion '__n < this->size()' failed.

    return 0;
}