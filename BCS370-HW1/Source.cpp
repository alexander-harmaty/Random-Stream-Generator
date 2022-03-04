#include <iostream>
#include <random>
#include <fstream>
using namespace std;

void randomStream(std::string filename, int iterations)
{
    //set randoms for letters
    std::random_device rd1;
    std::mt19937 gen1(rd1());
    std::uniform_int_distribution<> dis1(0, 5);

    //set randoms for numbers that follow 'A'
    std::random_device rd2;
    std::mt19937 gen2(rd2());
    std::uniform_int_distribution<> dis2(INT_MIN, INT_MAX);

    //declare variables
    int temp;
    string letters[6] = {"A","D","P","E","C","S"}; //string to hold letters, use rand for i to get rand letter
    ofstream outputFile(filename); //open file

    for (int i = 0; i < iterations; ++i)
    {
        temp = dis1(gen1); //temp int to hold rand num
        if (temp == 0) //if rand num produces 'A', use rand gen2 to add more rand nums
        {
            outputFile << letters[temp] << " " << dis2(gen2);//output to file
            std::cout << letters[temp] << " " << dis2(gen2);//output to console
        }
        else //if rand != A, the just add the letter
        {
            outputFile << letters[temp];
            std::cout << letters[temp];
        }
        if (i != iterations - 1) //num of lines must be EXACTLY same as iterations...if not last line, add new line
        {
            outputFile << "\n";
            std::cout << "\n";
        }
    }
    outputFile.close(); //close file
}

int main() {
    //ask for filename
    std::cout << "Please input a filename. (remember to add an extension, ie 'txt')...";
    string filename;
    std::cin >> filename;

    //ask for iterations
    std::cout << "Please input the iterations...";
    int iterations;
    std::cin >> iterations;

    //call method
    randomStream(filename, iterations);
}