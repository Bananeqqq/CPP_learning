#include<iostream>
#include<string>

std::string shiftFunc(std::string word, int key);
std::string deshiftFunc(std::string word, int key);

std::string Shift(std::string word, int key);
std::string deShift(std::string word, int key);

std::string ShiftWithWord(std::string word, std::string key);
std::string deShiftWithWord(std::string word, std::string key);

int main(){
    std::string userInputWord;
    int shiftingNumKey;
    std::string shiftingWordKey;
    int choice;
    bool correct_choice = true;

    std::cout << "\n\nInsert a word(s) u wanna shift: ";
    std::getline(std::cin, userInputWord);
    

    do {
        std::cout << "\nChoose shifting method: \n1 - number key\n2 - word key\nYour choice: ";
        std::cin >> choice;

        if (choice != 1 && choice != 2){
            std::cout << "\nWrong choice!!" << std::endl;
            correct_choice = false;
        }
    }while (!correct_choice);

    if (choice == 1){
        std::cout << "Insert a number key: ";
        std::cin >> shiftingNumKey;

        std::cout << "\nShifting word: " << userInputWord << "\nShifting key: " << shiftingNumKey << std::endl;
        std::string word__ = Shift(userInputWord, shiftingNumKey);
        std::cout << "\nShifted word: " << word__ << std::endl;
        std::cout << "Deshifted word: " << deShift(word__, shiftingNumKey) << std::endl;
    }else if (choice == 2){
        std::cout << "Insert a word key: ";
        std::cin >> shiftingWordKey;

        std::cout << "\nShifting word: " << userInputWord << "\nShifting keyword: " << shiftingWordKey << std::endl;
        std::string word__ = ShiftWithWord(userInputWord, shiftingWordKey);
        std::cout << "\nShifted word: " << word__ << std::endl;
        std::cout << "Deshifted word: " << deShiftWithWord(word__, shiftingWordKey) << std::endl;
    }

    return 0;
}


std::string Shift(std::string word, int key){
    std::string result;
    for (char c : word){
        if (c != 32){
            if (c > 64 && c < 91){ //upper case
                int value = c - 'A' + key;
                value = value % 26;
                c = 'A' + value;
            }else {
                int value = c - 'a' + key;
                value = value % 26;
                c = 'a' + value;
            }
        }
        result += c;
    }
    return result;
}

std::string deShift(std::string word, int key){
    std::string result;

    for (char c : word){
        if (c!=32){
            key = key % 26;
            if (c > 64 && c < 91){ //upper case
            int value = c - 'A' - key;
                if (value < 0) {
                    c = 'Z' + value + 1;
                }else{
                    c = 'A' + value;
                }
            }else{
                int value = c - 'a' - key;
                if (value < 0) {
                    c = 'z' + value + 1;
                }else{
                    c = 'a' + value;
                }
            }
        }
        result += c;
    }
    return result;
}

std::string ShiftWithWord(std::string word, std::string key){
    std::string result;
    for (int i = 0; i < word.length(); i++){
        if (word[i] != 32){
            std::string defaultKey = key;

            while (key.length() < word.length()){
                key += defaultKey;
            }

            int key_;
            
            if (key[i] > 64 && key[i] < 91){
                key_ = key[i] - 'A';
            }else{
                key_ = key[i] - 'a';
            }
            key_ = key_ % 26;

            if (word[i] > 64 && word[i] < 91){ //upper case
                int value = word[i] - 'A' + key_;
                value = value % 26;
                word[i] = 'A' + value;
            }else {
                int value = word[i] - 'a' + key_;
                value = value % 26;
                word[i] = 'a' + value;
            }
        }
        result += word[i];
    }
    return result;
}

std::string deShiftWithWord(std::string word, std::string key){
    std::string result;
    for (int i = 0; i < word.length(); i++){
        if (word[i] != 32){
            std::string defaultKey = key;

            while (key.length() < word.length()){
                key += defaultKey;
            }

            int key_;
            
            if (key[i] > 64 && key[i] < 91){
                key_ = key[i] - 'A';
            }else{
                key_ = key[i] - 'a';
            }
            key_ = key_ % 26;

            if (word[i] > 64 && word[i] < 91){ //upper case

                int value = word[i] - 'A' - key_;
                if (value < 0) {
                    word[i] = 'Z' + value + 1;
                }else{
                    word[i] = 'A' + value;
                }
            }else {

                int value = word[i] - 'a' - key_;
                if (value < 0) {
                    word[i] = 'z' + value + 1;
                }else{
                    word[i] = 'a' + value;
                }
            }
        }
        result += word[i];
    }
    return result;
}



//First try, not as good as func above, but still should be working
std::string shiftFunc(std::string word, int key){
    std::string shiftedOutputWord = word;

    for (int i = 0; i < shiftedOutputWord.length(); i++){
        key = key % 26;
        int temp = shiftedOutputWord[i] - 'a' + key;
        if (temp > 25){
            int x = 'z' - shiftedOutputWord[i];
            temp = 'a' - x + key - 1;
            shiftedOutputWord[i] = temp;
        }else{
        shiftedOutputWord[i] += key;
        }
        
    }
    return shiftedOutputWord;
}

std::string deshiftFunc(std::string word, int key){
    std::string deshiftedOutputWord;

    for (char c: word){ //=(int i = 0; i < shiftedOutputWord.length(); i++)
        key = key % 26;
        int temp = c - 'a' - key;
        if (temp < 0){
            int x = temp;
            temp = 'z' + x + 1;
            c = temp;
        }else{
            c -= key;
        }
        deshiftedOutputWord += c;
    }

    return deshiftedOutputWord;
}