#include <string>
#include <iostream>
#include <fstream>
#include <vector>

typedef struct Position{
    int x;
    int y;
} position_t;

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

void parse_commands_update_pos(std::vector<std::string> *file_data, position_t *pos){
    for (int i = 0; i < int(file_data->size()); i++){
        std::string line = file_data->at(i);
        int space_pos = line.find(' ');
        std::string command = line.substr(0, space_pos);
        int move_value = std::stoi(line.substr(space_pos + 1, line.length()));

        if (command.compare("up") == 0){
            // Y is actually a measure of depth, therefore up would decrease
            // the depth and down would make it increase
            pos->y -= move_value;
        } else if (command.compare("down") == 0){
            pos->y += move_value;
        } else if (command.compare("forward") == 0){
            pos->x += move_value;
        }
    }
}

int main(int argc, char *argv[]){
    if (argc < 2){
        std::cout<<"Usage: ./puzzle FILE_PATH"<<std::endl;
        return 0;
    }

    std::string file_path = argv[1];
    std::vector<std::string> file_data;

    load_file(file_path, &file_data);

    // Initialize submarines position
    position_t pos = {0, 0};
    parse_commands_update_pos(&file_data, &pos);

    int multiplied = pos.x * pos.y;
    std::cout<<"part1: "<<multiplied<<std::endl;

    return 1;
}
