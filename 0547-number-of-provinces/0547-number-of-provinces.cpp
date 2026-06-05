class DSU{
public:
    vector<int>parent,size;
    DSU(int n){
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent.push_back(i);
        }
    }
    int findPar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findPar(parent[node]);
    }
    void unionSet(int node1,int node2){
        node1=findPar(node1);
        node2=findPar(node2);
        if(node1!=node2){
            if(size[node1]<size[node2]){
                swap(node1,node2);
            }
            parent[node2]=node1;
            size[node1]+=size[node2];
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        DSU ds(n);
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]==1){
                    if(ds.findPar(i+1)!=ds.findPar(j+1)){
                        ds.unionSet(i+1,j+1);
                        count++;
                        cout<<count<<" "<<ds.parent[i+1]<<" "<<ds.parent[j+1]<<" "<<i+1<<" "<<j+1<<endl;
                    }
                }
            }
        }
        return n-count;
    }
};