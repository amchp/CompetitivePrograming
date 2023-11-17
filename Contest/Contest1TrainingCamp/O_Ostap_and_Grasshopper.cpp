#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <sstream>  // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <math.h>
#include <unordered_map>
#include <queue>
#include <array>
#include <tuple>


// Useful constants 
#define INF                         (int)2e9 
#define EPS                         1e-9

#define el '\n'

#define MAXN                         (int)2e5

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, g, t, m, M;
    bool pass = true;
    cin >> n >> k;
    string s;
    vi o;
    cin >> s;
    for(int i = 1; i <= n ; ++i){
        if(s.at(i - 1) == 'G')g = i;
        if(s.at(i - 1) == 'T')t = i;
        if(s.at(i - 1) == '#')o.push_back(i);
    }
    if(g % k != t % k)pass = false;
    else{
        m = min(g, t);
        M = max(g, t);
        for(int i = 0; i < o.size(); ++i){
            if(o[i] % k == g % k && m < o[i] && o[i] < M){pass = false;break;}
        }
    }
    if(pass)cout << "YES" << el;
    else cout << "NO" << el;
}