//
//  main.cpp
//  PS_GRP_bfs
//
//  Created by Jose Mari Syjuco on 23/10/21.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    string name;
    vector<Node *> children;
    Node(string str) { name = str; }
    
    vector<string> breadthFirstSearch(vector<string> *array) {
        queue<Node*> q;
        q.push(this);
        
        while (!q.empty()) {
            Node* node = q.front();       // Get front node
            array->push_back(node->name); // Add to answer
            
            // Get children of front most node and add to queue
            if (node->children.size())
                for (Node* child : node->children)
                    q.push(child);
            
            q.pop();                      // Remove node at front of queue
        }
        return *array;
    }
    
    Node *addChild(string name) {
        Node *child = new Node(name);
        children.push_back(child);
        return this;
    }
};

int main() {
    Node graph("A");
    graph.addChild("B")->addChild("C")->addChild("D");
    graph.children[0]->addChild("E")->addChild("F");
    graph.children[2]->addChild("G")->addChild("H");
    graph.children[0]->children[1]->addChild("I")->addChild("J");
    graph.children[2]->children[0]->addChild("K");
    
    vector<string> inputArray{};
    vector<string> ans = graph.breadthFirstSearch(&inputArray);
    for (string i : ans) printf("%s ", i.c_str());
    printf("\nFIN\n");
    return 0;
}
