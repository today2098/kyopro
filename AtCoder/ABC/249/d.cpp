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
    
    vector<ll> cnt((int)2e5+10, 0);
    REP(i,n){
        int a;
        cin>>a;
        cnt[a]++;
    }
    
    ll ans=0;
    for(int i=1;i<=2e5;++i){ // O(M*logM).
        for(int j=1;i*j<=2e5;++j){
            ans+=cnt[i]*cnt[j]*cnt[i*j];
        }
    }
    
    cout<<ans<<endl;
}

// I refered explanations.
