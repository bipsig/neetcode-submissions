class KthLargest {
public:
    priority_queue <int, vector <int>, greater <int>> heap;
    int k;

    KthLargest(int k_, vector<int>& nums) {
        k = k_;

        for (int i = 0; i < nums.size(); i++) {
            heap.push (nums [i]);
            if (heap.size() > k) {
                heap.pop();
            }
        }
    }
    
    int add(int val) {
        heap.push (val);
        if (heap.size() > k) {
            heap.pop();
        }

        return heap.top();
    }
};
