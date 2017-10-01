#include "game.h"
#include "Figures/bishop.h"
#include "Figures/king.h"
#include "Figures/knight.h"
#include "Figures/pawn.h"
#include "Figures/queen.h"
#include "Figures/rook.h"

Game::Game() : view(nullptr)
{
    init();
}

void Game::init()
{
    Dlist<Cell*> *cells = new Dlist<Cell*>;

    int cellType = 0;
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
    {
        Position *pos = new Position(i % BOARD_SIZE, i / BOARD_SIZE);

        Figure* figure = initFigure(pos);

        Cell* cell = new Cell(pos, cellType, figure);

        cells->pushBack(cell);

        //
        if ((i + 1) % BOARD_SIZE != 0)
        {
            cellType = cellType == 0 ? 1 : 0;
        }
    }

    view = new GameView(cells);
    view->startLoop();
}

Figure *Game::initFigure(Position *pos)
{
    int color = pos->getY() == 0 || pos->getY() == 1 ? 0 : 1;
    Figure* result = nullptr;

    if (pos->getY() == 0 || pos->getY() == BOARD_SIZE - 1)
    {
        switch(pos->getX())
        {
            case 0:
            case BOARD_SIZE - 1:
                result = new Rook(color);
                break;
            case 1:
            case BOARD_SIZE - 2:
                result = new Knight(color);
                break;
            case 2:
            case BOARD_SIZE - 3:
                result = new Bishop(color);
                break;
            case 3:
                result = new King(color);
                break;
            case 4:
                result = new Queen(color);
                break;
            default:
                break;

        }
    }
    else if (pos->getY() == 1 || pos->getY() == BOARD_SIZE - 2)
    {
        result = new Pawn(color);
    }

    return result;
}
