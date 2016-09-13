#ifndef FILEDECORATOR_H
#define FILEDECORATOR_H

#include "File.hpp"
#include "Version.hpp"

class FileDecorator:public File {
public:
    FileDecorator(File* file, Version& ver):itsFile(file),itsVer(ver) {
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
    }

    int write(const string& from, const FileID* to){
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        itsFile->write(from, to);

        // update version info;
        int v=itsVer.read(CLIENT);
        int v1 = itsVer.read(SERVER);
        if (v != v1) {
            cout<<"### ERROR ###, version not equal!!"<<endl;
        }
        itsVer.write(SERVER, v+1);
    }
    int read(const FileID* from, const string& to){
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        itsFile->read(from, to);

        // update version info;
        int v1 = itsVer.read(SERVER);
        itsVer.write(CLIENT, v1);
    }

private:
    File* itsFile;
    Version itsVer;
};

#endif /* FILEDECORATOR_H */