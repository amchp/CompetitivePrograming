#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, sum = 0;
    cin >> n;
    int rations[n];
    for(int i = 0; i < n; ++i){
        cin >> rations[i];
        sum += rations[i];
    }
    if(sum % 2 == 1)cout << "NO" << endl;
    else{
        int m = 0;
        for(int i = 0; i < n; ++i){
            if(rations[i] % 2 == 1){
                m += 2;
                rations[i] += 1;
                rations[i+1] += 1;
            }
        }
        cout << m << endl;
    }
}