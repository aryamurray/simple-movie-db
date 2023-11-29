#include "helper.h"
void flushBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}