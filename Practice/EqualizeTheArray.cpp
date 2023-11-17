#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    int n, ma = 0, in;
    cin >> n;
    int arr[n];
    unordered_map<int, int> m;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        m[arr[i]]++;
        
        if(ma < m[arr[i]]){
            ma = m[arr[i]]; 
            in = arr[i];
        }
    }
    cout << n - m[in] << endl;
}