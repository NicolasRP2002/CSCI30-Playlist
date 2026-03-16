
#ifndef AUDIOSTREAM_H
#define AUDIOSTREAM_H
#include <iostream>

using namespace std;

class AudioStream{
protected:
    string title;
    string artist;
    int duration;
public:
    AudioStream(string t, string a, int d){
        title = t;
        artist = a;
        duration = d;
    }

    virtual ~AudioStream(){
        //cout << "Destroying Song: " << endl;
    }

    void print(){
        cout << "The stream \"" << title << "\" is " << duration << " seconds, performed by " << artist << endl; 
    }

    //clase abstracta sirve para que cada archivo song o podcast pueda tener su propio play()
    virtual void play() const = 0;
};

#endif