#pragma once

#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include <tlhelp32.h>

BOOL remoteThreadEnum(IN DWORD dwMainThreadId, IN DWORD  dwProcessId, OUT DWORD* dwThreadId, OUT DWORD* hThread);

