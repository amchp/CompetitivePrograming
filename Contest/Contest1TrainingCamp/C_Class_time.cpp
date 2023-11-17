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
    int n;
    cin >> n;
    string f, l;
    vector<string> v(n);
    for(int i = 0; i < n; ++i){
        cin >> f >> l;
        v[i] = l + " " + f;
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; ++i){
        f = v[i].substr(v[i].find(" ") + 1);
        l = v[i].substr(0, v[i].find(" "));
        cout << f << " " << l << el;
    }
}