#include "kernel.h"
#include "module.h"

#include "sysutil.h"

int (*sceSysUtilSendSystemNotificationWithText)(int messageType, char* message);

void initSysUtil(void) {
	int sysUtilHandle = sceKernelLoadStartModule("/system/common/lib/libSceSysUtil.sprx", 0, NULL, 0, 0, 0);

	RESOLVE(sysUtilHandle, sceSysUtilSendSystemNotificationWithText);
}
