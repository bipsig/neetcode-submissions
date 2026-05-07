class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue <pair <double, int>> heap;
        for (int i = 0; i < points.size(); i++) {
            double dist = sqrt ((points [i][0]*points [i][0]) + (points [i][1]*points [i][1]));
            heap.push (make_pair (dist, i));

            if (heap.size() > k) {
                heap.pop();
            }
        }

        vector <vector <int>> ans;
        while (!heap.empty()) {
            int ind = heap.top().second;
            ans.push_back (points [ind]);
            heap.pop();
        }

        return ans;
    }
};
