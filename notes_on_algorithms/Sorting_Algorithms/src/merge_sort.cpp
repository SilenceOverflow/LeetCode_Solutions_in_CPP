#include <iostream>
#include <vector>

using namespace std;
vector<int> merge(const vector<int> a, const vector<int> b);


vector<int> merge_sort(vector<int>& nums, int left, int right) {
    vector<int> res;
    if (nums.empty() || !nums.size())
        return res;

    // base case, only one element
    if (left == right) {
        res.push_back(nums[left]);
        return res;
    }

    int mid = left + (right - left) / 2;
    vector<int> l = merge_sort(nums, left, mid);
    vector<int> r = merge_sort(nums, mid+1, right);
    res = merge(l, r);

    return res;
}

vector<int> merge(const vector<int> a, const vector<int> b) {
    vector<int> res;
    int l = 0, r = 0;
    int n = a.size(), m = b.size();
    while (l < n && r < m) {
        if (a[l] < b[r]) {
            res.push_back(a[l]);
            l++;
        }
        else {
            res.push_back(b[r]);
            r++;
        }
    }

    while (l < n) {
        res.push_back(a[l]);
        l++;
    }
    while (r < m) {
        res.push_back(b[r]);
        r++;
    }

    return res;
}



void print_nums(const vector<int>& nums)
{
    if (nums.empty() || !nums.size())
        return;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}


int main() {
//    vector<int> a ( {7,3,5,8,9,1,2,4,6} );
    vector<int> a = {9,7,5,3,1,0,2,4,6,8};
    cout << "Before sorting:" << endl;
    print_nums(a);

    vector<int> res = merge_sort(a, 0, a.size() - 1);

    cout <<  "After sorting:" << endl;
    print_nums(res);

    return 0;
}