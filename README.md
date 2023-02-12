# COPtify
This is a programming project for my class COP4530 Data Structures. 

This program implements a basic version of a Spotify-like music streaming service. It allows a user to create an account with a name and email. You can create The playlist has a list of songs, represented by the Song class, which includes information such as the song name, artist, album name, and duration. The Playlist class supplies methods to manage the playlist, such as add a song, play, play next or previous, and so on, while the User class allows to create a user and holds name and email of the user. The program allows the user to interact with the system and manage the playlist of songs, simulating the basic functionality of a music streaming service.

The linked list is composed of Node objects, which are defined in the “classNode.hpp” file and are connected to each other using prev and next pointers. The data element of the Node is an object of type E*, since the class is templated, and called songInfo (note below). 
Class Playlist, which is defined in the file named “classPlaylist.hpp”, implements a templated doubly linked list.
Note: although the class is templated, it is assumed that only type Song will be utilized.
