#include <bits/stdc++.h>
#define REP(i,n)   for(int i=0;i<(int)(n);++i)
#define FOR(i,l,r) for(int i=(int)(l);i<(int)(r);++i)
#define ALL(v)     (v).begin(),(v).end()
#define debug(x)   std::cerr<<"(L"<<__LINE__<<") "<<#x<<": "<<(x)<<std::endl
using ll  = long long;
using vi  = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int,int>;
using namespace std;
constexpr int       INF  = 1e9;
constexpr long long LINF = 1e18;
constexpr double    EPS  = 1e-10;
constexpr int       MOD  = 1e9+7;
template<class Class> void line(const Class &a,std::ostream &os=std::cerr){int cnt=0;for(const auto &elem:a)os<<(cnt++==0?"":" ")<<elem;os<<std::endl;}

int main(){
    string x;
    cin>>x;
    
    int n=x.size();
    
    set<ll> st;
    FOR(first,1,10)FOR(k,-9,9){ // O(9*19).
        string s(n,0);
        bool ok=true;
        REP(i,n){
            int num=first+i*k;
            if(0<=num and num<=9){
                s[i]='0'+num;   
            }else{
                ok=false;
                break; // REP(i).
            }
        }
        if(ok) st.insert(stol(s));
    }
    // line(st);
    
    auto ans=*st.lower_bound(stol(x));
    cout<<ans<<endl;
}

// I refered explanations.
