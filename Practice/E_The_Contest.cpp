#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
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

typedef long long ll;
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int a, b, c;
    cin >> a >> b >> c;
    int abc = a + b + c;
    vi as(a), bs(b), cs(c);
    forn(i, a){
        cin >> as[i];
    }
    forn(i, b)cin >> bs[i];
    forn(i, c)cin >> cs[i];
    sort(all(as));
    sort(all(bs));
    sort(all(cs));
    int cnt = c;
    int nin = 0;
    vi mnc(abc);
    fored(i, 1, abc){
        if(cnt != 0 && cs[cnt - 1] == i){
            --cnt;
        }else{
            ++nin;
        }
        mnc[i - 1] = nin + cnt;
        // cout << mnc[i - 1] << ' ';
    }
    int ans = mnc[0];
    ford(i, abc - 1){
        mnc[i] = min(mnc[i], mnc[i + 1]);
    }
    nin = 0;
    cnt = a;
    int inda = 0;
    int indc = 0;
    // d(ans);
    for1(i, abc){
        if(inda < a && as[inda] == i){
            --cnt;
            ++inda;
        }else if(indc < c && cs[indc] == i){
            ++indc;
        }else{
            ++nin;
        }
        if(i == abc){
            ans = min(ans, nin + cnt + c);
            // d(nin);
            // d(cnt);
        }
        else{
            ans = min(ans, nin + cnt + mnc[i]);
            // d(nin);
            // d(cnt);
            // d(mnc[i]);
        }
        // d(ans);
    }
    // d(ans);
    int indb = 0;
    indc = 0;
    nin = 0;
    cnt = b;
    for1(i, abc){
        if(indb < b && bs[indb] == i){
            --cnt;
            ++indb;
        }else if(indc < c && cs[indc] == i){
            ++indc;
        }else{
            ++nin;
        }
        if(i == abc){
            ans = min(ans, nin + cnt + c);
            // d(nin);
            // d(cnt);
        }
        else{
            ans = min(ans, nin + cnt + mnc[i]);
            // d(nin);
            // d(cnt);
            // d(mnc[i]);
        }
        // d(ans);
    }
    // d(ans);
    cout << ans << el;
}
