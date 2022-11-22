class Solution {
public:
    
    
bool isSquare(int x)
{
    int sqRoot = sqrt(x);
    return (sqRoot * sqRoot == x);
}
    
    int numSquares(int n) {
        
        // Recursive solution ------>
        
//         // base cases
// 	// if n is perfect square then
// 	// Minimum squares required is 1
// 	// (144 = 12^2)
// 	if (sqrt(n) - floor(sqrt(n)) == 0)
// 		return 1;
// 	if (n <= 3)
// 		return n;

// 	// getMinSquares rest of the
// 	// table using recursive
// 	// formula
// 	// Maximum squares required
// 	// is n (1*1 + 1*1 + ..)
// 	int res = n;

// 	// Go through all smaller numbers
// 	// to recursively find minimum
// 	for (int x = 1; x <= n/2; x++)
// 	{
// 		int temp = x * x;
// 		if (temp > n)
// 			break;
// 		else
// 			res = min(res, 1 + numSquares
// 								(n - temp));
// 	}
// 	return res;
        
        
        
        
        
       // <---- Lagrange’s Four Square Theorem ----->
                 // TC : O(sqrt(n))
        
         // ans = 1 if the number is a perfect square
    if (isSquare(n)) {
        return 1;
    }
 
    // ans = 2:
    // we check for each i if n - (i * i) is a perfect
    // square
    for (int i = 1; i <= (int)sqrt(n); i++) {
        if (isSquare(n - (i * i))) {
            return 2;
        }
    }
 
    // ans = 4
    // possible if the number is representable in the form
    // 4^a (8*b + 7).
    while (n % 4 == 0) {
        n >>= 2;
    }
    if (n % 8 == 7) {
        return 4;
    }
 
    // since all the other cases have been evaluated, the
    // answer can only then be 3 if the program reaches here
    return 3;
        
    }
};


 


