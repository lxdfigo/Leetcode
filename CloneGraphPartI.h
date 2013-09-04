#include <stack>
#include <map>
#include <vector>

struct Node
{
	std::vector<struct Node *> neighbors;
};
class Solution
{
public:
Node* copyGraph(Node *node)
{
	if (node == NULL) return NULL;
	std::stack<Node*> nodeStack;
	std::map<Node*,Node*> nodeMap;
	nodeStack.push(node);
	Node *copy = new Node;
	copy->neighbors.resize(node->neighbors.size());
	nodeMap[node] = copy;
	while(!nodeStack.empty())
	{
		Node *cur = nodeStack.top();
		nodeStack.pop();
		for(unsigned int i = 0; i < cur->neighbors.size(); ++i)
		{
			Node *curNeighbor = cur->neighbors[i];
			if (nodeMap.find(curNeighbor) == nodeMap.end())
			{
				Node *newNode = new Node;
				newNode->neighbors.resize(curNeighbor->neighbors.size());

				nodeMap[curNeighbor] = newNode;
				nodeStack.push(curNeighbor);
			}
			nodeMap[cur]->neighbors[i] = nodeMap[curNeighbor];
		}
	}
	return copy;
}
};