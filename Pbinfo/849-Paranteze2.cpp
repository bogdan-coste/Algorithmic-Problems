#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

int main() {
    std::ifstream f("paranteze2.in");

    if (!f) {
        std::cerr << "Cannot open paranteze2.in\n";
        return 1;
    }

    std::ofstream g("paranteze2.out");

    int consec = 0;
    int max = 0;
    std::string line;
    std::getline(f, line);

    for (int i = 0; i < line.size(); i++) {
        if (line[i] == '(') {
            consec++;
        } else {
            if (consec > max) {
                max = consec;
            }

            consec--;
        }
    }

    g << max << std::endl;
    return 0;
}
