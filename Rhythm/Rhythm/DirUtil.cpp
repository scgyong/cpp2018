#include "DirUtil.h"
#include <Windows.h>

void DirUtil::readDir(string dir, vector<string>& files)
{
	WIN32_FIND_DATAA FindFileData;
	HANDLE hFind = FindFirstFileA(dir.c_str(), &FindFileData);

	if (hFind == INVALID_HANDLE_VALUE) {
		return;
	}

	do {
		printf("%s\n", FindFileData.cFileName);
		files.push_back(FindFileData.cFileName);
	} while (FindNextFileA(hFind, &FindFileData));

	FindClose(hFind);
}

