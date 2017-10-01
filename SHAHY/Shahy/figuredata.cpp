#include "figuredata.h"


FigureData::FigureData(const char *url, Dlist<Position> *goPath, Dlist<Position> *atackPath)
{
    imagePath = new String(url);
    this->goPath = goPath;

    this->atackPath = atackPath != nullptr ? atackPath : goPath;
}

FigureData::FigureData(const String url, Dlist<Position> *goPath, Dlist<Position> *atackPath)
{
    imagePath = new String(url);
    this->goPath = goPath;

    this->atackPath = atackPath != nullptr ? atackPath : goPath;
}

FigureData::~FigureData()
{
    if(goPath != nullptr)
        delete goPath;

    if(atackPath != nullptr)
        delete atackPath;

    if(imagePath != nullptr)
        delete imagePath;

}

String *FigureData::getImagePath()
{
    return imagePath;
}

void FigureData::setImagePath(const char *url)
{
    imagePath = new String(url);
}

Dlist<Position> *FigureData::getGoPath()
{
    return goPath;
}

Dlist<Position> *FigureData::getAtackPath()
{
    return atackPath;
}
