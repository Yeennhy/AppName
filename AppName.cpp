#include <AllLibrary.h>

struct Button
{
    Rectangle rect;
    const char *label;
};

bool isLinkedListScreen = false;
char inputValue[10] = "";
int inputIndex = 0;
std::vector<std::string> enteredValues;


bool IsMouseOverButton(int startX, int startY, int width, int height) {
    Vector2 mousePos = GetMousePosition();

    // Kiểm tra xem chuột có nằm trong vùng button không
    if (mousePos.x >= startX && mousePos.x <= (startX + width) &&
        mousePos.y >= startY && mousePos.y <= (startY + height)) {
        
        // Nếu chuột nằm trong vùng button và được bấm
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            return true;
            int i = 0;
            DrawText("HIHI", 100, 100, 50, BLACK);
            while (!IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
                i++;
                if (i > 100000000) return false;
            }
            return true;
        }
    }

    return false;
}

int main(){
    InitWindow(screenWidth, screenHeight, "Visualization App");
    SetTargetFPS(120);

    LinkedListNode *head = nullptr;
    LinkedList list;
    Vector2 start = {100, 100};
    Vector2 end = {500, 500};

    int nums[50] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int nums2[50] = {43, 21, 31, 56, 45, 32, 34, 81, 91, 11};
    int id = 0;
    LinkedListNode * head = nullptr;

    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(GRAY);
        EndDrawing();
        if (IsKeyPressed(KEY_SPACE)){
            list.insertNode(head, nums[id]);
            id ++;
        }
    }


    CloseWindow();
    return 0;
}
