#pragma once
#include <windows.h>
#include <vector>
class UsbModule
{
public:
	UsbModule(LPCSTR srcFile);
	~UsbModule(void);

	bool InitFileList(LPCSTR dir);
	void Display();
	vector<string> GetFileList();

private:
	vector<string> FileList;
};

