#include <bits/stdc++.h>
#define REP(i,n)   for(int i=0;i<(int)(n);++i)
#define FOR(i,l,r) for(int i=(int)(l);i<(int)(r);++i)
#define ALL(v)     (v).begin(),(v).end()
using ll  = long long;
using vi  = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int,int>;
using namespace std;
constexpr int       INF  = 1e9;
constexpr long long LINF = 1e18;
constexpr double    EPS  = 1e-10;
constexpr int       MOD  = 1e9+7;

int main(){
    int n;
    int c;
    cin>>n>>c;
    
    vector<pii> vp(n);
    for(auto &[t,a]:vp) cin>>t>>a;
    
    bool f[30][2]={};
    REP(i,30) f[i][1]=true;
    for(const auto &[t,a]:vp){
        if(t==1){
            REP(i,30){
                if(a>>i&1){}
                else{
                    REP(j,2) f[i][j]=false;
                }
            }
        }else if(t==2){
            REP(i,30){
                if(a>>i&1){
                    REP(j,2) f[i][j]=true;
                }
            }
        }else{
            REP(i,30){
                if(a>>i&1){
                    REP(j,2) f[i][j]=!f[i][j];
                }
            }    
        }
        
        bitset<30> tmp(c);
        REP(i,30) tmp[i]=f[i][tmp[i]];
        c=tmp.to_ulong();
        
        cout<<c<<endl;
    }
}

// I refered explanations.
