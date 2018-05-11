# Sorting Algorithms
## `comparator` in C++
Define **comparator** for **struct Interval**: 

```
sort(intervals.begin(), intervals.end(), **[](Interval &a, Interval &b) {return a.start < b.start;}**);
```
----

> All sorting algorithms below are to make the input array in *numerial ascending order*.

## Bubble Sort
- Main idea:
	- Easiest sorting method
	- each itertation move the minmum element of the unordered part to the end of the ordered part, i.e, in the ith iteration, move the ith minmum element to the ith element in the array
- Time Complexity: O(n^2)
- Space Complexity: O(1)
- [CPP Script](src/bubble_sort.cpp)	

## Selection Sort
- Main idea: 
	- each itertation traverse the unordered part and select the global minimum in 
	- put it at the end of the ordered part or in the ith iteration, swap the ith element and the minimum one
	- perform above until the last element
- Time Complexity: O(n^2)
- Space Complexity: O(1)
- [CPP Script](src/select_sort.cpp)

## Insertion Sort
- Main idea: 
	- in the ith iteration, swap the ith element and each one larger than it in the left side, i.e., to make the left i elements in order
- Time Complexity: O(n^2)
- Space Complexity: O(1)
- [CPP Script](src/insert_sort.cpp)

## Merge Sort
- Main idea: 
	- first split the array into ordered part (minimum case is only one element)
	- then merge two sorted array into the final sorted array
- Time Complexity: O(nlog(n))
- Space Complexity: O(n)
- [CPP Script](src/merge_sort.cpp)


## Heap Sort

## Shell SOrt
- Main idea: 
	- 
## radi sort

## bucket sort

# Summary
The table below is referring to [Algorithms, Part I](https://www.coursera.org/learn/introduction-to-algorithms).
<!-- |           | inplace? | stable? |  worst  | average |  best  |   remarks    |
| :-----:   | :-----:  | :-----: | :-----: | :-----: | :-----:|   :-----:    |
| Selection |    X     |         | O(n^2/2)| O(n^2/2)|O(n^2/2)| N exchanges  | -->

![sorting_summary](sorting_summary.png)



**Stable Sorting** means that the implementation preserves the input order of equal elements in the sorted order。




# References:
1. [排序和搜索](http://wdxtub.com/interview/14520597162931.html)
2. [几种常见排序算法](http://brianway.github.io/2016/05/08/algorithms-several-sort-algorithms)
3. [程序员面试秘籍 第九章 排序](https://github.com/zhuyaguang/kill-interview-part-2/tree/master/程序员面试秘籍%20第九章%20排序)
4. [链表排序（冒泡、选择、插入、快排、归并、希尔、堆排序）](http://www.cnblogs.com/TenosDoIt/p/3666585.html)