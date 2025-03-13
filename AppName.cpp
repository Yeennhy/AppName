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

int main()
{
    InitWindow(screenWidth, screenHeight, "Visualization App");
    SetTargetFPS(60);

    LinkedListNode *head = nullptr;
    // insertNode(head, 5);
    // insertNode(head, 6);
    // insertNode(head, 7);

    int nums[50] = {1, 3, 5, 43, 2, 9, 10, 78, 23};
    int id = -1;
    int second[50] = {3, 5, 7, 45, 4, 11, 12, 80, 25};

    while (!WindowShouldClose())
    {
        int r = 100;
        int font_size = 40;
        int spacing = 120;
        Vector2 center = {screenWidth/2, screenHeight / 2};

        BeginDrawing();
        ClearBackground(GRAY);

        // DrawLinkedList(head);
        DrawRectangle(50, 50, 90, 25, PINK);
        Vector2 mousePosition = GetMousePosition();
        if (IsMouseOverButton(50, 50, 90, 25)) {
            id ++;
            if (!head) insertNode(head, nums[id]);
            else traverse(head, nums[id]);
        }

        if (head) DrawLinkedList(head);

        //delete
        DrawRectangle(200, 50, 90, 25, BLUE);
        if (IsMouseOverButton(200, 50, 90, 25)) {
            deleteNode(head, nums[id]);
            id --;
        }

        if (head) DrawLinkedList(head);

        //update

        DrawRectangle(300, 50, 90, 25, GREEN);
        if (IsMouseOverButton(300, 50, 90, 25) && id >= 0) {
            update1(head, nums, second[id], id);
        }

        if (head) DrawLinkedList(head);

        EndDrawing();
    }


    CloseWindow();
    return 0;
}