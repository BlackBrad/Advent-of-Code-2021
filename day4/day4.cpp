#include <string>
#include <iostream>
#include <fstream>
#include <vector>

typedef struct BingoBoardEntry{
    int entry;
    bool marked;
} BingoBoardEntry_t;

class BingoBoard{
    private:
        std::vector<std::vector<BingoBoardEntry_t>> board;
    public:
        BingoBoard(){

        }

        ~BingoBoard(){

        }

        BingoBoardEntry_t get_board_entry(int x, int y){
            return board[x][y];
        }

        void add_new_line(std::string line){
            std::vector<BingoBoardEntry_t> board_line;
            std::string copy = line;

            while (true){
                std::string temp = copy.substr(0, 2);
                int entry = 0;
                entry = stoi(temp, nullptr, 10);
                BingoBoardEntry_t temp_entry = {entry, false};

                board_line.push_back(temp_entry);

                copy = copy.substr(2, temp.length());
                std::cout<<"temp: "<<temp<<std::endl;
                std::cout<<"copy"<<copy<<std::endl;

                if (copy.length() == 0){
                    break;
                }
            }

            board.push_back(board_line);
        }
};

bool load_file(std::string file_path, std::vector<std::string> *file_data){
    std::string temp_line;
    std::ifstream input_file;
    input_file.exceptions (std::ifstream::badbit ); // No need to check failbit

    try{
        input_file.open(file_path);
        if (!input_file.is_open()){
            std::cout<<"Could not open file: "<<file_path<<std::endl;
            return false;
        }
        while(std::getline(input_file, temp_line)){
            file_data->push_back(temp_line);
        }
    }catch (const std::ifstream::failure& e){
        std::cout<<"Error reading file: "<<file_path<<"!"<<std::endl;
        return false;
    }

    return true;
}

int main(int argc, char *argv[]){
    /*
     * TEMPLATE
     */
    if (argc < 2){
        std::cout<<"Usage: ./puzzle FILE_PATH"<<std::endl;
        return 1;
    }

    std::string file_path = argv[1];

    std::vector<std::string> file_data;

    if (!load_file(file_path, &file_data)){
        return 1;
    }

    /*
     * PART ONE
     */
    //part one goes here
    
    for (int i = 0; i < int(file_data.size()); i++){
        BingoBoard *board = new BingoBoard();
        board->add_new_line(file_data.at(i));
    }

    /*
     * PART TWO
     */
    //part two goes here
    return 0;
}
