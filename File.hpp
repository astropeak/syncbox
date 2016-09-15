#ifndef FILE_H
#define FILE_H



#include <iostream>
#include <string>
#include "FileID.hpp"

using namespace std;

class File {
public:
    virtual int write(const string& from, const FileID& to) = 0;
    virtual int read(const FileID& from, const string& to) = 0;
    virtual int remove(const FileID& server) = 0;
    virtual int remove(const string& client) = 0;
};

#endif /* FILE_H */