//
//  main.cpp
//  PS_GRP_dfs
//
//  Created by Jose Mari Syjuco on 23/10/21.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Node {
public:
    string name;
    vector<Node *> children;
    
    Node(string str) { name = str; }
    
    void traverse(Node* node, vector<string> *ans) {
        ans->push_back(node->name);
        
        if (node->children.size())
            for (auto o : node->children)
                traverse(o, ans);
    }
    
    vector<string> depthFirstSearch(vector<string> *array) {
        traverse(this, array);
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
    graph.depthFirstSearch(&inputArray);
    for (string i : inputArray) printf("%s ", i.c_str());
    printf("\nFIN\n");
    return 0;
}
