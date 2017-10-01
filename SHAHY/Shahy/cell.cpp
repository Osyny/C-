#include "cell.h"

Cell::Cell(Position* _pos, int _type, Figure* _figure)
{
    pos = _pos;
    type = _type;

    figure = _figure;
}

Cell::~Cell()
{
    if(pos != nullptr)
        delete pos;

    if(figure != nullptr)
        delete figure;
}

bool Cell::getActive()
{
    return isActive;
}

void Cell::setPosition(Position *_pos)
{
    pos = _pos;
}

Position *Cell::getPosition()
{
    return pos;
}

int Cell::getType()
{
    return type;
}

Figure *Cell::getFigure()
{
    return figure;
}

void Cell::setFigure(Figure *_figure)
{
    figure = _figure;
}

Cell *Cell::doStep(Dlist<Cell *> *cells, Cell *activeCell)
{
    Cell* result = nullptr;

    //Perform go or atack
    if(activeCell != nullptr && activeCell != this && !activeCell->isEmpty())
    {
        FigureData* activeFigureData = activeCell->getFigure()->getData();

        //Check go
        if (isEmpty())
        {
            if (checkPath(activeFigureData->getGoPath(), activeCell->getPosition()) &&
                checkFreeWay(cells, activeCell->getPosition()))
            {
                figure = activeCell->getFigure();
                activeCell->setFigure(nullptr);
            }
        }
        // When figura beaten
        else if (activeCell->getFigure()->getColor() != figure->getColor())
        {
            if (checkPath(activeFigureData->getAtackPath(), activeCell->getPosition()) &&
                checkFreeWay(cells, activeCell->getPosition()))
            {

                if (figure->getColor() == 0)
                {
                    GameData::getInstance()->getDownBeatFig()->pushBack(figure);
                }
                else
                {
                    GameData::getInstance()->getUpBeatFig()->pushBack(figure);
                }
                figure = activeCell->getFigure();
                activeCell->setFigure(nullptr);
            }
        }
    }
    else if (activeCell == nullptr || activeCell != this) //Backlight cell
    {
        result = this;
    }

    return result;
}

bool Cell::checkFreeWay(Dlist<Cell*> *cells, Position* activePos)
{
    bool result = true;

    int dx = pos->getX() - activePos->getX();
    int dy = pos->getY() - activePos->getY();

    //Check horizontal line
    if (dy == 0 && abs(dx) > 1)
    {
         int dir = dx > 0 ? 1 : -1;

         for (int i = 1; i < abs(dx); i++)
         {
             Position curPos(activePos->getX() + i * dir, activePos->getY());
             int index = curPos.getIndex(8, 8);

             Cell *cell = cells->getElem(index)->getData();
             if (cell != nullptr && !cell->isEmpty())
             {
                 result = false;
                 break;
             }
         }
    }
    //Check vertical line
    else if(dx ==0 && abs(dy) > 1)
    {
        int dir = dy > 0 ? 1 : -1;
        for(int i = 1; i < abs(dy); i++)
        {
            Position curPos(activePos->getX(), activePos->getY() + i * dir);
            int index = curPos.getIndex(8, 8);

            Cell *cell = cells->getElem(index)->getData();
            if(cell != nullptr && !cell->isEmpty())
            {
                result = false;
                break;
            }

        }
    }

    //Check diagonal
    else if(abs(dx) == abs(dy) && abs(dx) > 1)
    {
        int dirX = dx > 0 ? 1: -1;
        int dirY = dy > 0 ? 1: -1;

        for(int i = 1; i < abs(dx); i++)
        {
            Position curPos(activePos->getX() + i * dirX, activePos->getY() + i * dirY);
            int index = curPos.getIndex(8, 8);

            Cell *cell = cells->getElem(index)->getData();
            if(cell != nullptr && !cell->isEmpty())
            {
                result = false;
                break;
            }

        }
    }


    return result;

}

bool Cell::isEmpty()
{
    return figure == nullptr;
}

bool Cell::checkPath(Dlist<Position> *path, Position* activePos)
{
    bool result = false;
    for (auto cur = path->getHead(); cur != nullptr; cur = cur->getNext())
    {
        int pathX = cur->getData().getX();
        int pathY = cur->getData().getY();

        if (activePos->getX() + pathX == pos->getX() && activePos->getY() + pathY == pos->getY())
        {
            result = true;
            break;
        }
    }
    return result;
}
