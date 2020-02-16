#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;
#define REP(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(long long i=(a),i##Len_=(b);i<i##Len_;i++)
typedef long ll;


map<ll, string> st;
int main() {

    ll N,M;
    cin >> N >> M;

    //p県
    vector <pair<ll,ll>> py(M);


    REP(i,M)
    {
        cin >> py[i].first >> py[i].second;
    }

    vector <pair<ll,ll>> moto(M);

    moto = py;

    sort(py.begin(),py.end());

    //同じ県なら振り直す
    ll ken = -1;
    ll cnt = 1;

    REP(i,M)
    {
        if(ken == py[i].first)
        {
            cnt++;
        }
        else
        {
            cnt = 1;
            ken = py[i].first;

        }

        //年で紐付け
        std::ostringstream sout;
        sout << std::setfill('0') << std::right << std::setw(6) << py[i].first; // "000000"
        sout << std::setfill('0') << std::right << std::setw(6) << cnt; // "000000"
        string tmp = sout.str();

        st[py[i].second] = tmp;
    }

    REP(i,M)
    {  
        cout << st[moto[i].second] << endl;
    }



    return 0;

}
