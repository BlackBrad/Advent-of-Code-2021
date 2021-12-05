#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

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

void find_gamma_and_epsilon(const std::vector<std::string> *file_data, int *gamma, int *epsilon){
    std::string str_gamma = "";
    std::string str_epsilon = "";
    for (int i = 0; i < int(file_data->at(0).length()); i++){
        int number_of_highs = 0;
        for (int j = 0; j < int(file_data->size()); j++){
            if (file_data->at(j)[i] == '1'){
                number_of_highs++;
           }
        }
        if (number_of_highs > int(file_data->size() / 2)){
            str_gamma += "1";
            str_epsilon += "0";
        } else {
            str_gamma += "0";
            str_epsilon += "1";
        }
    }

    *gamma = stoi(str_gamma, nullptr, 2);
    *epsilon = stoi(str_epsilon, nullptr, 2);
}

void find_oxygen_or_co2(const std::vector<std::string> *file_data, int *oxygen, bool is_oxygen){
    std::vector<std::string> file_data_copy;
    for (int i = 0; i < int(file_data->size()); i++){
        file_data_copy.push_back(file_data->at(i));
    }

    for (int i = 0; i < int(file_data->at(0).length()); i++){
        int number_of_highs = 0;
        int number_of_lows = 0;
        for (int j = 0; j < int(file_data_copy.size()); j++){
            if (file_data_copy.at(j)[i] == '1'){
                number_of_highs++;
            } else {
                number_of_lows++;
            }
        }

        char match = ' ';
        if (!is_oxygen){
            match = '1';
            if (number_of_lows <= number_of_highs){
                match = '0';
            }
        } else {
            match = '0';
            if (number_of_highs >= number_of_lows){
                match = '1';
            }
        }

        std::vector<int> elements_to_remove;
        for (int k = 0; k < int(file_data_copy.size()); k++){
            if (file_data_copy.at(k)[i] == match){
                elements_to_remove.push_back(k);
            }
        }

        for (int l = 0; l < int(elements_to_remove.size()); l++){
            file_data_copy.erase(file_data_copy.begin()+elements_to_remove.at(l)-l);
        }

        if (file_data_copy.size() == 1){
            break;
        }
    }

    *oxygen = stoi(file_data_copy.at(0), nullptr, 2);
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
    int gamma = 0;
    int epsilon = 0;
    int power_consumption = 0;
    find_gamma_and_epsilon(&file_data, &gamma, &epsilon);

    power_consumption = gamma * epsilon;
    std::cout<<"part1: "<<power_consumption<<std::endl;
    /*
     * PART TWO
     */
    //part two goes here
    int oxygen = 0;
    int co2 = 0;
    int life_support = 0;
    find_oxygen_or_co2(&file_data, &oxygen, true);
    find_oxygen_or_co2(&file_data, &co2, false);

    life_support = oxygen * co2;
    std::cout<<"part2: "<<life_support<<std::endl;

    return 0;
}
