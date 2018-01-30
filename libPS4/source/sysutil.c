#include "kernel.h"
#include "module.h"

#include "sysutil.h"

int (*sceSysUtilSendSystemNotificationWithText)(int messageType, char* message);

void initSysUtil(void) {
	int sysUtilHandle;
	loadModule("/system/common/lib/libSceSysUtil.sprx", &sysUtilHandle);
	RESOLVE(sysUtilHandle, sceSysUtilSendSystemNotificationWithText);
}
