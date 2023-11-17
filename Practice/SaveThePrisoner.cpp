#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int t, n, m, s, c;
    cin >> t;
    while(t--){
        cin >> n >> m >> s;
        if(n < m){
            c = ((m + s - 2) % n) + 1;
        }
        else{
            c = s + m - 2;
            c = c % n;
            c++;
        }
        cout << c << endl;
    }
}