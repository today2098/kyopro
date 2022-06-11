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
    int n,q;
    cin>>n>>q;
    
    vi a(n);
    for(auto &in:a) cin>>in;
    sort(ALL(a));
    
    vector<pii> query(q);
    REP(i,q){
        int x;
        cin>>x;
        query[i]=pii(x,i);
    }
    sort(ALL(query));
    
    ll sum=0;
    for(const auto &elem:a) sum+=elem;
    int pre=0;
    auto l=a.begin();
    auto r=a.begin();
    vector<ll> ans(q);
    for(const auto &[x,i]:query){
        if(x==pre){}
        else{
            auto nl=lower_bound(ALL(a),x);
            auto nr=upper_bound(ALL(a),x);
            sum+=(x-pre)*(l-a.begin());
            sum-=(x-pre)*(a.end()-nr);
            for(auto itr=l;itr<nr;++itr){
                sum-=*itr-pre;
                sum+=x-*itr;
            }
            
            pre=x;
            l=nl, r=nr;
        }
        
        ans[i]=sum;
    }
    
    line(ans,cout);
}
