#include "exceptions.h"

void showException(int errCode)
{
    switch (errCode)
    {
        case ALLOC_EXCEPION:
            QMessageBox::critical(NULL, "Ошибка", "Ошибка выделения памяти");
            break;
        case FILE_READING_EXCEPTION:
            QMessageBox::critical(NULL, "Ошибка", "Ошибка открытия файла");
            break;
        case FILE_FORMAT_EXCEPTION:
            QMessageBox::critical(NULL,"Ошибка", "Ошибка формата записи");
            break;
        case COMMAND_EXCEPTION:
            QMessageBox::critical(NULL, "Ошибка", "Команды не найдено");
            break;
        case NO_ARR_EXCEPTION:
            QMessageBox::critical(NULL, "Ошибка", "Массив пустой");
            break;
    }
}
