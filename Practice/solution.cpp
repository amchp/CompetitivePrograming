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

// Useful constants 
#define INF                         (int)1e9 
#define EPS                         1e-9

#define el '\n'

using namespace std;

int main(){
    long n, k, v, temp, o = 0;
    cin >> n >> k;
    priority_queue<int, vector<int>, greater<int> > b;
    for(int i = 0; i < n; ++i){
        cin >> v;
        b.push(v);
    }
    bool pass = false;
    while(b.size() > 1){
        if(b.top() < k){
            temp = b.top();
            b.pop();
            v = temp + 2*b.top();
            b.pop();
            b.push(v);
            o++;
        }else{
            pass = true;
            break;
        }
    }
    if(b.size() == 1 && b.top() >= k)pass = true;
    if(pass)cout << o << el;
    else cout << -1 << el;
}