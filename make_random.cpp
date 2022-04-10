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
    std::random_device seed;
    // std::mt19937 rnd(seed());
    std::mt19937_64 rnd(seed());

    // std::uniform_int_distribution<> dist_(0, 100);
    // std::normal_distribution<> ndist_(50.0, 10.0);

    std::uniform_int_distribution<> dist_n(1,10);
    int n = dist_n(rnd);
    cout<<n<<endl;
    
    vi v(n);
    REP(i,n) v[i]=i+1;
    
    int mx=1;
    for(int i=1;i<=n;++i) mx*=i;
    std::uniform_int_distribution<> dist_pq(1,mx);
    int p=dist_pq(rnd);
    int q=dist_pq(rnd);
    int cnt=1;
    do{
        if(cnt==p){
            for(auto out:v) cout<<out<<' ';
            cout<<endl;
        }
        if(cnt==q){
            for(auto out:v) cout<<out<<' ';
            cout<<endl;
        }
        cnt++;
    }while(next_permutation(ALL(v)));
}
