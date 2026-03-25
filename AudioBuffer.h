#ifndef AUDIOBUFFER_H
#define AUDIOBUFFER_H
#include <string>
#include "supportFunctions.h"

using namespace std;

class AudioBuffer{
    private:
    void* data;

    public:
    AudioBuffer(int duration, string title) : data(nullptr){
        data = loadAudioResource(duration, title);
    }

    ~AudioBuffer() {
        if (data) {
            freeAudioResource(data);
            data = nullptr;
        }
    }

    AudioBuffer(const AudioBuffer&) = delete;
    AudioBuffer& operator=(const AudioBuffer&) = delete;

    AudioBuffer(AudioBuffer&& other) noexcept : data(other.data) {
        other.data = nullptr;
    }
    AudioBuffer& operator=(AudioBuffer&& other) noexcept {
        if (this != &other) {
            if (data) freeAudioResource(data);
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }

    void play() const { playAudioResource(data);}
};
#endif