**Brute Force :**
TC: O(n^2)
Implement nested for-loops and try to check for required sum
​
**Approach 2 : using two-pointer**
TC : O(n logn)
Take the left pointer to the start of the array, and right pointer to end of array and then check for sum. If equal to sum, store the indices and return. If greater than sum, then decrement the right pointer else increment left pointer
​
**Approach 3 : using map**
TC : O(n)
We need to find 2 numbers a, b so that a + b = target.
We need a HashMap datastructure to store elements in the past, let name it seen.
The idea is that we iterate b as each element in nums, we check if we found a (where a = target - b) in the past.
If a exists in seen then we already found 2 numbers a and b, so that a + b = target, just output their indices.
Else add b to the seen.
​