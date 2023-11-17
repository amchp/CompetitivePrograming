#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    bool found = false;
    int m = 1000000;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            if(arr[i] == arr[j]){
                found = true;
                m = min(m, j-i);
            }
        }
    }
    if(found) cout << m << endl;
    else cout << -1 << endl;
}