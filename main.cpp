// FCAI – Programming 1 – 2022 - Assignment 4
// Last Modification Date: 10/5/2022
// Author1 and ID and Group: Tarek Msotafa 20200916
// Author2 and ID and Group: Abdullah Ashraf 20210232
// Author3 and ID and Group: Abdulrahman Taymour 20210200
// Teaching Assistant: Afaf
// Purpose: Text Editor
#include<iostream>
#include"complimentary.h"
using namespace std;
int main(){
    string file;
    string an;
    int x;
    cout<<"Enter the desired File name and extension : ";
    getline(cin,file);
    fstream fls(file);
    if(fls){
        cout<<"The file is Now opened successfully \n";
    }else
    {
        cout<<"I've created a file 4 u  \n";
    }
    
//------------------------------------------------
    while (true)
    {
        menu();
    cout<<"Add your App Number : ";
    getline(cin,an);
    x=stoi(an);

    if (x==16)
    {
        break;
    }

    switch (x)
    {
    case 1:
         Addcont(file);
         break;
    case 2:
         contdisp(file);
         break;
    case 3:
         emptyfile(file);
         break;
    case 4:
        filenc(file);
        break;
    case 5:
        filedec(file);
        break;
    case 6:
        mergefile(file);
        break;
    case 7:
        wordcount(file);
        break;
    case 8:
        carcount(file);
            break;
    case 9:
        noflines(file);
        break;
    case 10:
        wordsrch(file);
        break;
    case 11:
        nmbrtimes(file);
        break;
    case 12:
        uppercase(file);
        break;
    case 13:
        lowercase(file);
        break;
    case 14:
        frstcap(file);
        break;
    case 15:
        save(file);
        break;
}
    }
    cout<<"Thanks for using the program <3 ";

}