#ifndef FILEID_H
#define FILEID_H

#include <string>
using namespace std;

class FileID {
public:
    //get the relative path this file should be saved on client side
    virtual const string getPath(void) const =0;
};

#endif /* FILEID_H */