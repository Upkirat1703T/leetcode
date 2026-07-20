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

```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            if (mp.count(nums[i])) {
                if (i - mp[nums[i]] <= k)
                    return true;
            }
            mp[nums[i]] = i;
        }

        return false;
    }
};
```
