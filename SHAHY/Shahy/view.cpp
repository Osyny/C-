#include "view.h"

GameView::GameView(Dlist<Cell *> *_cells) : isStarted(true), activeCell(nullptr)
{
    cells = _cells;
    window = new RenderWindow(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "The Game!");

    init();
}

GameView::~GameView()
{
    if (cells != nullptr)
        delete cells;

    if (window != nullptr)
        delete window;

}

void GameView::init()
{
    Image icon;
    if (icon.loadFromFile("Images/Icon.png"))
    {
        window->setIcon(32, 32, icon.getPixelsPtr());
    }

    bgImage.loadFromFile("Images/Background.png");

    updateGraphics();
}

void GameView::startLoop()
{
    cout << "Loop started!\n";
    isStarted = true;
    eventLoop();
}

void GameView::stopLoop()
{
    cout << "Loop has been sttoped!\n";
    isStarted = false;
}

void GameView::eventLoop()
{
    while (isStarted && window->isOpen())
    {
        Event event;
        while (window->pollEvent(event))
        {
            if (event.type == Event::MouseButtonPressed)
            {
                int mouseX = event.mouseButton.x - BOARD_X;
                int mouseY = event.mouseButton.y - BOARD_Y;

                if (mouseX >= 0 && mouseX <= CELL_SIZE * BOARD_SIZE && mouseY >= 0 && mouseY <= CELL_SIZE * BOARD_SIZE)
                {
                    Position pos(mouseX / CELL_SIZE, mouseY / CELL_SIZE);

                    auto cur = cells->getElem(pos.getIndex(BOARD_SIZE, BOARD_SIZE));

                    if (cur != nullptr)
                    {
                        Cell* cell = cur->getData();

                        cout << "Click on cell X: " << cell->getPosition()->getX() << ", Y: " << cell->getPosition()->getY()
                             << ", index: " << cell->getPosition()->getIndex(BOARD_SIZE, BOARD_SIZE) << endl;

                        activeCell = cell->doStep(cells, activeCell);

                        updateGraphics();
                    }

                }
            }
            else if (event.type == Event::Closed)
            {
                window->close();
            }
        }
    }
}

void GameView::updateGraphics()
{
    window->clear(Color::White);

    //Draw background
    Sprite bgSprite(bgImage);
    bgSprite.setScale(WINDOW_WIDTH / bgImage.getSize().x, WINDOW_HEIGHT / bgImage.getSize().y);
    window->draw(bgSprite);

    //Draw board
    for (auto iter = cells->getHead(); iter != nullptr; iter = iter->getNext())
    {
        Cell* cell = iter->getData();

        //Draw cell
        RectangleShape rect(Vector2f(CELL_SIZE, CELL_SIZE));
        rect.setPosition(cell->getPosition()->getX() * CELL_SIZE + BOARD_X, cell->getPosition()->getY() * CELL_SIZE + BOARD_Y);
        rect.setFillColor(cell->getType() == 0 ? Color::Yellow : Color::Blue);

        window->draw(rect);

        //Draw figure if it exist
        if (!cell->isEmpty())
        {
            FigureData* data = cell->getFigure()->getData();
            const char* url = data->getImagePath()->getStr();
            Texture figureImage;
            figureImage.loadFromFile(url);

            long int figureX = rect.getPosition().x + (CELL_SIZE - (int)figureImage.getSize().x) / 2;
            long int figureY = rect.getPosition().y + (CELL_SIZE - (int)figureImage.getSize().y) / 2;

            Sprite figureSprite(figureImage);
            figureSprite.setPosition(figureX, figureY);

            window->draw(figureSprite);
        }


    }

    // Draw backlight
    if (activeCell != nullptr)
    {
        RectangleShape selRect(Vector2f(CELL_SIZE - 4, CELL_SIZE - 4));
        selRect.setPosition(activeCell->getPosition()->getX() * CELL_SIZE + BOARD_X + 2, activeCell->getPosition()->getY() * CELL_SIZE + BOARD_Y + 2);
        selRect.setOutlineColor(Color(0xFF0000FF));
        selRect.setOutlineThickness(4);
        selRect.setFillColor(Color::Transparent);
        window->draw(selRect);
    }

    //Draw beaten figures - SINGLTON
    GameData *gameData = GameData::getInstance();
    int i = 0;
    for(auto cur = gameData->getUpBeatFig()->getHead(); cur != nullptr; cur = cur->getNext())
    {
        FigureData* data = cur->getData()->getData();
        const char* url = data->getImagePath()->getStr();
        Texture figureImage;
        figureImage.loadFromFile(url);

        long int figureX = BOARD_X + CELL_SIZE / 2 * i;
        long int figureY = UP_BEATEN_Y + CELL_SIZE / 2 - figureImage.getSize().y / 2;

        Sprite figureSprite(figureImage);
        figureSprite.setScale(0.5, 0.5);
        figureSprite.setPosition(figureX, figureY);

        window->draw(figureSprite);
        i++;
    }

    i = 0;
    for(auto cur = gameData->getDownBeatFig()->getHead(); cur != nullptr; cur = cur->getNext())
    {
        FigureData* data = cur->getData()->getData();
        const char* url = data->getImagePath()->getStr();
        Texture figureImage;
        figureImage.loadFromFile(url);

        long int figureX = BOARD_X + CELL_SIZE / 2 * i;
        long int figureY = DOWN_BEATEN_Y + CELL_SIZE / 2 - figureImage.getSize().y / 2 ;

        Sprite figureSprite(figureImage);
        figureSprite.setScale(0.5, 0.5);
        figureSprite.setPosition(figureX, figureY);

        window->draw(figureSprite);
        i++;
    }


    window->display();
}
