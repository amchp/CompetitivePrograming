#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < n; ++i)
#define el '\n'

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

bool sol(){
    int n;
    cin >> n;
    vi a(n);
    ll sm = 0;
    forn(i, n){
        cin >> a[i];
        sm += a[i];
    }
    vll b(n);
    forn(i, n - 1){
        b[i] = 1;
        --sm;
    }
    b[n - 1] = sm;
    int m1 = -1;
    forn(i, n - 1){
        if(a[i] == 1){
            --b.back();
            if(b.back() == 0)return false;
            b[i] = 2;
        }
        if(b[i] + 1 != a[i])m1 = i;
    }
    if(a[n - 1] == b[n - 1] && (b[n - 1] == 1|| m1 == -1))return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        if(sol())cout << "YES" << el;
        else cout << "NO" << el;
    }
}