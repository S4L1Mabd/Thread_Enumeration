#include"func.h"

DWORD TargetedTID = NULL;
DWORD TargetedPID  = NULL ;
DWORD TrueTargetThread;
BOOL verifier = FALSE;
HANDLE TargetHthread;


int main(int argc , char *argv[]) {

	if (argc < 3) {

		printf("[!] invalid usage : runer.exe <PID> <TID> \n ");
		return EXIT_FAILURE;

	}
	TargetedPID = atoi(argv[1]);
	TargetedTID = atoi(argv[2]);
	verifier = EnumThreads(TargetedTID,TargetedPID , &TrueTargetThread, &TargetHthread);

	if (verifier == FALSE) {

		printf("[!] Thread Not Found  \n");
		return EXIT_FAILURE;
	}

	printf("[+] Targeted Thread Found   \n");
	return EXIT_SUCCESS;

}