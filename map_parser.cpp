#include <fstream>
#include <iostream>
void writeToCache(std::string line);
std::fstream file("cached_map.txt");

void parseFolder(){

}
void parseFile(std::string filename){
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
            writeToCache(line);
        }
    file.close();
}}

void writeToCache(std::string line){
    file << line << std::endl;
}