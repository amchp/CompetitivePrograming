#include <iostream>

using namespace std;

int main(){
    int x1, v1, x2, v2, i;
    double t;
    cin >> x1 >> v1 >> x2 >> v2;
    if(v1 == v2) cout << "NO" << endl;
    else if(v1 == v2 && x1 == x2) cout << "YES" << endl;
    else{
        t = ((double)(x2 - x1)/(v2 - v1));
        i = (int)t;
        if(t > 0 || t - i != 0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}