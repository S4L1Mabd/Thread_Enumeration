#include"func.h"


BOOL remoteThreadEnum(IN DWORD dwMainThreadId,IN DWORD  dwProcessId , OUT DWORD *dwThreadId, OUT DWORD *hThread){




		//DWORD dwProcessId = GetCurrentProcessId();
		HANDLE hSnapshot = NULL;

		THREADENTRY32 MyThread = {
			.dwSize = sizeof(THREADENTRY32)
		};

		hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, NULL);

		if (hSnapshot == INVALID_HANDLE_VALUE) {

			printf("[!] error on getting snapshot  \n ");
			return FALSE;
		}

		if (!Thread32First(hSnapshot, &MyThread)) {

			printf("[!] error on getting the first Thread  \n ");
			return FALSE;
		}



		do {

			if ((MyThread.th32OwnerProcessID == dwProcessId)) {

				*dwThreadId = MyThread.th32ThreadID;
				*hThread = OpenThread(THREAD_ALL_ACCESS, FALSE, MyThread.th32ThreadID);

			}
			else {

				printf("[!] error on func enumthread \n ");
				break;
			}





		} while (Thread32Next(hSnapshot, &MyThread));


		if (hSnapshot != NULL)
			CloseHandle(hSnapshot);
		if (*dwThreadId == NULL || *hThread == NULL) {

			printf("[!] error on func enumthread \n ");
			return FALSE;
		}

		return TRUE;

	}
