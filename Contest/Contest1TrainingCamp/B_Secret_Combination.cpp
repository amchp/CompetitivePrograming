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
    int n, g, a;
    string m, val;
    string s;
    getline(cin, s);
    n = stoi(s);
    getline(cin, s);
    vector<int> v(n);
    m = string(1000, '9');
    for(int i = 0; i < n; ++i)v[i] = s.at(i) - '0';
    for(int i = 0; i < n; ++i){
        g = 10 - v[i];
        val = "0";
        for(int j = 1; (i + j) < n; ++j){
            a = (v[i + j] + g) % 10;
            val = val + (char)(a + '0');
        }
        for(int j = 0; j < i; ++j){
            a = (v[j] + g) % 10;
            val = val + (char)(a + '0');
        }
        m = min(val, m);
    }
    cout << m << el;
}