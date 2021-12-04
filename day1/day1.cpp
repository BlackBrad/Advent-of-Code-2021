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
        input_file.close();
        return false;
    }

    input_file.close();

    return true;
}

void convert_string_vector_to_array(std::vector<std::string> *string_vector, int *array){
    for (int i = 0; i < int(string_vector->size()); i++){
        array[i] = std::stoi(string_vector->at(i), nullptr, 10);
    }

}

void count_larger_depths(int *array, int *count, int *size){
    int previous_depth = array[0];
    for (int i = 1; i < *size; i++){
        if (array[i] > previous_depth){
            *count += 1;
        }
        previous_depth = array[i];
    }
}

int main(int argc, char *argv[]){
    if (argc < 2){
        std::cout<<"Usage: ./puzzle FILE_PATH"<<std::endl;
        return 0;
    }

    std::string file_path = argv[1];
    std::vector<std::string> file_data;
    int *depths = nullptr;
    int depths_size = 0;
    int larger_depth_count = 0;

    if (!load_file(file_path, &file_data)){
        return 0;
    }

    // Set the depths array to be the same size as the file data
    depths_size = file_data.size();
    depths = new int[depths_size];
    convert_string_vector_to_array(&file_data, depths);

    count_larger_depths(depths, &larger_depth_count, &depths_size);

    std::cout<<larger_depth_count<<std::endl;

    return 1;
}
