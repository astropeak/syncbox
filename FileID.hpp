#ifndef FILEID_H
#define FILEID_H

#include <string>
using namespace std;

class FileID {
public:
    virtual const string getPath(void) const =0;
};

#endif /* FILEID_H */