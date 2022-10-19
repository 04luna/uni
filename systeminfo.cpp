// CPU & Memory information - Linux mint
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileHandling{
public:
    void read(string name){
        string line;
        ifstream myfile(name.c_str());
        if(myfile.is_open()){
            
            while(getline(myfile,line))
                cout << line << '\n';
           
            myfile.close();
        }
        else 
            cout << "Unable to open file"<<endl; 
    }
};

int main () {
    FileHandling* file = new FileHandling();
    
    cout<<"------------------  CPU INFO ------------------------"<<endl<<endl;
    file->read("/proc/cpuinfo");
    cout<<"------------------------------------------------------"<<endl<<endl;
    
    cout<<"------------------ MEMORY INFO ----------------------"<<endl<<endl;
    file->read("/proc/meminfo");
    cout<<"-----------------------------------------------------"<<endl<<endl;
    
    delete file;
    return 0;
}