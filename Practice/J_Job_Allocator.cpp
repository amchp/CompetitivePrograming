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


int k;
int arr[9][9][9][9][9][9][9][9];
int cp[8];

void sol(int ind, vi& cur, int& sm){
    if(ind == k){
        // for(int v : cur){
        //     cout << v;
        // }
        // cout << el;
        arr[cur[0]][cur[1]][cur[2]][cur[3]][cur[4]][cur[5]][cur[6]][cur[7]] += sm;
        return;
    }
    forn(i, cp[ind] + 1){
        sol(ind + 1, cur, sm);
        cur[ind]++;
    }
    cur[ind] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    memset(arr, 0, sizeof(arr));
    memset(cp, 0, sizeof(cp));
    int n;
    cin >> n >> k;
    vector<vi> comp;
    while(n--){
        char c;
        cin >> c;
        if(c == 'C'){
            int r;
            cin >> r;
            forn(i, k)cp[i] = 0;
            forn(i, r){
                int v;
                cin >> v;
                v--;
                cp[v]++;
            }
            vi cur(8, 0);
            int sm = 1;
            sol(0, cur, sm);
            forn(i, k){
                cur[i] = cp[i];
            }
            comp.pb(cur);
        }else if(c == 'D'){
            int ind;
            cin >> ind;
            ind--;
            forn(i, k){
                cp[i] = comp[ind][i];
                // d(cp[i]);
            }
            vi cur(8, 0);
            int sm = -1;
            sol(0, cur, sm);
        }else if(c == 'J'){
            int r;
            cin >> r;
            forn(i, k)cp[i] = 0;
            forn(i, r){
                int v;
                cin >> v;
                v--;
                cp[v]++;
            }
            cout << arr[cp[0]][cp[1]][cp[2]][cp[3]][cp[4]][cp[5]][cp[6]][cp[7]] << el;
        }
    }
}
