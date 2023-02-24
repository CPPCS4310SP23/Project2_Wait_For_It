#ifndef __BIN_WAIT_WAIT_H
#define __BIN_WAIT_WAIT_H

#include <POSIXApplication.h>

<<<<<<< HEAD
// Used the same implmentation of other header files in the bin.

/**
 * @addtogroup bin
 * @{
 */

/**
 * Wait implementation that suspends a process until the state is changed.
 */
class Wait : public POSIXApplication
{
	public:
		/**
		 * Constructor
		 *
		 * @param argc Argument count
		 * @param argv Argument values
		 */
		Wait(int argc, char **argv);

		/**
		 * Destructor
		 */
		virtual ~Wait();

		/**
		* Execute the application.
		*
		* @return Result code
		*/
		virtual Result exec();
};

/*
=======
/**
 * @addtogroup bin
 * @{
 */

/**
 * Wait for a process to finish before starting another.
 */
class Wait : public POSIXApplication {
    public:

        /**
         * Constructor
         *
         * @param argc Argument count
         * @param argv Argument values
         */
        Wait(int argc, char **argv);

        /**
         * Destructor
         */
        virtual ~Wait();

        /**
         * Execute the application.
         *
         * @return Result code
         */
        virtual Result exec();
};

/**
>>>>>>> a2a5830ca25b7dba41d3a1ce69440ff5d2f4d6e2
 * @}
 */

#endif /* __BIN_WAIT_WAIT_H */