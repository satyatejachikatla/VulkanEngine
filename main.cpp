#include <first_app.hpp>
#include <ve_device/ve_device.hpp>

#include <cstdlib>
#include <iostream>
#include <stdexcept>

int main()
{
    ve::FirstApp app{};

    try
    {
        app.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}