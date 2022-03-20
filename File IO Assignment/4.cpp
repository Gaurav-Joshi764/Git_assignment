#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

int main()
{
    fstream file;
    int count=0;
    char file_content[50];

    file.open("1.txt");

    while(file)
    {
        file>>file_content;
        int len = strlen(file_content);
        if(file_content [len-1] == 's')
        {
            count++;
        }
    }
    cout<<"total number of word that ends with 's' is:" <<count<<endl;

    file.close();

    return 0;
}
