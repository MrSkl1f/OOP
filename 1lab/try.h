#ifndef TRY_H
#define TRY_H

#include <stdlib.h>
#include <cstdio>
#include "QGraphicsView"

#define OK 0
#define ERROR_OPENING_FILE 1
#define ERROR_READING_COUNT 2
#define ERROR_FORMAT_COUNT 3
#define ERROR_FORMAT_DATA 4
#define ERROR_ALLOC_MEMORY 5
#define ERROR_TASK 6

enum currentTask
{
    FREE,
    INPUT_DATA_FROM_FILE,
    DRAW,
    MOVE,
    SCALE,
    TURN
};

struct graphView
{
    QGraphicsView *graphView;
    int height;
    int width;
};

struct inputData
{
    const char *filename;
};

struct link
{
    int from;
    int to;
};

struct linksData
{
    int amountLinks;
    link *arrayStructlinks;
};

struct point
{
    double x;
    double y;
    double z;
    int number;
};

struct scene
{
    QGraphicsScene *scene;
    QPen pen;
};

struct pointsData
{
    int amountDots;
    point *arrayStructpoints;
};

struct figure
{
    pointsData points;
    linksData links;
};

struct Manager
{
    currentTask task;
    union
    {
        struct inputData input;
        struct graphView curView;
    };
};

figure &initFigure(figure &myFigure);
int pointsAlloc(pointsData &points, linksData &links);
void pointsFree(pointsData &points, linksData &links);
void freeMemory(figure &myFigure);
void freePreviousFigure(figure &myFigure);
int readCountOfPointsAndLinks(FILE *file, figure &myFigure);
int inputDataFromFile(const char *filename, figure &myFigure);
int readPoint(point &dot, FILE *file);
int readAllPoints(pointsData &points, FILE *file);
int readLinks(link &arrayLinks, FILE *file);
int readAllLinks(link *arrayStructlinks, int amountLinks, FILE *file);
int readPointsAndLinks(FILE *file, figure &myFigure);
int inputDataFromFile(const char *filename, figure &myFigure);
int manager(Manager myManager);

#endif // TRY_H
