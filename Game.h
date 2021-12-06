#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Snake - Thijs, Anouchka - Rings, Angelica - 1DAE13GDE" };

// Change the window dimensions here
float g_WindowWidth{ 700 };
float g_WindowHeight{ 700 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
const float g_CellSize{ 25 };
int g_GridSize{ (g_WindowWidth/g_CellSize) * (g_WindowHeight/g_CellSize) };
Rectf* pCells{ new Rectf[g_GridSize] {} };
int g_Fruit{};
// Declare your own functions here
void InitGrid();
void InitializeFruit();
int GetCellIdx(Point2f point);
#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void Draw();
void Update(float elapsedSec);
void End();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
