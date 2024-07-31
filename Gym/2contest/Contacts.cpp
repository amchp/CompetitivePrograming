#include <iostream>
#include <unordered_map>
#include <iomanip>
using namespace std;

int main(){
    int n, count;
    unordered_map <string, int> myMap;
    cin >> n;
    getchar();
    while(n--){
        string s, value;
        cin >> s;
        cin >> value;
        if(s == "add"){
            myMap[value]++;
        }
        if(s == "find"){
            count = 0;
            for(const auto& kv : myMap){
                if(kv.first.compare(0, value.size(), value) == 0){
                    count++;
                }
            }
            cout << count << endl;
        }
    }
}