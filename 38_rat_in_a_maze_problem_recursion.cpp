// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

bool safe(vector<vector<int>> &m, int n,  vector<vector<int>> &visited, int r, int c, string output, vector<string> &ans){
    if(r>=0 && r<n && c>=0 && c<n && visited[r][c]==0 && m[r][c]==1){
        return true;
    }
    else{
        return false;
    }
};

void letsGo(vector<vector<int>> &m, int n,  vector<vector<int>> visited, int r, int c, string output, vector<string> &ans){
    
    // base case
    if(r==(n-1) && c==(n-1)){
        ans.push_back(output);
        return;
    }
    
    visited[r][c]=1; 
    
    // checking for left
    if(safe(m, n, visited, r, c-1, output, ans)){
        
        output.push_back('L');
        letsGo(m, n, visited, r, c-1, output, ans);
        output.pop_back();
    }
    // checking for down
    if(safe(m, n, visited, r+1, c, output, ans)){
        output.push_back('D');
        letsGo(m, n, visited, r+1, c, output, ans);
        output.pop_back();
    }
    // checking for right
    if(safe(m, n, visited, r, c+1, output, ans)){
        output.push_back('R');
        letsGo(m, n, visited, r, c+1, output, ans);
        output.pop_back();
    }
    // checking for top
    if(safe(m, n, visited, r-1, c, output, ans)){
        output.push_back('U');
        letsGo(m, n, visited, r-1, c, output, ans);
        output.pop_back();
    }
    
    visited[r][c]=0; // backtracking
    
};

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector<string> ans;
        
        // edge case
        if(m[0][0]==0){
            return ans;
        }
    
        int r=0, c=0;
        
        // creating a mapping
        vector<vector<int>> visited = m;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                visited[i][j]=0;
            }
        }
       
        string output="";
        
        letsGo(m, n, visited, r, c, output, ans);
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};