#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int p, d, m, s, g;
    cin >> p >> d >> m >> s;
    g = 0;
    while(s-p > 0){
        s -= p;
        if(p > m)p -= d;
        if(p < m)p = m;
        if(p == m) {
             g += (s / p) + 1; 
            break;
        }
        g++;
    }
    cout << g << endl;
}