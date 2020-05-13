#include "inputLinks.h"

int readCountOfLinks(FILE *curFile, int &countOfLinks)
{
    int errCode = NO_EXCEPTION;
    if (fscanf(curFile, "%d", &countOfLinks) != 1)
        return FILE_FORMAT_EXCEPTION;
    return errCode;
}

int readAllLinks(linkData &info, FILE *curFile)
{
    int errCode = NO_EXCEPTION;
    for (int i = 0; i < info.countOfLinks && !errCode; i++)
        errCode = inputLink(curFile, info.links, i);
    return errCode;
}

int inputLink(FILE *curFile, oneLink *curLink, int curPos)
{
    int errCode = NO_EXCEPTION;
    if (inputCurLink(curFile, curLink[curPos]) != 2)
        return FILE_FORMAT_EXCEPTION;
    return errCode;
}

int inputCurLink(FILE *curFile, oneLink &curLink)
{
    return fscanf(curFile, "%d %d", &(curLink.from), &(curLink.to));
}
