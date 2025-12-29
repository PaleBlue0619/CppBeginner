# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;

int main(void){
    vector<int> vec{1,2,3,4,5,6,7,8,9,3};

    /*删除vec中值为5的元素*/
    int target = 5;
    int idx = find(vec.begin(), vec.end(), target) - vec.begin();
    cout << "idx: " << idx << endl;
    if (idx != vec.size()){ // 如果存在该元素, 则删除该元素
        vec.erase(vec.begin() + idx);
    }
    
    /*删除vec中所有值为3的元素*/
    auto itr = vec.begin();
    while (itr != vec.end()){
        if (*itr == 3){
            itr = vec.erase(itr);
        }else{
            itr++;
        }
    }
    for (auto itr = vec.begin(); itr != vec.end(); itr++){
        cout << *itr << endl;
    }
    return 0;
}
