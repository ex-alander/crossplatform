/*#include <iostream>
#include <fstream>
#include <string>
int main(int argc, char* argv[])
{
    argc = 5;
    std::cin >> argv[1];
    if (argc > 1) {
        std::cin >> argv[1];
        if (std::cin.fail()) {
            std::ofstream out; // opening the file (writing mode)
            out.open("error.txt");
            if (out.is_open())
            {
                out << "No name dude" << std::endl;
            }
            out.close(); // closing the file
        }
        std::cout << "Hello, " << argv[1] << std::endl;
    }
    else
    {
        std::ofstream out; // opening the file (writing mode)
        out.open("error.txt");
        if (out.is_open())
        {
            out << "No name dude" << std::endl;
        }
        out.close(); // closing the file
    }
    return 0;
}
*/
#include <iostream>
#include <fstream>
int main(int argc, char** argv) {
    if (argv[1])
    std::cout << "Hello, " << argv[1];
    else {
        std::ofstream out; // opening the file (writing mode)
        out.open("error.txt");
        if (out.is_open())
        {
            out << "No name dude" << std::endl;
        }
        out.close(); // closing the file
    }
}