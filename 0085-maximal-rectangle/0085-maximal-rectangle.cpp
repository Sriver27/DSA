class Solution {
private:
    vector<int> nextSmallerElement(vector<int> arr, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        
        for(int i = n-1; i>=0;i--)
        {
            int curr = arr[i];
            while(s.top() != -1 && (arr[s.top()]) >= curr)
                s.pop();
            
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmallerElement(vector<int> arr, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        
        for(int i = 0; i<n;i++)
        {
            int curr = arr[i];
            while(s.top() != -1 && (arr[s.top()]) >= curr)
                s.pop();
            
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int> heights) {
        
        int n = heights.size();
        
        vector<int> next(n);
        next = nextSmallerElement(heights,n);
        
        vector<int> prev(n);
        prev = prevSmallerElement(heights,n);
        
        int area = INT_MIN;
        
        for(int i = 0; i < n; i++)
        {
            int len = heights[i];
            
            if(next[i] == -1)
                next[i] = n;
            
            int breadth = next[i] - prev[i] - 1;
            
            int newArea = len * breadth;
            
            area = max(area,newArea);
        }
        
        return area;
    }    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        if(matrix.size()==0) return 0;
        // for each cell with value=1, we look upward (north), the number of continuous '1' is the height of cell
        vector<int> heights(matrix[0].size());
        int maxArea=-1;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]=='0'){
                    heights[j] = 0;
                } else {
                    heights[j] ++;
                }
            }            
            int area = largestRectangleArea(heights);
            maxArea = max(maxArea, area);
        }
        return maxArea;
        
    }
};