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
std::vector<Type> table(size_t n, Type val) { return std::vector<Type>(n, val); }

template <class... Args>
auto table(size_t n, Args... args) {
    auto val = table(args...);
    return std::vector<decltype(val)>(n, std::move(val));
}

int main(){
    int n,k;
    string s;
    cin>>n>>k>>s;

    auto &&posi=table(n,26,-1); // posi[i][c]:=(文字列sのi文字以降に文字cがある最左インデックス).
    posi[n-1][s[n-1]-'a']=n-1;
    for(int i=n-2;i>=0;--i)REP(c,26){
        if(c==s[i]-'a') posi[i][c]=i;
        else posi[i][c]=posi[i+1][c];
    }

    string ans(k,0);
    int p=0;
    REP(i,k)REP(c,26){
        if(posi[p][c]>=0 and n-posi[p][c]>=k-i){
            ans[i]='a'+c;
            p=posi[p][c]+1;
            break; // REP(c).
        }
    }

    cout<<ans<<endl;
}
