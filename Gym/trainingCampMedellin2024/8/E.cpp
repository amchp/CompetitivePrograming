#include <bits/stdc++.h>

#define el '\n'
#define forn(i, n) for(int i = 0; i < n; ++i)
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz(x) x.size()

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vll a(n);
    forn(i, n){
        cin >> a[i];
    }
    vll pw2;
    ll pw = 1;
    while(pw < 3e9){
        pw2.pb(pw);
        pw*= 2;
    }
    vll ans;
    sort(all(a));
    forn(i, n){
        for(ll& pw : pw2){
            vll cans = {a[i]};
            if(sz(ans) < sz(cans)){
                ans = cans;
            }

            auto it = lower_bound(all(a), a[i] + pw);
            if(*it != a[i] + pw)continue;
            cans.pb(*it);
            if(sz(ans) < sz(cans)){
                ans = cans;
            }

            it = lower_bound(all(a), a[i] + pw*2LL);
            if(*it != a[i] + pw*2LL)continue;
            cans.pb(*it);
            if(sz(ans) < sz(cans)){
                ans = cans;
            }
        }
    }
    cout << sz(ans) << el;
    for(ll& v : ans)cout << v << ' ';
    cout << el;
}