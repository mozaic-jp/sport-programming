#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm> // sort
#include <unistd.h>
#include <map>
#include <deque>

#define pii pair<int,int>
#define REP(i, n) for (long long i = 0; i < (n); i++) 
using namespace std;

typedef long long ll;
static const ll INF = 1000000000000000000LL;
static const ll MOD = 1000000007;

int main()
{
    string s;
    cin >> s;

    int q;
    cin >> q;

    deque<char> data;  
    REP(i,s.size())
    {
        data.push_back(s[i]);
    }
    //反転の状態 trueのとき通常
    bool ima = true;

    REP(i, q)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            ima = !ima;
        }
        else
        {
            int f;
            char c;
            cin >> f >> c;
            if(ima)
            {
                if(f == 1)
                {
                    data.push_front(c);
                }
                else
                {
                    //末尾
                    data.push_back(c);
                }
            }
            else
            {
                if(f == 1)
                {
                    data.push_back(c);
                }
                else
                {
                    //先頭
                    data.push_front(c);
                }
            }
        }
    }


    int n = data.size();
    
    if(ima)
    {
        REP(i,n)
        {
            //先頭から出力
            cout << data.front();
            data.pop_front();
        }
    }
    else
    {
        REP(i,n)
        {
            //末尾から出力
            cout << data.back();
            data.pop_back();
        }       
    }

    cout << endl;




    return 0;
}