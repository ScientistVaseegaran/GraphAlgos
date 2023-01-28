#include <cmath>
#include <cstdio>
#include <iostream> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <limits.h>
#include <string.h>
#include <stack>

typedef long long int ll;

#define VartaMaameDurrr ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1e9 + 7
#define fi(a,b) for(ll i = a; i < b; i++)
#define fj(a,b) for(ll j = a; j < b; j++)
#define fk(a,b) for(ll k = a; k < b; k++)

using namespace std;

ll n;
bool *visited = (bool*)malloc((n+1)*sizeof(bool));
bool *StackPresence = (bool*)malloc((n+1)*sizeof(bool));
ll* lowlink = (ll*)malloc((n+1)*sizeof(ll));
ll* ids = (ll*)malloc((n+1)*sizeof(ll));
ll id = 1;
stack <ll> VerStack;

void dfs(vector <ll> *gal, ll from, ll SCCcount){
    VerStack.push(from);
    visited[from] = true;
    StackPresence[from] = true;
    ids[from] = id;
    lowlink[from] = id;
    id++;
    for(auto to : gal[from]){
        if(!(visited[to])){
            dfs(gal,to,SCCcount);
        }
        if(StackPresence[to]){
            lowlink[from] = min(lowlink[from], lowlink[to]);
        }
    }

    if(ids[from] == lowlink[from]){
        while(ll node = VerStack.top()){
            VerStack.pop();
            lowlink[node] = ids[from];
            StackPresence[node] = false;
            if(node == from){
                break;
            }
        }
        SCCcount++;
    }
}

ll Tarjans(vector <ll> *gal){
    ll SCCcount = 0;
    fi(1,n+1){
        visited[i] = false;
    }
    fi(1,n+1){
        if(!(visited[i])){
            dfs(gal,i,SCCcount);
        }
    }
    return SCCcount;
}

void solve(){
    ll e,from,to,ans;
    cin >> n >> e;
    vector <ll> gal[n+1];
    fi(0,e){
        cin >> from >> to;
        gal[from].push_back(to);
    }
    ans = Tarjans(gal);
    cout << ans << "\n";
}

//Example
// 8 13
// 1 2
// 2 3
// 3 1
// 7 3
// 7 1
// 7 5
// 5 6
// 6 7
// 6 1
// 4 5
// 4 8
// 8 6
// 8 4

int main()
{
    VartaMaameDurrr;   
    solve();    
    return 0;
}