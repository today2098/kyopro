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
    int n;
    cin>>n;
    
    vi c(9);
    for(auto &in:c) cin>>in;
    
    int min_c=*min_element(ALL(c));
    int digit=n/min_c;
    
    string ans(digit,0);
    REP(i,digit){
        for(int j=8;j>=0;--j){
            int rest=n-c[j];
            if(rest>=0 and rest/min_c>=digit-i-1){
                ans[i]='0'+j+1;
                n-=c[j];
                break;
            }
        }
    }
        
    cout<<ans<<endl;
}

// I refered explanations.
