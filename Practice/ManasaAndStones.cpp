#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int t, n, a, b, s;
    cin >> t;
    while(t--){
        cin >> n >> a >> b;
        if(a > b){
            s = a;
            a = b;
            b = s;
        }
        if(a == b) cout << (n-1)*a;
        else{
            for(int i = 0; i < n; ++i){
                cout << ((n-i-1)*a + (i)*b) << " ";
            }
        }
        cout << '\n';
    }
}