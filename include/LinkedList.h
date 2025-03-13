#include <AllLibrary.h>

struct LinkedListNode {
    int val;
    LinkedListNode* next;
};

//const
const int r = 50;  
const int font_size = 40; 
const int spacing = 50; 

//algorithm
void insertNode(LinkedListNode* &head, int key);
void deleteNode(LinkedListNode* &head, int key);
LinkedListNode *search(LinkedListNode* head, int key);
void update(LinkedListNode *&head, int &first, int second);
void DrawRim(Vector2 center, Color RimDark, Color RimBland);

void traverse(LinkedListNode* &head, int key);

void update1(LinkedListNode *head, int nums[], int key, int id);

//animation
void DrawArrow(Vector2 start, Vector2 end, float arrowSize, Color color);
void DrawLinkedList(LinkedListNode* head);