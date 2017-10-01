#pragma once
#include "position.h"
#include "dlist.h"
#include "str.h"

class FigureData
{
public:
    FigureData(const char* url, Dlist<Position> *goPath, Dlist<Position> *atackPath = nullptr);
    FigureData(const String url, Dlist<Position> *goPath, Dlist<Position> *atackPath = nullptr);


    ~FigureData();

    String *getImagePath();
    void setImagePath(const char *url);

    Dlist<Position> *getGoPath();
    Dlist<Position> *getAtackPath();

private:
    Dlist<Position> *goPath ;
    Dlist<Position> *atackPath ;

    String *imagePath;
};
