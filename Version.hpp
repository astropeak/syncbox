#ifndef VERSION_H
#define VERSION_H

static const int CLIENT = 0;
static const int SERVER = 1;

class Version {
public:
    Version(int loc): itsLoc(loc) {
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
    }
    int write(int ver) {
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        cout<<" ver: "<<ver<<endl;
        if (itsLoc == CLIENT) clientVersion = ver;
        else serverVersion = ver;
    }
    int read(){
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        if (itsLoc == CLIENT) {
            cout<<" read client ver: "<<clientVersion<<endl;
            return clientVersion;
        } else {
            cout<<" read server ver: "<<serverVersion<<endl;
            return serverVersion;
        }
    }
private:
    int itsLoc;
    static int clientVersion; //for test only
    static int serverVersion; //for test only
};

int Version::clientVersion = 0;
int Version::serverVersion = 1;

#endif /* VERSION_H */