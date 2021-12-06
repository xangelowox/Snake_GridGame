#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	InitGrid();
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	SetColor(0, 0, 0, 1);
	DrawRect(10, 10, 25, 25);

}

void Update(float elapsedSec)
{
	// process input, do physics 

	// e.g. Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
}

void End()
{
	delete[] pCells;
	pCells = nullptr;
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	//switch (key)
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	////std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//switch (e.button)
	//{
	//case SDL_BUTTON_LEFT:
	//{
	//	//std::cout << "Left mouse button released\n";
	//	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	//	break;
	//}
	//case SDL_BUTTON_RIGHT:
	//	//std::cout << "Right mouse button released\n";
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	//std::cout << "Middle mouse button released\n";
	//	break;
	//}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void InitGrid()
{
	// for every row: for every column: start.x + column*10, start.y + row*10, 25, 25
	float nrCols{ g_WindowWidth / g_CellSize }, nrRows{ g_WindowHeight / g_CellSize };
	int cellnr{ 0 };

	for (int row{ 0 }; row < nrRows; row++)
	{
		for (int col{ 0 }; col < nrCols; col++)
		{
			pCells[cellnr] = Rectf{ col * g_CellSize, row * g_CellSize, g_CellSize, g_CellSize };
			++cellnr;
		}
	}
}

void InitializeFruit()
{
	Point2f point{ GetRand(0, int(g_WindowWidth)), GetRand(0, int(g_WindowHeight)) };
	GetCellIdx(point);
	int idx{ GetCellIdx(point) };
}

int GetCellIdx(Point2f point)
{
	for (int i = 0; i < g_GridSize; i++)
  {
		if(IsPointInRect(point, pCells[i]))
			return i;
  }
}

#pragma endregion ownDefinitions