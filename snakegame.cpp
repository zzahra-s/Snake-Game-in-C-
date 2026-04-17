#include <iostream>
#include <raylib.h>
#include <fstream>
#include <string.h>

using namespace std;

float size_of_cell=25;
float cell_count=20;
float borders=75;
double lastupdatetime = 0;  
double speeed_of_snake = 0.2;  
int max_walls=100;
int max_snake=100;
int walls[100][2];  
int number_of_walls = 0;         
bool is_game_mode = false;   
int body_of_snake[100][2];  
int snakesize = 3;          
int direction_of_snake[2] = { 1, 0 };  
bool is_add_segment = false;
int score=0;
int current_level = 1;


void SaveGameEndless( int score, int length, int snakeBody[][2], int snakeDirection[2], int foodX, int foodY) {
  
    ofstream fout("endlesssave.txt");

    if (!fout.is_open()) {
        cout << "Error: Unable to open file for saving!" << endl;
        return;  
    }
    fout << score << " " << length << " " << foodX << " " << foodY << endl;

    for (int i = 0; i < length; i++) {
        fout << snakeBody[i][0] << " " << snakeBody[i][1] << endl;
    }

    fout << snakeDirection[0] << " " << snakeDirection[1] << endl;

    fout.close();

    cout << "Game Saved Successfully!" << endl;
}
bool LoadGameEndless( int &score, int &length, int snakeBody[][2], int snakeDirection[2], int &foodX, int &foodY) {
    ifstream fin("endlesssave.txt");

    if (!fin.is_open()) {
        cout << "Error: No saved game found!" << endl;
        return false;  
    }

    fin >> score >> length >> foodX >> foodY;

    for (int i = 0; i < length; i++) {
        fin >> snakeBody[i][0] >> snakeBody[i][1];
    }

    fin >> snakeDirection[0] >> snakeDirection[1];

    fin.close();

    return true;  
}

void SaveCustomGame(int score, int snakeLength, int snakeBody[][2], int snakeDirection[2], int foodX, int foodY, int wallCount, int walls[][2]) 
{

    ofstream fout("customsave.txt");


    if (!fout.is_open()) {
        cout << "Error: Unable to open file for saving!" << endl;
        return; 
    }

    fout << score << " " << snakeLength << " " << foodX << " " << foodY << " " << wallCount << endl;

    for (int i = 0; i < snakeLength; i++) {
        fout << snakeBody[i][0] << " " << snakeBody[i][1] << endl;
    }
    fout << snakeDirection[0] << " " << snakeDirection[1] << endl;


    for (int i = 0; i < wallCount; i++) {
        fout << walls[i][0] << " " << walls[i][1] << endl;
    }

    fout.close();

   
    cout << "Game Saved Successfully!" << endl;
}
bool LoadCustomGame( int &score, int &snakeLength, int snakeBody[][2], int snakeDirection[2], int &foodX, int &foodY, int &wallCount, int walls[][2]) 
{
    ifstream fin("customsave.txt");

    if (!fin.is_open()) {
        cout << "Error: No saved game found!" << endl;
        return false;  
    }

    fin >>  score >> snakeLength >> foodX >> foodY >> wallCount;

    for (int i = 0; i < snakeLength; i++) {
        fin >> snakeBody[i][0] >> snakeBody[i][1];
    }

    fin >> snakeDirection[0] >> snakeDirection[1];

    for (int i = 0; i < wallCount; i++) {
        fin >> walls[i][0] >> walls[i][1];
    }

    fin.close();

    return true;  
    
}

void SaveLevelGame(int level, int score, int length, int snakeBody[][2], int snakeDirection[2], int foodX, int foodY) {
  
    ofstream fout("levelsave.txt");

    if (!fout.is_open()) {
        cout << "Error: Unable to open file for saving!" << endl;
        return;  
    }

    fout << level << " " << score << " " << length << " " << foodX << " " << foodY << endl;

    for (int i = 0; i < length; i++) {
        fout << snakeBody[i][0] << " " << snakeBody[i][1] << endl;
    }

    fout << snakeDirection[0] << " " << snakeDirection[1] << endl;

    fout.close();

    cout << "Game Saved Successfully!" << endl;
}
bool LoadLevelGame(int &level, int &score, int &length, int snakeBody[][2], int snakeDirection[2], int &foodX, int &foodY) {
    ifstream fin("levelsave.txt");

    if (!fin.is_open()) {
        cout << "Error: No saved game found!" << endl;
        return false;  
    }

    fin >> level >> score >> length >> foodX >> foodY;

    for (int i = 0; i < length; i++) {
        fin >> snakeBody[i][0] >> snakeBody[i][1];
    }

    fin >> snakeDirection[0] >> snakeDirection[1];

    fin.close();

    return true;  
}


void level1()
{
    number_of_walls = 6;
    walls[1][0] = 6; 
    walls[1][1] = 5;
    walls[0][0] = 5; 
    walls[0][1] = 5;
    walls[2][0] = 7; 
    walls[2][1] = 5;
    walls[3][0] = 5; 
    walls[3][1] = 6;
    walls[5][0] = 5; 
    walls[5][1] = 8;
    walls[4][0] = 5; 
    walls[4][1] = 7;

    for (int i = 0; i < number_of_walls; i++) {
        Rectangle wallRect = {borders + (walls[i][0] * size_of_cell), borders + walls[i][1] * size_of_cell, size_of_cell, size_of_cell };
        DrawRectangle(wallRect.x, wallRect.y, wallRect.width, wallRect.height, DARKGRAY);
    }
}

void level3()
{
    number_of_walls = 20;
    walls[0][0] = 5; 
    walls[0][1] = 15;
    walls[1][0] = 6; 
    walls[1][1] = 15;
   walls[9][0] = 1; 
   walls[9][1] = 4;
    walls[3][0] = 10; 
    walls[3][1] = 6;
    walls[4][0] = 10;
     walls[4][1] = 7;
    walls[5][0] = 10; 
    walls[5][1] = 8;
    walls[6][0] = 11; 
    walls[6][1] = 8;
    walls[7][0] = 1; 
    walls[7][1] = 2;
    walls[8][0] = 1; 
    walls[8][1] = 3;
     walls[15][0] = 14; 
     walls[15][1] = 3;
    walls[10][0] = 15; 
    walls[10][1] = 10;
    walls[11][0] = 15; 
    walls[11][1] = 11;
    walls[12][0] = 15; 
    walls[12][1] = 12;
    walls[13][0] = 14; 
    walls[13][1] = 1;
    walls[14][0] = 14; 
    walls[14][1] = 2;
    walls[2][0] = 7; 
    walls[2][1] = 15;
    walls[16][0] = 14; 
    walls[16][1] = 4;
    walls[17][0] = 13; 
    walls[17][1] = 4;
    walls[18][0] = 12; 
    walls[18][1] = 4;
    walls[19][0] = 11; 
    walls[19][1] = 4;


    
    for (int i = 0; i < number_of_walls; i++) {
        Rectangle wallRect = { borders + (walls[i][0] * size_of_cell), borders + (walls[i][1] * size_of_cell), size_of_cell, size_of_cell };
        DrawRectangle(wallRect.x, wallRect.y, wallRect.width, wallRect.height, DARKGRAY);
    }
}


void level2()
{
    number_of_walls = 10;
    walls[0][0] = 5; 
    walls[0][1] = 15;
    walls[2][0] = 7; 
    walls[2][1] = 15;
    walls[1][0] = 6; 
    walls[1][1] = 15;
     walls[8][0] = 1; 
     walls[8][1] = 3;
    walls[3][0] = 10;
     walls[3][1] = 6;
    walls[4][0] = 10; 
    walls[4][1] = 7;
    walls[5][0] = 10; 
    walls[5][1] = 8;
    walls[6][0] = 11; 
    walls[6][1] = 8;
    walls[7][0] = 1; 
    walls[7][1] = 2;
    walls[9][0] = 1;
     walls[9][1] = 4;
    
    for (int i = 0; i < number_of_walls; i++) {
        Rectangle wallRect = { borders +( walls[i][0] * size_of_cell), borders + (walls[i][1] * size_of_cell), size_of_cell, size_of_cell };
        DrawRectangle(wallRect.x, wallRect.y, wallRect.width, wallRect.height, DARKGRAY);
    }
}


void sort_high_scores(int highscores[], char names[][20], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (highscores[j] < highscores[j + 1]) {
                
                int tempScore = highscores[j];
                highscores[j] = highscores[j + 1];
                highscores[j + 1] = tempScore;
                char tempName[20];
                strcpy(tempName, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], tempName);
            }
        }
    }
}

void updatesHighScores(int highscores[], char names[][20], int &size, int score, char playerName[20]) {
    if (size < 10) {
        highscores[size] = score;
        strcpy(names[size],playerName);
        size++;
    } else if (score > highscores[size - 1]) {
        highscores[size - 1] = score;
        strcpy(names[size - 1], playerName);
    }
    sort_high_scores(highscores, names, size);
}


void loadHighscores(int highscores[], char names[][20], int &size) {
    size = 0;  
    ifstream fin("highscores.txt");
    if (fin.is_open()) {
        while (fin >> names[size] >> highscores[size] && size < 10) {
            size++;
        }
        fin.close();
    }
}

void saveHighscores(int highscores[], char names[][20], int size) {
    ofstream fout("highscores.txt");
    for (int i = 0; i < size; i++) {
        fout << names[i] << " " << highscores[i] << endl;
    }
    fout.close();
}

void displayHighscores(int highscores[], char names[][20], int size) {
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        DrawText("High Scores", GetScreenWidth()/2 - 100, 50, 40, BLACK);
        
        for (int i = 0; i < size; i++) {
            DrawText(TextFormat("%d. %s", i+1, names[i]), 
                     GetScreenWidth()/2 - 100, 
                     150 + i * 30, 
                     20, 
                     BLACK);
            
            DrawText(TextFormat("%d", highscores[i]), 
                     GetScreenWidth()/2 + 100, 
                     150 + i * 30, 
                     20, 
                     RED);
        }
        
        DrawText("Press ESC to return", GetScreenWidth()/2 - 100, GetScreenHeight() - 50, 20, DARKGRAY);
        
        EndDrawing();
        
        if (IsKeyPressed(KEY_ESCAPE)) {
            break;
        }
    }
}


int chooseSnakecolor()
{
    Color colors[] = { PINK,BLUE,PURPLE,GREEN,RED,YELLOW, ORANGE };
    char colorNames[7][10] = { "Pink",  "Blue",  "Purple",   "Green", "Red",  "Yellow",  "Orange"  };
    int color_index_selected = 0;
    int size_of_colors=7*4;
    int size_of_color_element=4;
    int number_of_colors = size_of_colors / size_of_color_element;

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_A))
        {
            color_index_selected = (color_index_selected - 1 + number_of_colors) % number_of_colors;
        }
        if (IsKeyPressed(KEY_D))
        {
            color_index_selected = (color_index_selected + 1) % number_of_colors;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Select Snake Color (Use A/D to cycle):", 10, 10, 20, DARKGRAY);
        DrawText(colorNames[color_index_selected], 10, 40, 20, DARKGRAY);

        for (int i = 0; i < 5; ++i)
        {
            DrawRectangle(300 + i * 30, 200, 25, 25, colors[color_index_selected]);
        }

        EndDrawing();

        if (IsKeyPressed(KEY_ENTER))
        {
            return color_index_selected;
        }
    }

    return -1; 
}

void showSnake(Color snakeColor)
{
    for (int i = 0; i < snakesize; i++)
    {
        float x = body_of_snake[i][0];
        float y = body_of_snake[i][1];
        Rectangle segment = Rectangle{ borders+ x * size_of_cell, borders + y * size_of_cell, size_of_cell, size_of_cell };
        DrawRectangleRounded(segment, 0.5, 6, snakeColor);
    }
}

void UpdateSnake()
{
    if (is_add_segment)
    {
        for (int i = snakesize; i > 0; i--)
        {
            body_of_snake[i][1] = body_of_snake[i - 1][1];
            body_of_snake[i][0] = body_of_snake[i - 1][0];
            
        }
        body_of_snake[0][1] += direction_of_snake[1];
        body_of_snake[0][0] += direction_of_snake[0];
        
        snakesize++;
        is_add_segment = false;
    }
    else
    {
        for (int i = snakesize- 1; i > 0; i--)
        {
            body_of_snake[i][0] = body_of_snake[i - 1][0];
            body_of_snake[i][1] = body_of_snake[i - 1][1];
        }
        body_of_snake[0][1] += direction_of_snake[1];
        body_of_snake[0][0] += direction_of_snake[0];
        
    }
}
void GameOver(char playerName[50], int score)
{
        
    int highscores[10] = {0};
    char names[10][20] = {0};
    int size = 0;
    is_game_mode=false;

    loadHighscores(highscores, names, size);


    updatesHighScores(highscores, names, size, score, playerName);


    saveHighscores(highscores, names, size);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);


        DrawText("Game Over", 200, 100, 40, DARKGRAY);
        DrawText(TextFormat("Player: %s", playerName), 200, 160, 20, DARKGRAY);
        DrawText(TextFormat("Score: %i", score), 200, 200, 20, DARKGRAY);
        DrawText("Press ESC to Exit", 200, 240, 20, DARKGRAY);

        EndDrawing();

        if (IsKeyPressed(KEY_ESCAPE))
        {
            CloseWindow(); 
            exit(0);
        }
    }
}


void Resetsnake()
{
    snakesize = 3;
    body_of_snake[2][0] = 4; 
    body_of_snake[2][1] = 9;
    body_of_snake[0][0] = 6; 
    body_of_snake[0][1] = 9;
    body_of_snake[1][0] = 5;
     body_of_snake[1][1] = 9;
    
    direction_of_snake[0] = 1; 
    direction_of_snake[1] = 0;

}
void Randomcoords(int& foodX, int& foodY)
{
    bool validPosition = false;
    
    while (!validPosition)
    {
        foodY = GetRandomValue(0, cell_count - 1);
        foodX = GetRandomValue(0, cell_count - 1);
        
        
        bool isOnSnake = false;
        for (int i = 0; i < snakesize; i++)
        {
            if (body_of_snake[i][0] == foodX && body_of_snake[i][1] == foodY)
            {
                isOnSnake = true;
                break;
            }
        }
        
        bool isOnWall = false;
        for (int i = 0; i < number_of_walls; i++)
        {
            if (walls[i][0] == foodX && walls[i][1] == foodY)
            {
                isOnWall = true;
                break;
            }
        }
        
        if (!isOnSnake && !isOnWall)
        {
            validPosition = true;
        }
    }
}

void spawnFood(int foodX, int foodY)
{
    DrawEllipse((borders+ foodX * size_of_cell + size_of_cell / 2),
        (borders + foodY * size_of_cell + size_of_cell / 2),
        size_of_cell / 2, size_of_cell / 3, RED);
}

void CheckCollisionFood(int &foodX, int &foodY)
{
    if (body_of_snake[0][0] == foodX && body_of_snake[0][1] == foodY)
    {
        Randomcoords(foodX, foodY);  
        is_add_segment = true;
        score++;
    }
}

void CheckCollisionedges()
{
    if (body_of_snake[0][0] >= cell_count)
        body_of_snake[0][0] = 0;
    else if (body_of_snake[0][0] < 0)
        body_of_snake[0][0] = cell_count - 1;

    if (body_of_snake[0][1] >= cell_count)
        body_of_snake[0][1] = 0;
    else if (body_of_snake[0][1] < 0)
        body_of_snake[0][1] = cell_count - 1;
}

void CheckCollisiontail(char playerName[50],int score)
{
    for (int i = 1; i < snakesize; i++) 
    {
        if (body_of_snake[0][0] == body_of_snake[i][0] && body_of_snake[0][1] == body_of_snake[i][1])
        {
            GameOver(playerName,score);
            Resetsnake();
            break;
        }
    }
}

void CheckCollisionWithWalls(int& foodX, int& foodY,char playerName[50],int score)
{
    for (int i = 0; i < number_of_walls; i++)
    {
        if (body_of_snake[0][0] == walls[i][0] && body_of_snake[0][1] == walls[i][1])
        {
            GameOver(playerName,score);
            Resetsnake();
            break;
        }
    }
}

void AddWall(int x, int y)
{
    if (number_of_walls < max_walls)
    {
        walls[number_of_walls][0] = x;
        walls[number_of_walls][1] = y;
        number_of_walls++;
    }
}

void SpeedMenu()
{
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Select Snake Speed:",borders + 10, borders + 10, 40, BLACK);
        DrawText("1. Slow", borders+ 10, borders + 50, 30, BLACK);
        DrawText("2. Medium", borders + 10, borders + 90, 30, BLACK);
        DrawText("3. Fast", borders+ 10, borders + 130, 30, BLACK);

        if (IsKeyPressed(KEY_ONE))
        {
            speeed_of_snake = 0.5;
            return;
        }
        if (IsKeyPressed(KEY_TWO))
        {
            speeed_of_snake = 0.2;
            return;
        }
        if (IsKeyPressed(KEY_THREE))
        {
            speeed_of_snake = 0.1;
            return;
        }

        EndDrawing();
    }
}

void PlayerName(char playerName[], int maxLength)
{
    int length = 0; 
    bool nameEntered = false;

    while (!nameEntered && !WindowShouldClose())
    {
        int key = GetCharPressed();

        while (key > 0)
        {
            if (key == KEY_BACKSPACE && length > 0)
            {
                length--; 
                playerName[length] = '\0'; 
            }
            else if (key >= 32 && key <= 126 && length < maxLength - 1)
            {
                playerName[length] = (char)key;
                length++;
                playerName[length] = '\0'; 
            }
            key = GetCharPressed(); 
        }

        if (IsKeyPressed(KEY_ENTER) && length > 0)
        {
            nameEntered = true;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Enter your name:", 10, 10, 20, DARKGRAY);
        DrawText(playerName, 10, 40, 20, DARKGRAY); 
        EndDrawing();
    }
}


int GameMode()
{
    char modes[3][20] = { "Endless Mode",  "Level Mode", "Custom Mode" };

    int mode_selected = 0;
    int size_of_modes=3*20;
    int size_of_element=20;
    int number_of_modes = size_of_modes / size_of_element;

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_W))
        {
            mode_selected = (mode_selected - 1 + number_of_modes) % number_of_modes;
        }
        if (IsKeyPressed(KEY_S))
        {
            mode_selected = (mode_selected + 1) % number_of_modes;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Select Game Mode (Use W/S to navigate):", 10, 10, 20, DARKGRAY);

for (int i = 0; i < number_of_modes; ++i)
{
    Color color;


    if (i == mode_selected)
    {
        color = RED;  
    }
    else
    {
        color = DARKGRAY;  
    }

    DrawText(modes[i], 200, 100 + i * 40, 20, color);
}


        EndDrawing();

        if (IsKeyPressed(KEY_ENTER))
        {
            return mode_selected;
        }
    }

    return -1; 
}


void EndlessMode(Color snakecolor,char playerName[50])
{
       int foodX, foodY;
    Randomcoords(foodX, foodY);  
    while (!WindowShouldClose())
    {
        BeginDrawing();
       
        if (IsKeyPressed(KEY_Q)) {
            SaveGameEndless(score, snakesize, body_of_snake, direction_of_snake, foodX, foodY);
          
            ClearBackground(RAYWHITE);
            DrawText("Game Saved!", GetScreenWidth() / 2 - 100, GetScreenHeight() / 2, 30, BLUE);
            EndDrawing();
            WaitTime(2.0); 
            break;
        }

   
        if (IsKeyPressed(KEY_L)) {
            if (LoadGameEndless( score, snakesize, body_of_snake, direction_of_snake, foodX, foodY)) {
                is_game_mode = true;  

                
                ClearBackground(RAYWHITE);
                DrawText("Game Loaded Successfully!", GetScreenWidth() / 2 - 150, GetScreenHeight() / 2, 30, BLUE);
                EndDrawing();
                WaitTime(2.0);  

                ClearBackground(RAYWHITE);
                spawnFood(foodX, foodY);  
                showSnake(snakecolor);    
            } else {
              
                ClearBackground(RAYWHITE);
                DrawText("No saved game found!", GetScreenWidth() / 2 - 150, GetScreenHeight() / 2, 30, BLUE);
                EndDrawing();
                WaitTime(2.0);  
            }
        }


        if (is_game_mode)
        {
            if (GetTime() - lastupdatetime >= speeed_of_snake)
            {
                lastupdatetime = GetTime();
                UpdateSnake();
            }

            if (IsKeyPressed(KEY_W) && direction_of_snake[1] != 1)
            {
                direction_of_snake[0] = 0;
                direction_of_snake[1] = -1;
            }
            if (IsKeyPressed(KEY_S) && direction_of_snake[1] != -1)
            {
                direction_of_snake[0] = 0;
                direction_of_snake[1] = 1;
            }
            if (IsKeyPressed(KEY_A) && direction_of_snake[0] != 1)
            {
                direction_of_snake[0] = -1;
                direction_of_snake[1] = 0;
            }
            if (IsKeyPressed(KEY_D) && direction_of_snake[0] != -1)
            {
                direction_of_snake[0] = 1;
                direction_of_snake[1] = 0;
            }

            CheckCollisionFood(foodX, foodY);
            CheckCollisionedges();
            CheckCollisiontail(playerName,score);

        }
        else
        {
            
            if (IsKeyPressed(KEY_ENTER))
            {
                is_game_mode = true;
            }
        }

        ClearBackground(RAYWHITE);
        DrawRectangleLinesEx(Rectangle{ borders- 5, borders - 5, size_of_cell * cell_count + 10, size_of_cell * cell_count + 10 }, 5, BLACK);
        DrawText("Hungry Snake", borders- 5, 20, 40, BLACK);
        DrawText(TextFormat("Score: %i",snakesize - 3), borders- 5, borders+ size_of_cell * cell_count + 10, 40, BLACK);
        spawnFood(foodX, foodY);
        showSnake(snakecolor);

        EndDrawing();
    }
    Resetsnake();


}
void LevelMode(Color snakecolor, char playerName[50])
{
    int foodX, foodY;
    Randomcoords(foodX, foodY);  

    current_level = 1;  
    score = 0;
    number_of_walls = 0;  
    bool newLevelReady = true;  
    bool justLoaded = false;  

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);


        DrawRectangleLinesEx(Rectangle{ borders- 5, borders - 5, size_of_cell * cell_count + 10, size_of_cell * cell_count + 10 }, 5, BLACK);
        DrawText("Hungry Snake", borders - 5, 20, 40, BLACK);
        DrawText(TextFormat("Score: %i", score), borders - 5, borders + size_of_cell * cell_count + 10, 40, BLACK);
        DrawText(TextFormat("Level: %i", current_level), 330, borders + size_of_cell * cell_count + 10, 40, BLACK);


        if (current_level == 1) level1();
        else if (current_level == 2) level2();
        else if (current_level == 3) level3();

 
        if (newLevelReady)
        {
            DrawText(TextFormat("Level %d", current_level), GetScreenWidth() / 2 - 50, GetScreenHeight() / 2, 40, GREEN);
            DrawText("Press ENTER to start", GetScreenWidth() / 2 - 100, GetScreenHeight() / 2 + 50, 20, DARKGRAY);

            if (IsKeyPressed(KEY_ENTER))
            {
                newLevelReady = false;
                is_game_mode = true;
                score = 0;  
                Resetsnake();  
                Randomcoords(foodX, foodY);  
            }

            spawnFood(foodX, foodY);
            showSnake(snakecolor);
            EndDrawing();
            continue;
        }


        if (IsKeyPressed(KEY_Q))
        {

            SaveLevelGame(current_level, score, snakesize, body_of_snake, direction_of_snake, foodX, foodY);
            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Game Saved!", GetScreenWidth() / 2 - 100, GetScreenHeight() / 2, 30, BLUE);
            EndDrawing();
            WaitTime(2.0);  
            break;
        }

    
        if (IsKeyPressed(KEY_L))
        {
            if (LoadLevelGame(current_level, score, snakesize, body_of_snake, direction_of_snake, foodX, foodY))
            {
                is_game_mode = true;  
                newLevelReady = false;  
                justLoaded = true;  

               
                BeginDrawing();
                ClearBackground(RAYWHITE);
                DrawText("Game Loaded Successfully!", GetScreenWidth() / 2 - 150, GetScreenHeight() / 2, 30,BLUE);
                EndDrawing();
                WaitTime(2.0);  

                BeginDrawing();
                ClearBackground(RAYWHITE);
                spawnFood(foodX, foodY);  
                showSnake(snakecolor);   
                EndDrawing();
            }
            else
            {
            
                BeginDrawing();
                ClearBackground(RAYWHITE);
                DrawText("No saved game found!", GetScreenWidth() / 2 - 150, GetScreenHeight() / 2, 30, RED);
                EndDrawing();
                WaitTime(2.0);  
            }
        }

  
        if (is_game_mode)
        {
            if (justLoaded)
            {
                showSnake(snakecolor);
                justLoaded = false;  
            }
            else
            {
                if (GetTime() - lastupdatetime >= speeed_of_snake)
                {
                    lastupdatetime = GetTime();
                    UpdateSnake();  
                }

               
                if (IsKeyPressed(KEY_W) && direction_of_snake[1] != 1) { direction_of_snake[0] = 0; direction_of_snake[1] = -1; }
                if (IsKeyPressed(KEY_S) && direction_of_snake[1] != -1) { direction_of_snake[0] = 0; direction_of_snake[1] = 1; }
                if (IsKeyPressed(KEY_A) && direction_of_snake[0] != 1) { direction_of_snake[0] = -1; direction_of_snake[1] = 0; }
                if (IsKeyPressed(KEY_D) &&direction_of_snake[0] != -1) { direction_of_snake[0] = 1; direction_of_snake[1] = 0; }

        
                if (score >= 15 * current_level)
                {
                    current_level++;
                    newLevelReady = true;  
                    is_game_mode = false;
                    number_of_walls = 0;  

                    if (current_level > 3)
                    {
                        DrawText("Congratulations! You completed all levels!", GetScreenWidth() / 2 - 200, GetScreenHeight() / 2, 30, BLUE);
                        EndDrawing();
                        WaitTime(3.0);
                        return;  
                    }
                }

            
                CheckCollisionWithWalls(foodX, foodY, playerName, score);
                CheckCollisionFood(foodX, foodY);
                CheckCollisionedges();
                CheckCollisiontail(playerName, score);
            }

           
            spawnFood(foodX, foodY);
            showSnake(snakecolor);
        }

        EndDrawing();  
    }
}


void CustomMode(Color snakecolor, char playerName[50]) {
    number_of_walls = 0;
    SpeedMenu();  

    int foodX, foodY;
    Randomcoords(foodX, foodY);  
    while (!WindowShouldClose()) {
        BeginDrawing();


        if (IsKeyPressed(KEY_Q)) {
            SaveCustomGame(score, snakesize, body_of_snake, direction_of_snake, foodX, foodY, number_of_walls, walls);
          
            ClearBackground(RAYWHITE);
            DrawText("Game Saved!", GetScreenWidth() / 2 - 100, GetScreenHeight() / 2, 30, BLUE);
            EndDrawing();
            WaitTime(2.0);  
            break;
        }

        if (IsKeyPressed(KEY_L)) {
            if (LoadCustomGame(score, snakesize, body_of_snake, direction_of_snake, foodX, foodY,number_of_walls, walls)) {
                is_game_mode = true;
     

            
                ClearBackground(RAYWHITE);
                DrawText("Game Loaded Successfully!", GetScreenWidth() / 2 - 150, GetScreenHeight() / 2, 30, BLUE);
                EndDrawing();
        
                ClearBackground(RAYWHITE);
                spawnFood(foodX, foodY);  
                
                for (int i = 0; i < number_of_walls; i++) {
                    Rectangle wallRect = { borders + walls[i][0] * size_of_cell, borders + walls[i][1] * size_of_cell, size_of_cell , size_of_cell };
                    DrawRectangle(wallRect.x, wallRect.y, wallRect.width, wallRect.height, DARKGRAY);
                }
            } else {
              
                ClearBackground(RAYWHITE);
                DrawText("No saved game found!", GetScreenWidth() / 2 - 150, GetScreenHeight() / 2, 30, BLUE);
                EndDrawing();
                WaitTime(2.0);  
            }
        }


        if (is_game_mode) {
       
            if (GetTime() - lastupdatetime >= speeed_of_snake) {
                lastupdatetime = GetTime();
                UpdateSnake();
            }

       
            if (IsKeyPressed(KEY_W) && direction_of_snake[1] != 1) 
            {
                direction_of_snake[0] = 0;
                direction_of_snake[1] = -1;
            }
            if (IsKeyPressed(KEY_S) && direction_of_snake[1] != -1)  
            {
                direction_of_snake[0] = 0;
                direction_of_snake[1] = 1;
            }
            if (IsKeyPressed(KEY_A) && direction_of_snake[0] != 1)  
            {
                direction_of_snake[0] = -1;
                direction_of_snake[1] = 0;
            }
            if (IsKeyPressed(KEY_D) && direction_of_snake[0] != -1)  
            {
                direction_of_snake[0] = 1;
                direction_of_snake[1] = 0;
            }


            CheckCollisionFood(foodX, foodY);
            CheckCollisionedges();
            CheckCollisiontail(playerName, score);
            CheckCollisionWithWalls(foodX, foodY, playerName, score);
        }
        else {
        
            DrawText("Use mouse to add walls", 10, 55, 15, BLACK);

           
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                Vector2 mousePos = GetMousePosition();
                int gridX = (mousePos.x - borders) /size_of_cell;
                int gridY = (mousePos.y - borders) / size_of_cell;

                if (gridX >= 0 && gridX <cell_count && gridY >= 0 && gridY < cell_count) {
                    AddWall(gridX, gridY);
                }
            }

            
            if (IsKeyPressed(KEY_ENTER)) {
                is_game_mode = true;  
            }
        }

     
        ClearBackground(RAYWHITE);
        DrawRectangleLinesEx(Rectangle{ borders - 5, borders - 5, size_of_cell * cell_count + 10, size_of_cell * cell_count + 10 }, 5, BLACK);
        DrawText("Hungry Snake", borders - 5, 20, 40, BLACK);
        DrawText(TextFormat("Score: %i", snakesize-3), borders - 5,borders + size_of_cell * cell_count + 10, 40, BLACK); 
        spawnFood(foodX, foodY);
        showSnake(snakecolor);

       
        for (int i = 0; i < number_of_walls; i++) {
            Rectangle wallRect = Rectangle{ borders + walls[i][0] * size_of_cell, borders + walls[i][1] * size_of_cell, size_of_cell, size_of_cell};
            DrawRectangle(wallRect.x, wallRect.y, wallRect.width, wallRect.height,DARKGRAY);
        }

        EndDrawing();
    }

    is_game_mode= 0;
    Resetsnake();
}

void ShowMenu()
{
    char menu[4][20] = { "Start Game",  "High Scores","How To Play" , "Exit" };
    int highlight = 0;
    int numOptions = sizeof(menu) / sizeof(menu[0]);

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_W))
        {
            highlight = (highlight - 1 + numOptions) % numOptions;
        }
        if (IsKeyPressed(KEY_S))
        {
            highlight = (highlight + 1) % numOptions;
        }

        if (IsKeyPressed(KEY_ENTER))
        {
            if (highlight == 0) 
            {
                char playerName[50] = { 0 }; 
                PlayerName(playerName, sizeof(playerName));

                int colorIndex = chooseSnakecolor();
                int modeIndex = GameMode();

                Color colors[] = { PINK,BLUE,PURPLE,GREEN,RED,YELLOW, ORANGE };
                char modes[3][20] = { "Endless Mode",   "Level Mode",  "Custom Mode"};

                while (!WindowShouldClose())
                {
                    BeginDrawing();
                    ClearBackground(RAYWHITE);
                    DrawText("Player:    ", 10, 10, 20, DARKGRAY);
                    DrawText(playerName, 80, 10, 20, DARKGRAY);

                    DrawText("Snake Color:    ", 10, 40, 20, DARKGRAY);
                    DrawRectangle(150, 40, 50, 50, colors[colorIndex]);

                    DrawText("Game Mode:    ", 10, 100, 20, DARKGRAY);
                    DrawText(modes[modeIndex], 150, 100, 20, DARKGRAY); 

                    DrawText("Press Enter to start", 10, 160, 20, DARKGRAY);
                    EndDrawing();

                    if (IsKeyPressed(KEY_ENTER))
                    {
                        if(modeIndex==0)
                        {
                            EndlessMode(colors[colorIndex],playerName);
                        }
                        else if(modeIndex==1)
                        {
                            LevelMode(colors[colorIndex],playerName);

                        }
                        else if(modeIndex==2)
                        {
                            CustomMode(colors[colorIndex],playerName);
                        }
                
                    }
                }
            }
            else if (highlight == 1) 
            {
        int highscores[10] = {0};
        char names[10][20] = {0};
        int size = 0;
        loadHighscores(highscores, names, size);

        displayHighscores(highscores, names, size);
            }
                                   else if (highlight == 2) 
            {
                while (!WindowShouldClose())
                {
                    BeginDrawing();
                    ClearBackground(RAYWHITE);
                    DrawText("1. Press Q to save and quit.", 10, 10, 20, DARKGRAY);
                    DrawText("2. Press L to load that game.", 10, 50, 20, DARKGRAY);
                    DrawText("3. Use WASD to navigate.", 10, 90, 20, DARKGRAY);
                    EndDrawing();

                    if (IsKeyPressed(KEY_ESCAPE))
                    {
                        break;
                    }
                }
            }
        
            else if (highlight == 3) 
            {
                return;
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hungry Snake Game", 10, 10, 30, DARKGRAY);
        DrawText("Use W/S to navigate and Enter to select", 10, 50, 20, DARKGRAY);
        for (int i = 0; i < numOptions; ++i)
{
    Color color;
    if (i == highlight)
    {
        color = RED;  
    }
    else
    {
        color = DARKGRAY;  
    }

    DrawText(menu[i], 200, 100 + i * 40, 20, color);
}


        EndDrawing();
    }
}
int main()
{
    
        InitWindow(2 *borders + size_of_cell * cell_count, 2 * borders + size_of_cell * cell_count, "Hungry Snake");
       SetTargetFPS(60);
           ShowMenu();
    CloseWindow(); 
    return 0;
}
// clang++ -std=c++11 24L2512_24L2514.cpp -o 24L2512_24L2514 -I/usr/local/include -L/usr/local/lib -lraylib -lm -lpthread -ldl -framework OpenGL -framework Cocoa -framework IOKit -framework CoreFoundation