// Recursive Solution

// class Solution {
// public:
//    int minTotalUtil(vector<vector<int>>& triangle, int h, int j) {
        
//        if(h == triangle.size()) {
//              return 0;
//         }  
        
//         return triangle[h][j]+min(minTotalUtil(triangle, h+1, j),minTotalUtil(triangle, h+1, j+1));
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
         
//           return minTotalUtil(triangle, 0, 0);
//     }
// };



class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};