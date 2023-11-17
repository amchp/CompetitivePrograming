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
    vi a(n+2, 1);
    bool one = true;
    for(int i = 2; i < n+2; ++i){
        if(a[i] == 2)continue;
        for(int j = i*2; j < n + 2; j += i){a[j] = 2; one = false;}
    }
    if(one)cout << 1 << el;
    else cout << 2 << el;
    for(int i = 2; i < n+2; ++i)cout << a[i] << " ";
    cout << el;
}