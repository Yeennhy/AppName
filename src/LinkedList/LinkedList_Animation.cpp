#include <AllLibrary.h>

void LinkedList::DrawArrow(Vector2 start, Vector2 end) {
    float arrowAngle = PI/6;
    float angle = atan2f(end.y - start.y, end.x - start.x);
    Vector2 arrowHead = {end.x, end.y};

    Vector2 left = {arrowHead.x - arrow_size * cos(angle + arrowAngle), 
                    arrowHead.y - arrow_size * sin(angle + arrowAngle)};
    Vector2 right = {arrowHead.x - arrow_size * cos(angle - arrowAngle), 
                     arrowHead.y - arrow_size * sin(angle - arrowAngle)};

    DrawLineEx(start, arrowHead, 5, arrow_color);
    DrawLineEx(arrowHead, left, 3, arrow_color);
    DrawLineEx(arrowHead, right, 3, arrow_color);
}

void LinkedList::DrawNode(Vector2 center, int key, int choose){
    string s = to_string(key);

    BeginDrawing();
    // ClearBackground(GRAY);
    //Draw circle
    if (choose == 1){
        DrawCircleV(center, radius + 3, choose_color);
    }
    if (choose == -1){
        DrawCircleV(center, radius + 3, visit_color);
    }
    DrawCircleV(center, radius + 1, ring);
    DrawCircleV(center, radius, circle);
    //Draw text
    DrawText(s.c_str(), center.x - 5*s.size(), center.y, font_size, text_color);

    EndDrawing();
}

void LinkedList::DrawCode(int x, int y, string text){
    //need to edit
    DrawText(text.c_str(), x, y, font_size, text_color);
}

//di chuyển xéo
void LinkedList::MoveCircle(Vector2 start, Vector2 end, int key){
    Vector2 center = start;
    while (center.x != end.x && center.y != end.y){
        DrawNode(center, key, 0);
        if (center.x != end.x){
            center.x ++;
        }
        if (center.y != end.y){
            center.y ++;
        }

        WaitTime(0.01);
    }
}

void LinkedList::DrawLinkedlist(LinkedListNode* head){
    if(!head) return;
    int count = FindSumNode(head);
    Vector2 center = Getposition(count);
    while(head){
        DrawNode(center, head->val, 0);
        if(head->next){
            Vector2 newCenter = {center.x + 2 * radius + spacing, center.y};
            DrawArrow(center, newCenter);
            center = newCenter;
        }
        head = head->next;
    }
}

Vector2 LinkedList::Getposition(int count){
    int d = 2 * radius * count + (count - 1)*spacing;
    Vector2 center = {(screenWidth/2 - d/2) + radius, screenHeight/2};
    return center; 
}

int LinkedList::FindSumNode(LinkedListNode* head){
    if(!head) return 0;
    int cnt = 0;
    LinkedListNode* tmp = head;
    while(tmp){
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}

