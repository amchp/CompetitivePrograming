#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < n; ++i)
#define for1(i,n) for(int i = 1; i <= n; ++i)
#define el '\n'
#define d(x) cerr<<#x<<" "<<x<<el
using namespace std;

typedef long long ll;
typedef array<ll,2> v2;

const ll inf = 1e18;
struct stree{
    v2 neutro = {-inf,0};
    int n, l, r, pos;
    v2 val; vector<v2> t;
    stree(int n): n(n), t(n << 2, neutro){}
    inline v2 oper(v2 a, v2 b){ return max(a, b); }
    v2 query(int v, int tl, int tr){
        if(tl > r || tr < l)return neutro;
        if(l <= tl && tr <= r)return t[v];
        int tm = (tl + tr) >> 1;
        return oper(query(v << 1, tl, tm), query((v << 1) | 1, tm + 1, tr));
    }
    void upd(int v, int tl, int tr){
        if(tl == tr){ t[v] = oper(t[v], val); return; }
        int tm = (tl + tr) >> 1;
        if(pos <= tm)upd(v << 1, tl, tm);
        else upd((v << 1) | 1, tm + 1, tr);
        t[v] = oper(t[v << 1], t[(v << 1) | 1]);
    }
    void upd(int idx, v2 num){ pos = idx, val = num, upd(1, 0, n - 1); }
    v2 query(int ql, int qr){ l = ql, r = qr; return query(1, 0, n - 1); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m;
    ll C;

    cin>>n>>C>>m;
    vector<ll> pos(m+1), val(m+1);
    vector<ll> dp(m+1);
    vector<stree> st(2, stree(n+1));
    auto cost = [&] (int i, int j)->ll{
        return dp[j] - C * abs(pos[i] - pos[j]) + val[i];
    };
    pos[0] = 1;
    ll tot = 0;
    for1(i,m){
        cin>>pos[i]>>val[i];
       auto [val0, i0] = st[0].query(0, pos[i]);
       auto [val1, i1] = st[1].query(pos[i], n);

       ll ans = max({cost(i, i0), cost(i, i1), cost(i, 0)});
       st[0].upd(pos[i], {ans + pos[i] * C, i});
       st[1].upd(pos[i], {ans - pos[i] * C, i});
       dp[i] = ans;
       tot = max(tot, ans);
    //    cout<<"======="<<el;
    }
    cout<<tot<<el;

}