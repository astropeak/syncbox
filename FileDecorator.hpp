#ifndef FILEDECORATOR_H
#define FILEDECORATOR_H

#include "File.hpp"
#include "Version.hpp"

class FileDecorator:public File {
public:
    FileDecorator(File* file):itsFile(file) {
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
    }

    int write(void){
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        itsFile->write();

        // update version info;
        Version ver(CLIENT);
        int v=ver.read();
        ver.write(v+1);
        Version ver1(SERVER);
        int v1 = ver.read();
        if (v != v1) {
            cout<<"### ERROR ###, version not equal!!"<<endl;
        }
        ver1.write(v+1);
    }
    int read(void){
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        itsFile->read();

        // update version info;
        Version ver1(SERVER);
        int v1 = ver1.read();

        Version ver(CLIENT);
        ver.write(v1);
    }

private:
    File* itsFile;
};

#endif /* FILEDECORATOR_H */