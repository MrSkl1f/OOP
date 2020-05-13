#include "drawFigure.h"

int drawFigure(curFigure &myFigure, graphView &infoGraph)
{
    int codeError = NO_EXCEPTION;

    codeError = SceneInit(infoGraph);
    drawLinks(myFigure, infoGraph);

    return codeError;
}

int SceneInit(graphView &infoGraph)
{
    QGraphicsScene *canvas = NULL;
    int codeError = NO_EXCEPTION;
    if (!infoGraph.graphViewUI->scene())
    {
        canvas = new QGraphicsScene(infoGraph.graphViewUI);
        if (!canvas)
            codeError = ALLOC_EXCEPION;
        else
        {
            canvas->setSceneRect(QRectF(QPointF(0, 0), QSizeF(infoGraph.width, infoGraph.height)));
            infoGraph.graphViewUI->setScene(canvas);
        }
    }
    else
        infoGraph.graphViewUI->scene()->clear();
    return codeError;
}
