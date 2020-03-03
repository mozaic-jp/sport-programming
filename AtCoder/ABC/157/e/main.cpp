#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm> // sort
#include <unistd.h>
#include <map>
#include <set> 

#define pii pair<int,int>
#define REP(i, n) for (long long i = 0; i < (n); i++) 
using namespace std;


typedef long long ll;
static const ll INF = 1000000000000000000LL;
static const ll MOD = 1000000007;


//各範囲の文字の数をセグ木で保存
//各文字の部分累積和をとっておけば、
//

int main()
{
    int N;
    cin >> N;
    string s;
    cin >> s;
    
    set <int> st[26];
    REP(i,N)
    {
        st[s[i] - 'a'].insert(i);
    }

    int Q;
    cin >> Q;

    REP(i,Q)
    {
        int q;
        cin >> q;
        if(q == 1)
        {
            int l;
            char c;
            cin >> l >> c;
            --l;
            if(s[l] != c)
            {
                st[s[l] - 'a'].erase(l);
                st[c - 'a'].insert(l);
            }
        }
        else
        {
            int l,r;
            cin >> l >> r;
            --l;--r;
            int res = 0;
            REP(d,26)
            {
                int off = *st[d].lower_bound(l);
                if(off <= r)++res;
            }
            cout << res << endl;
        }
    }
    return 0;
}