#include "kernel.h"
#include "module.h"

#include "dialog.h"

// libSceCommonDialog
int32_t (*sceCommonDialogInitialize)(void);
bool (*sceCommonDialogIsUsed)(void);

// libSceMsgDialog
int32_t (*sceMsgDialogInitialize)(void);
int32_t (*sceMsgDialogTerminate)(void);
int32_t (*sceMsgDialogOpen)(const SceMsgDialogParam *param);
int32_t (*sceMsgDialogClose)(void);
int32_t (*sceMsgDialogGetResult)(SceMsgDialogResult *result);
SceCommonDialogStatus (*sceMsgDialogGetStatus)(void);
SceCommonDialogStatus (*sceMsgDialogUpdateStatus)(void);
int32_t (*sceMsgDialogProgressBarInc)(SceMsgDialogProgressBarTarget target, uint32_t delta);
int32_t (*sceMsgDialogProgressBarSetMsg)(SceMsgDialogProgressBarTarget target, const char *barMsg);
int32_t (*sceMsgDialogProgressBarSetValue)(SceMsgDialogProgressBarTarget target, uint32_t rate);

void initDialog(void) {

	int libCommonDialog = sceKernelLoadStartModule("/system/common/lib/libSceCommonDialog.sprx", 0, NULL, 0, 0, 0);

	RESOLVE(libCommonDialog, sceCommonDialogInitialize);
	RESOLVE(libCommonDialog, sceCommonDialogIsUsed);

	int libMsgDialog = sceKernelLoadStartModule("/system/common/lib/libSceMsgDialog.sprx", 0, NULL, 0, 0, 0);

	RESOLVE(libMsgDialog, sceMsgDialogInitialize);
	RESOLVE(libMsgDialog, sceMsgDialogTerminate);
	RESOLVE(libMsgDialog, sceMsgDialogOpen);
	RESOLVE(libMsgDialog, sceMsgDialogClose);
	RESOLVE(libMsgDialog, sceMsgDialogGetResult);
	RESOLVE(libMsgDialog, sceMsgDialogGetStatus);
	RESOLVE(libMsgDialog, sceMsgDialogUpdateStatus);
	RESOLVE(libMsgDialog, sceMsgDialogProgressBarInc);
	RESOLVE(libMsgDialog, sceMsgDialogProgressBarSetMsg);
	RESOLVE(libMsgDialog, sceMsgDialogProgressBarSetValue);
}
