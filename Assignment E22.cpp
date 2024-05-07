#include <bits/stdc++.h>
using namespace std;

class Heap {
private:
    vector<int> min_heap;
    vector<int> max_heap;

public:
    Heap() {}

    void heapify(int m) {
        /*
         * m = 0: heapify minheap
         * m = 1 heapify maxheap
         */
        if ( m == 0 ) {
            int i = min_heap.size() - 1;
            while (i > 0 && min_heap[(i-1)/2] > min_heap[i]) {
                swap(min_heap[i], min_heap[(i-1)/2]);
                i = (i-1) / 2;
            }
        } else if ( m == 1 ) {
            int i = max_heap.size() - 1;
            while (i > 0 && max_heap[(i-1)/2] < max_heap[i]) {
                swap(max_heap[i], max_heap[(i-1)/2]);
                i = (i-1) / 2;
            }
        }
    }

    void insert(int marks) {
        min_heap.emplace_back(marks);
        max_heap.emplace_back(marks);
        heapify(0);
        heapify(1);
    }

    inline int max() {
        return max_heap.front();
    }

    inline int min() {
        return min_heap.front();
    }
};

int main() {
    Heap heap;

    heap.insert(32);
    heap.insert(23);
    heap.insert(22);
    heap.insert(35);
    heap.insert(50);

    cout << "MAX MARKS: " << heap.max() << "\tMIN MARKS: "  << heap.min() << endl;

    return 0;
}
