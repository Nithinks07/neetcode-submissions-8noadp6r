class Solution {

private:
    int dir[4][2] = {
        {1,0},{-1,0},{0,1},{0,-1}
    } ;
    set<pair<int,int>> path ;
    bool solve(int i, int j,int ind,vector<vector<char>>& board, string word){
        if(ind==word.size()) 
            return true ;
        if(
            i<0 || i>= board.size() || 
            j<0 || j>= board[0].size() ||
            word[ind]!=board[i][j] || path.count({i,j}) 
        )
            return false ;
        
        path.insert({i,j}) ;
        for(auto& d : dir){
            if(solve(i+d[0],j+d[1],ind+1,board,word))
                return true ;
        }
        path.erase({i,j}) ;
        return false ;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    if(solve(i,j,0,board,word))
                        return true ;
                }
            }
        }
        return false ;
    }
};
