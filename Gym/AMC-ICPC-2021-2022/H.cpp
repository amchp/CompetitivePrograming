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

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define el "\n"

typedef pair<int, int> ii;
typedef vector<int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int N, K;
    cin >> N >> K;
    vector<vector<int>> color(K);
    vector<vector<int>> ind(K);
    forn(i, N){
        int v, c;
        cin >> v >> c;
        c--;
        color[c].pb(v);
        ind[c].pb(i);
    }
    // cout << el;
    forn(i, K){
        sort(all(color[i]));
    }
    vi ans(N);
    forn(i, K){
        forn(j, color[i].size()){
            ans[ind[i][j]] = color[i][j];
        }
    }
    bool pass = true;
    // forn(i, N){
    //     cout << ans[i] << ' ';
    // }
    // cout << el;
    forn(i, N - 1){
        pass &= ans[i] <= ans[i + 1];
    }
    if(pass)cout << "Y" << el;
    else cout << "N" << el;
}