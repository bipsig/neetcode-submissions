class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector <int> nextSmaller (n, n);
        stack <int> st;

        for (int i = n-1; i >= 0; i--) {
            int curr = heights [i];
            while (!st.empty() && heights [st.top()] >= curr) {
                st.pop();
            }
            if (!st.empty()) {
                nextSmaller [i] = st.top();
            }

            st.push (i);
        }

        while (!st.empty()) {
            st.pop();
        }

        vector <int> prevSmaller (n, -1);
        for (int i = 0; i < n; i++) {
            int curr = heights [i];
            while (!st.empty() && heights [st.top()] >= curr) {
                st.pop();
            }
            if (!st.empty()) {
                prevSmaller [i] = st.top();
            }

            st.push (i);
        }

        for (int i = 0; i < n; i++) {
            cout << prevSmaller [i] << " ";
        }

        int ans = -1;
        for (int i = 0; i < n; i++) {
            int wid = nextSmaller [i] - prevSmaller [i] - 1;
            int area = wid * heights [i];

            ans = max (ans, area);
        }

        return ans;
    }
};
