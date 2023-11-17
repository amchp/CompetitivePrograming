#include <iostream>
#include <cmath>


using namespace std;

int main(){
    long long t, i, c;
    cin >> t;
    i = 1;
    c = 0;
    while(t >= i){
        i += (long long)3*pow(2, c);
        c++;
    }
    cout << i - t << endl;
}