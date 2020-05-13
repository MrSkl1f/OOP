#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#define NO_EXCEPTION 0
#define ALLOC_EXCEPION 1
#define FILE_READING_EXCEPTION 2
#define FILE_FORMAT_EXCEPTION 3
#define COMMAND_EXCEPTION 4
#define NO_ARR_EXCEPTION 5

#include "QMessageBox"

void showException(int errCode);

#endif // EXCEPTIONS_H
