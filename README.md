Hello! This is file handling programm. This programm compresses and decompresses texts from files.

                                          INSTRUCTIONS
                                          
1.Write text that you want to compress to input.txt
2.Run encode.cpp
3.If you want to decompress text that you get from encode.cpp, run decode.cpp                                          

                                          CODE STRUCTURE 

There are two different codes in my project: 
1)Compressing text(encode.cpp) 
2)Decompressing text(decode.cpp)

1)This part of my project compresses text using input.txt and output.txt. User writes the compressing text to input.txt and gets its compressed version in output.txt. 

Here is the main block of code:

\\
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
\\

Here the text is being compressed using Run-Length technique. This technique stores each symbol with the number of times it was written in a row. For example, the string "aaabbcccc" can be compressed to "a3b2c4".

Function above iterates through each character of the input string. For each character, it counts the number of consecutive occurrences by using a while loop that increments a count variable as long as the current character is the same as the next character.

2)This part of my project decompresses text using output.txt and decompressed.txt. Programm gets compressed data from output.txt (It is required to firstly compress the data using first part of my projet) and decompresses it, storing decompressed text into the decompressed.txt file.

Here is the main block of code:

\\
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
\\
Function iterates through the string str using a 'for' loop with a step of 2, as each character in the compressed string represents both the character and its count. Within the loop, it checks if the next character after the current character (str[i]) is a digit between '0' and '9'. This check determines whether the count is a single digit or a two-digit number. If the count is a two-digit number, it calculates the count by converting the next two characters (str[i+1] and str[i+2]) to integers and then multiplying the first digit by 10 and adding it to the second digit to get the final count.
