#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue
{
    vector<int> heap;
    bool isMaxHeap; // true for max heap (max priority), false for min heap (min priority)

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void heapifyUp(int i)
    {
        if (i == 0)
            return;

        int p = parent(i);
        bool shouldSwap = isMaxHeap ? (heap[i] > heap[p]) : (heap[i] < heap[p]);

        if (shouldSwap)
        {
            swap(heap[i], heap[p]);
            heapifyUp(p);
        }
    }

    void heapifyDown(int i)
    {
        int left = leftChild(i);
        int right = rightChild(i);
        int target = i;

        if (isMaxHeap)
        {
            // Max heap: find maximum among node and its children
            if (left < heap.size() && heap[left] > heap[target])
                target = left;
            if (right < heap.size() && heap[right] > heap[target])
                target = right;
        }
        else
        {
            // Min heap: find minimum among node and its children
            if (left < heap.size() && heap[left] < heap[target])
                target = left;
            if (right < heap.size() && heap[right] < heap[target])
                target = right;
        }

        if (target != i)
        {
            swap(heap[i], heap[target]);
            heapifyDown(target);
        }
    }

public:
    PriorityQueue(bool maxHeap = true) : isMaxHeap(maxHeap) {}

    void insert(int val)
    {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
        cout << "Inserted: " << val << endl;
    }

    int extractTop()
    {
        if (heap.empty())
        {
            cout << "Priority queue is empty!" << endl;
            return -1;
        }

        int top = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
            heapifyDown(0);

        return top;
    }

    int peek()
    {
        if (heap.empty())
        {
            cout << "Priority queue is empty!" << endl;
            return -1;
        }
        return heap[0];
    }

    bool isEmpty()
    {
        return heap.empty();
    }

    int size()
    {
        return heap.size();
    }

    void display()
    {
        cout << "Priority Queue: ";
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }

    string getType()
    {
        return isMaxHeap ? "Max Priority Queue" : "Min Priority Queue";
    }
};

int main()
{
    cout << "Priority Queue Implementation using Heaps:\n";

    // Test Max Priority Queue
    cout << "\n=== Max Priority Queue Demo ===\n";
    PriorityQueue maxPQ(true);

    maxPQ.insert(10);
    maxPQ.insert(30);
    maxPQ.insert(20);
    maxPQ.insert(5);
    maxPQ.insert(40);

    cout << "\n"
         << maxPQ.getType() << ":\n";
    maxPQ.display();
    cout << "Top element (highest priority): " << maxPQ.peek() << endl;

    cout << "\nExtracting elements:\n";
    while (!maxPQ.isEmpty())
    {
        cout << "Extracted: " << maxPQ.extractTop() << endl;
    }

    // Test Min Priority Queue
    cout << "\n=== Min Priority Queue Demo ===\n";
    PriorityQueue minPQ(false);

    minPQ.insert(10);
    minPQ.insert(30);
    minPQ.insert(20);
    minPQ.insert(5);
    minPQ.insert(40);

    cout << "\n"
         << minPQ.getType() << ":\n";
    minPQ.display();
    cout << "Top element (lowest priority): " << minPQ.peek() << endl;

    cout << "\nExtracting elements:\n";
    while (!minPQ.isEmpty())
    {
        cout << "Extracted: " << minPQ.extractTop() << endl;
    }

    // Interactive demo
    cout << "\n=== Interactive Demo ===\n";
    PriorityQueue pq(true);
    int choice, value;

    do
    {
        cout << "\nPriority Queue Operations:\n";
        cout << "1. Insert\n2. Extract Top\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            pq.insert(value);
            break;
        case 2:
            cout << "Extracted: " << pq.extractTop() << endl;
            break;
        case 3:
            cout << "Top element: " << pq.peek() << endl;
            break;
        case 4:
            pq.display();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}