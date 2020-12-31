#pragma once
#include "stopwatch.hpp"

using namespace System;

namespace Relapse {
	public ref class PrecisionWatch
	{
    public:
        // constructor
        PrecisionWatch();

        // wrapper methods
        void Start();
        int ElapsedNanoseconds();
        double ElapsedMicroseconds();
        double ElapsedMilliseconds();
        double ElapsedSeconds();
    private:
        stopwatch::Stopwatch* mySW;
	};
}
