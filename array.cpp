#include<iostream>


void append_helper(int* arr, int elm, int pos){

    arr[pos++] = elm;

}

int append(int* arr, int pos, int size){

    for(int i = pos; i < pos + size; i++){

        int elm;
        std::cout << "Element No. " << i;
        std::cin >> elm;
        append_helper(arr, elm, i);
        
    }

    return pos + size;

}

void display(int* arr, int size){

    for(int i = 0; i < size; i++){
        std::cout << "Element no. " << i << " : " << arr[i] << std::endl;
    }

}

int* resize_helper(int* old_arr, int size){
    int* new_arr = new int[size];
    
    for(int i = 0; i < sizeof(old_arr)/sizeof(old_arr[0]) + 1; i++){
        new_arr[i] = old_arr[i];
    }

    delete old_arr;
    return new_arr;
}

int* resize(int* arr, int size){
    
    return resize_helper(arr, size);

}

int input_size(char* prompt){

    int size;
    int i = 0;

    while(prompt[i] != '\0'){
        std::cout << prompt[i++];
    }

    std::cin >> size;
    return size;

}

int main(){

    char choice;

    int* arr = nullptr;
    int size = 0;
    int current_pos = 0; 

    char* prompt1 = "How many? : ";

    size = input_size(prompt1);
    arr = new int[size];

    current_pos = append(arr, current_pos, size);
    std::cout << " IT IS FULL NIGGA WANT MORE? Y/N" << std::endl;
    char option;

    std::cin >> option;
    
    while(option == 'y' || option == 'Y'){
        size = input_size(prompt1);
        arr = resize(arr, size + current_pos);

        current_pos = append(arr, current_pos, size);
        std::cout << current_pos;
        std::cout << " IT IS FULL NIGGA WANT MORE? Y/N" << std::endl;
        
        std::cin >> option;
    }

    display(arr, current_pos);
}