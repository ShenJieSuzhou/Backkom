#include "StdAfx.h"
#include "FileModule.h"
#include <fstream>
#include "Backkom.h"


FileModule::FileModule(LPCSTR fp, CString disc)
{
	this->fname = fp;
	UsbModule usb(fname);
	m_fContainer = usb.GetFileList();

	if(!FileFilter(m_fContainer, 1))												//过滤掉除指定文件后缀的文件路径
	{
		AfxMessageBox(_T("文件过滤失败 匹配不到指定文件格式"));
	}

	if(ReadFiles(m_fWanted, disc) == 0)
	{
		AfxMessageBox(_T("FIles Open and Copy Failed"));
		return;
	}

	AfxMessageBox(_T("SUCCEED"));
}


FileModule::~FileModule(void)
{
}

int FileModule::ReadFiles(vector<string> fcon, CString disc)
{
	ifstream fin;
	ofstream fout;
	for(int i = 0; i <  fcon.size(); i++)
	{
		char buffer[1024];
		string foutName;
		string str(disc.GetBuffer());

		foutName = str + m_fFinal[i];
		disc.ReleaseBuffer();

		fin.open(fcon[i], ios::binary | ios::in);
		fout.open(foutName , ios::binary | ios::out);

		if(!fout || !fin)
		{
			continue;
			return 0;
		}

		while(!fin.eof())
		{
			fin.read(buffer, sizeof(buffer));
			fout.write(buffer, fin.gcount());
		}
		
		fin.close();
		fout.close();

	}

	return 1;
}


bool FileModule::FileFilter(vector<string> fcon, int File_Format)
{
	if(File_Format == 1)
	{
		//指向文件名
		const char *m_pStr;	
		//文件后缀名
		string suffix;

		for(int i = 0 ; i < fcon.size(); i++)
		{
			bool isFindDot = false;
			m_pStr = fcon[i].c_str();
			int len = strlen(m_pStr);

			for(int j = 0 ; j < len ; j++)
			{
				if(m_pStr[j] == '.' || isFindDot == true)
				{
					suffix += m_pStr[j];
					isFindDot = true;
				}
			}
			if(suffix == ".doc" || suffix == ".docx")
			{
				m_fWanted.push_back(fcon[i]);
			}
			suffix.erase();
		}

		FilePathClean(m_fWanted);
		return true;
	}
	else
	{
		return false;
	}
}

vector<string> FileModule::FilePathClean(vector<string> m_filelist)
{
	//最终的命名的文件
	string FinalFileName;

	for(int i = 0 ; i < m_filelist.size(); i++)
	{
		const char *m_pFname;
		m_pFname = m_filelist[i].c_str();
		int length = strlen(m_pFname);

		for(int j = length-1; j >= 0; j--)
		{
			if(m_pFname[j] == '\\' )
			{
				break;
			}
			FinalFileName += m_pFname[j];
		}

		FinalFileName = ReverseTheName(FinalFileName);
		m_fFinal.push_back(FinalFileName);
		FinalFileName.erase();
	}

	return m_fFinal;
}

string FileModule::ReverseTheName(string m_str)
{
	int len = m_str.length();
	if(len == 0)
	{
		return "";
	}

	const char *m_p = m_str.c_str();
	char * temp = new char[len];

	for(int i = len - 1, j = 0; i >= 0, j < len ; i--, j++)
	{
		 temp[i] = m_p[j] ;
	}
	temp[len] = '\0';

	return temp;
}
