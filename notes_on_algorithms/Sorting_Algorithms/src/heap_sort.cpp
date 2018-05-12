#include <iostream>
#include <vector>

using namespace std;
void print_nums(const vector<int>& nums);


// refer to: https://www.geeksforgeeks.org/heap-sort/
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(vector<int>& nums, int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (l < n && nums[l] > nums[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && nums[r] > nums[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(nums[i], nums[largest]);

        // Recursively heapify the affected sub-tree
        heapify(nums, n, largest);
    }
}

// main function to do heap sort
void heap_sort(vector<int>& nums)
{
    if (nums.empty() || !nums.size())
        return;
    int n = nums.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(nums, n, i);
//        print_nums(nums);
    }

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(nums[0], nums[i]);

        // call max heapify on the reduced heap
        heapify(nums, i, 0);
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
    cout << "----------" << endl;

    heap_sort(a);

    cout << "----------" << endl;
    cout <<  "After sorting:" << endl;
    print_nums(a);

    return 0;
}