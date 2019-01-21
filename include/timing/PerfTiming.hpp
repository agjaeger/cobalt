#pragma once
	
#include <windows.h>

namespace cobalt {
	namespace timing {
		LARGE_INTEGER PCFreq;
		LARGE_INTEGER StartTime;

		void StartTimer() {
			QueryPerformanceFrequency(&PCFreq);
			QueryPerformanceCounter(&StartTime);
		}

		double GetElapsedMicroseconds() {
			LARGE_INTEGER EndTime;
			QueryPerformanceCounter(&EndTime);

			LARGE_INTEGER elapsedTime;
			elapsedTime.QuadPart = EndTime.QuadPart - StartTime.QuadPart; // elapsed number of ticks

			elapsedTime.QuadPart *= 1000000; // convert ticks to microseconds
			elapsedTime.QuadPart /= PCFreq.QuadPart; // ticks per second

			return (double) elapsedTime.QuadPart;
		}

		double GetElapsedMilliseconds() {
			LARGE_INTEGER EndTime;
			QueryPerformanceCounter(&EndTime);

			LARGE_INTEGER elapsedTime;
			elapsedTime.QuadPart = EndTime.QuadPart - StartTime.QuadPart; // elapsed number of ticks

			elapsedTime.QuadPart *= 1000; // convert ticks to microseconds
			elapsedTime.QuadPart /= PCFreq.QuadPart; // ticks per second

			return (double) elapsedTime.QuadPart;
		}
	};
};