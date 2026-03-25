#ifndef PLAYLIST_H 
#define PLAYLIST_H
#include <iostream>
#include "AudioStream.h"
#include "Song.h"
#include "Podcast.h"
using namespace std;

class Playlist{
    private:
    AudioStream* m_list[100];
    int m_count;
    
    public:


    //constructor
    Playlist() {
        m_count = 0; 
    }

    void addSong(string title, string artist, int duration, string album){
        cout << "Adding Song: " << title << "..." << endl;
        try {
            addStream(new Song(title, artist, duration, album));
        } catch (runtime_error & e) {
            cout << "  [Playlist]: Failed to add " << title << " -> " << e.what() << endl;
        }
    }

    void addPodcast(string title, string host, int duration, int episode, string guest){
        cout << "Adding Podcast: " << title << "..." << endl;
        try {
            addStream(new Podcast(title, host, duration, episode, guest));
        } catch(runtime_error& e) {
            cout << "  [Playlist]: Failed to add " << title << " -> " << e.what() << endl;
        }
    }

    void addStream(AudioStream* s){   
        if (m_count < 100){
            m_list[m_count++] = s;
        }  
    }

    void playAll(){
        cout << endl <<  "--- Playing Your Playlist ---" << endl;
        for(int i = 0; i < m_count; i++){
            m_list[i]->play();
        }
    }

    void showPlaylist(){
        cout << endl << "--- Listing Your Playlist ---" << endl;
        for(int i = 0; i < m_count; i++){
            cout  << i << ":";
            m_list[i]->print();
        }
    }

    void swapSongs(int idx1, int idx2){
        if (idx1 >= 0 && idx1 < m_count && idx2 >= 0 && idx2 < m_count){
            AudioStream* temp = m_list[idx1];
            m_list[idx1] = m_list[idx2];
            m_list[idx2] = temp;
        }
    }
    
    ~Playlist(){
        for (int i = 0; i < m_count; i++){
            delete m_list[i];
        }
    }

};
#endif