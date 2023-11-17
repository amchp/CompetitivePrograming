#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream> // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <math.h>
#include <unordered_map>
#include <queue>
#include <array>
#include <set>
#include <numeric>

using namespace std;

struct bucket
{
    vector<int> a, b;
    int n, len;
    void init(){ // preprocessing
        n = (int)a.size();
        len = (int)sqrt(n + .0) + 1;
        b.resize(len);
        for (int i = 0; i < n; ++i)
            b[i / len] += a[i];
    }
    void update(int pos, int val){
        int bpos = pos / len;
        int r = min(n, len * (bpos + 1));
        int l = bpos * len;
        a[pos] = val;
        b[bpos] = 0;
        for (int i = l; i < r; ++i)
            b[bpos] += a[i];
    }
    int query(int l, int r){
        int sum = 0;
        int c_l = l / len, c_r = r / len;
        if (c_l == c_r)
        {
            for (int i = l; i <= r; ++i)
                sum += a[i];
        }
        else
        {
            for (int i = l, end = (c_l + 1) * len - 1; i <= end; ++i)
                sum += a[i];
            for (int i = c_l + 1; i <= c_r - 1; ++i)
                sum += b[i];
            for (int i = c_r * len; i <= r; ++i)
                sum += a[i];
        }
    }
};