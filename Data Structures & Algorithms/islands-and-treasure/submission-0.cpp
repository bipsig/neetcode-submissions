class Solution {
public:
    int m, n;

    bool isValid (int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector <int> dx = {0,0,1,-1};
        vector <int> dy = {1,-1,0,0};

        queue <pair <int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid [i][j] == 0) {
                    q.push (make_pair (i, j));
                }
            }
        }

        while (!q.empty()) {
            int currx = q.front().first;
            int curry = q.front().second;
            q.pop();

            for (int x = 0; x < 4; x++) {
                int newx = currx + dx [x];
                int newy = curry + dy [x];

                if (isValid (newx, newy) && grid [newx][newy] == 2147483647) {
                    grid [newx][newy] = grid [currx][curry] + 1;
                    q.push (make_pair (newx, newy));
                }
            }
        }
    }
};
