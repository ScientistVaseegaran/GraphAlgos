#include <iostream> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <limits.h>

typedef long long int ll;
#define MOD 1e9 + 7
#define fi(a,b) for(ll i = a; i < b; i++)
#define fj(a,b) for(ll j = a; j < b; j++)
#define fk(a,b) for(ll k = a; k < b; k++)

using namespace std;

void bellman(unordered_map <ll,vector <vector <ll>>> gal, ll n, ll start,ll* dist){
    dist[start] = 0;
    fi(1,n-1){
        for(auto m : gal[i]){
            dist[m[0]] = min(dist[m[0]],dist[i]+m[1]);
        }
    }
    fi(1,n-1){
        for(auto m : gal[i]){
            if((dist[i]+m[1]) < dist[m[0]]){
                dist[i] = INT_MIN;
                dist[m[0]] = INT_MIN;
            }
        }
    }

}

void solve(){
    ll n,e,start;
    cin >> n >> e;
    unordered_map <ll,vector <vector <ll>>> gal;
    ll dist[n+1];
    fi(1,n+1){
        dist[i] = INT_MAX;
    }
    ll from,to,weight;
    fi(0,e){
        cin >> from >> to >> weight;
        vector <ll> temp = {to,weight};
        gal[from].push_back(temp);
    }
    cin >> start;
    bellman(gal,n,start,dist);
    fi(1,n+1){
        cout << dist[i] << " ";
    }
}

//example
// 10 13
// 1 2 5
// 2 3 20
// 3 4 10
// 4 3 -15
// 2 7 60
// 7 8 -50
// 8 9 -10
// 2 6 30
// 3 5 75
// 6 5 25
// 6 7 5
// 5 10 100
// 6 9 50
// 1

int main(){
	// VarteMaameDurrr;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	ll t; cin >> t;
	while (t--) {
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}