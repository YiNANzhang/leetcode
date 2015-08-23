/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr) return nullptr;
				UndirectedGraphNode *clone;
        unordered_map<int, UndirectedGraphNode *> visited;
        queue<UndirectedGraphNode *> q;

        q.push(node);
        //UndirectedGraphNode *point;
        //point = node;
        clone = new UndirectedGraphNode(node->label);
        visited[node->label] = clone;
        while(!q.empty()) {
            UndirectedGraphNode *temp = q.front();
            q.pop();

            for (auto it : temp->neighbors) {
                if (visited.find(it->label) == visited.end()) {
                    UndirectedGraphNode *neighborNode = new UndirectedGraphNode(it->label);
                    q.push(it);
                    visited[it->label] = neighborNode;
                }
				(visited[temp->label]->neighbors).push_back(visited[it->label]);
            }
        }
        return clone;
    }
};
