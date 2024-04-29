#include <bits/stdc++.h>
using namespace std;

class Heap {
private:
    vector<int> min_heap;
    vector<int> max_heap;
    int size;

public:
    Heap(): size(-1) {}

    void heapify(int i, int m) {
        /*
         * m = 0: heapify minheap
         * m = 1 heapify maxheap
         */
        if ( m == 0 ) {
            while (min_heap[(i-1)/2] > min_heap[i]) {
                swap(min_heap[i], min_heap[(i-1)/2]);
                i = (i-1) / 2;
                if ( i == -1 )
                    break;
            }
        } else if ( m == 1 ) {
            while (min_heap[(i-1)/2] < min_heap[i]) {
                swap(max_heap[i], max_heap[(i-1)/2]);
                i = (i-1) / 2;
                if ( i == -1 )
                    break;
            }
        }
    }

    void insert(int marks) {
        min_heap.emplace_back(marks);
        max_heap.emplace_back(marks);
        size++;
        heapify(size, 0);
        heapify(size, 1);
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

    heap.insert(22);
    heap.insert(32);
    heap.insert(23);
    heap.insert(35);
    heap.insert(50);

    cout << "MAX MARKS: " << heap.max() << "\tMIN MARKS: "  << heap.min() << endl;

    return 0;
}
