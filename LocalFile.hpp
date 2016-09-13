#ifndef LOCAL_FILE_H
#define LOCAL_FILE_H

#include "File.hpp"

class LocalFile:public File {
public:
    int write(void);
    int read(void);
    LocalFile(const string& destDir, const string& name, const string& dir);
    virtual ~LocalFile(){};
private:
    const string& itsDestDir;
    int copy(const string& name, const string& dir, const string& destDir);
};

#endif /* LOCAL_FILE_H */