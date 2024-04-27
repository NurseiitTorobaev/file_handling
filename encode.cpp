#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void comp(string str, ofstream& outputFile) 
{
    int n = str.size();
    for (int i = 0; i < n; i++) 
    {
        int count = 1;
        while (i < n - 1 && str[i] == str[i + 1]) 
        {
            count++;
            i++;    
        }
        cout << str[i] << count;
        outputFile << str[i] << count;
    }
}
int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    if (!inputFile.is_open()) 
    {
        cerr << "Failed to open the input file." << endl;
        return 1;
    }
    if (!outputFile.is_open()) 
    {
        cerr << "Failed to open the output file." << endl;
        return 1;
    }
    string line;
    int n;
    cout<<"Hello, this is compressing part of Run-Length programm"<<endl;
    cout<<"Your compressed text: ";
    while (getline(inputFile, line))
    {
        comp(line, outputFile);
    }
    inputFile.close();
    outputFile.close();
    return 0;
}