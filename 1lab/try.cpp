#include "try.h"

figure &initFigure(figure &myFigure)
{
    myFigure.points.amountDots = 0;
    myFigure.points.arrayStructpoints = NULL;

    myFigure.links.amountLinks = 0;
    myFigure.links.arrayStructlinks = NULL;

    return myFigure;
}

int pointsAlloc(pointsData &points, linksData &links)
{
    int codeError = OK;

    int countDots = points.amountDots;
    int countLinks = links.amountLinks;

    points.arrayStructpoints = (point*) calloc(countDots, sizeof(point));
    links.arrayStructlinks = (link*) calloc(countLinks, sizeof(link));

    if (!points.arrayStructpoints)
        codeError = ERROR_ALLOC_MEMORY;

    if (!links.arrayStructlinks)
        codeError = ERROR_ALLOC_MEMORY;

    return codeError;
}

void pointsFree(pointsData &points, linksData &links)
{
    if (points.arrayStructpoints)
        free(points.arrayStructpoints);

    if (links.arrayStructlinks)
        free(links.arrayStructlinks);
}

void freeMemory(figure &myFigure)
{
    pointsFree(myFigure.points, myFigure.links);
}

void freePreviousFigure(figure &myFigure)
{
    freeMemory(myFigure);
}

int readCountOfPointsAndLinks(FILE *file, figure &myFigure)
{
    int errorCode = OK;
    int countPoints = 0, countLinks = 0;
    if (fscanf(file, "%d %d", &countPoints, &countLinks) != 2)
    {
        errorCode = ERROR_READING_COUNT;
    }
    if (countPoints <= 0 || countLinks <= 0)
    {
        errorCode = ERROR_FORMAT_COUNT;
    }
    if (!errorCode)
    {
        myFigure.points.amountDots = countPoints;
        myFigure.links.amountLinks = countLinks;
    }
    return errorCode;
}

int readPoint(point &dot, FILE *file)
{
    int codeError = OK;

    if (fscanf(file, "%lf %lf %lf %d", &dot.x, &dot.y, &dot.z, &dot.number) != 4)
        codeError = ERROR_FORMAT_DATA;

    return codeError;
}

int readAllPoints(pointsData &points, FILE *file)
{
    int codeError = OK;

    for (int i = 0; i < points.amountDots && !codeError; i++)
    {
        if (readPoint(points.arrayStructpoints[i], file))
            codeError = ERROR_FORMAT_DATA;
    }
    return codeError;
}

int readLinks(link &arrayLinks, FILE *file)
{
    int codeError = OK;

    if (fscanf(file, "%d %d", &arrayLinks.from, &arrayLinks.to) != 2)
        codeError = ERROR_FORMAT_DATA;

    return codeError;
}

int readAllLinks(linksData &links, FILE *file)
{
    int codeError = OK;

    for (int i = 0; i < links.amountLinks && !codeError; i++)
    {
        if (readLinks(links.arrayStructlinks[i], file))
            codeError = ERROR_FORMAT_DATA;
    }
    return codeError;
}

int readPointsAndLinks(FILE *file, figure &myFigure)
{
    int errorCode = OK;

    errorCode = readAllPoints(myFigure.points, file);

    if (!errorCode)
    {
        errorCode = readAllLinks(myFigure.links, file);
    }

    return errorCode;
}

int inputDataFromFile(const char *filename, figure &myFigure)
{
    int codeError = OK;
    FILE *file = fopen(filename, "r");

    if (!file)
    {
        codeError = ERROR_OPENING_FILE;
    }
    else
    {
        codeError = readCountOfPointsAndLinks(file, myFigure);
    }

    if (!codeError)
    {
        freePreviousFigure(myFigure);
    }

    if (!codeError)
    {
        codeError = pointsAlloc(myFigure.points, myFigure.links);
    }

    if (codeError == ERROR_ALLOC_MEMORY)
    {
        freeMemory(myFigure);
    }

    if (!codeError)
    {
        codeError = readPointsAndLinks(file, myFigure);
    }

    if (!ERROR_OPENING_FILE)
    {
        fclose(file);
    }

    return codeError;
}

int SceneInit(scene &canvas, graphView &drawInfo)
{
    int codeError = OK;

    canvas.scene = new QGraphicsScene(drawInfo.graphView);
    if (!canvas.scene)
        codeError = ERROR_ALLOC_MEMORY;

    canvas.pen = QPen(Qt::black);

    return codeError;
}

void CanvasPlace(graphView &drawInfo, scene &canvas)
{
    canvas.scene->setSceneRect(QRectF(QPointF(0, 0), QSizeF(drawInfo.width, drawInfo.height)));
    QGraphicsScene *prev = drawInfo.graphView->scene();
    delete prev;
    drawInfo.graphView->setScene(canvas.scene);
}

int DrawFigure(figure &myFigure, graphView &drawInfo)
{
    int codeError = OK;
    scene canvas;

    codeError = SceneInit(canvas, drawInfo);
    DrawLinks(myFigure.points, myFigure.links, drawInfo, canvas);
    CanvasPlace(drawInfo, canvas);

    return codeError;
}

int manager(Manager myManager)
{
    static figure myFigure = initFigure(myFigure);
    int errorCode = OK;

    switch (myManager.task)
    {
        case INPUT_DATA_FROM_FILE:
            errorCode = inputDataFromFile(myManager.input.filename, myFigure);
            //printf("%d %d", myFigure.points.amountDots, myFigure.links.amountLinks);
            break;
        case DRAW:

        default:
            errorCode = ERROR_TASK;
    }
    return errorCode;
}
