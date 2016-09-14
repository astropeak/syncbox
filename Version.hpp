#ifndef VERSION_H
#define VERSION_H

#include "FileID.hpp"

static const int CLIENT = 0;
static const int SERVER = 1;

class Version {
public:
    virtual int write(int loc, const FileID& id, int ver)=0;
    virtual int read(int loc, const FileID& id)=0;
};

#endif /* VERSION_H */