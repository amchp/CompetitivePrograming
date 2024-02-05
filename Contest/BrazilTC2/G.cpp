#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define el '\n'

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vi a(2*n);
    forn(i, n){
        cin >> a[i];
        a[i + n] = a[i];
    }
    bool pass = false;
    forn(i, n){
        bool cur = true;
        fore(j, i, n + i - 2){
            if(a[j] > a[j + 1]){
                cur = false;
                break;
            }
        }
        pass |= cur;
        if(pass)break;
    }
    if(pass)cout << "Phew" << el;
    else cout << "Lie" << el;
    return 0;
}