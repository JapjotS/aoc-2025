#include <iostream>
#include <fstream>
#include <regex> //to do change this for something that actually works
using namespace std;




int main(){
    const int max = 100;
    int start = 50;
    int zero_times = 0;

    string input_line;
    ifstream input_file("C:\\CODING\\aoc-2025\\question1input.txt");
    smatch matches;


    while (getline (input_file, input_line)){

        if (std::regex_search(input_line,matches ,std::regex("^(\\D)(\\d+).*"))){
            //cout << matches[1]; //direction
            //cout << matches[2]; //value
            char Right = 'R';
            char Left = 'L';
            //cout << matches[2] << endl;
            if (matches[1].str()[0] == 'L'){
                //cout << start << endl;
                start = start - stoi(matches[2]);
                if (start < 0){
                    start = (start - stoi(matches[2]) % 100 + 100) % 100;
                }
            }

            if (matches[1] == 'R'){
                    start = start+stoi(matches[2]);
                    if (start>=100){
                        start = start % 100;
                    }
            }

            if (start == 0){
                zero_times = zero_times + 1;
            }


            //cout << start << endl;
            //to get actual value = sum + 1 mod 100

        }

    }

    input_file.close();
    cout << zero_times;

    return 0;

}
