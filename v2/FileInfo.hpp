#ifndef FILEINFO_H
#define FILEINFO_H

/* this class can do some caching mechnism */
// method: save the file info to a file under ~/.syncbox. then read all property form that file
struct FI_Data {

};
typedef struct FI_Data FI_Data;

class FileInfo {
public:
    // file is used to get or set some property of the file itself.
    FileInfo(File& file):itsFile(file){
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
    }
    FI_Data getInfo(const string& path){
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        FileData fd=itsFile.getInfo(path);
    }
    int setInfo(const string& path, int property, int value){
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
    }
private:
    File& itsFile;
};

#endif /* FILEINFO_H */