#include <iostream>
#include <vector>

using namespace std;

int main(){
    string s;
    int a, mult, max;
    getline(cin, s);
    while(!s.empty()){
        int num;
        max = -1000000;
        vector<int> nums;
        a = s.find(" ");
        num = stoi(s.substr(0, a));
        s = s.substr(a+1, s.length()) + " ";
        while(num != -999999){
            nums.push_back(num);
            a = s.find(" ");
            num = stoi(s.substr(0, a));
            s = s.substr(a+1, s.length());
        }
        for(int i = 0; i < nums.size(); ++i){
            mult = 1;
            for(int j = i; j < nums.size(); ++j){
                mult *= nums[j];
                if(max < mult) max = mult;
            }
        }
        cout << max << endl;
        getline(cin, s);
    }
    
}