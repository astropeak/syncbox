#ifndef FILE_H
#define FILE_H



#include <iostream>
#include <string>
using namespace std;

class File {
public:
    virtual int write(void) = 0;
    virtual int read(void) = 0;
    File(const string& name, const string& dir):itsName(name),itsDir(dir) {
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        cout<<" name: "<<name<<", dir: "<<dir<<endl;
    }
    File(void):itsName(""), itsDir(""){
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
    }
    virtual ~File() {};
protected:
    const string& itsName;
    const string& itsDir;
};

#endif /* FILE_H */