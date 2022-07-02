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
    int n,k;
    int q;
    cin>>n>>k>>q;
    
    vi a(k);
    for(auto &in:a) cin>>in;
    
    while(q--){
        int l;
        cin>>l;
        l--;
        
        if(l==k-1){
            if(a[l]<n) a[l]++;
        }else{
            if(a[l]+1<a[l+1]) a[l]++;
        }
    }
    
    line(a,cout);
}
