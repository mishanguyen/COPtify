# COPtify
This is a programming project for my class COP4530 Data Structures. 

This program implements a basic version of a Spotify-like music streaming service. It allows a user to create an account with a name and email. You can create The playlist has a list of songs, represented by the Song class, which includes information such as the song name, artist, album name, and duration. The Playlist class supplies methods to manage the playlist, such as add a song, play, play next or previous, and so on, while the User class allows to create a user and holds name and email of the user. The program allows the user to interact with the system and manage the playlist of songs, simulating the basic functionality of a music streaming service.

The linked list is composed of Node objects, which are defined in the “classNode.hpp” file and are connected to each other using prev and next pointers. The data element of the Node is an object of type E*, since the class is templated, and called songInfo (note below). 
Class Playlist, which is defined in the file named “classPlaylist.hpp”, implements a templated doubly linked list.
Note: although the class is templated, it is assumed that only type Song will be utilized.
A.	Member functions:
•	bool empty() const | (line 36)
Returns true if the playlist is empty, i.e., the next pointer of the header points to the trailer.
•	void updateSongInfo() | (line 49)
Helps in updating the song information
•	Node<E>* play() | (line 111)
Plays a song from the playlist
•	Node<E>* prev() | (line 139)
Plays the previous song in the playlist
•	Node<E>* next() | (line 155)
Plays the next song in the playlist
•	void remove() | (line 171)
Removes a particular song from the playlist
•	void showPlaylist() | (line 196)
Displays the playlist with the user’s information
•	void clear() | (line 212)
Deallocates memory for nodes
•	void add() | (line 225)
Add songs to the playlist
B.	Constructors and destructor
•	Playlist<E>() 
The constructor initializes the header and trailer pointers to Node objects and sets the next pointer of the header to the trailer, and the previous pointer of the trailer to the header.
•	~Playlist<E>()
The destructor clears all the nodes in the playlist and deletes the header and trailer nodes.
