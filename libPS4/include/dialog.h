#pragma once

#include "libc.h"

// libSceCommonDialog

extern int32_t (*sceCommonDialogInitialize)(void);
extern bool (*sceCommonDialogIsUsed)(void);

#define SCE_COMMON_DIALOG_MAGIC_NUMBER 0xC0D1A109

#define SCE_COMMON_DIALOG_ERROR_NOT_SYSTEM_INITIALIZED -2135425023	/* 0x80B80001 */
#define SCE_COMMON_DIALOG_ERROR_ALREADY_SYSTEM_INITIALIZED -2135425022	/* 0x80B80002 */
#define SCE_COMMON_DIALOG_ERROR_NOT_INITIALIZED	-2135425021	/* 0x80B80003 */
#define SCE_COMMON_DIALOG_ERROR_ALREADY_INITIALIZED -2135425020	/* 0x80B80004 */
#define SCE_COMMON_DIALOG_ERROR_NOT_FINISHED	-2135425019	/* 0x80B80005 */
#define SCE_COMMON_DIALOG_ERROR_INVALID_STATE	-2135425018	/* 0x80B80006 */
#define SCE_COMMON_DIALOG_ERROR_RESULT_NONE	-2135425017	/* 0x80B80007 */
#define SCE_COMMON_DIALOG_ERROR_BUSY		-2135425016	/* 0x80B80008 */
#define SCE_COMMON_DIALOG_ERROR_OUT_OF_MEMORY	-2135425015	/* 0x80B80009 */
#define SCE_COMMON_DIALOG_ERROR_PARAM_INVALID	-2135425014	/* 0x80B8000A */
#define SCE_COMMON_DIALOG_ERROR_NOT_RUNNING	-2135425013	/* 0x80B8000B */
#define SCE_COMMON_DIALOG_ERROR_ALREADY_CLOSE	-2135425012	/* 0x80B8000C */
#define SCE_COMMON_DIALOG_ERROR_ARG_NULL	-2135425011	/* 0x80B8000D */
#define SCE_COMMON_DIALOG_ERROR_UNEXPECTED_FATAL -2135425010	/* 0x80B8000E */
#define SCE_COMMON_DIALOG_ERROR_NOT_SUPPORTED	-2135425009	/* 0x80B8000F */
#define SCE_COMMON_DIALOG_ERROR_INHIBIT_SHAREPLAY_CLIENT -2135425008	/* 0x80B80010 */

typedef enum SceCommonDialogStatus {
	SCE_COMMON_DIALOG_STATUS_NONE				= 0,
	SCE_COMMON_DIALOG_STATUS_INITIALIZED			= 1,
	SCE_COMMON_DIALOG_STATUS_RUNNING			= 2,
	SCE_COMMON_DIALOG_STATUS_FINISHED			= 3
} SceCommonDialogStatus;

typedef enum SceCommonDialogResult {
	SCE_COMMON_DIALOG_RESULT_OK				= 0,
	SCE_COMMON_DIALOG_RESULT_USER_CANCELED			= 1,
} SceCommonDialogResult;

typedef struct SceCommonDialogBaseParam {
	size_t size;
	uint8_t reserved[36];
	uint32_t magic;
} SceCommonDialogBaseParam __attribute__ ((__aligned__(8)));

static inline
void _sceCommonDialogSetMagicNumber( uint32_t* magic, const SceCommonDialogBaseParam* param )
{
	*magic = (uint32_t)( SCE_COMMON_DIALOG_MAGIC_NUMBER + (uint64_t)param );
}

static inline
void _sceCommonDialogBaseParamInit(SceCommonDialogBaseParam *param)
{
	memset(param, 0x0, sizeof(SceCommonDialogBaseParam));
	param->size = (uint32_t)sizeof(SceCommonDialogBaseParam);
	_sceCommonDialogSetMagicNumber( &(param->magic), param );
}

// libSceMsgDialog

#define SCE_SYSMODULE_MESSAGE_DIALOG 0x00a4

typedef int32_t SceMsgDialogMode;
#define SCE_MSG_DIALOG_MODE_INVALID				(0)
#define SCE_MSG_DIALOG_MODE_USER_MSG				(1)
#define SCE_MSG_DIALOG_MODE_PROGRESS_BAR			(2)
#define SCE_MSG_DIALOG_MODE_SYSTEM_MSG				(3)

typedef int32_t SceMsgDialogButtonType;
#define SCE_MSG_DIALOG_BUTTON_TYPE_OK				(0)
#define SCE_MSG_DIALOG_BUTTON_TYPE_YESNO			(1)
#define SCE_MSG_DIALOG_BUTTON_TYPE_NONE				(2)
#define SCE_MSG_DIALOG_BUTTON_TYPE_OK_CANCEL			(3)
#define SCE_MSG_DIALOG_BUTTON_TYPE_WAIT				(5)
#define SCE_MSG_DIALOG_BUTTON_TYPE_WAIT_CANCEL			(6)
#define SCE_MSG_DIALOG_BUTTON_TYPE_YESNO_FOCUS_NO		(7)
#define SCE_MSG_DIALOG_BUTTON_TYPE_OK_CANCEL_FOCUS_CANCEL	(8)
#define SCE_MSG_DIALOG_BUTTON_TYPE_2BUTTONS			(9)

typedef struct SceMsgDialogButtonsParam {
	const char *msg1;
	const char *msg2;
	char reserved[32];
} SceMsgDialogButtonsParam;

typedef struct SceMsgDialogUserMessageParam {
	SceMsgDialogButtonType buttonType;
	int :32;
	const char *msg;
	SceMsgDialogButtonsParam *buttonsParam;
	char reserved[24];
} SceMsgDialogUserMessageParam;

typedef int32_t SceMsgDialogProgressBarType;
#define SCE_MSG_DIALOG_PROGRESSBAR_TYPE_PERCENTAGE		(0)
#define SCE_MSG_DIALOG_PROGRESSBAR_TYPE_PERCENTAGE_CANCEL	(1)

typedef struct SceMsgDialogProgressBarParam {
	SceMsgDialogProgressBarType barType;
	int :32;
	const char *msg;
	char reserved[64];
} SceMsgDialogProgressBarParam;

typedef int32_t SceMsgDialogSystemMessageType;
#define SCE_MSG_DIALOG_SYSMSG_TYPE_TRC_EMPTY_STORE		(0)
#define SCE_MSG_DIALOG_SYSMSG_TYPE_TRC_PSN_CHAT_RESTRICTION	(1)
#define SCE_MSG_DIALOG_SYSMSG_TYPE_TRC_PSN_UGC_RESTRICTION	(2)

typedef struct SceMsgDialogSystemMessageParam {
	SceMsgDialogSystemMessageType sysMsgType;
	char reserved[32];
} SceMsgDialogSystemMessageParam;

typedef int SceUserServiceUserId;

typedef struct SceMsgDialogParam {
	SceCommonDialogBaseParam baseParam;
	size_t size;
	SceMsgDialogMode mode;
	int :32;
	SceMsgDialogUserMessageParam *userMsgParam;
	SceMsgDialogProgressBarParam *progBarParam;
	SceMsgDialogSystemMessageParam *sysMsgParam;
	SceUserServiceUserId userId;
	char reserved[40];
	int :32;
} SceMsgDialogParam;

typedef int32_t SceMsgDialogButtonId;
#define SCE_MSG_DIALOG_BUTTON_ID_INVALID			(0)
#define SCE_MSG_DIALOG_BUTTON_ID_OK				(1)
#define SCE_MSG_DIALOG_BUTTON_ID_YES				(1)
#define SCE_MSG_DIALOG_BUTTON_ID_NO				(2)
#define SCE_MSG_DIALOG_BUTTON_ID_BUTTON1			(1)
#define SCE_MSG_DIALOG_BUTTON_ID_BUTTON2			(2)

typedef struct SceMsgDialogResult {
	SceMsgDialogMode mode;
	int32_t result;
	SceMsgDialogButtonId buttonId;
	char reserved[32];
} SceMsgDialogResult;

typedef int32_t SceMsgDialogProgressBarTarget;
#define SCE_MSG_DIALOG_PROGRESSBAR_TARGET_BAR_DEFAULT		(0)

static inline
void sceMsgDialogParamInitialize(SceMsgDialogParam *param)
{
	memset( param, 0x0, sizeof(SceMsgDialogParam) );

	_sceCommonDialogBaseParamInit( &param->baseParam );
	param->size = sizeof(SceMsgDialogParam);
}

extern int32_t (*sceMsgDialogInitialize)(void);
extern int32_t (*sceMsgDialogTerminate)(void);
extern int32_t (*sceMsgDialogOpen)(const SceMsgDialogParam *param);
extern int32_t (*sceMsgDialogClose)(void);
extern int32_t (*sceMsgDialogGetResult)(SceMsgDialogResult *result);
extern SceCommonDialogStatus (*sceMsgDialogGetStatus)(void);
extern SceCommonDialogStatus (*sceMsgDialogUpdateStatus)(void);
extern int32_t (*sceMsgDialogProgressBarInc)(SceMsgDialogProgressBarTarget target, uint32_t delta);
extern int32_t (*sceMsgDialogProgressBarSetMsg)(SceMsgDialogProgressBarTarget target, const char *barMsg);
extern int32_t (*sceMsgDialogProgressBarSetValue)(SceMsgDialogProgressBarTarget target, uint32_t rate);

void initDialog(void);
