#include<bits/stdc++.h>

#define sz(a) a.size()
#define forn(i,n) for(int i = 0; i <n;++i)
#define el '\n'
#define db(x) cerr<<#x<<" "<<x<<el
using namespace std;
typedef vector<int> vi;
struct stree{
    int nuetro = 0, n, l, r, val, pos; vi t;
    stree(int n):n(n), t(n<<2){build(1, 0, n-1);}
    inline int oper(int a, int b){return a+b;}
    void build(int v, int  tl, int tr){
        if(tl == tr){t[v] = 1;return;}
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm), build((v << 1) | 1, tm+1, tr);
        t[v] = oper(t[v << 1], t[(v << 1) | 1]);
    }

    // int query(int v, int  tl, int tr){

    //     return oper(query(v<<1, tl, tm)query((v<<1) | 1, tm+1, tr));
    // }
    int kesimo(int v, int tl, int tr){
        if(tl == tr){--t[v];return tl;}
        int tm = (tl + tr) >> 1;
        int ans = -1;
        if(t[v<<1] >= val) ans = kesimo(v<<1, tl, tm);
        else {
            val -= t[v<<1];
            ans = kesimo((v<<1) | 1, tm+1, tr);
        }
        t[v] = oper(t[v << 1], t[(v << 1) | 1]);
        return ans;
    }

    void upd(int v, int tl, int tr){
        if(tl == tr){t[v] += val;return;}
        int tm = (tl + tr) >> 1;
        if(pos <= tm) upd(v<<1, tl, tm);
        else upd((v<<1) | 1, tm+1, tr);
        t[v] = oper(t[v<<1], t[(v<<1) | 1]);

    }
    void upd(int pos, int x){
        pos = pos, val = x; upd(1,0, n-1);
    }
    int kesimo(int k){
        val = k; return kesimo(1,0,n-1);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int m;
    cin>>m; 
    int n = m/2;
    int a[2][n];
    stree st(m);

    forn(j,2){
        forn(i,n){
            cin>>a[j][i];
        }
    }
    int ans[2][n];
    forn(i,m){
        ans[i&1][i>>1] = st.kesimo(a[i&1][i>>1]);
    }
    forn(j,2){
    forn(i,n)cout<<ans[j][i]+1<<" ";cout<<el;}
}