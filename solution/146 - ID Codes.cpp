#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(){
    string str;
    while(cin >> str)
    {
        if(str == "#")
            break;
        vector<char> v(str.begin(), str.end());

        next_permutation(v.begin(), v.end());
        string sol(v.begin(), v.end());

        sort(v.begin(), v.end());
        string first_perm(v.begin(), v.end());

        if(sol != first_perm)
            cout<<sol<<endl;
        else
            cout<<"No Successor"<<endl;
    }
    return 0;
}
