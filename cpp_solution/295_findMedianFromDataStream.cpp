#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

class MedianFinder {
public:
    priority_queue<int> leftSide;
    priority_queue<int, vector<int>, greater<int> > rightSide;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if ( leftSide.empty() || num < leftSide.top() )
        {
            leftSide.push(num);
        }
        else
        {
            rightSide.push(num);
        }
        // every time we only insert one new element. 
        // thus the difference between two queue won't be greater than 2
        if ( leftSide.size()+1 < rightSide.size() )
        {
            leftSide.push(rightSide.top());
            rightSide.pop();
        }
        if ( rightSide.size()+1 < leftSide.size() )
        {
            rightSide.push(leftSide.top());
            leftSide.pop();
        }
    }
    
    double findMedian() {
        if (leftSide.size() > rightSide.size())
            return leftSide.top();
        else if (leftSide.size() == rightSide.size() )
            return ( leftSide.top() + rightSide.top() )/2.0;
        else
            return rightSide.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

int main()
{
	return 0;
}