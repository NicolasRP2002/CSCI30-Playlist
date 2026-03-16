#ifndef PODCAST_H 
#define PODCAST_H

#include "AudioStream.h"
#include <iostream>
#include <string>
using namespace std;

class Podcast : public AudioStream {
    private:
    int episodeNumber;
    string guest;
    public:

    Podcast(string t, string a, int d, int eN, string g)
        : AudioStream(t, a, d), episodeNumber(eN), guest(g) {}

    //override permite que se printee algo diferende dependiendo de si es song o podcast
    void play() const override {
        cout << "Now playing Podcast: " << title << " Episode #" << episodeNumber << ", featuring " << guest << "." << endl;
    }

};
#endif