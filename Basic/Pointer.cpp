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
        *(heapArr_b + i) = i;
        // 指针+整数 = 指针指向偏移整数个元素
    }

    // 指针越界问题
    heapArr_a[k]; // 发生指针越界, 报不报错随机

    // 查看结果
    cout << "method-1(index): " << heapArr_a[k-1] << endl;  // 9
    cout << "method-2(pointer): " << heapArr_b[k-1] << endl; // 7 (开头跳过了两个元素)

    // 手动释放内存,避免内存泄露
    delete[] heapArr_a;
    // delete[] heapArr_b;
    return 0;
};

void func(int* p){
    // 指针解引用
    cout << "p=" << *p << endl; 
    // 重新赋值
    *p = 100.0;
};

void arrFunc(int* p, int size){
    // 数组元素指针解引用
    for (int i=0; i<size; i++){
        p[i] = i * i; // 重新赋值  - 方式1
        *p = i * i; // 重新赋值 - 方式2
        p = p + 1;
    };
};

void pointerTransfer(void){
    /* 函数指针传递
    1. 将变量的地址（指针）传递给函数
    2. 传递数组首元素地址
    */
    
    // 将变量的地址（指针）传递给参数
    int a = 1;
    int* p = &a; // 指针存储地址
    func(p);
    cout << "a=" << a << endl; // 100

    // 传递数组首元素地址
    int* arr = new int[4] {0, 1, 2, 3}; // 堆上开辟数组
    // 获取数组首元素地址
    int* ptr = arr; // 首元素的指针
    cout << "ptr=" << *ptr << endl;
    arrFunc(arr, 4);
    // 查看修改后的堆上数组
    cout << "arr=" << arr[0] << arr[1] << arr[2] << arr[3] << endl;
    delete[] arr;
};

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

    /* 函数指针传递 */
    pointerTransfer();

    return 0;
}