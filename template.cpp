#include <string>
#include <iostream>
#include <fstream>
#include <vector>

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

    /*
     * PART TWO
     */
    //part two goes here
    return 0;
}
