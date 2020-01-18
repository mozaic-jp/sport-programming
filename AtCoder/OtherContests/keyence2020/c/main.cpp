#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <math.h>
#include <algorithm> // sort

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll INF = 1000000000000000000LL;
using namespace std;

const int MOD = 1000000007;

int main(){
    ll N;
    cin >> N;
    //末尾がAのもの、先頭がBのものを集める、
    //どちらにも該当するやつは、べつで保存する

    ll a = 0;
    ll b = 0;
    ll ab = 0;
    ll res = 0;
    string s;
    REP(i,N)
    {
        cin >> s;
        for(int i = 1; i < s.size(); ++i)
        {
            if(s[i-1] == 'A' && s[i] =='B')++res;
        }

        if(s[0] == 'B' && s[s.size() - 1] == 'A')
        {
            ++ab;
        }
        else if(s[0] == 'B')++b;
        else if(s[s.size()-1] == 'A')++a;
    }

    //XXA 1
    //BXX 2
    //BXXA 2

    //XXABXXABXXABXX

    //BXXA は 3個で  A BXXABXXABXXA
    // (3-1)個

    res += ab;

    if(a > b)
    {
        res += b;
    }
    else
    {
        res += a;
    }

    if(a == 0 && b == 0 && ab > 0)
    {
        --res;
    }

    cout << res << endl;

    return 0;    
}
