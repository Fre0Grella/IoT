#ifndef __DISPLAY__
#define __DISPLAY__

class Display {
    public:
        virtual void print(char string[]) = 0;
        virtual void clear() = 0;
};

#endif