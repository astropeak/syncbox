#ifndef LOCALVERSION_H
#define LOCALVERSION_H

#include "Version.hpp"
#include <iostream>
#include <fstream>
#include <boost/filesystem.hpp>
#include "File.hpp"
// using std::ofstream;
// using std::ifstream;
// using std::endl;
// using std::cout;
using namespace boost::filesystem;


class LocalVersion: public Version {
public:
    int write(int loc, const FileID& id, int ver) {
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        if (loc == CLIENT){
            // cout<<" wriet client ver: "<<ver<<endl;
            writeVer(itsClientHomeDir+"/"+id.getPath(), ver);
        }
        else {
            // cout<<" wriet server ver: "<<ver<<endl;
            writeVer(itsServerHomeDir+"/"+ id.getPath() +".version", ver);
        }
    }
    int read(int loc, const FileID& id){
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        if (loc == CLIENT) {
            // cout<<" read client ver"<<endl;
            return readVer(itsClientHomeDir+"/"+id.getPath());
        } else {
            // cout<<" read server ver"<<endl;
            path p(id.getPath());
            return readVer(itsServerHomeDir+"/"+id.getPath()+".version");
        }
    }

    int remove(int loc, const FileID& server){
        path p(itsServerHomeDir+"/"+server.getPath());
        boost::filesystem::remove(p);
        return 1;
    }
    int remove(int loc, const string& client){
        path p(itsClientHomeDir+"/"+ sub(client, localHome));
        boost::filesystem::remove(p);
        return 1;
    }

    static void setDirs(const string client, const string server){
        itsClientHomeDir=client;
        itsServerHomeDir=server;
    }
private:
    string sub(const string& a, const string& b){
        string s(a.c_str() + b.length());
        cout<<" sub resutl: "<<s<<endl;
        return s;
    }

    int writeVer(const string& name, int ver) {
        // cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        // cout<<" name: "<<name<<", ver: "<<ver<<endl;
        //write ver to file name
        path p(name);
        path pdir(p.parent_path());
        if (!exists(pdir)) {
            cout<<" create directory: "<<pdir.c_str()<<endl;
            create_directories(pdir);
        }

        std::ofstream of;
        of.open(name.c_str());
        of<<ver;
        of.close();
    }
    int readVer(const string& name){
        // cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        // cout<<" name: "<<name<<endl;
        path p(name);

        if (!exists(p)) {
            cout<<" file not exists: "<<name<<endl;
            return -1;
        }

        std::ifstream iff;
        iff.open(name.c_str());
        int ver=-1;
        iff>>ver;
        cout<<" ver:"<<ver<<endl;
        iff.close();
        return ver;
    }
    static string itsClientHomeDir;
    static string itsServerHomeDir;
};

string LocalVersion::itsClientHomeDir;
string LocalVersion::itsServerHomeDir;

#endif /* LOCALVERSION_H */