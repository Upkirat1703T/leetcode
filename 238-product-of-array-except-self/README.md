# LeetCode 238 - Product of Array Except Self

## 1. Intuition

Computing the product for every index by multiplying all other elements would require **O(n²)** time.

Since division is not allowed, we compute the product of all elements to the left and right of every index. The answer for each position becomes:

`Left Product × Right Product`

We can accomplish this without using extra arrays by storing prefix products in the answer array and maintaining a running suffix product.

---

## 2. Approach

1. Create an answer array initialized with `1`.
2. Traverse from left to right while maintaining the prefix product.
3. Store the prefix product in the answer array.
4. Traverse from right to left while maintaining the suffix product.
5. Multiply each answer by the current suffix product.
6. Return the answer array.

### Time Complexity

**O(n)**

### Space Complexity

**O(1)** (excluding the output array)

---

## 3. Code

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n);
        output[0] = 1;
        for(int i=1; i<n; i++){
            output[i] = output[i-1] * nums[i-1];
        }
        int right = 1;
        for(int i=n-1; i>=0; i--){
            output[i] *= right;
            right *= nums[i];
        }
        return output;
    }
};
```
