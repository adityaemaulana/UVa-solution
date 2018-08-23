#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

typedef vector<int> vi;

const int SET = 1;
const int RESET = 2;
const int FLIP = 3;

class SegmentTree {
private:
    vi st, A, lazy;
    int n;
    int left(int p){ return p << 1; }
    int right(int p){ return (p << 1) + 1; }

    void build(int p, int L, int R){
        if(L == R)
            st[p] = A[L];
        else{
            build(left(p), L, (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R);
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = p1 + p2;
        }
    }

    void setType(int p, int type){
        if(type == FLIP){
            if(lazy[p] == SET)
                lazy[p] = RESET;
            else if(lazy[p] == RESET)
                lazy[p] = SET;
            else if(lazy[p] == FLIP)
                lazy[p] = 0;
            else
                lazy[p] = FLIP;
        }
        else
            lazy[p] = type;
    }

    void doUpdate(int p, int L, int R){
        if(lazy[p] == SET)
            st[p] = (R - L + 1);
        else if(lazy[p] == RESET)
            st[p] = 0;
        else if(lazy[p] == FLIP)
            st[p] = (R - L + 1) - st[p];
        else
            st[p] = st[p];

        if(L != R){
            setType(right(p), lazy[p]);
            setType(left(p), lazy[p]);
        }
        lazy[p] = 0;
    }

    int rsq(int p, int L, int R, int i, int j){
        if(i > R || j < L) return -1;

        if(lazy[p] != 0)
            doUpdate(p, L, R);

        if(L >= i && R <= j) return st[p];

        int p1 = rsq(left(p), L, (L+R) / 2, i, j);
        int p2 = rsq(right(p), (L+R) / 2 + 1, R, i, j);

        if(p1 == -1) return p2;
        if(p2 == -1) return p1;
        st[p] = st[left(p)] + st[right(p)];

        return (p1 + p2);
    }

    void update(int p, int L, int R, int i, int j, int val){
        if(lazy[p] != 0)
            doUpdate(p, L, R);

        if(i > R || j < L) return;

        if(L >= i && R <= j){
            setType(p, val);
            doUpdate(p, L, R);
            return;
        }

        update(left(p), L, (L + R) / 2, i, j, val);
        update(right(p), (L + R) / 2 + 1, R, i, j, val);
        st[p] = st[right(p)] + st[left(p)];
    }

public:
    SegmentTree(const vi &_A){
        A = _A; n = (int)A.size();
        st.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    int rsq(int i, int j){ return rsq(1, 0, n - 1, i, j); }

    void update(int i, int j, int new_value){
        return update(1, 0, n - 1, i, j, new_value);
    }
};

int main(){
    ofstream out("o.txt");
    int t, m, l, q, a, b;
    string cmd;

    cin>>t;
    for(int i = 1; i <= t; i++){
        cout<<"Case "<<i<<":"<<endl;
        vi A;
        string str;

        cin>>m;
        while(m--){
            cin>>l;
            getline(cin,str);
            getline(cin,str);
            for (int j=1; j <= l; j++)
                for (unsigned int k=0; k < str.length(); k++) A.push_back(int(str[k])-48);
        }


        SegmentTree st(A);

        cin>>q;
        int numCase = 1;
        while(q--){
            cin>>cmd>>a>>b;
            if(cmd == "F")
                st.update(a, b, SET);
            else if(cmd == "E")
                st.update(a, b, RESET);
            else if(cmd == "I")
                st.update(a, b, FLIP);
            else{
                cout<<"Q"<<numCase<<": "<<st.rsq(a, b)<<endl;
                numCase++;
            }
        }
    }
    out.close();
}

