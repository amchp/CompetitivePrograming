#include <iostream>
#include <map>
#include <iomanip>
using namespace std;
int main(){
    int n;
    cin >> n;
    getchar();
    getchar();
    cout << fixed << setprecision(4);
    while(n--){
        map <string, int> myMap;
        string s;
        getline(cin, s);
        float count = 0;
        while(!s.empty()){
            myMap[s]++;
            count++;
            getline(cin, s);
        }
        for(const auto& kv : myMap){
            cout << kv.first << " ";
            cout << (((kv.second * 1.0) * 100.0) / count) << endl;
        }
        if(!(n == 0)) cout << endl;
    }
}