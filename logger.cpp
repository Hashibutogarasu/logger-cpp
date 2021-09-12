#include <iostream>
#include "Log.h"


int main()
{

    const char * filename = "test.txt";
    const char * mode = "a";

    Logger logger;

    logger.debug(filename, mode, (const char*)"debug\n");
    logger.info(filename, mode, (const char*)"info\n");
    logger.warn(filename, mode, (const char*)"warning!\n");

}