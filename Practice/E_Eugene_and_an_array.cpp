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
    int n;
    cin >> n;
    long long arr[20001];
    long long leftSum[20001];
    long long rightSum[20001];
    for(int i = 0; i < n; ++i)cin >> arr[i];
    leftSum[0] = arr[0];
    rightSum[n - 1] = arr[n - 1];
    for(int i = 1; i < n; ++i){
        leftSum[i] = arr[i] + leftSum[i - 1];
        rightSum[n - i - 1] = arr[n - i - 1] + rightSum[n - i];
    }
}