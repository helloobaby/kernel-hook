this repositories come from https://github.com/adrianyy/kernelhook.

i add hde support to determine patched bytes.

example:

DriverIn:
HkDetourFunction((PVOID)NtClose, (PVOID)HookedNtClose,(PVOID*)&OriginalNtClose);

DriverUnload:
HkRestoreFunction((PVOID)NtClose, (PVOID)OriginalNtClose);


