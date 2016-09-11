#ifndef LOCAL_FILE_H
#define LOCAL_FILE_H

#include "File.hpp"

class LocalFile:public File {
public:
    int write(void);
    int read(void);
    LocalFile(string destDir, string name, string dir);
    virtual ~LocalFile(){};
private:
    string itsDestDir;
};

#endif /* LOCAL_FILE_H */