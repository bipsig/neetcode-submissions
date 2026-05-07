class MedianFinder {
public:
    priority_queue <int> left;
    priority_queue <int, vector <int>, greater <int>> right;

    MedianFinder() {
        
    }
    void insertInLeft (int num) {
        if (right.empty() || right.top() > num) {
            left.push (num);
        }
        else {
            left.push (right.top());
            right.pop();
            right.push (num);
        }
    }

    void insertInRight (int num) {
        if (num > left.top()) {
            right.push (num);
        }
        else {
            right.push (left.top());
            left.pop();
            left.push (num);
        }
    }
    
    void addNum(int num) {
        if (left.size() == right.size()) {
            insertInLeft (num);
        }
        else {
            insertInRight (num);
        }
    }
    
    double findMedian() {
        if (left.size() == right.size()) {
            return (left.top() + right.top())/2.0;
        }
        return left.top();
    }
};
