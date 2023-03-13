#ifndef __BIN_RENICE_RENICE_H
#define __BIN_RENICE_RENICE_H

#include <POSIXApplication.h>

/**
 * @addtogroup bin
 * @{
 */

/**
 * Wait for a process to finish before starting another.
 */
class Renice : public POSIXApplication {
    public:

        /**
         * Constructor
         *
         * @param argc Argument count
         * @param argv Argument values
         */
        Renice(int argc, char **argv);

        /**
         * Destructor
         */
        virtual ~Renice();

        /**
         * Execute the application.
         *
         * @return Result code
         */
        virtual Result exec();
};

/**
 * @}
 */

#endif /* __BIN_WAIT_WAIT_H */