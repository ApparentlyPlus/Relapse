#include "pch.h"
#include "stopwatch.hpp"
#include "Relapse.h"

namespace sw = stopwatch;

Relapse::PrecisionWatch::PrecisionWatch()
{
    mySW = new stopwatch::Stopwatch();
}

void Relapse::PrecisionWatch::Start()
{
    mySW->start();
}

int Relapse::PrecisionWatch::ElapsedNanoseconds()
{
    return mySW->elapsed<sw::ns>();
}

double Relapse::PrecisionWatch::ElapsedMicroseconds()
{
    int mus = mySW->elapsed<sw::mus>();
    if (mus == 0) { 
        double value = (double)ElapsedNanoseconds() / (double)1000;
        return value;
    }

    return mus;
}

double Relapse::PrecisionWatch::ElapsedMilliseconds()
{
    int ms = mySW->elapsed();;
    if (ms == 0) {
        double value = (double)ElapsedMicroseconds() / (double)1000;
        return value;
    }

    return ms;
}

double Relapse::PrecisionWatch::ElapsedSeconds()
{
    int s = mySW->elapsed<sw::s>();
    if (s == 0) {
        double value = (double)ElapsedMilliseconds() / (double)1000;
        return value;
    }

    return s;
}

