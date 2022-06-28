#include <iostream>
#include <cctype>
#include <string>
#include <fstream>


char *cLowering(char *cdestination, const char *csource);

std::string sLowering(const std::string &ssource);

int main() {
    int SIZE = 0;
    std::ifstream in;
    in.open(("data.txt"));
    if (!in.is_open()) {
        std::cerr << "File can not be opened\n";
        return 1;
    }
    while (!in.eof()) {
        in >> SIZE;
//        std::cout << SIZE << std::endl;
        char *phrase = new char[SIZE + 1];
        char *cdestination = new char[SIZE + 1];
 //       in.seekg(1, std::ios::cur);
        in.ignore();
        in.getline(phrase, SIZE, '\n');
        std::cout << phrase << std::endl;
        std::string stringPhrase = phrase;
        std::cout << cLowering(cdestination, phrase) << std::endl;
        std::cout << sLowering(stringPhrase) << std::endl;
        delete[] phrase;
        delete[] cdestination;
    }
    in.close();

    return 0;
}

char *cLowering(char *cdestination, const char *csource) {
    int i = 0;
    while (csource[i]) {

        cdestination[i] = std::tolower(csource[i]);
        i += 1;
    }
    return cdestination;
}

std::string sLowering(const std::string &ssource) {
    std::string stringDestination;
    for (char i: ssource) {
        stringDestination.push_back(std::tolower(i));
    }
    return stringDestination;
}
