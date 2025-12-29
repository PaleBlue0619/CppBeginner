# include<string>
# include<iostream>
# include<vector>
# include<map>
# include<algorithm>
using namespace std;
int main(void){
    // 倒序排序 - vector<int>
    vector<int> vec{1,2,3,4,5,6,7,8,9};
    std::sort(vec.begin(),vec.end(), [](int a, int b){return a>b;}); // 这里写成&a>&b也可以
    for (auto itr=vec.begin(); itr!=vec.end(); itr++){
        cout << *itr << endl;
    };
    vec.clear();

    // 倒序排序 - vector<string>
    vector<string> stringVec{"A1","C2","D3","B4","E5","G6","F7","I8","H9"};
    std::sort(stringVec.begin(), stringVec.end(), [](string& a, string& b) {
        return a[0] > b[0];  // 只比较第一个字符
    });
    for (auto itr=stringVec.begin(); itr!=stringVec.end(); itr++){
        cout << *itr << endl;
    };
    return 0;
}
