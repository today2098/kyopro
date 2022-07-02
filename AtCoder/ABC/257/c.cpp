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
    string s;
    cin>>n>>s;
    
    vector<pii> vp(n);
    REP(i,n){
        int w;
        cin>>w;
        vp[i]=pii(w,i);
    }
    sort(ALL(vp));
    
    int tmp=0;
    for(auto c:s){
        if(c=='1') tmp++;
    }
    
    int ans=tmp;
    int i=0;
    while(i<n){
        int x=vp[i].first;
        while(i<n and vp[i].first<=x){
            int id=vp[i].second;
            tmp+=(s[id]=='0'?1:-1);
            i++;
        }
        ans=max(ans,tmp);
    }
    
    cout<<ans<<endl;
}
