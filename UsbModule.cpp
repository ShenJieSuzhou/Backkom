#include "StdAfx.h"
#include "UsbModule.h"
#define LEN 1024

UsbModule::UsbModule(LPCSTR srcFile)
{
	InitFileList(srcFile);
}


UsbModule::~UsbModule(void)
{
}

bool UsbModule::InitFileList(LPCSTR dir)
{
	WIN32_FIND_DATA m_Data;
	HANDLE hError;

	int FileCount = 0;
	char FilePathName[LEN];
	char FileFullName[LEN];

	strcpy(FilePathName, dir);
	strcat(FilePathName, "\\*.*");

	hError = FindFirstFile(FilePathName, &m_Data);
	if(hError == INVALID_HANDLE_VALUE)
	{
		AfxMessageBox("����ʧ��");
		return 0;
	}

	while(::FindNextFile(hError, &m_Data))
	{
		if(strcmp(m_Data.cFileName, ".") == 0 || strcmp(m_Data.cFileName, "..") == 0)		//���� . �� ..
		{
			continue;
		}

		wsprintf(FileFullName, "%s\\%s", dir, m_Data.cFileName);
		FileCount++;

		if(m_Data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)										//�ж��Ƿ����ļ���
		{
			InitFileList(FileFullName);
		}
		else
		{
			FileList.push_back(FileFullName);																			//��ʽ������ļ��������б�
		}
	}
}

vector<string> UsbModule::GetFileList()
{
	return FileList;
}