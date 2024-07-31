#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= n; ++i)
#define el '\n'
#define all(x) x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;

void sol(){
    int n;
    cin >> n;
    set<int> izq, win;
    vi a(n);
    forn(i, n){
        cin >> a[i];
    }
    izq.insert(a[0]);
    int ans = 0;
    for1(i, n - 1){
        auto it = izq.upper_bound(a[i]);
        
        if(it == izq.begin()){
            izq.insert(a[i]);
            continue;
        }
        izq.insert(a[i]);
        it = win.upper_bound(a[i]);
        if(it == win.begin()){
            ++ans;
            win.insert(a[i]);
        }
    }
    cout << ans << el;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        sol();
    }
}