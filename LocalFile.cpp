#include <iostream>
#include <boost/filesystem.hpp>
#include "LocalFile.hpp"
#include <fstream>
#include <libgen.h>
#include <stdlib.h>
using namespace std;
using namespace boost::filesystem;


int LocalFile::write(void) {
    // copy file "itsDir/itsName" to "itsDestDir/itsName".
    cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
    copy(itsName, itsDir, itsDestDir);
}

int LocalFile::read(void) {
    cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
    copy(itsName, itsDestDir, itsDir);
}

int LocalFile::copy(const string& name, const string& dir, const string& destDir) {
    cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
    path from(dir+"/"+name);
    path dest(destDir+"/"+name);

    path pdir(dest.parent_path());
    if (!exists(pdir)) {
        create_directories(pdir);
    }
    copy_file(from, dest, copy_option::overwrite_if_exists);
}

LocalFile::LocalFile(const string& destDir, const string& name, const string& dir):
    itsDestDir(destDir), File(name, dir) {
    cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
    cout<<" destDir: "<<destDir<<endl;
    // do nothing
}