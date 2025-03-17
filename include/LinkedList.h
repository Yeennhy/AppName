#include <AllLibrary.h>

struct LinkedListNode {
    int val;
    LinkedListNode* next;
};

struct req{
    int id;
    string info;
    LinkedListNode * node;
    Vector2 start;
    Vector2 end;
    int result;
};

// vector <req> g;
const int screenWidth = 1100;
const int screenHeight = 1100;


class LinkedList {
    public:
        const int radius = 50;
        const int font_size = 60;
        const int spacing = 50;
        const Color choose_color = GREEN;
        const Color visit_color = RED;
        const Color ring = BLACK;
        const Color circle = BLUE;
        const Color text_color = BLACK;
        const float arrow_size = 15.0;
        const Color arrow_color = BLACK;
        //handle
        void handleLinkedList(LinkedListNode* &head, int key);
        Rectangle workplace;
    // private:

        //algorithm
        void insertNode(LinkedListNode* &head, int key);
        void deleteNode(LinkedListNode* &head, int key);
        LinkedListNode *search(LinkedListNode* head, int key);
        void update(LinkedListNode *&head, int &first, int second);
        //animation

        void DrawNode(Vector2 center, int key, int choose);
        void DrawArrow(Vector2 start, Vector2 end);
        void DrawCode(int x, int y, string text);
        void MoveCircle(Vector2 start, Vector2 end, int key);
        void DrawLinkedlist(LinkedListNode* head);
        Vector2 Getposition(int count);
        int FindSumNode(LinkedListNode* head);
};