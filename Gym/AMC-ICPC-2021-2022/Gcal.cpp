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
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define ford(i, n) for (int i = n - 1; i > -1; --i)
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define el "\n"

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    ll prv = 1;
    ll cur = 1;
    ford(i, s.size() -1){
        if(s[i] == 'A'){
            ll tmp = cur;
            cur += prv;
            prv = tmp;
        }else{
            prv = cur;
        }
    }
    cout << cur << el;
}