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

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define ford(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define all(v) v.begin(), v.end()
#define el '\n'

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

const int nax = 3e5 + 5;

int n;
vector<ii> x(2);
vector<vi> ans(2);
ii a[nax];

bool sol(){
    int j = n;
    forn(i, 2){
        j--;
        int cnt = 1;
        while(j > -1 && a[j].first < ((long double)x[i].first / (long double)cnt)){
            cnt++;
            ans[x[i].second].push_back(a[j].second);
            j--;
        }
        if(j > -1)ans[x[i].second].push_back(a[j].second);
    }
    return j > -1;
}

int main(){
    cin >> n;
    forn(i, 2){
        int v;
        cin >> v;
        x[i] = make_pair(v, i);
    }
    forn(i, n){
        int v;
        cin >> v;
        a[i] = make_pair(v, i);
    }
    sort(a, a + n);
    // forn(i, n){
    //     cout << a[i].first << ' ';
    // }
    // cout << el;
    if(sol()){
        cout << "Yes" << el;
        cout << ans[0].size() << ' ' << ans[1].size() << el;
        forn(i, 2){
            forn(j, ans[i].size()){
                cout << ans[i][j] + 1 << ' ';
            }
            cout << el;
        }
        return 0;
    }
    ans[0].clear();
    ans[1].clear();
    swap(x[0], x[1]);
    if(sol()){
        cout << "Yes" << el;
        cout << ans[0].size() << ' ' << ans[1].size() << el;
        forn(i, 2){
            forn(j, ans[i].size()){
                cout << ans[i][j] + 1 << ' ';
            }
            cout << el;
        }
        return 0;
    }
    cout << "No" << el;
}