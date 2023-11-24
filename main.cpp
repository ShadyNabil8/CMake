#include <iostream>
#include "led.h"
#include "mymath.h"
#include "defaultconfig.h"
int main(int argc, char const *argv[])
{
    GetMathLib();
    std::cout << "HelloWorldCMake" << std::endl;
    std::cout << "PRODUVT_YEAR: " << msgfromCMake << std::endl;
    std::cout << "APP_VERSION_MAJOR: " << APP_VERSION_MAJOR << std::endl;
    std::cout << "APP_VERSION_MINOR: " << APP_VERSION_MINOR << std::endl;
    return 0;
}
