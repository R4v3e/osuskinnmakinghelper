#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <Windows.h>

using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;
using namespace std;

void readFiles(string myPath) {
    string tmp = "";
    int _tmp = -1;
    int _tmp2 = -1;
    string tmp2 = "";
    for (const auto& dirEntry : recursive_directory_iterator(myPath)) {        
      
        _tmp = dirEntry.path().string().find('.');
        _tmp2 = dirEntry.path().string().find_last_of('\\');

        if (_tmp2 != -1) {
            tmp2 = dirEntry.path().string().substr(_tmp2 + 1);
            tmp2 = myPath +"/" + tmp2;
           
        }

        if (_tmp != -1) {
            tmp = dirEntry.path().string();
            cout << "copy to: " << tmp2 << std::endl;
            std::replace(tmp.begin(), tmp.end(), '\\', '/');
            cout << "copy from: " << tmp << std::endl;
         
            ifstream source(tmp, ios::binary);
            ofstream dest(tmp2, ios::binary);

            dest << source.rdbuf();

            source.close();
            dest.close();           
        }
    }      
}



int main() {

    string path = "E:\\Projects\\OsuSkinOrganizer\\Osu_Skin_Organizer\\skin";
    int x = -1;
    int y = -1;

    cout << "***********************************************************************" << endl;
    cout << "+                        1. use program                               +" << endl;
    cout << "+                        2. exit                                      +" << endl;
    cout << "***********************************************************************" << endl;
    
    cin >> x;
    if (x != 1) return 0;
    do {
        system("cls");

        cout << "skin folder path: " << endl;
        cin >> path;
        system("cls");
        cout << "is this path correct? " << endl;
        cout << path << endl;
        cout << "1. yes 2. no" << endl;
        cin >> y;
    } while(y != 1);

    std::replace(path.begin(), path.end(), '\\', '/');

    readFiles(path);
       

    return EXIT_SUCCESS;
}