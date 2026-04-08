class Solution {
public:
    int uniquePaths(int m, int n) {
        return dfs(m,n,0,0);
    }

    int dfs ( int m, int n, int i, int j) {
        if ( i == m-1 && j == n-1)
            return 1;
        
        int possible = 0;
        if ( i+1 <= m-1 && j <=n-1)
            possible = dfs(m,n,i+1,j);
        
        if(i <= m-1 && j+1 <= n-1)
            possible += dfs(m,n,i,j+1);
        
        return possible;
    }
};
