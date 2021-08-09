this repositorie comes from https://github.com/adrianyy/kernelhook.

i add hde support to determine patched bytes.

Example:

HkDetourFunction((PVOID)NtClose, (PVOID)HookedNtClose,(PVOID*)&OriginalNtClose);

HkRestoreFunction((PVOID)NtClose, (PVOID)OriginalNtClose);


