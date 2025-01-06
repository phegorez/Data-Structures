#include <iostream>
#include <string>

using namespace std;

// 1 สร้าง class ของ เพลง โดยข้อมูลจะประกอบไปด้วยชื่อเพลง (string) ตำแหน่งเพลงก่อนหน้าและถัดไป เป็น address
// 2 สร้าง class ของ playlist โดยจะประกอบไปด้วย ชื่อ playlist (string) และ ตำแหน่งเพลงแรกและสุดท้าย เป็น address

class Song
{
public:
    string title;
    Song *next_song;
    Song *prev_song;

    // constructor
    Song(string title)
    {
        this->title = title;
        this->next_song = nullptr;
        this->prev_song = nullptr;
    }
};

class Playlist
{
private:
    string name;
    Song *first_song;
    Song *last_song;

public:
    // constructor
    Playlist(string name)
    {
        this->name = name;
        this->first_song = nullptr;
        this->last_song = nullptr;
    };

    // method
    void add_song(Song *newSong)
    {
        // ถ้ามีไม่มีเพลงแรกใน Playlist ให้เพลงที่เพิ่มเข้ามาเป็นเพลงแรก
        if (this->first_song == nullptr)
        {
            this->first_song = newSong;
            this->last_song = newSong;
        }
        else
        {
            // ถ้ามีเพลงแรกแล้วให้เพลงใหม่เป๋นเพลงถัดไปของเพลงสุดท้าย
            this->last_song->next_song = newSong;
            newSong->prev_song = this->last_song;
            this->last_song = newSong;
        }
    }

    void deleteSong(string title)
    {
        Song *temp = first_song;
        while (temp != nullptr)
        {
            if (temp->title == title)
            {
                if (temp->prev_song)
                {
                    temp->prev_song->next_song = temp->next_song;
                    if (temp->next_song) // ตรวจสอบก่อนเข้าถึง title
                        cout << "find new next song pointer " << temp->next_song->title << endl;
                }
                else
                {
                    first_song = temp->next_song;
                    cout << "find new first song pointer" << endl;
                }

                if (temp->next_song)
                {
                    temp->next_song->prev_song = temp->prev_song;
                    if (temp->prev_song) // ตรวจสอบก่อนเข้าถึง title
                        cout << "find new prev song pointer  " << temp->prev_song->title << endl;
                }
                else
                {
                    last_song = temp->prev_song;
                    cout << "find new last song pointer" << endl;
                }
                delete temp;
                return; // ใช้ return แทน break เพื่อจบการทำงานทันที
            }
            cout << "Continue to next song" << endl;
            temp = temp->next_song;
        }
        cout << "Song not found!" << endl;
    }

    void displayPlaylist()
    {
        Song *currentSong = this->first_song;
        while (currentSong != nullptr)
        {
            cout << currentSong->title << endl;
            currentSong = currentSong->next_song;
        }
    }
};

int main()
{
    Playlist p("My Playlist");
    p.add_song(new Song("Song 1"));
    p.add_song(new Song("Song 2"));
    p.add_song(new Song("Song 3"));
    p.displayPlaylist();
    p.deleteSong("Song 2");
    p.displayPlaylist();
    return 0;
}