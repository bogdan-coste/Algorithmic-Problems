#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::string simplifyPath1(std::string path) {

    std::vector<std::string> worker;
    std::string res;

    int i = path.size() - 1;

    while (i >= 0) {

        if (i <= 0) {
            break;
        }

        while (i >= 0 && path[i] == '/') {
            i--;
        }

        if (i < 0) {
            break;
        }

        int lead = i;

        while (i >= 1 && path[i - 1] != '/') {
            i--;
        }

        int trail = i;

        int length = lead - trail + 1;
        worker.push_back(path.substr(trail, length));

        i--;
    }

    int idx = 0;
    int skipDir = 0;

    while (idx < (int)worker.size()) {

        if (worker[idx] == ".") {
            worker.erase(worker.begin() + idx);
            continue;
        }

        if (worker[idx] == "..") {
            skipDir++;
            worker.erase(worker.begin() + idx);
            continue;
        }

        if (skipDir > 0) {
            skipDir--;
            worker.erase(worker.begin() + idx);
            continue;
        }

        idx++;
    }

    for (int i = (int)worker.size() - 1; i >= 0; i--) {
        res += "/" + worker[i];
    }

    return res.empty() ? "/" : res;
}

std::string simplifyPath2(std::string path) {

    std::vector<std::string> stack;
    std::stringstream ss(path);
    std::string dir;

    while (std::getline(ss, dir, '/')) {

        if (dir == "" || dir == ".") {
            continue;
        }

        else if (dir == "..") {
            if (!stack.empty()) {
                stack.pop_back();
            }
        }

        else {
            stack.push_back(dir);
        }
    }

    if (stack.empty()) {
        return "/";
    }

    std::string res;

    for (int i = 0; i < stack.size(); i++) {
        res += "/" + stack[i];
    }

    return res;
}

int main() {

    std::cout << simplifyPath2("/home/user/Documents/../Pictures");
}
