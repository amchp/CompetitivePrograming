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
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define all(v) v.begin(), v.end()
#define el '\n'
#define mp make_pair
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

bool eq(const string& a, const string& b){
    int n = a.size();
    if (n % 2)
    {
        bool pass = true;
        forn(i, n)
        {
            pass &= a[i] == b[i];
        }
        return pass;
    }
    int m = n / 2;
    string a1 = a.substr(0, m);
    string a2 = a.substr(m, n - m);
    string b1 = b.substr(0, m);
    string b2 = b.substr(m, n - m);
    bool ans = eq(a1, b1) && eq(a2, b2);
    ans |= eq(a1, b2) && eq(a2, b1);
    return ans;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    if(eq(s1, s2)){
        cout << "YES" << el;
    }else{
        cout << "NO" << el;
    }
}