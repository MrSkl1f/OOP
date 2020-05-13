#ifndef DRAWFIGURE_H
#define DRAWFIGURE_H

#include "QGraphicsView"
#include "QPen"
#include "figure.h"
#include "exceptions.h"


struct graphView
{
    QGraphicsView *graphViewUI;
    int height;
    int width;
};


#include "transformPoints.h"

int drawFigure(curFigure &myFigure, graphView &drawInfo);
//void canvasPlace(graphView &drawInfo);
int SceneInit(graphView &drawInfo);

#endif // DRAWFIGURE_H
