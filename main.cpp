#include "Playlist.h"
#include "Song.h"
#include "Podcast.h"

int main() {
    Playlist myPlaylist;

    // Direct heap allocation passed to the Playlist
    myPlaylist.addStream(new Song("Starman", "David Bowie", 250, "Ziggy Stardust"));
    myPlaylist.addStream(new Podcast("The Daily", "Michael Barbaro", 1800, 1024, "NYT Staff"));
    myPlaylist.addStream(new Song("Blinding Lights", "The Weekend", 200, "After Hours"));

    myPlaylist.showPlaylist();

    myPlaylist.playAll();

    int index1, index2;
    cout << "\nEnter two indices to swap (e.g., 0 2): " << endl;
    cin >> index1 >> index2;
    //swaps the songs
    myPlaylist.swapSongs(index1, index2);

    cout << "\n--- Playlist After Swap ---\n";
    myPlaylist.showPlaylist();

    

    return 0; // Playlist destructor handles memory cleanup
}