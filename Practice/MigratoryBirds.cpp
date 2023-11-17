#include <iostream>
#include <map>

using namespace std;

int main(){
    map<int, int> birds;
    int n, ID;
    cin >> n;
    while(n--){
        cin >> ID;
        birds[ID]++;
    }
    int max = 0;
    for (auto const& [key, val] : birds){
        if(max < val){max = val; ID = key;}
    }
    cout << ID << endl;
}