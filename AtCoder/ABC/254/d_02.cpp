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
    
    bool is_square[n+1]={}; // is_square[i]:=(数iが平方数か否か).
    for(int i=1;i*i<=n;++i) is_square[i*i]=true;
    
    vvi d(n+1); // d[i][]:=(数iの約数のリスト).
    FOR(i,1,n+1)for(int j=i;j<=n;j+=i) d[j].push_back(i);
    
    vi cnt(n+1,0);
    FOR(i,1,n+1){
        int f; // f(i):=(整数iのうち最大の平方数).
        for(auto itr=d[i].rbegin();itr<d[i].rend();++itr){
            if(is_square[*itr]){
                f=*itr;
                break;
            }
        }
        cnt[i/f]++;
    }
    
    ll ans=0;
    FOR(i,1,n+1) ans+=cnt[i]*cnt[i];
    
    cout<<ans<<endl;
}
