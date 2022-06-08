class Solution {
public:
    void helper(int i, int j, vector<vector<int>> &image, int oldColor, int newColor, int n, int m)
{
    // Base conditions
        
    if(i < 0 || j < 0 || i == n || j == m || image[i][j] != oldColor) return;
    
    image[i][j] = newColor;// since the base condition didn't match, then we are standing on a pixel that needs to be colored
        
        // Recursive relations - traversing in all 4 directions
        
    helper(i+1,j,image,oldColor,newColor,n,m);
    helper(i-1,j,image,oldColor,newColor,n,m);
    helper(i,j+1,image,oldColor,newColor,n,m);
    helper(i,j-1,image,oldColor,newColor,n,m);
}

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int oldColor = image[sr][sc];
    int m = image[0].size();
    int n= image.size();
    
    if(oldColor == newColor) return image; //edge case - if we would have not written this we would have been stuck in an infinite loop, because we are always trying to color what is already there
    
    helper(sr,sc,image,oldColor,newColor,n,m);
    
    return image;
        
    }
};