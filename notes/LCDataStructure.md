# Data Structure in C++

## Pair
- pair<int,int> p, using `p.first, p.second` to obtain each element of the pair


## Priority Queue
- priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
- priority_queue 是容器适配器，它提供常数时间的（默认）最大元素查找，对数代价的插入与释出。可用用户提供的 Compare 更改顺序，例如，用 **std::greater<T> 将导致最小元素作为 top() 出现**。

```C++
std::priority_queue<int, std::vector<int>, std::greater<int> > q2;

// 用 lambda 比较元素
auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1);};
std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);
```

- priority_queue<int> q;
- q.emplace(number);
- q.top();

## Set
### initialization:
- set<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
### Check for existing:
- primes.count(bits);
### insert // & erase
- primes.insert(xxxx);
### set to vector
- set<vector<int>> res;
- vector<vector<int>> (res.begin(), res.end());

## Sorting
- define **comparator** for **struct Interval**: 'sort(intervals.begin(), intervals.end(), **[](Interval &a, Interval &b) {return a.start < b.start;}**);'

## Stack
- stack<int> s;
- s.push(element);
- s.pop();
- int top_element = s.top();

## String
- string to int: `stoi(a)`; 
- int to string: `to_string(int/long)`
- substring: `string substr (size_t pos = 0, size_t len = npos) const;`
- find `s` at or after `pos` : `size_t find (const char* s, size_t pos = 0)`
- `isalpha()`, `isupper()`, `tolower()`, `toupper()`

## Struct
- TreeNode* res = new TreeNode(initial_value);

## Vector
### initialization:
- vector<string> res({S}); // string S
- vector<vector<int>> res(1); // build a [[]]
- vector<int> a(10);
- vector<int> dp(n,0);
- vector<int> a ( {7,3,5,8,9,1,2,4,6} );
- vector<int> a = {7,3,5,8,9,1,2,4,6};
- vector<int> output(nums.size(),1); // fill in with '1'
- vector<vector<bool>> visited (m, vector<bool>(n, false));
- vector<vector<int>> res(pow(2, nums.size()), vector<int>());
- vector<vector<int>> dir{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
- vector<Interval> res{intervals[0]};  struct Interval
### insert & erase
- vector<vector<int> > words;
- a.insert(a.begin() + i, first);
- a.erase(a.begin() + i);
### push & pop
- v.push_back(xxxx);
- v.pop_back();
### subvector:
- extract a subvector from a vector: `vector<int> subVec = vector<int>(vec.begin() + num1, vec.begin() + num2);`
