int evalRPN(vector < string > & tokens) {

    auto* stack = new vector<int>(tokens.size() / 2 + 1);

    int sum = 0;
    string token_final;

    for (const auto & token: tokens) {

        if (token == "+" || token == "-" || token == "*" || token == "/") {

            if(stack->size() >= 2){
                int arg1 = stack->back();
                stack->pop_back();

                int arg2 = stack->back();
                stack->pop_back();

                if (token == "+") stack->push_back(arg2 + arg1);
                else if (token == "-") stack->push_back(arg2 - arg1);
                else if (token == "*") stack->push_back(arg2 * arg1);
                else if (token == "/") stack->push_back(arg2 / arg1);
            }

        } else {
            stack->push_back(stoi(token));
        }
    }
    
    int result = stack->back();
    delete stack;
    return result;
}
