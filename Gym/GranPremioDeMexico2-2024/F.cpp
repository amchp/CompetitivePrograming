#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < n; ++i)
#define el '\n'

using namespace std;

typedef vector<int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, p;
    cin >> n >> p;
    vi a(n);
    int ans = 0;
    forn(i, n){
        cin >> a[i];
        if(a[i] <= p)ans = max(ans, a[i]);
    }
    cout << ans << el;
}