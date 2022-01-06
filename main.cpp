#include <iostream>
#include "vector"
#include <fstream>
#include <boost/algorithm/string/classification.hpp> // Include boost::for is_any_of
#include <boost/algorithm/string/split.hpp> // Include for boost::split

struct Person
{
    std::string name;
    std::vector<std::string> friends;
    Person(std::string name){
        this->name = name;
    }
};
int find_person(std::string name, std::vector<Person> people){
    for (int i = 0;i<people.size();i++) {
        if (people[i].name == name){
            return i;
        }
    }

    return -1;
}
void virtualFriends(std::string filename){

    std::ifstream file(filename);
    std::string line;
    getline(file, line);
    int tests = stoi(line);

    for (int i =0;i<tests;i++){
        std::getline(file, line);
        int n = stoi(line);

        for (int j =0;j<n;j++){
            std::getline(file, line);
            std::vector<std::string> words;
            boost::split(words, line, boost::is_any_of(" "));
            std::vector<Person> people;

            if (find_person(words[0],people) == -1){
                Person p(words[0]);
                p.friends.push_back(words[1]);
            }
            if (find_person(words[1],people) == -1){
                Person p(words[0]);
                p.friends.push_back(words[0]);
            }

        }
    }
    file.close();

}


int main() {
    virtualFriends("../friends.txt");
    return 0;
}
