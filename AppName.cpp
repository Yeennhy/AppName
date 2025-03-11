#include <AllLibrary.h>

struct Button {
    Rectangle rect;
    const char* label;
};

bool isLinkedListScreen = false;
char inputValue[10] = "";
int inputIndex = 0;
std::vector<std::string> enteredValues;


const int screenWidth = 1100;
const int screenHeight = 1100;

int main() {
    InitWindow(screenWidth, screenHeight, "Visualization App");
    SetTargetFPS(60);

    Button mainButtons[3] = {
        {{screenWidth / 2 - 100, 200, 200, 50}, "Linked List"},
        {{screenWidth / 2 - 100, 300, 200, 50}, "Tree"},
        {{screenWidth / 2 - 100, 400, 200, 50}, "Hash Table"}
    };

    Button linkedListButtons[3] = {
        {{screenWidth / 2 - 100, 200, 200, 50}, "Insert"},
        {{screenWidth / 2 - 100, 300, 200, 50}, "Delete"},
        {{screenWidth / 2 - 100, 400, 200, 50}, "Search"}
    };

    Rectangle inputBox = {screenWidth / 2 - 100, 500, 200, 50};

    while (!WindowShouldClose()) {
        Vector2 mousePoint = GetMousePosition();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if (!isLinkedListScreen) {
                for (int i = 0; i < 3; i++) {
                    if (CheckCollisionPointRec(mousePoint, mainButtons[i].rect) && i == 0) {
                        isLinkedListScreen = true;
                    }
                }
            }
        }

        int key = GetCharPressed();
        while (key > 0) {
            if ((key >= 48 && key <= 57) && inputIndex < 9) {
                inputValue[inputIndex] = (char)key;
                inputIndex++;
                inputValue[inputIndex] = '\0';
            }
            key = GetCharPressed();
        }

        if (IsKeyPressed(KEY_BACKSPACE) && inputIndex > 0) {
            inputIndex--;
            inputValue[inputIndex] = '\0';
        }

        if (IsKeyPressed(KEY_ENTER) && inputIndex > 0) {
            enteredValues.push_back(std::string(inputValue));
            inputIndex = 0;
            inputValue[0] = '\0';
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // if (!isLinkedListScreen) {
        //     DrawText("Visualization App", screenWidth / 2 - MeasureText("Visualization App", 30) / 2, 100, 30, DARKBLUE);
        //     for (int i = 0; i < 3; i++) {
        //         Color btnColor = CheckCollisionPointRec(mousePoint, mainButtons[i].rect) ? LIGHTGRAY : GRAY;
        //         DrawRectangleRec(mainButtons[i].rect, btnColor);
        //         DrawRectangleLinesEx(mainButtons[i].rect, 2, DARKGRAY);
        //         DrawText(mainButtons[i].label, mainButtons[i].rect.x + (mainButtons[i].rect.width - MeasureText(mainButtons[i].label, 20)) / 2, 
        //                  mainButtons[i].rect.y + 15, 20, BLACK);
        //     }
        // } else {
        //     DrawText("Linked List Operations", screenWidth / 2 - MeasureText("Linked List Operations", 30) / 2, 100, 30, DARKBLUE);
        //     for (int i = 0; i < 3; i++) {
        //         Color btnColor = CheckCollisionPointRec(mousePoint, linkedListButtons[i].rect) ? LIGHTGRAY : GRAY;
        //         DrawRectangleRec(linkedListButtons[i].rect, btnColor);
        //         DrawRectangleLinesEx(linkedListButtons[i].rect, 2, DARKGRAY);
        //         DrawText(linkedListButtons[i].label, linkedListButtons[i].rect.x + (linkedListButtons[i].rect.width - MeasureText(linkedListButtons[i].label, 20)) / 2, 
        //                  linkedListButtons[i].rect.y + 15, 20, BLACK);
        //     }

        //     // Draw input box
        //     DrawRectangleRec(inputBox, WHITE);
        //     DrawRectangleLinesEx(inputBox, 2, DARKGRAY);
        //     DrawText(inputValue, inputBox.x + 10, inputBox.y + 15, 20, BLACK);

        //     // Display entered values
        //     int yOffset = 550;
        //     for (const auto& value : enteredValues) {
        //         DrawText(value.c_str(), screenWidth / 2 - 50, yOffset, 20, DARKBLUE);
        //         yOffset += 30;
        //     }
        // }

        print();
        
        EndDrawing();
        
    }

    CloseWindow();
    return 0;
}