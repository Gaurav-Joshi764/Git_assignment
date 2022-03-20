#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

int main()
{
    fstream file;
    int count=0;
    char file_content [50];

    file.open("1.txt");

    while (file)
    {
         file>>file_content;
         if(file_content[0] == 'e')
         {
            count++;
         }
    }
    cout<<"total number of word that starts from 'e' is:"<<count <<endl;
    file.close();

    return 0;
}
