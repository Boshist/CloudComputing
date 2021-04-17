#include "ATS.h"

int main()
{
    
    ATS ats = ATS();
    ats.Call("Alice", "John");
    ats.Call("Alice", "Alex");
    ats.Call("James", "Tim");
    ats.Call("Lucas", "Emma");

    while (ats.Working());

    return 0;
}
