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

        void mark_board(int value){
            for (int i = 0; i < int(board.size()); i++){
                for (int j = 0; j < int(board.at(i).size()); j++){
                    if (board.at(i).at(j).entry == value){
                        board.at(i).at(j).marked = true;
                    }
                }
            }
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

                if (copy.length() < 3){
                    break;
                }

                copy = copy.substr(3, copy.length());
            }

            board.push_back(board_line);
        }
};

std::vector<int> get_vector_of_marks(std::string marks){
        std::vector<int> vector_of_marks;

        int current_index = 0;
        int end_index = 0;

        std::string copy = marks;

        while (current_index < marks.length()){
            std::string temp = "";
            int comma = copy.find(',');

        }

        return vector_of_marks;
}

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

std::vector<BingoBoard> generate_bingo_boards(
        const std::vector<std::string> *file_data){
    std::vector<BingoBoard> boards;

    BingoBoard *temp_board = new BingoBoard();
    for (int i = 2; i < int(file_data->size()); i++){
        if (file_data->at(i).compare("") == 0){
            boards.push_back(*temp_board);
            temp_board = nullptr;
            temp_board = new BingoBoard();
            continue;
        }

        temp_board->add_new_line(file_data->at(i));
    }

    return boards;
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
    std::vector<BingoBoard> boards = generate_bingo_boards(&file_data);

    /*
     * PART TWO
     */
    //part two goes here
    return 0;
}
