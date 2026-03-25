
#ifndef AUDIOSTREAM_H
#define AUDIOSTREAM_H
#include <iostream>
#include "AudioBuffer.h"

using namespace std;

class AudioStream{
protected:
    string title;
    string artist;
    int duration;

    AudioBuffer buffer;
public:
    AudioStream(string t, string a, int d) : title(t), artist(a), duration(d), buffer(d,t)
    {}

    virtual void play() = 0;

    virtual void print() = 0;

    virtual ~AudioStream() {}

};

#endif