#include <AllLibrary.h>


void LinkedList::insertNode(LinkedListNode* &head, int key) {
    if (!head) {
        head = new LinkedListNode;
        head->val = key;
        head->next = nullptr;
        return;
    }
    
    LinkedListNode * a = head;
    // Vẽ cái tô màu đỏ
    while (a->next){
        a = a->next;
    }
    LinkedListNode * tmp = new LinkedListNode;
    tmp->val = key;
    tmp->next = nullptr;
    a->next = tmp;
}

void LinkedList::deleteNode(LinkedListNode* &head, int key) {
    if (!head) return;
    LinkedListNode* tmp = head;
    LinkedListNode* prev = nullptr;

    if (head->val == key) {
        head = head->next; 
        delete tmp;
        return;
    }

    while (tmp && tmp->val != key) {
        prev = tmp;
        tmp = tmp->next;
    }

    if (tmp) {
        prev->next = tmp->next;
        delete tmp;
    }
}


LinkedListNode * LinkedList::search(LinkedListNode* head, int key){
    if(!head) return nullptr;
    LinkedListNode* tmp = head;
    while(tmp){
        if(tmp->val == key) return tmp;
        tmp = tmp->next;
    }
    return nullptr;
}


void LinkedList::update(LinkedListNode *&head, int &first, int second){
    LinkedListNode * tmp = search(head, first);
    if(!tmp){
        cout << "Not found!";
        return;
    }
    else{
        tmp->val = second;
        return;
    }
}

