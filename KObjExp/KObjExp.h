#pragma once

#define DRIVER_CURRENT_VERSION 0x0101

#define IOCTL_KOBJEXP_OPEN_OBJECT				CTL_CODE(0x8000, 0x800, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_KOBJEXP_DUP_HANDLE				CTL_CODE(0x8000, 0x801, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_KOBJEXP_OPEN_EVENT_BY_NAME		CTL_CODE(0x8000, 0x802, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_KOBJEXP_OPEN_SEMAPHORE_BY_NAME	CTL_CODE(0x8000, 0x803, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_KOBJEXP_OPEN_JOB_BY_NAME			CTL_CODE(0x8000, 0x804, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_KOBJEXP_OPEN_DESKTOP_BY_NAME		CTL_CODE(0x8000, 0x805, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_KOBJEXP_OPEN_PROCESS				CTL_CODE(0x8000, 0x806, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_KOBJEXP_GET_VERSION				CTL_CODE(0x8000, 0x807, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_KOBJEXP_GET_OBJECT_ADDRESS		CTL_CODE(0x8000, 0x808, METHOD_BUFFERED, FILE_ANY_ACCESS)

struct OpenObjectData {
	void* Address;
	ACCESS_MASK Access;
};

struct DupHandleData {
	ULONG Handle;
	ULONG SourcePid;
	ACCESS_MASK AccessMask;
	ULONG Flags;
};

struct OpenProcessData {
	ULONG ProcessId;
	ACCESS_MASK AccessMask;
};
