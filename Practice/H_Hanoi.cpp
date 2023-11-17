#include <algorithm>
#include <array>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream> // istringstream buffer(myString);
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

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
const int nax = 505;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

vi tower[3];
int pos[nax];
int indexes[nax];
vector<ii> ans;

void sol(int ind, int sTower, int dTower){
    if(ind >= tower[sTower].size())return;
    if(sTower == dTower)return;
    // d(tower[sTower][ind]);
    // d(sTower);
    // d(dTower);
    if(sTower == 0){
        int dInd = ind;
        while(dInd + 1 < tower[sTower].size() && tower[sTower][dInd] <= tower[sTower][dInd + 1]){
            dInd++;
        }
        int nTower = dTower == 1 ? 2 : 1;
        sol(dInd + 1, sTower, nTower);
        int mInd = tower[dTower].size();
        while(mInd >= 1 && tower[sTower].back() >= tower[dTower][mInd - 1]){
            mInd--;
        }
        sol(mInd, dTower, nTower);
        sol(dInd + 1, 0, nTower);
        while(ind != (int)tower[sTower].size()){
            if(tower[dTower].size() > 0)assert(tower[sTower].back() < tower[dTower].back());
            ans.pb({sTower, dTower});
            pos[tower[sTower].back()] = dTower;
            indexes[tower[sTower].back()] = tower[dTower].size();
            tower[dTower].pb(tower[sTower].back());
            tower[sTower].pop_back();
        }
        return;
    }
    while(ind != (int)tower[sTower].size() - 1){
        ans.pb({sTower, 0});
        pos[tower[sTower].back()] = 0;
        indexes[tower[sTower].back()] = tower[0].size();
        tower[0].pb(tower[sTower].back());
        tower[sTower].pop_back();
    }
    if(dTower != 0){
        int mInd = tower[dTower].size();
        while(mInd >= 1 && tower[sTower].back() >= tower[dTower][mInd - 1]){
            mInd--;
        }
        sol(mInd, dTower, 0);
        if(tower[dTower].size() > 0)assert(tower[sTower].back() < tower[dTower].back());
    }
    ans.pb({sTower, dTower});
    pos[tower[sTower].back()] = dTower;
    indexes[tower[sTower].back()] = tower[dTower].size();
    tower[dTower].pb(tower[sTower].back());
    tower[sTower].pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n;
    cin >> n;
    forn(i, n){
        int v;
        cin >> v;
        pos[v] = 0;
        indexes[v] = tower[0].size();
        tower[0].pb(v);
    }
    fored(i, 1, n){
        sol(indexes[i], pos[i], 2);
    }
    assert(ans.size() <= 2*n*n);
    for1(i, n){assert(pos[i] == 2);}
    cout << ans.size() << el;
    forn(i, ans.size()){
        cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << el;
    }
}
