#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v){os<<"{";string sep="";for(const auto &x:v)os<<sep<<x,sep=", ";return os<<"}";}
template<typename T,size_t N> ostream& operator<<(ostream &os,const array<T,N> &a){os<<"{";string sep="";for(const auto &x:a)os<<sep<<x,sep=", ";return os<<"}";}
template<typename T> ostream& operator<<(ostream &os,const set<T> &s){os<<"{";string sep="";for(const auto &x:s)os<<sep<<x,sep=", ";return os<<"}";}
template<typename K,typename V> ostream& operator<<(ostream &os,const map<K,V> &m){os<<"{";string sep="";for(const auto &x:m)os<<sep<<"("<<x.first<<": "<<x.second<<")",sep=", ";return os<<"}";}
template<typename A,typename B> ostream& operator<<(ostream &os,const pair<A,B> &p){return os<<"("<<p.first<<", "<<p.second<<")";}

void dbg_out(){cerr<<endl;}
template<typename Head,typename... Tail>void dbg_out(Head H,Tail... T){cerr<<" "<<H;dbg_out(T...);}

#ifdef MIGUEL_DEBUG
    #define dbg(...) cerr<<"("<<#__VA_ARGS__<<"):" , dbg_out(__VA_ARGS__)
#else
    #define dbg(...)
#endif

void solve(){
    int n; cin >> n;
    struct Trampo {
        array<int, 7> dias;
        int grana;
    };
    vector<Trampo> a(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 7; j++) cin >> a[i].dias[j];
        cin >> a[i].grana;
    }
    int dp[3][3][3][3][3][3][3] = {0};
    for (auto &t: a) {
        for (int a = 2; a >= 0; a--)
        for (int b = 2; b >= 0; b--)
        for (int c = 2; c >= 0; c--)
        for (int d = 2; d >= 0; d--)
        for (int e = 2; e >= 0; e--)
        for (int f = 2; f >= 0; f--)
        for (int g = 2; g >= 0; g--) {
            array<int, 7> cur = {a, b, c, d, e, f, g};
            bool ok = true;
            for (int i = 0; i < 7; i++) {
                ok &= (cur[i] + t.dias[i]) <= 2;
            }
            if (!ok) continue;
            array<int, 7> nxt = cur;
            for (int i = 0; i < 7; i++) nxt[i] += t.dias[i];
            dp[nxt[0]][nxt[1]][nxt[2]][nxt[3]][nxt[4]][nxt[5]][nxt[6]] =
                max(dp[nxt[0]][nxt[1]][nxt[2]][nxt[3]][nxt[4]][nxt[5]][nxt[6]],
                    dp[a][b][c][d][e][f][g] + t.grana);
        }
    }
    cout << dp[2][2][2][2][2][2][2];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1; // cin>>T;
    while(T--)solve();
}