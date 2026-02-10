#include<iostream>
#include<algorithm>
#include<map>
#include<string>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;

    map<string, string> pwd_map;

    while(N--)
    {
        string add, pass;
        cin >> add >> pass;
        pwd_map[add] = pass;
    }
    while(M--)
    {
        string add;
        cin >> add;
        cout << pwd_map[add]<< "\n";
    }


    return 0;
}