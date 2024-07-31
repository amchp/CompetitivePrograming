#include<bits/stdc++.h>

#define el '\n'
#define db(x) cerr << #x << ' ' << x << el
#define forn(i,n) for(int i= 0; i < (int)n;++i)
#define ford(i,n) for(int i= (int)n - 1; i >= 0;--i)
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define pb push_back
#define sz(a) (int) a.size()
#define all(a) a.begin(), a.end()
#define fi first
#define se second
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef double ld;
const ll inf = 1e18;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    vi lth(n), dr(n);
    dr[0] = 2;
    forn(i, n){
        int nd;
        cin >> lth[i] >> nd;
        if(i == n - 1)continue;
        if(i&1){
            if(dr[i] == 0){
                if(nd == 1)dr[i + 1] = 3;
                else dr[i + 1] = 2;
            }else{
                if(nd == -1)dr[i + 1] = 3;
                else dr[i + 1] = 2;
            }
        }else{
            if(dr[i] == 2){
                if(nd == 1)dr[i + 1] = 0;
                else dr[i + 1] = 1;
            }else{
                if(nd == -1)dr[i + 1] = 0;
                else dr[i + 1] = 1;
            }
        }
    }
    if(n == 1){
        cout << 1 << el;
        return 0;
    }
    vi flth(n);
    int acc[2] = {1, 1};
    int prv[2] = {dr[1], dr[0]};
    forn(i, n){
        int ind = dr[i] / 2;
        // db(ind);
        if(prv[ind] == dr[i]){
            flth[i] = 1;
        }else{
            flth[i] = acc[ind];
        }
        prv[ind] = dr[i];
        ++acc[ind];
    }
    for(int& v : flth)cout << v << ' ';
    cout << el;
}