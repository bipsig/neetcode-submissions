class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue <int> heap;
        for (int i = 0; i < stones.size(); i++) {
            heap.push (stones [i]);
        }

        while (heap.size() > 1) {
            int a = heap.top();
            heap.pop();
            int b = heap.top();
            heap.pop();

            if (a == b) {
                continue;
            }
            else {
                heap.push (abs (a-b));
            }
        }

        if (heap.size() == 0) {
            return 0;
        }
        return heap.top();
    }
};
