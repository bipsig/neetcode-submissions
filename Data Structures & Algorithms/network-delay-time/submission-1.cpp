class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector <vector <pair <int, int>>> adj (n+1);

        for (int i = 0; i < times.size(); i++) {
            adj [times [i][0]].push_back (make_pair (times [i][2], times [i][1]));
        }

        vector <int> visited (n+1, INT_MAX);
        
        priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> heap;
        visited [k] = 0;
        heap.push (make_pair (0, k));

        while (!heap.empty()) {
            int currTime = heap.top().first;
            int curr = heap.top().second;
            heap.pop();

            for (int i = 0; i < adj [curr].size(); i++) {
                int time = adj [curr][i].first;
                int node = adj [curr][i].second;
                if(currTime > visited [curr]) {
                    continue;
                }

                if (visited [node] > time+currTime) {
                    heap.push (make_pair (time+currTime, node));
                    visited [node] = time+currTime;
                }
            }
        }

        int ans = INT_MIN;
        for (int i = 1; i < visited.size(); i++) {
            // cout << visited [i] << endl;
            if (visited [i] == INT_MAX) {
                return -1;
            }
            ans = max (ans, visited [i]);
        }

        return ans;
    }
};
