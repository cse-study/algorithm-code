/**
    Baekjoon 1068: 트리
    https://www.acmicpc.net/problem/1068

    문제: 트리에서 리프 노드란, 자식의 개수가 0인 노드를 말한다.
    트리가 주어졌을 때, 노드 하나를 지울 것이다. 그 때, 남은 트리에서 리프 노드의 개수를 구하는 프로그램을 작성하시오.
    노드를 지우면 그 노드와 노드의 모든 자손이 트리에서 제거된다.

    입력: 첫째 줄에 트리의 노드의 개수 N이 주어진다. N은 50보다 작거나 같은 자연수이다.
    둘째 줄에는 0번 노드부터 N-1번 노드까지, 각 노드의 부모가 주어진다.
    만약 부모가 없다면 (루트) -1이 주어진다. 셋째 줄에는 지울 노드의 번호가 주어진다.
    출력: 첫째 줄에 입력으로 주어진 트리에서 입력으로 주어진 노드를 지웠을 때, 리프 노드의 개수를 출력한다.

    @author Yuho Jeong
*/

#include <iostream>
#include <vector>
#include <algorithm>


class Node {

public:
    int parent;                     // 부모 노드의 번호
    std::vector <int> children;     // 자식 노드들의 번호
    Node() = default;
    Node(int parent_) { parent = parent_; };
    void RemoveChildByValue(int);
};


void Node::RemoveChildByValue(int id) {
    for(int i = 0; i < children.size(); i++){
        if (children[i] == id) {
            children.erase(children.begin() + i);
            break;
        }
    }
}


class Tree {

private:
    int num_node;               // 노드 수
    int num_leaves;             // leaf 노드 수
    Node* nodes;                // Tree 구조를 int array 형태로 정의
    void SetNodes(int*);        // Node list setter

public:
    Tree(int num_node_, int* parent_info) {
        num_node = num_node_;
        num_leaves = 0;
        SetNodes(parent_info);
    };
    void RemoveSelectedNode(int);
    void DepthFirstSearch(int);
    int GetNumLeaves();
};


void Tree::SetNodes(int* parent_info) {
    nodes = new Node[num_node];
    for(int i = 0; i < num_node; i++) {
        Node node(parent_info[i]);  // 노드 생성
        if(parent_info[i] != -1) {
            nodes[parent_info[i]].children.push_back(i);  // 자식 노드 정보 추가
        }
        nodes[i] = node;
    }
}


void Tree::RemoveSelectedNode(int delete_id_) {
    int parent_id = nodes[delete_id_].parent;
    if (parent_id != -1) {
        nodes[parent_id].RemoveChildByValue(delete_id_);
    }

    nodes[delete_id_].parent = -1;
    nodes[delete_id_].children.clear();
}


void Tree::DepthFirstSearch(int id) {
    // leaf 노드인 경우엔, num_leaves에 1 추가
    if(nodes[id].children.empty()) {
        num_leaves++;
    }
    // leaf 노드 아닌 경우엔 DFS 실시
    else {
        for(int i : nodes[id].children){
            DepthFirstSearch(i);
        }
    }
}


int Tree::GetNumLeaves() {
    DepthFirstSearch(0);
    return num_leaves;
}


int main() {
    // User input
    int num_node, delete_id;
    std::cin >> num_node;

    int parent_info[num_node];
    for(int i = 0; i < num_node; i++) {
        std::cin >> parent_info[i];
    }
    std::sort(parent_info, parent_info + num_node);

    std::cin >> delete_id;

    // Make a tree structure
    Tree tree(num_node, parent_info);

    // Run algorithm
    int num_leaves;

    if (delete_id != 0) {
        tree.RemoveSelectedNode(delete_id);     // 선택된 노드 제거
        num_leaves = tree.GetNumLeaves();                 // 트리 순회를 통해 leaf 노드 수 확인
    }
    else {
        num_leaves = 0;
    }

    std::cout << num_leaves;

    return 0;
}
