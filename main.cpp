#include <iostream>
#include <fstream>
#include <sstream>
#include <optional>
#include <vector>

enum class TokenType{
    _return,
    int_lit,
    semi
};

struct Token{
    TokenType type;
    std::optional<std::string> value {};
};

std::vector<Token> tokenize(const std::string& str){
    std::vector<Token> tokens;

    std::string buf;
    for(int i = 0; i < str.length(); i++){
        char c = str.at(i);
        if(std::isalpha(c)){
            buf.push_back(c);
            i++;
            while (std::isalnum(str.at(i))){
                buf.push_back(str.at(i));
                i++;
            }
            i--;

            if(buf == "return"){
                tokens.push_back({.type = TokenType::_return});
                buf.clear();
            }else{
                std::cerr << "Not return" << std::endl;
                exit(EXIT_FAILURE);
            }
        }else if(std::isdigit(c)){
            buf.push_back(c);
            i++;
            while(std::isdigit(str.at(i))){
                buf.push_back(str.at(i));
                i++;
            }
            i--;
            tokens.push_back({.type = TokenType::int_lit, .value = buf});
            buf.clear();
        }else if(c == ';'){
            tokens.push_back({.type = TokenType::semi});
        }else if(std::isspace(c)) {
            continue;
        }
        else{
            std::cerr << "YOU MESSED UP" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    return tokens;
}

std::string tokens_to_asm(std::vector<Token>& tokens){
    std::string output;
    for (int i = 0; i < tokens.capacity(); i++) {
        const Token& token = tokens.at(i);
        if(token.type == TokenType::_return){

        }
    }
}

int main(int argc, char* argv[]) {
    if(argc != 2) {
        std::cerr  << "Incorrect Usage. Correct Usage..." << std::endl;
        std::cerr  << "MikoCompiler <file.mk> "  << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "Compiling " << argv[1] << std::endl;

    std::string contents;

    {
        std::stringstream contents_stream;
        std::fstream input(argv[1], std::ios::in);
        contents_stream << input.rdbuf();
        contents = contents_stream.str();
        input.close();
    }

    std::vector<Token> t = tokenize(contents);

    return EXIT_SUCCESS;
}
