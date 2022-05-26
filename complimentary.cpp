#include<iostream>
#include<cctype>
#include<algorithm>
#include<string>
#include<fstream>
#include<vector>
using namespace std;


//function number 0-(menu display)
void menu(){
    cout<<"1-Append text to the file\n2-Display the content of the file\n3-Empty the content of the file\n4-Encrypt the file content \n";
    cout<<"5-Decrypt the file content\n6-Merge with another file\n7-Count the words number in file\n  8-Count the number of characters \n";
    cout<<"9-Count the lines in file\n10-search for a word\n11-Count the number of times a word exists in the file\n12-Turn to uppercase\n";
    cout<<"13-Turn the file content to lower case\n14-Turn file content to 1st caps\n15-save\n16-Exit \n\n";
}

//function number 1-(the Adding content)//
void Addcont(string fn) {
    string uin="";
    fstream userfile(fn);
    userfile.close();
    userfile.open(fn,ios::app);
    cout<<"Enter what you want to Append : \n";
    for (int i = 0; i < 10000; i++)
    {
        uin +=getchar();
        if (uin[uin.size()-1]==26){
            break;
        }
    }
    userfile<<"    "<<uin;
}

//function number 2-(displaying the file content)//
void contdisp(string fn){
    char arr[1000];
    ifstream userfile(fn);
    userfile.getline(arr,1000);
    cout<<"The content of the file is : \n ";
    cout<<arr<<endl;
}

//function number 3-(emptying the file)//
void emptyfile(string fn){
    cout<<"file is now empty .... like my life \n";
    ofstream userfile;
    userfile.open(fn);
    userfile<<"";
    userfile.close();
}

//function number 4-(encrypting file)//
void filenc(string fn){
    char arr[45];
    int k=0;
    ifstream userfile(fn);
    userfile.getline(arr,45);
    string word=arr;
    for(int i=0;i<word.size();i++){
        arr[i]=arr[i]+1;
    }
    userfile.close();
    ofstream userf;
    userf.open(fn);
    userf<<arr;
    cout<<"File encrypted successfully \n";
}

//function number 5-(decrypting file)//
void filedec(string fn){
    char arr[45];
    int k=0;
    ifstream userfile(fn);
    userfile.getline(arr,45);
    string word=arr;
    for(int i=0;i<word.size();i++){
        arr[i]=arr[i]-1;
    }
    userfile.close();
    ofstream userf;
    userf.open(fn);
    userf<<arr;
    cout<<"File decrypted successfully \n";
}

//function number 6-(Merging two files)//
void mergefile(string fn){
    string mf;
    cout<<"Enter the file to be merged and its extension : ";
    getline(cin,mf);
    ifstream userfile(mf);
    char arr[100];
    userfile.getline(arr,100);
    userfile.close();
    ofstream mainfile;
    mainfile.open(fn,std::ios_base::app);
    mainfile<<" "<<arr;
    cout<<"File merged successfully! \n";
}

//function number 7-(number of words)//
void wordcount(string fn){
    char arr[100];
    int count=0;
    ifstream userfile(fn);
    userfile.getline(arr,100);
    for(int i:arr){
        if (i==32){
            count++;
        }
    }
    cout<<count<<" Words were found ! \n";
}

//function number 8-(number of characters)//
void carcount(string fn){
    char arr[20];
    int count=0;
    ifstream userfile(fn);
    userfile.getline(arr,20);
    for(int i:arr){
        if (i!=32 && i!=0){
            count++;
        }
    }
    cout<<count<<" Character was found !";
}

//function number 9-(number of lines)
void noflines(string fn){
    vector<string>data;
    fstream userfile(fn);
    char line[100];
    while (!userfile.eof()) {
                userfile.getline(line, 100, '\n');
                data.push_back(string(line));
            }
    cout<<"number of lines is"<<data.size()<<endl;
}
//function number 10-(search for word)//
void wordsrch(string fn){
    string src;
    string flst;
    int count=0;
    int k=0;
    ifstream userfile(fn);
    getline(userfile,flst);
    cout<<"Add the word to be searched --> ";
    getline(cin,src);
    for(char i:flst){
       flst[k]=char(tolower(i));
       k++;
    }
    if(flst.find(src,0)<1000){
        cout<<"The word you searched for was found ! \n";
    }else{
        cout<<"Couldn't find the word u searched for =( \n";
    }

}

//function number 11-(number of times word exist)
void nmbrtimes(string fn){
    string src;
    string flst;
    int count=0;
    ifstream userfile(fn);
    getline(userfile,flst);
    cout<<"Add the word to be searched --> \n";
    getline(cin,src);
    for (int i = 0; flst.find(src,i) <10000 ; i+=flst.find(src,i))
    {
         if(flst.find(src,0)<1000){
        count=count+1;
    }
    }
    cout<<"The word was found "<<count<<" Times! \n";
}

//function number 12-(all upper case)//
void uppercase(string fn){
    char arr[45];
    int k=0;
    ifstream userfile(fn);
    userfile.getline(arr,50);
    for(char i:arr){
       arr[k]=char(toupper(i));
       k++;
    }
    ofstream file(fn);
    file<<arr;
    cout<<"File turned to capital case \n";
}

//function number 13-(all lower case)//
void lowercase(string fn){
    char arr[45];
    int k=0;
    ifstream userfile(fn);
    userfile.getline(arr,50);
    for(char i:arr){
       arr[k]=char(tolower(i));
       k++;
    }
    ofstream file(fn);
    file<<arr;
    cout<<"File turned to lower case \n";
}

//function number 14-(Turn the 1st letter into caps)
void frstcap(string fn){
    char arr[100];
    int count=0;
    int k=0;
    ifstream userfile(fn);
    userfile.getline(arr,100);
    for(int i:arr){
        if (i==32){
            arr[k+1]=char(toupper(arr[k+1]));
        }
        k++;
    }
     arr[0]=char(toupper(arr[0]));
    ofstream file(fn);
    file<<arr;
    cout<<"File saved successfully !";
}

//function number 15-(save)//
void save(string fn){
    string newfile;
    char arr[100];
    ifstream userfile(fn);
    userfile.getline(arr,100);
    cout<<"Enter the file name & extension to save the content in : \n";
    getline(cin,newfile);
    ofstream file(newfile);
    file<<arr;
}