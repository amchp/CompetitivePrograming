#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int q, a, b, output;
    cin >> q;
    while(q--){
        cin >> a >> b;
        if((double)(int)sqrt(a) == sqrt(a))a--;
        output = (int)(floor(sqrt(b)) - floor(sqrt(a)));
        cout << output << endl;
    }
}