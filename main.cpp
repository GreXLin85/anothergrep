#include <iostream>
#include <fstream>
#include <codecvt>

int main(int argc, char** argv) {
    if (argc < 3) {
        std::cout << "Usage: anothergrep <filename> <string to search>" << std::endl;
        return 0;
    }

    std::string data;
    std::string fileName = argv[1];
    std::string dataToSearch;

    for (int i = 2; i < argc; ++i) {
        dataToSearch.append((std::string)argv[i] + " ");
    }
    dataToSearch.pop_back();

    std::ifstream FileForSearch(fileName);

    if (FileForSearch.fail()){
        std::cout << fileName << " failed while opening" << std::endl;
        return 1;
    }

    size_t line = 0;

    std::ios::sync_with_stdio(false);
    while (getline(FileForSearch, data)) {
        int column = data.find(dataToSearch);
        if (column > -1){
            std::cout << line << ":" << column << " - " << data << "\n";
        }
        line++;
    }
    FileForSearch.close();
    return 0;
}