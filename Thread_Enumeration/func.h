#pragma once

#include<windows.h>
#include<stdio.h>
#include<stdint.h>
#include <tlhelp32.h>

BOOL EnumThreads(IN DWORD dwMainThreadId, IN DWORD dwProcessId , OUT DWORD* dwThreadId, OUT HANDLE* hThread);

