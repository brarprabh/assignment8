#include <iostream>
#include <vector>
using namespace std;

class HeapSort
{
    void heapify(vector<int> &arr, int n, int i, bool maxHeap = true)
    {
        int target = i; // Initialize target as root
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (maxHeap)
        {
            // For max heap (increasing order result)
            if (left < n && arr[left] > arr[target])
                target = left;
            if (right < n && arr[right] > arr[target])
                target = right;
        }
        else
        {
            // For min heap (decreasing order result)
            if (left < n && arr[left] < arr[target])
                target = left;
            if (right < n && arr[right] < arr[target])
                target = right;
        }

        if (target != i)
        {
            swap(arr[i], arr[target]);
            heapify(arr, n, target, maxHeap);
        }
    }

public:
    // Heapsort for increasing order (uses max heap)
    void heapSortIncreasing(vector<int> &arr)
    {
        int n = arr.size();

        // Build max heap
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i, true);

        // Extract elements from heap one by one
        for (int i = n - 1; i > 0; i--)
        {
            swap(arr[0], arr[i]);     // Move current root to end
            heapify(arr, i, 0, true); // Call heapify on reduced heap
        }
    }

    // Heapsort for decreasing order (uses min heap)
    void heapSortDecreasing(vector<int> &arr)
    {
        int n = arr.size();

        // Build min heap
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i, false);

        // Extract elements from heap one by one
        for (int i = n - 1; i > 0; i--)
        {
            swap(arr[0], arr[i]);      // Move current root to end
            heapify(arr, i, 0, false); // Call heapify on reduced heap
        }
    }

    void printArray(const vector<int> &arr)
    {
        for (int x : arr)
            cout << x << " ";
        cout << endl;
    }
};

int main()
{
    HeapSort sorter;

    cout << "Heapsort Demo:\n";

    // Test data
    vector<int> arr1 = {12, 11, 13, 5, 6, 7};
    vector<int> arr2 = {12, 11, 13, 5, 6, 7};

    cout << "\nOriginal array: ";
    sorter.printArray(arr1);

    // Sort in increasing order
    sorter.heapSortIncreasing(arr1);
    cout << "Sorted in increasing order: ";
    sorter.printArray(arr1);

    // Sort in decreasing order
    sorter.heapSortDecreasing(arr2);
    cout << "Sorted in decreasing order: ";
    sorter.printArray(arr2);

    // Another test with different data
    cout << "\nAnother test:\n";
    vector<int> arr3 = {64, 34, 25, 12, 22, 11, 90};
    vector<int> arr4 = {64, 34, 25, 12, 22, 11, 90};

    cout << "Original array: ";
    sorter.printArray(arr3);

    sorter.heapSortIncreasing(arr3);
    cout << "Increasing order: ";
    sorter.printArray(arr3);

    sorter.heapSortDecreasing(arr4);
    cout << "Decreasing order: ";
    sorter.printArray(arr4);

    return 0;
}