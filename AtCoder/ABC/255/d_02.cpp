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
    
    vector<ll> a(n);
    for(auto &in:a) cin>>in;
    sort(ALL(a));
    
    vector<ll> sum(n+1); // sum[i]:=(数列aの区間[0,i)の累積和).
    sum[0]=0;
    FOR(i,1,n+1) sum[i]+=sum[i-1]+a[i-1];
    
    while(q--){
        ll x;
        cin>>x;
        
        auto itr=lower_bound(ALL(a),x);
        int k=itr-a.begin();
        ll ans=(k*x-sum[k])+(sum[n]-sum[k]-(n-k)*x);
        
        cout<<ans<<endl;
    }
}
