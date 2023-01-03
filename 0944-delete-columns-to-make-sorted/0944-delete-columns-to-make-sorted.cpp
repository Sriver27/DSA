class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int delete_count=0;
        int row = strs.size();
        int col = strs[0].size();
        
        // column-wise
        for(int j=0; j<col; j++)
        {
            for(int i=0; i<row-1; i++)
            {
                if(strs[i][j]>strs[i+1][j])
                {
                    // increase the no. of columns to be deleted and then and there stop traversing that particular column
                    delete_count++;
                    break;
                }
            }
        }
        return delete_count;
    }
};