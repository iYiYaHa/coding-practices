class Solution {
    
    class UnionFind{
        private int[] parent;
        private int[] size;
        private int clusterCnt;
        
        UnionFind(int n){
            parent = new int[n];
            size = new int[n];
            for(int i = 0; i < n; ++i){
                parent[i] = i;
            }
            clusterCnt = n;
        }
        
        public void union(int i, int j){
            int rootI = getRoot(i);
            int rootJ = getRoot(j);
            if(rootI == rootJ)
                return;
            int sizeI = size[rootI];
            int sizeJ = size[rootJ];
            if(sizeI <= sizeJ){
                parent[rootI] = parent[rootJ];
                size[rootJ] += size[rootI];
            }else{
                parent[rootJ] = parent[rootI];
                size[rootI] += size[rootJ];
            }
            --clusterCnt;
        }
        
        public int getRoot(int i){
            while(i != parent[i]){
                parent[i] = parent[parent[i]];
                i = parent[i];
            }
            return i;
        }
        
        public int getClusterCnt(){
            return clusterCnt;
        }
    }
    public int findCircleNum(int[][] isConnected) {
        if(isConnected == null || isConnected.length <= 0 || isConnected[0].length <= 0)
            return 0;
        int n = isConnected.length;
        UnionFind uf = new UnionFind(n);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(isConnected[i][j] == 1){
                    uf.union(i, j);
                }
            }
        }
        return uf.getClusterCnt();
    }
}