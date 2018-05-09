// +build !minimal

#pragma once

#ifndef GO_QTNFC_H
#define GO_QTNFC_H

#include <stdint.h>

#ifdef __cplusplus
int QNearFieldManager_QNearFieldManager_QRegisterMetaType();
int QNearFieldShareManager_QNearFieldShareManager_QRegisterMetaType();
int QNearFieldShareTarget_QNearFieldShareTarget_QRegisterMetaType();
int QNearFieldTarget_QNearFieldTarget_QRegisterMetaType();
int QQmlNdefRecord_QQmlNdefRecord_QRegisterMetaType();
extern "C" {
#endif

struct QtNfc_PackedString { char* data; long long len; };
struct QtNfc_PackedList { void* data; long long len; };
void* QNdefFilter_NewQNdefFilter();
void* QNdefFilter_NewQNdefFilter2(void* other);
void QNdefFilter_AppendRecord2(void* ptr, long long typeNameFormat, void* ty, unsigned int min, unsigned int max);
void QNdefFilter_Clear(void* ptr);
void QNdefFilter_SetOrderMatch(void* ptr, char on);
void QNdefFilter_DestroyQNdefFilter(void* ptr);
char QNdefFilter_OrderMatch(void* ptr);
int QNdefFilter_RecordCount(void* ptr);
void* QNdefMessage_QNdefMessage_FromByteArray(void* message);
void* QNdefMessage_NewQNdefMessage();
void* QNdefMessage_NewQNdefMessage4(void* records);
void* QNdefMessage_NewQNdefMessage3(void* message);
void* QNdefMessage_NewQNdefMessage2(void* record);
void* QNdefMessage_ToByteArray(void* ptr);
void* QNdefMessage___QNdefMessage_records_atList4(void* ptr, int i);
void QNdefMessage___QNdefMessage_records_setList4(void* ptr, void* i);
void* QNdefMessage___QNdefMessage_records_newList4(void* ptr);
void* QNdefMessage___QList_other_atList3(void* ptr, int i);
void QNdefMessage___QList_other_setList3(void* ptr, void* i);
void* QNdefMessage___QList_other_newList3(void* ptr);
void* QNdefMessage___QList_other_atList2(void* ptr, int i);
void QNdefMessage___QList_other_setList2(void* ptr, void* i);
void* QNdefMessage___QList_other_newList2(void* ptr);
void* QNdefMessage___fromSet_atList(void* ptr, int i);
void QNdefMessage___fromSet_setList(void* ptr, void* i);
void* QNdefMessage___fromSet_newList(void* ptr);
void* QNdefMessage___fromStdList_atList(void* ptr, int i);
void QNdefMessage___fromStdList_setList(void* ptr, void* i);
void* QNdefMessage___fromStdList_newList(void* ptr);
void* QNdefMessage___fromVector_atList(void* ptr, int i);
void QNdefMessage___fromVector_setList(void* ptr, void* i);
void* QNdefMessage___fromVector_newList(void* ptr);
void* QNdefMessage___fromVector_vector_atList(void* ptr, int i);
void QNdefMessage___fromVector_vector_setList(void* ptr, void* i);
void* QNdefMessage___fromVector_vector_newList(void* ptr);
void* QNdefMessage___append_value_atList2(void* ptr, int i);
void QNdefMessage___append_value_setList2(void* ptr, void* i);
void* QNdefMessage___append_value_newList2(void* ptr);
void* QNdefMessage___swap_other_atList(void* ptr, int i);
void QNdefMessage___swap_other_setList(void* ptr, void* i);
void* QNdefMessage___swap_other_newList(void* ptr);
void* QNdefMessage___mid_atList(void* ptr, int i);
void QNdefMessage___mid_setList(void* ptr, void* i);
void* QNdefMessage___mid_newList(void* ptr);
void* QNdefMessage___toVector_atList(void* ptr, int i);
void QNdefMessage___toVector_setList(void* ptr, void* i);
void* QNdefMessage___toVector_newList(void* ptr);
void* QNdefNfcSmartPosterRecord_NewQNdefNfcSmartPosterRecord();
void* QNdefNfcSmartPosterRecord_NewQNdefNfcSmartPosterRecord3(void* other);
void* QNdefNfcSmartPosterRecord_NewQNdefNfcSmartPosterRecord2(void* other);
char QNdefNfcSmartPosterRecord_AddTitle(void* ptr, void* text);
char QNdefNfcSmartPosterRecord_AddTitle2(void* ptr, struct QtNfc_PackedString text, struct QtNfc_PackedString locale, long long encoding);
char QNdefNfcSmartPosterRecord_RemoveIcon2(void* ptr, void* ty);
char QNdefNfcSmartPosterRecord_RemoveTitle(void* ptr, void* text);
char QNdefNfcSmartPosterRecord_RemoveTitle2(void* ptr, struct QtNfc_PackedString locale);
void QNdefNfcSmartPosterRecord_AddIcon2(void* ptr, void* ty, void* data);
void QNdefNfcSmartPosterRecord_SetAction(void* ptr, long long act);
void QNdefNfcSmartPosterRecord_SetSize(void* ptr, unsigned int size);
void QNdefNfcSmartPosterRecord_SetTitles(void* ptr, void* titles);
void QNdefNfcSmartPosterRecord_SetTypeInfo(void* ptr, void* ty);
void QNdefNfcSmartPosterRecord_SetUri(void* ptr, void* url);
void QNdefNfcSmartPosterRecord_SetUri2(void* ptr, void* url);
void QNdefNfcSmartPosterRecord_DestroyQNdefNfcSmartPosterRecord(void* ptr);
long long QNdefNfcSmartPosterRecord_Action(void* ptr);
void* QNdefNfcSmartPosterRecord_Icon(void* ptr, void* mimetype);
void* QNdefNfcSmartPosterRecord_TypeInfo(void* ptr);
void* QNdefNfcSmartPosterRecord_TitleRecord(void* ptr, int index);
void* QNdefNfcSmartPosterRecord_UriRecord(void* ptr);
struct QtNfc_PackedString QNdefNfcSmartPosterRecord_Title(void* ptr, struct QtNfc_PackedString locale);
void* QNdefNfcSmartPosterRecord_Uri(void* ptr);
char QNdefNfcSmartPosterRecord_HasAction(void* ptr);
char QNdefNfcSmartPosterRecord_HasIcon(void* ptr, void* mimetype);
char QNdefNfcSmartPosterRecord_HasSize(void* ptr);
char QNdefNfcSmartPosterRecord_HasTitle(void* ptr, struct QtNfc_PackedString locale);
char QNdefNfcSmartPosterRecord_HasTypeInfo(void* ptr);
int QNdefNfcSmartPosterRecord_IconCount(void* ptr);
int QNdefNfcSmartPosterRecord_TitleCount(void* ptr);
unsigned int QNdefNfcSmartPosterRecord_Size(void* ptr);
void* QNdefNfcSmartPosterRecord___setIcons_icons_newList(void* ptr);
void* QNdefNfcSmartPosterRecord___setTitles_titles_atList(void* ptr, int i);
void QNdefNfcSmartPosterRecord___setTitles_titles_setList(void* ptr, void* i);
void* QNdefNfcSmartPosterRecord___setTitles_titles_newList(void* ptr);
void* QNdefNfcSmartPosterRecord___iconRecords_newList(void* ptr);
void* QNdefNfcSmartPosterRecord___titleRecords_atList(void* ptr, int i);
void QNdefNfcSmartPosterRecord___titleRecords_setList(void* ptr, void* i);
void* QNdefNfcSmartPosterRecord___titleRecords_newList(void* ptr);
void* QNdefNfcTextRecord_NewQNdefNfcTextRecord();
void* QNdefNfcTextRecord_NewQNdefNfcTextRecord2(void* other);
void QNdefNfcTextRecord_SetEncoding(void* ptr, long long encoding);
void QNdefNfcTextRecord_SetLocale(void* ptr, struct QtNfc_PackedString locale);
void QNdefNfcTextRecord_SetText(void* ptr, struct QtNfc_PackedString text);
long long QNdefNfcTextRecord_Encoding(void* ptr);
struct QtNfc_PackedString QNdefNfcTextRecord_Locale(void* ptr);
struct QtNfc_PackedString QNdefNfcTextRecord_Text(void* ptr);
void* QNdefNfcUriRecord_NewQNdefNfcUriRecord();
void* QNdefNfcUriRecord_NewQNdefNfcUriRecord2(void* other);
void QNdefNfcUriRecord_SetUri(void* ptr, void* uri);
void* QNdefNfcUriRecord_Uri(void* ptr);
void* QNdefRecord_NewQNdefRecord();
void* QNdefRecord_NewQNdefRecord2(void* other);
void QNdefRecord_SetId(void* ptr, void* id);
void QNdefRecord_SetPayload(void* ptr, void* payload);
void QNdefRecord_SetType(void* ptr, void* ty);
void QNdefRecord_SetTypeNameFormat(void* ptr, long long typeNameFormat);
void QNdefRecord_DestroyQNdefRecord(void* ptr);
void* QNdefRecord_Id(void* ptr);
void* QNdefRecord_Payload(void* ptr);
void* QNdefRecord_Type(void* ptr);
long long QNdefRecord_TypeNameFormat(void* ptr);
char QNdefRecord_IsEmpty(void* ptr);
char QNearFieldManager_StartTargetDetection(void* ptr);
void* QNearFieldManager_NewQNearFieldManager(void* parent);
char QNearFieldManager_UnregisterNdefMessageHandler(void* ptr, int handlerId);
int QNearFieldManager_RegisterNdefMessageHandler2(void* ptr, long long typeNameFormat, void* ty, void* object, char* method);
int QNearFieldManager_RegisterNdefMessageHandler(void* ptr, void* object, char* method);
int QNearFieldManager_RegisterNdefMessageHandler3(void* ptr, void* filter, void* object, char* method);
void QNearFieldManager_SetTargetAccessModes(void* ptr, long long accessModes);
void QNearFieldManager_StopTargetDetection(void* ptr);
void QNearFieldManager_ConnectTargetDetected(void* ptr);
void QNearFieldManager_DisconnectTargetDetected(void* ptr);
void QNearFieldManager_TargetDetected(void* ptr, void* target);
void QNearFieldManager_ConnectTargetLost(void* ptr);
void QNearFieldManager_DisconnectTargetLost(void* ptr);
void QNearFieldManager_TargetLost(void* ptr, void* target);
void QNearFieldManager_DestroyQNearFieldManager(void* ptr);
long long QNearFieldManager_TargetAccessModes(void* ptr);
char QNearFieldManager_IsAvailable(void* ptr);
void* QNearFieldManager___dynamicPropertyNames_atList(void* ptr, int i);
void QNearFieldManager___dynamicPropertyNames_setList(void* ptr, void* i);
void* QNearFieldManager___dynamicPropertyNames_newList(void* ptr);
void* QNearFieldManager___findChildren_atList2(void* ptr, int i);
void QNearFieldManager___findChildren_setList2(void* ptr, void* i);
void* QNearFieldManager___findChildren_newList2(void* ptr);
void* QNearFieldManager___findChildren_atList3(void* ptr, int i);
void QNearFieldManager___findChildren_setList3(void* ptr, void* i);
void* QNearFieldManager___findChildren_newList3(void* ptr);
void* QNearFieldManager___findChildren_atList(void* ptr, int i);
void QNearFieldManager___findChildren_setList(void* ptr, void* i);
void* QNearFieldManager___findChildren_newList(void* ptr);
void* QNearFieldManager___children_atList(void* ptr, int i);
void QNearFieldManager___children_setList(void* ptr, void* i);
void* QNearFieldManager___children_newList(void* ptr);
char QNearFieldManager_EventDefault(void* ptr, void* e);
char QNearFieldManager_EventFilterDefault(void* ptr, void* watched, void* event);
void QNearFieldManager_ChildEventDefault(void* ptr, void* event);
void QNearFieldManager_ConnectNotifyDefault(void* ptr, void* sign);
void QNearFieldManager_CustomEventDefault(void* ptr, void* event);
void QNearFieldManager_DeleteLaterDefault(void* ptr);
void QNearFieldManager_DisconnectNotifyDefault(void* ptr, void* sign);
void QNearFieldManager_TimerEventDefault(void* ptr, void* event);
void* QNearFieldManager_MetaObjectDefault(void* ptr);
void* QNearFieldShareManager_NewQNearFieldShareManager(void* parent);
long long QNearFieldShareManager_QNearFieldShareManager_SupportedShareModes();
void QNearFieldShareManager_ConnectError(void* ptr);
void QNearFieldShareManager_DisconnectError(void* ptr);
void QNearFieldShareManager_Error(void* ptr, long long error);
void QNearFieldShareManager_SetShareModes(void* ptr, long long mode);
void QNearFieldShareManager_ConnectShareModesChanged(void* ptr);
void QNearFieldShareManager_DisconnectShareModesChanged(void* ptr);
void QNearFieldShareManager_ShareModesChanged(void* ptr, long long modes);
void QNearFieldShareManager_ConnectTargetDetected(void* ptr);
void QNearFieldShareManager_DisconnectTargetDetected(void* ptr);
void QNearFieldShareManager_TargetDetected(void* ptr, void* shareTarget);
void QNearFieldShareManager_DestroyQNearFieldShareManager(void* ptr);
long long QNearFieldShareManager_ShareError(void* ptr);
long long QNearFieldShareManager_ShareModes(void* ptr);
void* QNearFieldShareManager___dynamicPropertyNames_atList(void* ptr, int i);
void QNearFieldShareManager___dynamicPropertyNames_setList(void* ptr, void* i);
void* QNearFieldShareManager___dynamicPropertyNames_newList(void* ptr);
void* QNearFieldShareManager___findChildren_atList2(void* ptr, int i);
void QNearFieldShareManager___findChildren_setList2(void* ptr, void* i);
void* QNearFieldShareManager___findChildren_newList2(void* ptr);
void* QNearFieldShareManager___findChildren_atList3(void* ptr, int i);
void QNearFieldShareManager___findChildren_setList3(void* ptr, void* i);
void* QNearFieldShareManager___findChildren_newList3(void* ptr);
void* QNearFieldShareManager___findChildren_atList(void* ptr, int i);
void QNearFieldShareManager___findChildren_setList(void* ptr, void* i);
void* QNearFieldShareManager___findChildren_newList(void* ptr);
void* QNearFieldShareManager___children_atList(void* ptr, int i);
void QNearFieldShareManager___children_setList(void* ptr, void* i);
void* QNearFieldShareManager___children_newList(void* ptr);
char QNearFieldShareManager_EventDefault(void* ptr, void* e);
char QNearFieldShareManager_EventFilterDefault(void* ptr, void* watched, void* event);
void QNearFieldShareManager_ChildEventDefault(void* ptr, void* event);
void QNearFieldShareManager_ConnectNotifyDefault(void* ptr, void* sign);
void QNearFieldShareManager_CustomEventDefault(void* ptr, void* event);
void QNearFieldShareManager_DeleteLaterDefault(void* ptr);
void QNearFieldShareManager_DisconnectNotifyDefault(void* ptr, void* sign);
void QNearFieldShareManager_TimerEventDefault(void* ptr, void* event);
void* QNearFieldShareManager_MetaObjectDefault(void* ptr);
char QNearFieldShareTarget_Share2(void* ptr, void* files);
char QNearFieldShareTarget_Share(void* ptr, void* message);
void QNearFieldShareTarget_Cancel(void* ptr);
void QNearFieldShareTarget_ConnectError(void* ptr);
void QNearFieldShareTarget_DisconnectError(void* ptr);
void QNearFieldShareTarget_Error(void* ptr, long long error);
void QNearFieldShareTarget_ConnectShareFinished(void* ptr);
void QNearFieldShareTarget_DisconnectShareFinished(void* ptr);
void QNearFieldShareTarget_ShareFinished(void* ptr);
void QNearFieldShareTarget_DestroyQNearFieldShareTarget(void* ptr);
long long QNearFieldShareTarget_ShareError(void* ptr);
long long QNearFieldShareTarget_ShareModes(void* ptr);
char QNearFieldShareTarget_IsShareInProgress(void* ptr);
void* QNearFieldShareTarget___share_files_atList2(void* ptr, int i);
void QNearFieldShareTarget___share_files_setList2(void* ptr, void* i);
void* QNearFieldShareTarget___share_files_newList2(void* ptr);
void* QNearFieldShareTarget___dynamicPropertyNames_atList(void* ptr, int i);
void QNearFieldShareTarget___dynamicPropertyNames_setList(void* ptr, void* i);
void* QNearFieldShareTarget___dynamicPropertyNames_newList(void* ptr);
void* QNearFieldShareTarget___findChildren_atList2(void* ptr, int i);
void QNearFieldShareTarget___findChildren_setList2(void* ptr, void* i);
void* QNearFieldShareTarget___findChildren_newList2(void* ptr);
void* QNearFieldShareTarget___findChildren_atList3(void* ptr, int i);
void QNearFieldShareTarget___findChildren_setList3(void* ptr, void* i);
void* QNearFieldShareTarget___findChildren_newList3(void* ptr);
void* QNearFieldShareTarget___findChildren_atList(void* ptr, int i);
void QNearFieldShareTarget___findChildren_setList(void* ptr, void* i);
void* QNearFieldShareTarget___findChildren_newList(void* ptr);
void* QNearFieldShareTarget___children_atList(void* ptr, int i);
void QNearFieldShareTarget___children_setList(void* ptr, void* i);
void* QNearFieldShareTarget___children_newList(void* ptr);
char QNearFieldShareTarget_EventDefault(void* ptr, void* e);
char QNearFieldShareTarget_EventFilterDefault(void* ptr, void* watched, void* event);
void QNearFieldShareTarget_ChildEventDefault(void* ptr, void* event);
void QNearFieldShareTarget_ConnectNotifyDefault(void* ptr, void* sign);
void QNearFieldShareTarget_CustomEventDefault(void* ptr, void* event);
void QNearFieldShareTarget_DeleteLaterDefault(void* ptr);
void QNearFieldShareTarget_DisconnectNotifyDefault(void* ptr, void* sign);
void QNearFieldShareTarget_TimerEventDefault(void* ptr, void* event);
void* QNearFieldShareTarget_MetaObjectDefault(void* ptr);
void* QNearFieldTarget_NewQNearFieldTarget(void* parent);
char QNearFieldTarget_Disconnect(void* ptr);
char QNearFieldTarget_HasNdefMessage(void* ptr);
char QNearFieldTarget_HasNdefMessageDefault(void* ptr);
char QNearFieldTarget_SetKeepConnection(void* ptr, char isPersistent);
void QNearFieldTarget_ConnectDisconnected(void* ptr);
void QNearFieldTarget_DisconnectDisconnected(void* ptr);
void QNearFieldTarget_Disconnected(void* ptr);
void QNearFieldTarget_ConnectNdefMessageRead(void* ptr);
void QNearFieldTarget_DisconnectNdefMessageRead(void* ptr);
void QNearFieldTarget_NdefMessageRead(void* ptr, void* message);
void QNearFieldTarget_ConnectNdefMessagesWritten(void* ptr);
void QNearFieldTarget_DisconnectNdefMessagesWritten(void* ptr);
void QNearFieldTarget_NdefMessagesWritten(void* ptr);
void QNearFieldTarget_DestroyQNearFieldTarget(void* ptr);
void QNearFieldTarget_DestroyQNearFieldTargetDefault(void* ptr);
long long QNearFieldTarget_AccessMethods(void* ptr);
void* QNearFieldTarget_Uid(void* ptr);
void* QNearFieldTarget_Url(void* ptr);
void* QNearFieldTarget_UrlDefault(void* ptr);
long long QNearFieldTarget_Type(void* ptr);
char QNearFieldTarget_IsProcessingCommand(void* ptr);
char QNearFieldTarget_KeepConnection(void* ptr);
int QNearFieldTarget_MaxCommandLength(void* ptr);
void* QNearFieldTarget___sendCommands_commands_atList(void* ptr, int i);
void QNearFieldTarget___sendCommands_commands_setList(void* ptr, void* i);
void* QNearFieldTarget___sendCommands_commands_newList(void* ptr);
void* QNearFieldTarget___writeNdefMessages_messages_atList(void* ptr, int i);
void QNearFieldTarget___writeNdefMessages_messages_setList(void* ptr, void* i);
void* QNearFieldTarget___writeNdefMessages_messages_newList(void* ptr);
void* QNearFieldTarget___dynamicPropertyNames_atList(void* ptr, int i);
void QNearFieldTarget___dynamicPropertyNames_setList(void* ptr, void* i);
void* QNearFieldTarget___dynamicPropertyNames_newList(void* ptr);
void* QNearFieldTarget___findChildren_atList2(void* ptr, int i);
void QNearFieldTarget___findChildren_setList2(void* ptr, void* i);
void* QNearFieldTarget___findChildren_newList2(void* ptr);
void* QNearFieldTarget___findChildren_atList3(void* ptr, int i);
void QNearFieldTarget___findChildren_setList3(void* ptr, void* i);
void* QNearFieldTarget___findChildren_newList3(void* ptr);
void* QNearFieldTarget___findChildren_atList(void* ptr, int i);
void QNearFieldTarget___findChildren_setList(void* ptr, void* i);
void* QNearFieldTarget___findChildren_newList(void* ptr);
void* QNearFieldTarget___children_atList(void* ptr, int i);
void QNearFieldTarget___children_setList(void* ptr, void* i);
void* QNearFieldTarget___children_newList(void* ptr);
char QNearFieldTarget_EventDefault(void* ptr, void* e);
char QNearFieldTarget_EventFilterDefault(void* ptr, void* watched, void* event);
void QNearFieldTarget_ChildEventDefault(void* ptr, void* event);
void QNearFieldTarget_ConnectNotifyDefault(void* ptr, void* sign);
void QNearFieldTarget_CustomEventDefault(void* ptr, void* event);
void QNearFieldTarget_DeleteLaterDefault(void* ptr);
void QNearFieldTarget_DisconnectNotifyDefault(void* ptr, void* sign);
void QNearFieldTarget_TimerEventDefault(void* ptr, void* event);
void* QNearFieldTarget_MetaObjectDefault(void* ptr);
void QQmlNdefRecord_ConnectRecordChanged(void* ptr);
void QQmlNdefRecord_DisconnectRecordChanged(void* ptr);
void QQmlNdefRecord_RecordChanged(void* ptr);
void QQmlNdefRecord_SetRecord(void* ptr, void* record);
void* QQmlNdefRecord_Record(void* ptr);
long long QQmlNdefRecord_TypeNameFormat(void* ptr);
void* QQmlNdefRecord_NewQQmlNdefRecord(void* parent);
void* QQmlNdefRecord_NewQQmlNdefRecord2(void* record, void* parent);
void QQmlNdefRecord_SetType(void* ptr, struct QtNfc_PackedString newtype);
void QQmlNdefRecord_SetTypeNameFormat(void* ptr, long long newTypeNameFormat);
void QQmlNdefRecord_ConnectTypeChanged(void* ptr);
void QQmlNdefRecord_DisconnectTypeChanged(void* ptr);
void QQmlNdefRecord_TypeChanged(void* ptr);
void QQmlNdefRecord_ConnectTypeNameFormatChanged(void* ptr);
void QQmlNdefRecord_DisconnectTypeNameFormatChanged(void* ptr);
void QQmlNdefRecord_TypeNameFormatChanged(void* ptr);
void QQmlNdefRecord_DestroyQQmlNdefRecord(void* ptr);
struct QtNfc_PackedString QQmlNdefRecord_Type(void* ptr);
void* QQmlNdefRecord___dynamicPropertyNames_atList(void* ptr, int i);
void QQmlNdefRecord___dynamicPropertyNames_setList(void* ptr, void* i);
void* QQmlNdefRecord___dynamicPropertyNames_newList(void* ptr);
void* QQmlNdefRecord___findChildren_atList2(void* ptr, int i);
void QQmlNdefRecord___findChildren_setList2(void* ptr, void* i);
void* QQmlNdefRecord___findChildren_newList2(void* ptr);
void* QQmlNdefRecord___findChildren_atList3(void* ptr, int i);
void QQmlNdefRecord___findChildren_setList3(void* ptr, void* i);
void* QQmlNdefRecord___findChildren_newList3(void* ptr);
void* QQmlNdefRecord___findChildren_atList(void* ptr, int i);
void QQmlNdefRecord___findChildren_setList(void* ptr, void* i);
void* QQmlNdefRecord___findChildren_newList(void* ptr);
void* QQmlNdefRecord___children_atList(void* ptr, int i);
void QQmlNdefRecord___children_setList(void* ptr, void* i);
void* QQmlNdefRecord___children_newList(void* ptr);
char QQmlNdefRecord_EventDefault(void* ptr, void* e);
char QQmlNdefRecord_EventFilterDefault(void* ptr, void* watched, void* event);
void QQmlNdefRecord_ChildEventDefault(void* ptr, void* event);
void QQmlNdefRecord_ConnectNotifyDefault(void* ptr, void* sign);
void QQmlNdefRecord_CustomEventDefault(void* ptr, void* event);
void QQmlNdefRecord_DeleteLaterDefault(void* ptr);
void QQmlNdefRecord_DisconnectNotifyDefault(void* ptr, void* sign);
void QQmlNdefRecord_TimerEventDefault(void* ptr, void* event);
void* QQmlNdefRecord_MetaObjectDefault(void* ptr);

#ifdef __cplusplus
}
#endif

#endif