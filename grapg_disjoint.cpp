#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, rank, size;
public:
        DisjointSet(int n){
            parent.resize(n+1);
            rank.resize(n+1, 0);
            size.resize(n+1, 1); // Initialize size for union by size
            for(int i = 0; i <= n+1; i++){ // Fixed loop condition
                parent[i] = i;
            }
        }
        int findUParent(int node){
            if(node == parent[node]) return node;
            return parent[node] = findUParent(parent[node]);
        }
        void unionByRank(int u, int v){
            int pu = findUParent(u);
            int pv = findUParent(v);

            if(pu == pv) return;

            if(rank[pu] < rank[pv]){
                parent[pu] = pv;
            } else if(rank[pv] < rank[pu]){
                parent[pv] = pu;
            } else {
                parent[pv] = pu;
                rank[pu]++;
            }
        }
         void unionBySize(int u, int v){
            int pu = findUParent(u);
            int pv = findUParent(v);

            if(pu == pv) return;
            if(size[pu] < size[pv]){
              parent[pu] = pv;
              size[pv] += size[pu];
            }
            else {
              parent[pv] = pu;
              size[pu] += size[pv];
            }

         }
};

int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    // Check if 3 and 7 are in the same set
    if(ds.findUParent(3) == ds.findUParent(7)){
        cout << "3 and 7 are in the same set." << endl;
    } else {
        cout << "3 and 7 are not in the same set." << endl;
    }

    ds.unionByRank(3, 7);

        if(ds.findUParent(3) == ds.findUParent(7)){
        cout << "3 and 7 are in the same set." << endl;
    } else {
        cout << "3 and 7 are not in the same set." << endl;
    }

    return 0;
}