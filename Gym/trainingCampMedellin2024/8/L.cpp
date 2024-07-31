#include <bits/stdc++.h>

#define el '\n'

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    bx -= ax;
    by -= ay;
    cx -= ax;
    cy -= ay;
    if((abs(bx) / bx) == (abs(cx) / cx) && (by / abs(by))== (cy / abs(cy))){
        cout << "YES" << el;
    }else{
        cout << "NO" << el;
    }
}