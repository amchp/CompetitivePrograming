#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int budget, a, b, sum, max;
    cin >> budget >> a >> b;
    int key[a], usb[b];
    for(int i = 0; i < a; ++i){
        cin >> key[i];
    }
    for(int i = 0; i < b; ++i){
        cin >> usb[i];
    }
    max = -1;
    for(int i = a - 1; i > -1; --i){
        for(int j = b - 1; j > -1; --j){
            sum = key[i] + usb[j];
            if(sum <= budget && max < sum)max = sum;
        }
    }
    cout << max << endl;
}