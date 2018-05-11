# Binary Search

> Referring to https://leetcode.com/explore/learn/card/binary-search/

## What is Binary Search?

In its simplest form, Binary Search operates on a contiguous sequence with a specified left and right index. This is called the Search Space. Binary Search maintains the `left`, `right`, and `middle` indicies of the search space and compares the search target or applies the search condition to the middle value of the collection; if the condition is unsatisfied or values unequal, the half in which the target cannot lie is eliminated and the search continues on the remaining half until it is successful. If the search ends with an empty half, the condition cannot be fulfilled and target is not found.

Binary Search is one of the most fundamental and useful algorithms in Computer Science. It describes the process of searching for a specific value in an ordered collection.

Terminology used in Binary Search:

Target - the value that you are searching for
Index - the current location that you are searching
Left, Right - the indicies from which we use to maintain our search Space
Mid - the index that we use to apply a condition to determine if we should search left or right

## how to identify Binary Search problems?

As mentioned in earlier, Binary Search is an algorithm that divides the search space in 2 after every comparison. Binary Search should be considered every time you need to search for an index or element in a collection. If the collection is unordered, we can always sort it first before applying Binary Search.



## 3 Parts of a Successful Binary Search

Binary Search is generally composed of 3 main sections:

- Pre-processing - Sort if collection is unsorted.

- Binary Search - Using a loop or recursion to divide search space in half after each comparison.

- Post-processing - Determine viable candidates in the remaining space.


## Templates
### Template #1:
Template #1 is used to search for an element or condition which can be determined by accessing a single index in the array.

```C++
int binarySearch(vector<int>& nums, int target){
  if(nums.size() == 0)
    return -1;

  int left = 0, right = nums.size() - 1;
  while(left <= right){
    // Prevent (left + right) overflow
    int mid = left + (right - left) / 2;
    if(nums[mid] == target){ return mid; }
    else if(nums[mid] < target) { left = mid + 1; }
    else { right = mid - 1; }
  }

  // End Condition: left > right
  return -1;
}
```

#### Key Attributes:

- Most basic and elementary form of Binary Search
- Search Condition can be determined without comparing to the element's neighbors (or use specific elements around it)
- No post-processing required because at each step, you are checking to see if the element has been found. If you reach the end, then you know the element is not found


#### Distinguishing Syntax:

- Initial Condition: `left = 0, right = length-1`
- Termination: `left > right`
- Searching Left: `right = mid-1`
- Searching Right: `left = mid+1`


### Template #2:
Template #2 is an advanced form of Binary Search. It is used to search for an element or condition which requires accessing the current index and its immediate right neighbor's index in the array.


```C++
int binarySearch(vector<int>& nums, int target){
  if(nums.size() == 0)
    return -1;

  int left = 0, right = nums.size();
  while(left < right){
    // Prevent (left + right) overflow
    int mid = left + (right - left) / 2;
    if(nums[mid] == target){ return mid; }
    else if(nums[mid] < target) { left = mid + 1; }
    else { right = mid; }
  }

  // Post-processing:
  // End Condition: left == right
  if(left != nums.size() && nums[left] == target) return left;
  return -1;
}
```


which means left != right in while (), each time we shoud deal with the elements which left and right point to, and should perform Post-processing to deal with the last element pointed by current "right" ptr
```
int findPeakElement(const vector<int> &num) 
    {
        int low = 0;
        int high = num.size()-1;
        
        while(low < high)
        {
            int mid1 = (low+high)/2;
            int mid2 = mid1+1;
            if(num[mid1] < num[mid2])
                low = mid2;
            else
                high = mid1;
        }
        return low;
    }
```

#### Key Attributes:

- An advanced way to implement Binary Search.
- Search Condition needs to access element's immediate right neighbor
- Use element's right neighbor to determine if condition is met and decide whether to go left or right
- Gurantees Search Space is at least 2 in size at each step!!!
- Post-processing required. Loop/Recursion ends when you have 1 element left. Need to assess if the remaining element meets the condition.!!!
 

#### Distinguishing Syntax:

- Initial Condition: `left = 0, right = length`
- Termination: `left == right`
- Searching Left: `right = mid`
- Searching Right: `left = mid+1`



### Template #3:




## why we use Binary Search?





#### A Question List

