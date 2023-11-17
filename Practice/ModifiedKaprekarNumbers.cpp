#include <iostream>
#include <cmath>

using namespace std;

int main(){
    bool value = false;
    int p, q, l, r, f, c;
    cin >> p >> q;
    for(int i = p; i <= q; ++i){
        string s = to_string((long)i*i);
        
        if(s.length() == 1){
            if(i == 1) cout << i << " ";
        }
        else if(s.length() % 2 == 0){
            f = s.length()/2;
            l = stoi((s.substr(0, f)));
            r = stoi((s.substr(f, f)));
            if(l+r == i){
                value = true;
                cout << i << " ";
            }
        }else{
            f = s.length()/2;
            c = ceil((double)s.length()/2);
            l = stoi(s.substr(0, f));
            r = stoi(s.substr(f, c));
            if(l+r == i){
                value = true;
                cout << i << " ";
            }
        }
    }
    if(value)cout << endl;
    else cout << "INVALID RANGE" << endl;
}