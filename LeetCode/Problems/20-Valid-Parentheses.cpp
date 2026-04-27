#include <iostream>
#include <vector>

bool invalidCombo(char firstChar, char secondChar) {
    if (firstChar == '(' && secondChar != ')') {
        return true;
    }

    if (firstChar== '[' && secondChar != ']') {
        return true;
    }

    if(firstChar == '{' && secondChar != '}') {
        return true;
    }

    return false;
}

bool isValid(std::string s) {

    std::vector<char> st;
    st.reserve(s.size());

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push_back(s[i]);
        } else {

            if (st.size() == 0) {
                return false;
            }

            if (invalidCombo(st.back(), s[i])) {
                return false;
            }

            st.pop_back();
        }
    }

    if (st.size() > 0) {
        return false;
    }

    return true;
}
