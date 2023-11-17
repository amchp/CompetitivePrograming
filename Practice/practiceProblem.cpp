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
#define MAXA                         (int)1e9

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans;
        int l, r;
        bool pL, pR;
        for(int i = 0; i < s.length(); ++i){
            l = 0;
            r = 0;
            pL = false; 
            pR = false;
            if(s.at(i) == c){
                ans.push_back(0);
                continue;
            }
            for(int j = i; i > -1; --j){
                l++;
                if(c == s.at(j)){
                    pL = true;
                    break;
                }
            }
            for(int j = i + 1; i < s.length(); ++j){
                r++;
                if(c == s.at(j)){
                    pR = true;
                    break;
                }
            }
            if(!pL)l = INF;
            if(!pR)r = INF;
            ans.push_back(min(l, r));
        }
        return ans;
    }
};