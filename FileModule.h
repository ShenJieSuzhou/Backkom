#pragma once
#include "UsbModule.h"
#include <vector>
#include <string>

class FileModule
{
public:
	FileModule(LPCSTR fp, CString disc);
	~FileModule(void);

	int ReadFiles(vector<string> fcon, CString disc);					//读取文件
	bool FileFilter(vector<string> fcon, int File_Format);				//文件过滤
	vector<string> FilePathClean(vector<string> m_filelist);		//文件路径清理
	string ReverseTheName(string m_str);									//反向文件名

private:
	LPCSTR fname;
	vector<string> m_fContainer;
	vector<string> m_fWanted;
	vector<string> m_fFinal;
};

