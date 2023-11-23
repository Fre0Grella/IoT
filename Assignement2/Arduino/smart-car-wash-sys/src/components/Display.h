#ifndef __DISPLAY__
#define __DISPLAY__

#include <String.h>

class Display {
    public:
        virtual void print(String string) = 0;
        virtual void clear() = 0;
};

#endif