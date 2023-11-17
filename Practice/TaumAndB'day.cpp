#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long b, w, bc, wc, z, sum;
        cin >> b >> w >> bc >> wc >> z;
        bc = min(bc, wc+z);
        wc = min(wc, bc+z);
        sum = b*bc + w*wc;
        cout << sum << endl;
    }
}