#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string.h>
#include <math.h>
#include <queue>
#include <set>
#include <assert.h>
#include <map>
#include <numeric>
#include <climits>
#include <cstring>
#include <tuple>

#define forn(i,n) for(int i = 0; i < (int)n;++i)
#define for1(i,n) for(int i = 1; i <= (int)n;++i)
#define fore(i, l, r) for(int i = (int)l; i <= (int)r;++i)
#define all(a) a.begin(),a.end()
#define el '\n'
#define sz(a) (int)a.size()
#define d(x) cout << #x << ' ' << x << el

using namespace std;

typedef vector<int> vi;
typedef long double ld;
typedef long long  ll;

struct fwtree{
    int n; vi bit;
    fwtree(int n) : n(n),bit(n+1,0){}
    int rsq(int r){
        int sum = 0;
        for(++r;r;r-=r&-r)sum+=bit[r];
        return sum;
    }
    int rsq(int l,int r){return rsq(r)-(l==0?0:rsq(l-1));}
    void upd(int r,int v){
        for(++r;r<=n;r+=r&-r)bit[r]+=v;
    }
};

int main(){
    int n;
    cin>>n;
    vi v(n+1);
    fwtree ft(n+n+2);
    for1(i,n){
        cin >> v[i];
    }
    ll ans = 0;
    for1(i,n - 1){
        int op = ft.rsq(1,v[i]);
        ans += 1LL*(v[i] + op) - i;
        // assert(v[i] + op >= i);
        ft.upd(v[i],1);
        ft.upd(v[i] + op,-1);
    }
    // for1(i, n)cout << v[i] << ' ';
    // cout << el;
    cout<<ans<<el;
}