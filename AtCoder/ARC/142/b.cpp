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

void solve1(vvi &ans,const int n){
    int next=1;
    REP(i,2)for(int y=i;y<n;y+=2)REP(x,n) ans[y][x]=next++;
}

void solve2(vvi &ans,const int n){
    int next=1;
    REP(i,2)REP(y,n)for(int x=(y+i)%2;x<n;x+=2) ans[y][x]=next++;
}

int main(){
    int n;
    cin>>n;
    
    vvi ans(n,vi(n));
    solve1(ans,n);
    // solve2(ans,n);
    
    REP(i,n) line(ans[i],cout);
}

// I refered explanations.
