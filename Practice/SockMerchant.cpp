#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    int n, ind, socks;
    unordered_map<int ,int> myMap;
    cin >> n;
    while(n--){
        cin >> ind;
        myMap[ind]++;
    }

    socks = 0;
    for( auto const& [key, val] : myMap ){
        socks += (val / 2);
    }
    cout << socks << endl; 
}