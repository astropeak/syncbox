#ifndef VERSION_H
#define VERSION_H

static const int CLIENT = 0;
static const int SERVER = 1;

class Version {
public:
    Version(const string& destDir, const string& name, const string& dir):
        itsDestDir(destDir), itsName(name), itsDir(dir){
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
    }
    int write(int loc, int ver) {
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        if (loc == CLIENT){
            cout<<" wriet client ver: "<<ver<<endl;
            clientVersion = ver;
        }
        else {
            cout<<" wriet server ver: "<<ver<<endl;
            serverVersion = ver;
        }
    }
    int read(int loc){
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        if (loc == CLIENT) {
            cout<<" read client ver: "<<clientVersion<<endl;
            return clientVersion;
        } else {
            cout<<" read server ver: "<<serverVersion<<endl;
            return serverVersion;
        }
    }
private:
    const string& itsDestDir;
    const string& itsName;
    const string& itsDir;

    static int clientVersion; //for test only
    static int serverVersion; //for test only
};

int Version::clientVersion = 2;
int Version::serverVersion = 1;

#endif /* VERSION_H */