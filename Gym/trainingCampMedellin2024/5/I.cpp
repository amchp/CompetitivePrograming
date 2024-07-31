#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < n; ++i)
#define ford(i, n) for(int i = n-1; i >= 0; --i)
#define el '\n'
#define db(x) cerr<<#x<<" "<<x<<el
#define pb push_back
#define sz(a) (int) a.size()
#define all(a) a.begin(), a.end()
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
const int nax =2e5;

ll count(vector<ll> v){
    int n = sz(v);
    vector<ll> ans(n), frec(2e5+1);
    vector<vector<ll>> events(n);
    forn(i,n){
        ans[i] -= frec[v[i]];
        ++frec[v[i]];
        for(auto l : events[i]){
            ans[l] += frec[v[l]];
            ans[l] *= (l+1);
            ans[l] = 1LL*(i - l + 1) * (l+1) - ans[l];
        }
        if(n-i-2>=0)
            events[n-i-2].pb(i);
    }
    ll tot = 0;
    forn(i,n) tot += ans[i];
    return tot;
}

void sol(){
    int n;
    cin>>n;
    vector<ll> v(n);
    forn(i,n){
        cin>>v[i];
    }
    ll ans = count(v);
    reverse(all(v));
    ans += count(v);
    reverse(all(v));
    forn(i,n/2){
        ans+= 1LL*(i+1)*(v[i] != v[n-i-1]);
    }
    cout<<ans<<el;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sol();
}