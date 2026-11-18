#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

Data*   init_data(int volume, bool playing, std::string artist, std::string song) {
    Data* ptr = new Data;
    ptr->volume = volume;
    ptr->playing = playing;
    ptr->artist = artist;
    ptr->song = song;
    return (ptr);
}
int main(void) {
    Data* track = init_data(36, 1, "Oklou", "choke enough");
    uintptr_t s_track = Serializer::serialize(track);
    std::cout << "uintptr_t: " << s_track << std::endl;
    Data* d_track = Serializer::deserialize(s_track);
    std::cout << "Original track address: " << track << std::endl;
    std::cout << "Recovered track address: " << d_track << std::endl;
    std::cout << "Vol: " << d_track->volume << "\nArtist: " << d_track->artist
            << "\nSong: " << d_track->song << std::endl;
    std::cout << "Null pointer serialized: " << Serializer::serialize(NULL) << std::endl;
    std::cout << "Null pointer deserialized: " << Serializer::deserialize(Serializer::serialize(NULL)) << std::endl;
    delete(track);
    return (0);
}