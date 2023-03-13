#include "Renice.h"

// Used similar implementation in main of other commands

int main(int argc, char **argv)
{
    Renice app(argc, argv);
    return app.run();
}
