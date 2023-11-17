#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for (long long i = (long long)l; i <= (long long)r; ++i)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define fored(i, l, r) for (int i = (int)r; i >= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout << #x << " " << x << el
#define ri(n) scanf("%d", &n)
#define sz(v) ((int)v.size())
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

using namespace std;

typedef __int128_t ll;
typedef double ld;
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int inf = 1e9;
const int nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int calc(ll a){
    int cnt = 0;
    while((!(a & ll(1)))){
        ++cnt;
        a >>= 1;
    }
    while(a != 1){
        a *= 3;
        a += 1;
        ++cnt;
        while(!(a & ll(1))){
            ++cnt;
            a >>= 1;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    cout << setprecision(20);
    long long s, w;
    cin >> s >> w;
    long long e = s + w - 1;
    // cout << e << el;
    int ans = 1;
    long long ind = s;
    int cnt = 1;
    int prv = -1;
    fore(i, s, e){
        int val = calc(i);
        if(prv == val){
            cnt++;
        }else{
            if(ans < cnt){
                ans = cnt;
                ind = i - cnt;
            }
            cnt = 1;
        }
        prv = val;
    }
    if(ans < cnt){
        ans = cnt;
        ind = e - cnt + 1;
    }
    cout << ans << ' ' << ind << el;
}
