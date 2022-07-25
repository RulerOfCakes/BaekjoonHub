#include <bits/stdc++.h>

using namespace std;
using pi = pair<int,int>;
using ll = long long;

int N, M, cnt, G;
int weight[100002], depth[100002];
int parents[100002];
//numbers : the numbered value of a node(for decomposition)
//ori : the original index number of n[u](ori[n[u]])
//hld : the vertex with minimum depth value in the range of u(hld[u])
int numbers[100002], ori[100002], hld[100002];

vector<vector<pi>> sadj,adj;

class segtree {
public:
	vector<long long> tree;
	vector<long long> lazy; // lazy propagation
	int size;

	segtree (int n) {
		for (size = 1; size < n; size *= 2);
		tree.resize(size * 2, 0);
		lazy.resize(size * 2);
	}
	void update(int node, long long x) {
		int idx = size + node - 1;
		long long diff = x - tree[idx];
		while (idx) {
			tree[idx] += diff;
			idx /= 2;
		}
	}
	void update_lazy(int node, int start, int end) {
		if (!lazy[node])return;
		tree[node] += lazy[node] * (end - start + 1);
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	void update_range(int node, int nStart, int nEnd, int rStart, int rEnd, ll diff) {
		update_lazy(node, nStart, nEnd);
		if (nEnd < rStart || nStart > rEnd)return;
		if (nStart >= rStart && nEnd <= rEnd) {
			lazy[node] = diff;
			update_lazy(node, nStart, nEnd);
			return;
		}
		
		int mid = (nStart + nEnd) / 2;
		update_range(node*2, nStart, mid, rStart, rEnd, diff);
		update_range(node*2+1, mid + 1, nEnd, rStart, rEnd, diff);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
	long long getsum(int node, int nStart, int nEnd, int rStart, int rEnd) {
		update_lazy(node, nStart, nEnd);
		if (nEnd < rStart || nStart > rEnd) return 0;
		if (rStart <= nStart && rEnd >= nEnd) return tree[node];
		int mid = (nStart + nEnd) / 2;
		return getsum(node * 2, nStart, mid, rStart, rEnd) + getsum(node * 2 + 1, mid+1, nEnd, rStart, rEnd);
	}
};

//hld
void dfs(int u){
    weight[u]=1;
    for(auto& sv:adj[u]){
        int v = sv.first;
        if(!weight[v]){
            
            parents[v]=u;
            depth[v]=depth[u]+1;
            dfs(v);
            weight[u]+=weight[v];
        }
    }
}

void split(int u){
    int heavyidx=-1;
    numbers[u] = ++cnt;
    ori[numbers[u]]=u;
    //find the heaviest child
    for(auto& sv: adj[u]){
        int v = sv.first;
        if(parents[v]==u&&(heavyidx==-1||weight[v]>weight[heavyidx]))heavyidx=v;
    }
    //if found, link the current vertex with it as the same group and continue the split
    if(heavyidx!=-1){
        hld[heavyidx]=hld[u];
        split(heavyidx);
    }
    //the remaining children are all first nodes of a new group
    for(auto& sv : adj[u]){
        int v = sv.first;
        if(parents[v]==u&&v!=heavyidx){
            hld[v]=v;
            split(v);
        }
    }
}

void update(int eidx, int x, segtree& seg){
    seg.update(numbers[eidx],x);
}

void update(int u, int v, ll val, segtree& seg){
    while(hld[u]!=hld[v]){
        //u is the deeper node
        if(depth[hld[u]] < depth[hld[v]])swap(u,v);
        seg.update_range(1,1,seg.size,numbers[hld[u]],numbers[u],val);
        u=parents[hld[u]];
    }
    if(depth[u]>depth[v])swap(u,v);
    if(u==v)return;
    seg.update_range(1,1,seg.size,numbers[u]+1,numbers[v],val);
}
//used in query()
ll getsum(int u, int v, segtree& seg){
    ll ret=0;
    while(hld[u]!=hld[v]){
        if(depth[hld[u]]<depth[hld[v]])swap(u,v);
        ret+=seg.getsum(1,1,seg.size,numbers[hld[u]],numbers[u]);
        u=parents[hld[u]];
    }
    if(depth[u]>depth[v])swap(u,v);
    if(u==v)return ret;
    return ret+seg.getsum(1,1,seg.size,numbers[u]+1,numbers[v]);
}

ll query(int u, int v, segtree& seg){
    //int l = lca(u,v);
    //lca is always G
    int l = G;
    return getsum(u,l, seg)+getsum(v,l, seg);
}

void update_query(int u, int v, ll val, segtree& seg){
    //int l = lca(u,v);
    //lca is always G
    int l = G;
    update(u,l,val,seg);
    update(v,l,val,seg);
}

vector<int> dist;

void dijkstra(int x){
    dist=vector<int>(N+1,INT_MAX);
    priority_queue<pi> pq;
    pq.push({0,x});
    dist[x]=0;
    while(!pq.empty()){
        int cx,cc;
        tie(cc,cx)=pq.top();
        pq.pop();
        cc=-cc;
        if(dist[cx]<cc)continue;
        for(auto& [nx,nc] : sadj[cx]){
            if(dist[nx]<=cc+nc)continue;
            dist[nx]=cc+nc;
            pq.push({-(cc+nc),nx});
        }
    }
}

int orival[100002];

void make_tree(int x){
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<bool> visited(N+1,0);
    pq.push(x);
    visited[x]=1;
    while(!pq.empty()){
        priority_queue<int,vector<int>,greater<int>> npq;
        while(!pq.empty()){
            int cx=pq.top();pq.pop();
            for(auto [nx,nc] : sadj[cx]){
                if(visited[nx])continue;
                if(dist[nx]==dist[cx]+nc){
                    npq.push(nx);
                    visited[nx]=1;
                    adj[cx].push_back({nx,nc});
                    adj[nx].push_back({cx,nc});
                    orival[nx]=nc;
                }
            }
        }
        pq=npq;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> G;
    segtree seg(N+1),cseg(N+1);
    adj = vector<vector<pi>>(N+1,vector<pi>());
    sadj = vector<vector<pi>>(N+1,vector<pi>());

    for(int i = 0;i  < M; i++){
        int a,b,d;
        cin >> a >> b >> d;
        sadj[a].push_back({b,d});
        sadj[b].push_back({a,d});
    }
    for(int i = 1; i <= N; i++){
        if(sadj[i].size()){
            sort(sadj[i].begin(),sadj[i].end());
        }
    }
    //make a tree from given graph
    dijkstra(G);
    make_tree(G);
    for(int i = 1; i <= N; i++){
        if(adj[i].size()){
            sort(adj[i].begin(),adj[i].end());
        }
    }
    //begin hld
    dfs(G);
    split(G);
    
    for(int i = 1; i <= N; i++){
        update(i,orival[i],seg);
    }
    int Q;
    ll tsum=0;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        char c;
        int u, v;
        cin >> c >> u;
        if(c=='1'){
            cin >> v;
            tsum+=v;
            update_query(u,G,v,cseg);
        }
        else{
            cout << query(u,G,seg)+tsum*depth[u]-query(u,G,cseg) << '\n';
        }
    }
}