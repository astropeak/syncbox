#ifndef FILEDECORATOR_H
#define FILEDECORATOR_H

#include "File.hpp"
#include "Version.hpp"

class FileDecorator:public File {
public:
    FileDecorator(File& file, Version& ver):itsFile(file),itsVer(ver) {
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
    }

    int write(const string& from, const FileID& to){
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        itsFile.write(from, to);

        // update version info;
        int v=itsVer.read(CLIENT, to);
        int v1 = itsVer.read(SERVER, to);
        if (v != v1) {
            cout<<"### ERROR ###, version not equal!!"<<endl;
        }
        itsVer.write(CLIENT, to, v+1);
        itsVer.write(SERVER, to, v+1);
    }
    int read(const FileID& from, const string& to){
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        itsFile.read(from, to);

        // update version info;
        int v1 = itsVer.read(SERVER, from);
        itsVer.write(CLIENT, from, v1);
    }
    int remove(const FileID& server) {
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        itsFile.remove(server);
    }
    int remove(const string& client) {
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        itsFile.remove(client);
    }

private:
    File& itsFile;
    Version& itsVer;
};

#endif /* FILEDECORATOR_H */