/* This is the header file for the Playlist class. */
#ifndef CLASSPLAYLIST_HPP
#define CLASSPLAYLIST_HPP
#include <iostream>
#include <string>
#include "classNode.hpp"
#include "classUser.hpp"

using namespace std;

template <typename E> class User;
template <typename E>
class Playlist {
    private:
        Node<E>* header;
        Node<E>* trailer;
        Node<E>* current; // holds the current node
    public:
        // Constructor for Playlist
        Playlist<E>() {
            header = new Node<E>();
            trailer = new Node<E>();
            header->next = trailer;
            trailer->prev = header;
            current = header->next; // initially points to the node after the header (i.e. trailer)
        }
        // Destructor
        ~Playlist<E>() {
            while (!empty()) {
                clear();
            }
            delete header;
            delete trailer;
        }
        // function protoypes
        bool empty() const { return (header->next == trailer); } 
        void clear();
        void add();
        void remove();
        void showPlaylist(const string& user, const string& email);
        void updateSongInfo();
        Node<E>* play();
        Node<E>* prev();
        Node<E>* next();
};

// the function to update song information
template <typename E>
void Playlist<E>::updateSongInfo() {
    // if playlist is empty, then the functions returns before doing anything
    if (empty()) {
        cout << "No songs in the playlist." << endl;
        return;
    }
    
    // getting the name of the song that needs to be updated
    string songName;
    cin.ignore();
    cout << "Enter the title of the song you would like to update: ";
    getline(cin, songName);
    
    // finding the node with the song that has that title
    Node<E>* cur = header->next;
    while (cur != trailer && cur->songInfo->getTitle() != songName) {
        cur = cur->next;
    }
    // if the pointer comes to the trailer node, then the song is not in the playlist
    if (cur == trailer) {
        cout << "No such song was found in the playlist." << endl;
        return;
    }
    cout << endl;

    // Menu for the user to select what info they want to update
    cout << "Please select one of the following:" << endl;
    cout << endl;
    cout << "1. Title" << endl;
    cout << "2. Artist Name" << endl;
    cout << "3. Album Name" << endl;
    cout << endl;
    cout << "Enter your selection: ";
    int choice;
    cin >> choice;
    // depending on what the user chose, we declare a new variable and use a setter to assign the new value
    if (choice == 1) { 
        string newTitle;
        cin.ignore();
        cout << "Enter the new title: ";
        getline(cin, newTitle);
        cur->songInfo->setTitle(newTitle);
    } else if (choice == 2) {
        string newArtist;
        cin.ignore();
        cout << "Enter the new artist name: ";
        getline(cin, newArtist);
        cur->songInfo->setArtist(newArtist);
    } else if (choice == 3) {
        string newAlbum;
        cin.ignore();
        cout << "Enter the new album name: ";
        getline(cin, newAlbum);
        cur->songInfo->setAlbum(newAlbum);
    } else {
        cout << "Invalid choice, try again!" << endl;
    }
    cout << endl;
}

// function to play a song by showing a message to the user, it returns a pointer to the song that was played
template <typename E>
Node<E>* Playlist<E>::play() {
    if (empty()) {
        cout << "There are no songs in the playlist." << endl;
        return current;
    }

    // we find the song by the title thatis entered by the user, case-sensitive
    string songName;
    cin.ignore();
    cout << "Enter the song title: ";
    getline(cin, songName);

    // finding the node with song the title of which matches the one provided by the user
    Node<E>* cur = header->next;
    while (cur != trailer && cur->songInfo->getTitle() != songName) {
        cur = cur->next;
    }
    if (cur == trailer) {
        cout << "No song with title " << songName << " found." << endl;
        return current; // return the initial current pointer
    }
    cout << "Now playing: " << cur->songInfo->getTitle() << " by " << cur->songInfo->getArtist() << endl;
    current = cur; // current is updated once the song is found
    return current; // pointer to the ciurrent node returned
}

// function to play the previous song, it return a pointer to that song
template <typename E>
Node<E>* Playlist<E>::prev() {
  if (empty()) {
    cout << "There are no songs in the playlist." << endl;
    return current;
  }
  if (current->prev == header) {
    cout << "No previous song in the playlist." << endl;
    return current;
  }
  current = current->prev;
  cout << "Now playing: " << current->songInfo->getTitle() << " by " << current->songInfo->getArtist() << endl;
  return current;
}

// function to play the next song of the playlist; returns the pointer to the next song
template <typename E>
Node<E>* Playlist<E>::next() {
    if (empty()) {
        cout << "There are no songs in the playlist." << endl;
        return current;
    }
    if (current->next == trailer) {
        cout << "No next song in the playlist." << endl;
        return current;
    }
    current = current->next;
    cout << "Now playing: " << current->songInfo->getTitle() << " by " << current->songInfo->getArtist() << endl;
    return current;
}

// the function to remove a song from the playlist. title is needed to delete the song 
template <typename E>
void Playlist<E>::remove() {
    cin.ignore();
    if (empty()) {
        cout << "No songs in the playlist." << endl;
        return;
    }
    string songName;
    cout << "Enter your song title: ";
    getline(cin, songName);
    Node<E>* cur = header->next;
    while (cur != trailer && cur->songInfo->getTitle() != songName) {
        cur = cur->next;
    }
    if (cur == trailer) {
        cout << "No song with title " << songName << " found." << endl;
        return;
    }
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    delete cur;
    cout << "Song with title \"" << songName << "\" removed!" << endl;
}

// function to display all songs in the playlist
template <typename E>
void Playlist<E>::showPlaylist(const string& user, const string& email) {
    if (empty()) {
        cout << "No songs in the playlist." << endl;
        return;
    }

    Node<E>* temp = header->next;
    cout << "Playlist for " << user << " (" << email << ")" << endl;
    while (temp != trailer) {
        cout << temp->songInfo->getTitle() << " by " << temp->songInfo->getArtist() << endl;
        temp = temp->next;
    }
}

// function to delete the linked list
template <typename E>
void Playlist<E>::clear() {
    // traverses through each node and reorganizes the pointers and deallocates memory for each node
    Node<E>* cur = header->next;
    while (cur != trailer) {
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        delete cur;
        cur = header->next;
    }
}

// function to add a new song. the user needs to enter the song title, album name, artist name, and duration
template <typename E>
void Playlist<E>::add() {
    
    string songTitle, artistName, albumName;
    int numMin, numSec;
    char ch;
    // inputting info
    cin.ignore();
    cout << "Enter your song title: ";
    getline(cin, songTitle);
    cout << "Enter artist name: ";
    getline(cin, artistName);
    cout << "Enter album name (if none, enter \"N/A\"): ";
    getline(cin, albumName);
    cout << "Enter song length (MM:SS): ";
    // check duration input format
    while (true) {
        cin >> numMin >> ch >> numSec;
        if (numMin >= 0 && numMin <= 60 && ch == ':' && numSec >= 0 && numSec < 60) {
            break;
        }
        cout << "Invalid format. Please re-enter song length (MM:SS): ";
    }
     // creates a new node with intiializing the members
    Node<E>* newNode = new Node<E>(new E(songTitle, artistName, albumName, numMin, numSec), header, trailer);
    Node<E>* cur = header->next;

    // if the playlist is empty
    if (empty()) {
        header->next = newNode;
        current = newNode;
        return;
    }

    // traversing until the end of the list
    while (cur->next != trailer) {
        cur = cur->next;
    }
    // connecting the new node
    cur->next = newNode;
    newNode->prev = cur;
}

#endif
