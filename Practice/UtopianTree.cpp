#include <iostream>

using namespace std;

int main(){
    int t, n, h;
    cin >> t;
    while(t--){
        cin >> n;
        h = 1;
        for(int i = 0; i < n; ++i){
            if(i % 2 == 0) h *= 2;
            else h++;
        }
        cout << h << endl;
    }
}