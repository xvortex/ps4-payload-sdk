#pragma once

extern int (*sceSysUtilSendSystemNotificationWithText)(int messageType, char* message);

void initSysUtil(void);
