# include<iostream>
# include<string>
# include<map>
using namespace std;

int main(void){
    /* 字典的初始化 */
    std::map<string, double> dict;
    std::map<int, int> tempDict{{001,90},{003,80},{002,90}};
    std::multimap<string, int> nameDict{{"ZHAOWEIGUO", 250}, {"ZHAOWEIGUO", 478}, {"SUNQING", 380}};
    cout << tempDict.size() << endl; // 获取字典的长度
    cout << tempDict.empty() << endl; // 判断字典是否为空

    /* 字典的访问 */
    // 这里用到了之前所介绍的std::pair模板类
    // 方式1:字典遍历
    for (auto &item: tempDict){
        cout << item.first << ":" << item.second << endl;
    } 
    for (auto itr = nameDict.begin(); itr != nameDict.end(); itr++){
        cout << itr->first << ":" << itr->second << endl;
    }
    // 方式2:字典访问
    cout << tempDict[001] << endl;

    /* 字典的修改 */
    tempDict[002] = 100; // 修改字典中某个键的值
    tempDict.insert(std::pair<int, int>(004, 80)); // 添加键值对
    tempDict.erase(002); // 删除键值对
    return 0;
}