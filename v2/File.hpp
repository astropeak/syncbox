#ifndef FILE_H
#define FILE_H

struct FileData {
};
typedef struct FileData FileData;

class File{
public:
    virtual ostream* getOstream(const string& path)=0;
    virtual istream* getIstream(const string& path)=0;
    virtual int remove(const string& path)=0;
    // get the info of the file itself. Such as if the file exists, its timestamp.
    virtual FileData getInfo(const string& path)=0;
    virtual int setInfo(const string& path, int property, int value)=0;
};

#endif /* FILE_H */