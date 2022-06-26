#include<iostream>
#include<dirent.h>
#include<fstream>
#include<stdio.h>
using namespace std;


int main()
{
    
 // to find total number of files in a folder/directory
    
    struct dirent *d;
    DIR *dr;
    dr = opendir(".");
    int count=0;
    string name[100];
    int j=0;
    if(dr!=NULL)
    {
        for(d=readdir(dr); d!=NULL; d=readdir(dr))
        {
            count++;
            name[j++]=d->d_name;
        }
        closedir(dr);
    }
    else{cout<<"\nError Occurred!";}
    
    
        
// to merge all files into one single file
    
    char fileTarget[1000], ch;
        fstream res;
    
    for(int i=0;i<count;i++)
    {
        fstream f1;
        f1.open(name[i], fstream::in);
        if(!f1)
        {
            cout<<"\nError Occurred (First Source File)!";
            return 0;
        }
        else
        {
           
            res.open(fileTarget, fstream::out);
            if(!res)
                cout<<"\nError Occurred (Target File)!";
            else
            {
                while(f1>>noskipws>>ch)
                    res<<ch;
                res<<"\n";
                
            }
        }
        f1.close();
    }
    res.close();
    
    cout<<endl;
    return 0;
}
