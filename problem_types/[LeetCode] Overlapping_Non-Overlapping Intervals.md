LeetCode里面关于Overlapping/Non-Overlapping的主要有一下几类：
- 寻找重叠/非重叠区间（具体区间数组）结果
- 计算重叠/非重叠区间个数
- 合并重叠区间，并返回合并后的区间数组

相关题目为：
- 56. Merge Intervals
- 57. Insert Interval
- 252. Meeting Rooms
- 253. Meeting Rooms II
- 435. Non-overlapping Intervals
- 452. Minimum Number of Arrows to Burst Balloons

基本有两类模板，一类直接Interval类sort，一类分别sort区间的起、止点。排好序后，仅需判断后一个的start在前一个区间之内即可判断是否存在overlapping。因为两个区间的包含关系主要只有四种情况：

```C++
// 对任意区间[A,B], [C,D]
A      B               A      B            A     B            A              B 
     C     D      C      D             C           D            C      D
```

以56. Merge Intervals为例给出这两类解题模板：

```C++
vector<Interval> merge(vector<Interval>& intervals) {
	if (!intervals.size())   return intervals;
	sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b) {return a.start < b.start;});
    vector<Interval> res{intervals[0]};
    for (int i = 1; i < intervals.size(); i++) {
	    if (res.back().end >= intervals[i].start)
			res.back().end = max(res.back().end, intervals[i].end);
        else
            res.push_back(intervals[i]);
        }
        return res
}
```


```C++
vector<Interval> merge(vector<Interval>& intervals) {
	if (!intervals.size())   return intervals;
		vector<Interval> res;
	    vector<int> starts, ends;
	    for (auto a : intervals) {
		    starts.push_back(a.start);
	        ends.push_back(a.end);
	    }
	    sort(starts.begin(),starts.end());
	    sort(ends.begin(),ends.end());
	    for (int i = 0, j = 0; i < starts.size(); i++) {
		    if (i == starts.size() - 1 || starts[i+1] > ends[i]) {
		        res.push_back(Interval(starts[j], ends[i]));
	            j = i + 1;
	        }
	     }
	    return res;
}
```