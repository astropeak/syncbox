#include <iostream>
#include "LocalFile.hpp"
#include <fstream>
#include <libgen.h>
#include <stdlib.h>
using namespace std;


int LocalFile::write(void) {
    // copy file "itsDir/itsName" to "itsDestDir/itsName".
    cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
    // string dest = itsDestDir+"/"+itsName;
    system(dirname((char *)("mkdir -p "+itsDestDir+"/"+itsName).c_str()));
    ifstream src((itsDir+"/"+itsName).c_str(), std::ios::binary);
    ofstream dest((itsDestDir+"/"+itsName).c_str(), std::ios::binary);
    dest << src.rdbuf();
}

int LocalFile::read(void) {
    cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
    // string dest = itsDestDir+"/"+itsName;
    // system(("mkdir -p "+itsDestDir+"/"+itsName).c_str());
    system(dirname((char *)("mkdir -p "+itsDir+"/"+itsName).c_str()));

    ifstream src((itsDestDir+"/"+itsName).c_str(), std::ios::binary);
    ofstream dest((itsDir+"/"+itsName).c_str(), std::ios::binary);
    dest << src.rdbuf();
    // copy file "itsDestDir/itsName" to "itsDir/itsName".
}

LocalFile::LocalFile(const string& destDir, const string& name, const string& dir):
    itsDestDir(destDir), File(name, dir) {
    cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
    cout<<" destDir: "<<destDir<<endl;
    // do nothing
}