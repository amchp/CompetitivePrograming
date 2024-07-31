#include <bits/stdc++.h>

#define forn(i, n) for(ll i = 0; i < (ll)n; ++i)
#define for1(i, n) for(ll i = 1; i <= (ll)n; ++i)
#define ford(i, n) for(ll i = (ll)n - 1; i >= 0; --i)
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define el '\n'
#define d(x) cerr<<#x<<" "<<x<<el
#define pb push_back

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
ll dx[] = {0,-1, 1, 0};
ll dy[] = {-1,0, 0, 1};


bool check(ll k, ll s, vi &ch){
    ll a = 0, b = 0;
    ll sum = 0;
    ll w = s*3LL;
    forn(i,k){
       a+= ch[i]%3 == 1;
       b+= ch[i]%3 == 2;
       sum += ch[i];
    }
    ll mn = min(a,b);
    a-=mn, b-=mn;
    if(a){
        sum += (a / 2);
        if(a&1)sum+=2;
    }if(b){
        sum += b;
    }
    return sum <= w;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ll n,s;
    cin>>n>>s;
    vi ch(n);
    forn(i,n)cin>>ch[i];
    if(s<=2 || n <= 2){
        cout<<min(n,s)<<el;
        return 0;
    }
    sort(all(ch));
    ll lo = 1, hi = n-1;
    while(lo + 1 < hi){
        ll mid = (hi+lo)/2;
        if(check(mid, s-2, ch)) lo = mid;
        else hi = mid;
    }
    cout<<lo+2<<el;
}