# include<iostream>
# include<fstream> // for 输入输出文件流
# include<sstream> // for 输入输出字节流
# include<string>
using namespace std;

/* Case-1: 从文件中读取一行文字  */
int wordFromKeyBoard(void){
    string input;
    cin >> input; 
    std::cin.ignore(); // 忽略换行符
    cout << input << endl;
    // cout << flush;
    return 0;
};
int lineFromKeyBoard(void){
    cout << "please input 2 lines:" << endl;
    string line;
    getline(cin, line);
    //这里程序等待你手动输入一行，按回车键结束这一行的输入
    cout << "your first input line is:" << line << endl;
    getline(cin, line);
    //这里程序等待你手动输入一行，按回车键结束这一行的输入
    cout << "your second input line is:" << line << endl;
    return 0;
};

/* Case-2: 从文件中读取变量 */
template <typename T>
void writeVarToFile(T obj){
    ofstream file("data.txt"); // 创建data.txt
    if (!file.is_open()){
        cout << "file open failed" << endl;
    };
    file << obj; // <<: 输出流
};
template <typename T>
T readVarFromFile(string filePath){
    ifstream file(filePath);
    if (!file.is_open()){
        cout << "file open failed" << endl;
        return T();
    };
    T obj;
    file >> obj; // >>: 输入流
    cout << obj << endl;
    return obj;
}

/* Case-3: 读取字节流数据 & 将字节流写入缓冲区 */
template <typename T>
void writeBytesToBuffer(T obj){
    // 创建字符串数据
    T data(obj);
    
    // 创建一个istringstream 对象, 用字符串数据初始化
    istringstream issObj(data);
    int age; 
    string name;
    
    // 从字符流中读取数据并赋值到变量
    issObj >> age >> name;
    cout << "age:" << age << " name:" << name << endl;
}
void readBytesFromBuffer(void){
    /* 
    本质上和 cout << << endl 没什么区别...
    就是中间用ostringstream对象接了一下
    */
    // 初始化一个ostringstream对象，准备存储外部数据
    ostringstream osObj;

    // 外部数据写入字符串流中
    string name("Maxim");
    int age = 23;
    osObj << age << " " << name << endl;

    // 通过.str()成员函数查看当前缓冲区中的数据
    cout << osObj.str() << endl;
}

int main(void){
    /* Case-1: 从键盘读取一行文字 */
    wordFromKeyBoard();
    lineFromKeyBoard();
    /* Case-2: 向文件中写入变量 & 从文件中读取变量 */
    writeVarToFile<string>("HelloWorld"); // 这里如果是"Hello World"编译虽然会通过，但是最后赋值的只有Hello（>> 运算符会以空白字符为分隔符读取数据）
    readVarFromFile<string>("data.txt");
    /* Case-3: 读取字节流数据 & 将字节流写入缓冲区 */
    writeBytesToBuffer<string>("23 Maxim");
    readBytesFromBuffer();
    return 0;
};