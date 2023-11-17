#include <iostream>
#include <map>
using namespace std;
int main(){
    int n, sum;
    cin >> n;
    getchar();
    while(n--){
        string s;
        getline(cin, s);
        sum = 0;
        int counter[7];
        int len = *(&counter + 1) - counter;
        for(int i = 0; i < len; i++){
            counter[i] = 0;
        }
        string memory = string();
        char c = s.at(0);
        bool valid = true;
        for(int i = 0; i < s.length(); ++i){
            if(c != s.at(i)){
                memory += c;
            }
            c = s.at(i);
            switch (c)
            {
            case 'B':
                sum += 1;
                counter[0]++;
                break;
            case 'U':
                sum += 10;
                counter[1]++;
                break;
            case 'S':
                sum += 100;
                counter[2]++;
                break;
            case 'P':
                sum += 1000;
                counter[3]++;
                break;
            case 'F':
                sum += 10000;
                counter[4]++;
                break;
            case 'T':
                sum += 100000;
                counter[5]++;
                break;
            case 'M':
                sum += 1000000;
                counter[6]++;
                break;
            }
        }
        for(int i = 0; i < len; ++i){
            if(counter[i] > 9){
                valid = false;
                break;
            }
        }
        memory += c;
        bool startToEnd = true;
        bool endToStart = true;
        string order;
        order = "BUSPFTM";
        for(int i = 0; i < memory.length(); ++i){
            int p = order.find(memory.at(i));
            if(p == -1) startToEnd = false;
            order = order.substr(p+1, order.length());
            
        }
        order = "MTFPSUB";
        for(int i = 0; i < memory.length(); ++i){
            int p = order.find(memory.at(i));
            if(p == -1) endToStart = false;
            order = order.substr(p+1, order.length());
        }
        if(!(startToEnd || endToStart)) valid = false;
        if(valid) cout << sum << endl;
        else cout << "error" << endl;
    }
}