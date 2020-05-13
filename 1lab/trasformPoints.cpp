#include "transformPoints.h"

void drawLinks(curFigure &myFigure, graphView &drawInfo)
{
    for (int i = 0; i < myFigure.links.countOfLinks; i++)
        drawCurLine(myFigure.points, myFigure.links, drawInfo, i);
}

void drawCurLine(pointData points, linkData links, graphView drawInfo, int i)
{
    coords firstPoint, secondPoint;
    firstPoint = takeDot(points.points, countPosFrom(links.links, i));
    secondPoint = takeDot(points.points, countPosTo(links.links, i));

    firstPoint = pointTransform(firstPoint, drawInfo);
    secondPoint = pointTransform(secondPoint, drawInfo);

    drawLine(drawInfo, firstPoint.x, secondPoint.x, firstPoint.y, secondPoint.y);
}

coords takeDot(onePoint *points, int curPos)
{
    return getDot(points[curPos]);
}

int countPosFrom(oneLink *links, int i)
{
    return links[i].from - 1;
}

int countPosTo(oneLink *links, int i)
{
    return links[i].to - 1;
}

coords getDot(onePoint point)
{
    coords dot = {point.x, point.y, point.z};
    return dot;
}

coords pointTransform(coords &curPoint, graphView drawInfo)
{
    curPoint.z = sqrt(2)/2 * curPoint.z;

    curPoint.x -= curPoint.z;
    curPoint.x += drawInfo.width / 2;

    curPoint.y = curPoint.z - curPoint.y;
    curPoint.y += drawInfo.height / 2;

    return curPoint;
}

void drawLine(graphView drawInfo, int x1, int x2, int y1, int y2)
{
    drawInfo.graphViewUI->scene()->addLine(x1, y1, x2, y2);
}
