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
    std::cout << track << std::endl;
    uintptr_t s_track = Serializer::serialize(track);
    track = Serializer::deserialize(s_track);
    std::cout << track << std::endl;
    delete(track);
    return (0);
}