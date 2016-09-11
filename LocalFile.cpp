#include <iostream>
#include "LocalFile.hpp"
using namespace std;


int LocalFile::write(void) {
    // copy file "itsDir/itsName" to "itsDestDir/itsName".
    cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
}

int LocalFile::read(void) {
    cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
    // copy file "itsDestDir/itsName" to "itsDir/itsName".
}

LocalFile::LocalFile(string destDir, string name, string dir):
    itsDestDir(destDir), File(name, dir) {
    cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
    cout<<" destDir: "<<destDir<<endl;
    // do nothing
}