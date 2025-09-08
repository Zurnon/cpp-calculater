
#include <iostream>
#include <vector>

template<typename __Type>
bool isIn(std::vector<std::string> holder, __Type hider);

namespace tokenizer {
    template<typename __Type>
        class token {
            private:
                std::vector<std::string> types = {"identifier", "number", "operator"};
                std::string type;
                std::string value;
            public:
                friend bool ::isIn<__Type>(const std::vector<std::string>& holder, const __Type& hider);

                token(std::string __type, std::string __value) : type(__type), value(__value) 
                    : type(__type), value(__value) {

                        if (isIn(types, __type)) {
                            return true;
                        } else {
                            return false;
                        }
                }
                
        };
}

namespace lexer {
    class start {
        private:
            bool lexing_complete = false;
            int pos;
            std::string source_code;
        public:
            start(std::string __source_code) {
                source_code = __source_code; }
            
            bool isSymbol(char __char) {
                return __char == '/' || __char == '*' || __char == '+' || __char == '-' || __char == '%' || __char == '='; }

            char peek() {
                if (pos < size(source_code)) {
                    return source_code[pos]; } return '~'; }

            void lex() {
                while (lexing_complete != true) {

                    if (peek() == 0) {
                        std::cout << "sogma" << std::endl;
                    }

                    pos++;
                }
            }
    };
}

template <typename __Type>
bool isIn(std::vector<std::string> holder, __Type hider) {
    for (int i = 0; i < size(holder); i++) {
        if (holder[i] == hider) {
            return true;
        }
    }
    return false;
}

int main() {

    return 0;
}