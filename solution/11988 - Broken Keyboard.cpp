#include <iostream>
#include <list>
#include <string>

using namespace std;
list<char> letter;

int main(){

    string s;
    while(getline(cin, s)){
        letter.clear();
        list<char>::iterator it = letter.begin();
        int i = 0;

        while(i < s.size()){
            if(s[i] == 91){
                it = letter.begin();
                i++;
            }else if(s[i] == 93){
                it = letter.end();
                i++;
            }else{
                letter.insert(it, s[i]);
                i++;
            }
        }

        for(list<char>::iterator it = letter.begin(); it != letter.end(); it++){
            cout<<*it;
        }
        cout<<endl;
    }
}
