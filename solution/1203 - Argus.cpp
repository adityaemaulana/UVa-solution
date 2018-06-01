#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
#define pi pair<int, int>

using namespace std;

struct comp{
    bool operator()(pi f, pi s)
    {
        return f.second  > s.second || (f.second == s.second) && (f.first > s.first);
    }
};


int main(){
    priority_queue<pi, vector<pi>, comp> pq;
    vector<pi> v;
    string inst;
    int qnum, per, k;

    while(cin>>inst){
        if(inst == "#")
            break;
        cin>>qnum>>per;
        v.push_back(make_pair(qnum, per));
    }

    cin>>k;

    for(int i = 1; i <= k; i++){
        for(int j = 0; j < v.size(); j++){
            int temp = v[j].second * i;
            pq.push(make_pair(v[j].first, temp));
        }
    }

    while(k--){
        cout<<pq.top().first<<endl;
        pq.pop();
    }

    return 0;
}
