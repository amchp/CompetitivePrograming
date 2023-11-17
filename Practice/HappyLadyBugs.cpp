#include <iostream>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){
    int g, n;
    string s;
    cin >> g;
    while(g--){
        cin >> n;
        getchar();
        getline(cin, s);
        unordered_map<char, int> ladyBugs;
        for(int i = 0; i < s.length(); ++i){
            ladyBugs[s.at(i)]++;
        }
        bool happy = true, canChange = false, needToChange = false;
        if(ladyBugs['_'] > 0)canChange = true;
        for(auto it : ladyBugs){
            if(it.first == '_')continue;
            else if(it.second < 2)happy = false;
        }
        bool next, last;
        for(int i = 0; i < s.length(); ++i){
            last = (i -1 > -1 && s.at(i) == s.at(i - 1));
            next = (i + 1 < s.length() && s.at(i) == s.at(i + 1));
            if(!(last || next)){
                needToChange = true;
                break;
            }
        }
        if(happy && (canChange || !needToChange)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}