# LeetCode 219 - Contains Duplicate II

## 1. Intuition

The problem asks whether there exist two equal elements such that the absolute difference between their indices is at most `k`.

A brute-force solution would compare every pair of elements, resulting in **O(n²)** time complexity.

A better approach is to keep track of the most recent index where every number appeared. Whenever we encounter the same number again, we simply check if the distance between the current index and its previous occurrence is less than or equal to `k`.

---

## 2. Approach

1. Create a hash map to store the last index of every element.
2. Traverse the array from left to right.
3. For every element:
   - If it already exists in the map:
     - Calculate the distance between the current index and the previous index.
     - If the distance is less than or equal to `k`, return `true`.
   - Update the current index in the map.
4. If no valid pair is found, return `false`.

### Time Complexity

**O(n)**

### Space Complexity

**O(n)**

---

## 3. Code

```java
import java.util.HashSet;
import java.util.Set;

class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Set<Integer> set = new HashSet<>();
        
        for (int i = 0; i < nums.length; i++) {
            // Remove the element that is now outside the window
            if (i > k) {
                set.remove(nums[i - k - 1]);
            }
            
            // Try to add the current element. If it fails, a duplicate exists.
            if (!set.add(nums[i])) {
                return true;
            }
        }
        
        return false;
    }
}
```
