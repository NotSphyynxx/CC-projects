#include <iostream>
#include <fstream>

int main(int ac, char **av){

    if (ac != 4){
        std::cout << "Arguments invalid !\n";
        return 1;
    }
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    std::ifstream f(filename.c_str());
    if (!f.is_open())
        return (1);
    filename += ".replace";
    std::ofstream o(filename.c_str());
    if (!o.is_open())
        return (1);
    
    std::string line;
    while (std::getline(f, line)) {
        std::string result;
        size_t i = 0;
        while (i < line.size()) {
            if (line.compare(i, s1.size(), s1) == 0) {
                result += s2;
                i += s1.size();
            }
            else{
                result += line[i];
                i++;
            }
        }
        o << result;
        if (f.eof()){
            std::cout << "EOF reached\n";
            break ;
        }
        else
            o << std::endl;
    }

    o.close();
    f.close();
}