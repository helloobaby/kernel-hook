this repositorie comes from https://github.com/adrianyy/kernelhook.

i add hde support to determine patched bytes.

Example:

DriverIn:

HkDetourFunction((PVOID)NtClose, (PVOID)HookedNtClose,(PVOID*)&OriginalNtClose);

DriverUnload:

HkRestoreFunction((PVOID)NtClose, (PVOID)OriginalNtClose);


