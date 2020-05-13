#ifndef INPUTLINKS_H
#define INPUTLINKS_H

#include "figure.h"
#include "exceptions.h"
#include <cstdio>

int readCountOfLinks(FILE *curFile, int &countOfLinks);
int readAllLinks(linkData &info, FILE *curFile);
int inputLink(FILE *curFile, oneLink *curLink, int curPos);
int inputCurLink(FILE *curFile, oneLink &curLink);

#endif // INPUTLINKS_H
