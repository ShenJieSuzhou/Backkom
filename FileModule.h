#pragma once
#include "UsbModule.h"
#include <vector>
#include <string>

class FileModule
{
public:
	FileModule(LPCSTR fp, CString disc);
	~FileModule(void);

	int ReadFiles(vector<string> fcon, CString disc);					//��ȡ�ļ�
	bool FileFilter(vector<string> fcon, int File_Format);				//�ļ�����
	vector<string> FilePathClean(vector<string> m_filelist);		//�ļ�·������
	string ReverseTheName(string m_str);									//�����ļ���

private:
	LPCSTR fname;
	vector<string> m_fContainer;
	vector<string> m_fWanted;
	vector<string> m_fFinal;
};

