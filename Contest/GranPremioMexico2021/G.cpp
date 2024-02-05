#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i <(int)n;++i)
#define fore(i,l,r) for(int i = l ; i<= (int)r; ++i)
#define for1(i,n) for(int i = 1; i <= (int)n;++i)
#define ford(i,n) for(int i = (int)n - 1; i >= 0;--i)
#define el '\n'
#define sz(a) (int)a.size()
#define pb push_back
#define all(a) a.begin(),a.end()
#define d(x) cerr<<#x<<" "<<x<<el
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ll> vl;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    bool win = true;
    if(n <= m){
        cout << "Pay the bill" << el;
        return 0;
    }
    int cur = m + 1;
    while(cur < n){
        int nxt = cur;
        while(__popcount(nxt) & 1){
            ++nxt;
        }
        if(nxt - cur > m){
            --nxt;
        }
        // d(nxt);
        if(nxt + 1 <= n && n <= nxt + m){
            win = false;
            break;
        }
        cur = nxt + m + 1;
    }
    if(win)cout << "Free snacks!" << el;
    else cout << "Pay the bill" << el;
    return 0;
}
