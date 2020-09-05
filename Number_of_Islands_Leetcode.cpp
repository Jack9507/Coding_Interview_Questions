//  First way with dfs :

class Solution {
public:
    int dfs(vector<vector<char>> &nums, int i, int j)
    {
        if(i <0 || i>=nums.size() || j <0 || j>= nums[0].size() || nums[i][j] =='0')
            return 0;
        
        nums[i][j] = '0';         // since we explored the current pos. so make it visited
        
        dfs(nums, i+1, j);
        dfs(nums, i-1, j);
        dfs(nums, i, j+1);
        dfs(nums, i, j-1);
    
        return 1;
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        if(grid.size() ==0)
            return 0;
        
        int res =0;    // start with zero islands
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[i].size(); j++)
            {
                if(grid[i][j] == '1')
                    res += dfs(grid, i, j);     
            }
        }
        return res;
        
    }
};



// Second way with bfs (iterative approach)   faster than recursive one.


class Solution {
public:
    void bfs(vector<vector<char>> &grid, int i, int j)
    {
        queue<pair<int,int> > q;
        q.push({i,j});
        
        grid[i][j]='0';        // once pushed in queue make it visited
        
        while(!q.empty())
        {
            pair<int, int> tmp= q.front();
            q.pop();
            
            int x=tmp.first;
            int y=tmp.second;
       
            
            if(x<grid.size()-1 && grid[x+1][y] =='1')
            {
               q.push({x+1,y});
               grid[x+1][y]='0';  
            }
            
            if(x>0 && grid[x-1][y] =='1')
            {
               q.push({x-1,y});
               grid[x-1][y]='0';  
            }
            
            if( y<grid[0].size()-1 && grid[x][y+1] =='1')
            {
               q.push({x,y+1});
               grid[x][y+1]='0';  
            }
            
            if( y>0 && grid[x][y-1] =='1')
            {
               q.push({x,y-1});
               grid[x][y-1]='0';  
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        if(grid.size() ==0)
            return 0;
        
        int res =0;    // start with zero islands
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[i].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    res++;
                    bfs(grid, i,j);
                }
                         
            }
        }
        return res;
        
    }
};
