#include <iostream>
#include <vector>

using namespace std;
 


class Solution {
public:

	struct Node {
		int x, y;
		Node (int x, int y)
		: x(x)
		, y(y)
		{}
		bool operator<(const Node& node) const
		{
			return x < node.x || (x == node.x && y < node.y);
		}
		int operator-(const Node& node) const
		{
			return (x-node.x)*(x-node.x)+(y-node.y)*(y-node.y);
		}
	};
	bool perpendicular(Node& left, Node& mid, Node& right)
	{
		return -(mid.x-left.x)*(mid.x-right.x) == (mid.y-left.y)*(mid.y-right.y);
	}

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    	vector<Node> nodes;
    	nodes.push_back(Node(p1[0], p1[1]));
    	nodes.push_back(Node(p2[0], p2[1]));
    	nodes.push_back(Node(p3[0], p3[1]));
    	nodes.push_back(Node(p4[0], p4[1]));
    	sort(nodes.begin(), nodes.end());
    	return perpendicular(nodes[1], nodes[0], nodes[2])
    	    && perpendicular(nodes[1], nodes[3], nodes[2])
    	    && nodes[0]-nodes[1] > 0
    	    && nodes[0]-nodes[1] == nodes[2]-nodes[3]
    	    && nodes[0]-nodes[1] == nodes[1]-nodes[3]
    	    && nodes[0]-nodes[1] == nodes[0]-nodes[2];

    }
};

int main()
{
	Solution solution;
	vector<int> p1, p2, p3, p4;
	p1.push_back(0);
	p1.push_back(0);
	p2.push_back(1);
	p2.push_back(1);
	p3.push_back(1);
	p3.push_back(0);
	p4.push_back(0);
	p4.push_back(1);
	cout<<solution.validSquare(p1, p2, p3, p4);
	return 0;
}