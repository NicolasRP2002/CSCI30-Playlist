#ifndef SONG_H
#define SONG_H
#include <iostream>
using namespace std;
#include "AudioStream.h"

class Song : public AudioStream{
   private:
   string albumName;
   public:

    //Constructor : AudioStream(t, a, d), albumName(aN);
   Song(string t, string a, int d, string aN): AudioStream(t, a, d), albumName(aN){};

    //function override play
   void play() override{
    cout << "Now playing Song: " << title << " by " << artist << " [Album: " << albumName << "]" << endl;
    buffer.play();
   }

   void print() override {
    cout << "The stream \"" << title << "\" is " << duration << " seconds, performed by " << artist << "." << endl;
   }

};
#endif