#ifndef PATHFILEID_H
#define PATHFILEID_H

class PathFileID: public FileID {
public:
    const string getPath(void) const{
        cout<<"itsPath: "<<itsPath<<endl;
        return itsPath;
    }
    PathFileID(const string& path):itsPath(path){
        cout<<"path: "<<path<<endl;
        cout<<"itsPath: "<<itsPath<<endl;
    }
private:
    const string itsPath;
};

#endif /* PATHFILEID_H */