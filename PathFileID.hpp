#ifndef PATHFILEID_H
#define PATHFILEID_H

class PathFileID: public FileID {
public:
    const string getPath(void) const{
        return itsPath;
    }
    PathFileID(const string& path):itsPath(path){
    }
private:
    const string itsPath;
};

#endif /* PATHFILEID_H */