#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    fstream file;
    int words_count=0;

    char ch;

    file.open("1.txt");

    while(file)
    {
        file.get(ch);
        if(ch=='a')
        {
            words_count++;
        }
    }

    cout<<"total words that contains 'a' in it: "<<words_count<<endl;
    file.close();

    return 0;
}
