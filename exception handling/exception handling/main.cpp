
#include <iostream>
using namespace std;

class myException{
public:
    char errmsg[50];
    int errorcode;
    
    myException(char * s, int c){
        strcpy(errmsg, s);
        errorcode=c;
    }
};
int main() {
    
    int i;
    
    try{
        cin>>i;
        if(i<0){
            throw myException("not positive",100);
        }
    }catch(myException e){
        cout<<e.errmsg;
        cout<<e.errorcode;
    }
    
    
    
    return 0;
}
