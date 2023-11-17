#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    string right[n];
    string my[n];
    getchar();
    for(int i = 0; i < n; ++i){
        getline(cin, right[i]);
    }
    for(int i = 0; i < n; ++i){
        getline(cin, my[i]);
    }
    for(int i = 0; i < n; ++i){
        if(right[i] != my[i]) cout << right[i] << " " << my[i];
    }
}