#ifndef FILEDECORATOR_H
#define FILEDECORATOR_H

#include "File.hpp"
#include "Version.hpp"

class FileDecorator:public File {
public:
    FileDecorator(File* file, Version& ver):itsFile(file),itsVer(ver) {
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
    }

    int write(void){
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        itsFile->write();

        // update version info;
        int v=itsVer.read(CLIENT);
        int v1 = itsVer.read(SERVER);
        if (v != v1) {
            cout<<"### ERROR ###, version not equal!!"<<endl;
        }
        itsVer.write(SERVER, v+1);
    }
    int read(void){
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        itsFile->read();

        // update version info;
        int v1 = itsVer.read(SERVER);
        itsVer.write(CLIENT, v1);
    }

private:
    File* itsFile;
    Version itsVer;
};

#endif /* FILEDECORATOR_H */