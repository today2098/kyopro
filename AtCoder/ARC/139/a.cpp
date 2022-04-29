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

template <typename Type>
void print_bits(Type a, std::ostream &os=std::cerr){
    int n=sizeof(a);
    std::string s(n,'0');
    for(int i=0;i<n;++i){
        if(a&1ULL) s[i]='1';
        a>>=1;
    }
    std::reverse(s.begin(),s.end());
    os<<s<<std::endl;
}

int main(){
    int n;
    cin>>n;

    vi t(n);
    for(auto &in:t) cin>>in;

    uint64_t a=1ULL<<t[0];
    FOR(i,1,n){
        if(t[i-1]>t[i]){
            a|=1ULL<<t[i];
        }else{
            a&=-1ULL<<t[i];
            a+=1ULL<<t[i];
            if((a>>t[i])&1ULL){}
            else a|=1ULL<<t[i];
        }
        // print_bits(a);
    }

    cout<<a<<endl;
}
