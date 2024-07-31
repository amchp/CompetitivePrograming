#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0 ; i< (int)n; ++i)
#define for1(i,n) for(int i = 1 ; i<= (int)n; ++i)
#define fore(i,l,r) for(int i = l ; i<= (int)r; ++i)
#define el '\n'
#define pb push_back
#define all(a) a.begin(),a.end()
#define d(x) cerr << #x << ' ' << x << el;
using namespace std;

typedef vector<int> vi;
typedef long long ll;

const int nax = 1e5 + 200;
const int mod = 998244353;

int binpow(int b, int e){
    int ans = 1;
    for(; e; b = 1LL*b*b%mod, e /= 2){
        if(e&1) ans = 1LL*ans*b%mod;
    }
    return ans;
}

int add(int a, int b){
    int ans = a + b;
    if(ans >= mod)ans -= mod;
    return ans;
}

vi g[nax];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    vi in(n);
    for1(i, n - 1){
        int p;
        cin >> p;
        --p;
        g[p].pb(i);
        g[i].pb(p);
        ++in[p];
    }
    vi dp(n, -1);
    queue<int> q, qq;
    forn(i, n){
        if(in[i] == 0){
            q.push(i);
            dp[i] = 1;
        }
    }
    int ans = 2;
    while(!q.empty()){
        swap(q, qq);
        while(!qq.empty()){
            int u = qq.front();
            qq.pop();
            for(int& v : g[u]){
                if(dp[v] == -1){
                    q.push(v);
                    dp[v] = ans;
                }
            }
        }
        ++ans;
    }
    int num = 0;
    forn(i, n){
        num = add(num, dp[i]);
        // cout << dp[i] << ' ';
    }
    // cout << el;
    // d(num);
    int dem = binpow(n, mod - 2);
    int fans = 1LL * num * dem % mod;
    cout << fans << el;
    return 0;
}