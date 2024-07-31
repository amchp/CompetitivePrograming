#include<bits/stdc++.h>

#define sz(a) a.size()
#define forn(i,n) for(int i = 0; i <n;++i)
#define for1(i,n) for(int i = 1; i <=n;++i)
#define fore(i, l, r) for(int i = l; i <= r; ++i)
#define el '\n'
#define db(x) cerr<<#x<<" "<<x<<el
#define all(x) x.begin(), x.end()
#define pb push_back

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef double ld;
typedef complex<ld> C;
typedef vector<ld> vd;

const ld PI = acos(-1.0L);
const ld one = 1;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, mx = 0;
    cin>>n;
    vector<ll> v(n);
    ll sum = 0;
    forn(i,n)cin>>v[i], sum+=v[i];
    for1(i,n-1)
        if(v[i] > v[mx])mx = i;

    sum -= v[mx];

    if(v[mx] <= sum*2LL) {
        sum+=v[mx];
        sum/=3LL;
    }
    cout<<sum<<el;

}