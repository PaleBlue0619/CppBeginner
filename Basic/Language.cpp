#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void){
    // for loop
    int iter = 1000;
    std::vector<int> t(iter); 
    for (int i=0; i<1000; i++){
        t[i] = i;
    };
    string res = "";
    for (int i=0; i<1000; i++){
        res += std::to_string(t[i]);
        cout << std::to_string(i) << endl;
    };

    // if - else if - else
    for (int i=0; i<t.size(); i++){
        if (i%2 == 0){
            cout << "Even:"+to_string(i) << endl;
        } else if (i%2!=0) {
            cout << "Odd:"+to_string(i) << endl;
        }else{
            continue;
        }
    }

    // do - while
    int counter = 1;
    do{
        counter *= 2;
        cout << "Counter:"+to_string(counter) << endl;
    }while(counter <= 8848);

    return 0;
}