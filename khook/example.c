#include <ntifs.h>
#include "khook/hk.h"

NTSTATUS (__fastcall *OriginalNtClose)(_In_ HANDLE Handle);
NTSTATUS HookedNtClose(
	_In_ HANDLE Handle
)
{
	DbgPrintEx(0, 0, "Called NtClose.\n");

	return OriginalNtClose(Handle);
}

VOID DriverUnload(
	_In_ PDRIVER_OBJECT DriverObject
)
{
	UNREFERENCED_PARAMETER(DriverObject);

	HkRestoreFunction((PVOID)NtClose, (PVOID)OriginalNtClose);
}

NTSTATUS DriverEntry(
	_In_ PDRIVER_OBJECT		DriverObject,
	_In_ PUNICODE_STRING	RegistryPath
)
{
	UNREFERENCED_PARAMETER(RegistryPath);

	DriverObject->DriverUnload = DriverUnload;

	HkDetourFunction((PVOID)NtClose, (PVOID)HookedNtClose,(PVOID*)&OriginalNtClose);

	return STATUS_SUCCESS;
}