#include <AllLibrary.h>

void DrawArrow(Vector2 start, Vector2 end, float arrowSize, Color color) {
    float arrowAngle = PI/6;
    float angle = atan2f(end.y - start.y, end.x - start.x);
    Vector2 arrowHead = {end.x, end.y};

    Vector2 left = {arrowHead.x - arrowSize * cos(angle + arrowAngle), 
                    arrowHead.y - arrowSize * sin(angle + arrowAngle)};
    Vector2 right = {arrowHead.x - arrowSize * cos(angle - arrowAngle), 
                     arrowHead.y - arrowSize * sin(angle - arrowAngle)};

    DrawLineEx(start, arrowHead, 5, color);
    DrawLineEx(arrowHead, left, 3, color);
    DrawLineEx(arrowHead, right, 3, color);
}

void DrawRim(Vector2 center, Color RimDark, Color RimBland){
    DrawCircleV(center, r, {0, 0, 0, 0});
        //vẽ hình node
        for(int i = 0;  i < 3; i++){
            DrawCircleLines(center.x, center.y, r + i, BLACK);
        }
        //vẽ viền node
        for (int i = 3; i < 5; i++) { 
            DrawCircleLines(center.x, center.y, r + i, RimDark);
        }
        for (int i = 5; i < 10; i++) { 
            DrawCircleLines(center.x, center.y, r + i, RimBland);
        }
}

void DrawLinkedList(LinkedListNode* head) {
    if (!head) {
        DrawText("Linked List is empty!", screenWidth / 2 - 100, screenHeight / 2, 20, RED);
        return;
    }
    
    int total = 0;  // Tổng số node
    LinkedListNode* temp = head;
    while (temp) {
        total++;
        temp = temp->next;
    }
    
    
    // Tính center
    int totalWidth = total * (2 * r + spacing) - spacing;
    Vector2 center = {screenWidth / 2 - totalWidth / 2 + r, screenHeight / 2};
    
    while (head) {
        DrawRim(center, {200, 200, 200, 150}, {230, 230, 230, 40});
        string s = to_string(head->val);
        int textWidth = MeasureText(s.c_str(), font_size); // bề rộng của node
        DrawText(s.c_str(), center.x - textWidth / 2, center.y - font_size / 2, font_size, WHITE);

        // Vẽ mũi tên nếu có node tiếp theo
        if (head->next) {
            Vector2 newCenter = {center.x + spacing + 2 * r, center.y};
            DrawArrow({center.x + r, center.y}, {newCenter.x - r, newCenter.y}, 15, BLACK);
            center = newCenter;
        }

        head = head->next;
    }
}


void traverse(LinkedListNode* &head, int key) {
    if (!head) return;   

    int total = 0;
    LinkedListNode* temp = head;
    while (temp) {
        total++;
        temp = temp->next;
    }

    // Tính toán vị trí node đầu tiên
    int totalWidth = total * (2 * r + spacing) - spacing;
    Vector2 center = {screenWidth / 2 - totalWidth / 2 + r, screenHeight / 2};

    LinkedListNode* cur = head;
    Vector2 curPos = center;

    while (cur) {
        DrawRim(curPos, RED, {255, 0, 0, 40});
        WaitTime(1); 

        DrawRim(curPos, {200, 200, 200, 150}, {230, 230, 230, 40});
        // move next node
        if (cur->next) {
            Vector2 nextPos = {curPos.x + spacing + 2 * r, curPos.y};
            curPos = nextPos;
        }

        cur = cur->next;
    }

    DrawRim(curPos, GREEN, {0, 255, 0, 40});
    WaitTime(0.3); 

    DrawRim(curPos, {200, 200, 200, 150}, {230, 230, 230, 40});

    insertNode(head, key);
}

bool Mouse(int startX, int startY, int endX, int endY, Vector2 mousePosition) {
    return (mousePosition.x >= startX && mousePosition.x <= endX &&
            mousePosition.y >= startY && mousePosition.y <= endY);
}
