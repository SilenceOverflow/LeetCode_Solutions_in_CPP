#include <iostream>
#include <vector>

using namespace std;

// refer to blog: https://blog.csdn.net/morewindows/article/details/6684558
void quick_sort(vector<int>& nums, int l, int r) {

    if (l < r) {
        int i = l, j = r, x = nums[l];
        while (i < j) {
            while (i < j && nums[j] >= x) j--;
            if (i < j) nums[i++] = nums[j];

            while (i < j && nums[i] < x) i++;
            if (i < j) nums[j--] = nums[i];
        }

        nums[i] = x;
        quick_sort(nums, l, i - 1);
        quick_sort(nums, i + 1, r);
    }
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
    vector<int> a ( {7,3,5,8,9,1,2,4,6,0} );
//    vector<int> a = {9,7,5,3,1,0,2,4,6,8};
    cout << "Before sorting:" << endl;
    print_nums(a);

    quick_sort(a, 0, a.size() - 1);

    cout <<  "After sorting:" << endl;
    print_nums(a);

    return 0;
}