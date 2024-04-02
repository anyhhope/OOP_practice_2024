#include <iostream>

struct Node {
    int value;
    Node* next;
};

// Node makeNode(int value, Node* next){
//     return new Node(value, next);
// }

int main(){
    Node* node_1 = new Node{1};
    Node* node_2 = new Node{2};
    Node* node_3 = new Node{3};

    node_1->next = node_2;
    node_2->next = node_3;

    Node* head = node_1;
    while(head->next){
        std::cout << head->value << std::endl;
        head = head->next;
    }
    std::cout << head->value << std::endl;

    delete node_1;
    delete node_2;
    delete node_3;

}