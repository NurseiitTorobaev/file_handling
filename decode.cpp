#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void decom(string str, ofstream& outputFile) 
{
    int n = str.size();
    for(int i = 0; i < n; i += 2) 
    {
        if((char)str[i+2]>47 && (char)str[i+2]<58)
        {
            for(int j = 0; j < ((str[i + 1] - '0')*10 + str[i+2] - '0') ; j++) 
            { 
                cout << str[i];
                outputFile << str[i];
            }
        i++;
        } 
        else 
        {
            for(int j = 0; j < str[i + 1] - '0'; j++) 
            { 
                cout << str[i];
                outputFile << str[i];
            }
        }
    }
}

int main() 
{
    ifstream inputFile("output.txt");
    ofstream outputFile("decompressed.txt");
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
    cout<<"Hello, this is decompressing part of Run-Length programm"<<endl;
    cout<<"Your decompressed text: ";
    while (getline(inputFile, line)) 
    {
    decom(line, outputFile);
    }
    cout << endl;
    inputFile.close();
    outputFile.close();
    return 0;
}