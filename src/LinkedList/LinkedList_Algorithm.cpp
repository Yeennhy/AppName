/*

- check input

- init
    - base_init
    - from file
    - random
- insert Node
- delete node by value
- update node have value U to V
- search K in linked_list

*/

struct Node {
    int val;
    Node *next;
};

void insert(Node* &head, int key){
    if(!head){
        head = new Node();
        head->val = key;
        head->next = nullptr;
        return;
    }
    else{
        Node* tmp = head;
        while(tmp){
            tmp = tmp->next;
        }
        tmp = new Node();
        tmp->val = key;
        tmp->next = nullptr;
        return;
    }
}

void deleteNode(Node* &head, int key){
    if(!head) return;
    if(head->val == key){
        Node* tmp = head;
        head = head->next;
        delete tmp;
        return;
    }
    else{
        Node* tmp = head;
        while(tmp && tmp->next && tmp->next->val != key){
            tmp = tmp->next;
        }
        if(!tmp->next) return;
        else{
            tmp->next = tmp->next->next;
        }
    }
}

Node *search(Node* head, int key){
    if(!head) return nullptr;
    if(head->val == key) return head;
    return search(head->next, key);
}


void update(Node *&head, int first, int second){
    Node* tmp = search(head, first);
    tmp->val = second;
    return;
}

