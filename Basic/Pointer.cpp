# include<iostream>
# include<vector>
# include<string>
using namespace std;

int markerCompare(void){
    /* 区分 *与& */
    int yr = 2025;
    int& yrRename = yr; // 引用(别名)
    int yrCopy = yr;    // 拷贝
    int* ptr = &yr;     // &取地址 → 存入int*类型的指针变量
    cout << "original variable value(solve reference): " << *ptr << endl; // 2025
    *ptr += 1;
    cout << "solve reference -> *ptr: " << *ptr << endl; // 2026
    cout << "solve reference -> original variable value: " << yr << endl; // 2026
    return 0;
}

int pointerCal(void){
    /* 指针运算 */
    int k = 10;
    // vector list = std::vector<int> vec(10);

    // 定义堆数组
    int* heapArr_a = new int[k];

    // 数组初始化
    int* heapArr_b = new int[k]{0,0,0,0,0,0,0,0,0,0};
    
    // 访问数组-方式1(通过下标访问)
    for(int i=0; i<k; i++){
        heapArr_a[i] = i;
    }

    // 访问数组-方式2(通过指针运算访问)
    // 指针一开始指向第0个元素，后面指针+整数会导致指针向右移动
    int startIdx = 2;
    heapArr_b = heapArr_b + startIdx; // 指针移动跳过 2 个元素
    for(int i=startIdx+1; i<k; i++){
         *(heapArr_b+i) = *(heapArr_b+i-1)+1;
        // 指针+整数 = 指针指向偏移整数个元素
    }

    // 指针越界问题
    heapArr_a[k]; // 发生指针越界, 报不报错随机

    // 查看结果
    cout << "method-1(index): " << heapArr_a[k-1] << endl;  // 9
    cout << "method-2(pointer): " << heapArr_b[k-1] << endl; // 7 (开头跳过了两个元素)

    // 手动释放内存,避免内存泄露
    delete[] heapArr_a;
    delete[] heapArr_b;
    return 0;
}

int main(void){
    /* 区别&与* 
    &: 引用 -> int& b = a
    &: 取地址 + *: 地址变量类型 -> int* ptr = &a
    *: 解引用 -> *ptr
    */
    markerCompare();

    /* 指针 */
    int a = 1;
    int* ptr = &a;

    /* 解引用 */
    cout << "a=" << *ptr << endl;

    /* 指针运算 */
    pointerCal();

    return 0;
}