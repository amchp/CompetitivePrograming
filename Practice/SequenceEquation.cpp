#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    int n;
    cin >> n;
    unordered_map<int, int> m;
    int arr[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    for(int i = 0; i < n; ++i){
        m[arr[i]] = i + 1;
    }
    for(int i = 1; i < n+1; ++i){
        cout << m[i] << endl;
    }
}