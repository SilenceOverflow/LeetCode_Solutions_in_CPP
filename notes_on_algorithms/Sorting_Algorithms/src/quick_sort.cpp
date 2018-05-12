#include <iostream>
#include <vector>
#include <algorithm>    // std::random_shuffle

using namespace std;

// refer to blog: http://x-wei.github.io/quick-sort-and-more.html
int partition(vector<int>& nums, int lo, int hi) {
    int pivot = nums[lo], i = lo, j = hi;
    while (true) {
        while (i < j && nums[j] >= pivot) j--; // move j to a point where a[j]<pivot
        while (i < j && nums[i] <= pivot) i++; // move i to a point where a[i]>pivot
        if (i >= j) break; // b
        // reak if i and j meets
        swap(nums[i++], nums[j--]);
    }
    swap(nums[lo], nums[j]); // swap pivot with a[j]
    return j;
}

void shuffle(vector<int>& nums) {
    random_shuffle (nums.begin(), nums.end());
}

//recursive helper function
void quick_sort(vector<int>& nums, int lo, int hi) {
    if (lo >= hi)
        return;

    int p = partition(nums, lo, hi);

    quick_sort(nums, lo, p - 1);
    quick_sort(nums, p + 1, hi);

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
//    vector<int> a ( {7,3,5,8,9,1,2,4,6,0} );
    vector<int> a = {9,7,5,3,1,0,2,4,6,8};
    cout << "Before sorting:" << endl;
    print_nums(a);

    shuffle(a);
    quick_sort(a, 0, a.size() - 1);

    cout <<  "After sorting:" << endl;
    print_nums(a);

    return 0;
}