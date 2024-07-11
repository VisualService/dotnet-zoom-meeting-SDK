//
//  MobileRTCMeetingService+Chat.h
//  MobileRTC
//
//  Created by Zoom Video Communications on 2018/6/6.
//  Copyright © 2019 Zoom Video Communications, Inc. All rights reserved.
//

#import <MobileRTC/MobileRTC.h>

@interface MobileRTCMeetingService (Chat)

/*!
 @brief Query if the chat is disabled in the meeting.
 @return YES means disabled, otherwise not. 
 */
- (BOOL)isChatDisabled;

/*!
 @brief Query if it is able to send private chat in the meeting. 
 @return YES means disabled, otherwise not.
 */
- (BOOL)isPrivateChatDisabled;

/*!
 @brief Set Attendee Chat Priviledge when in-meeting
 @param privilege The chat privilege of the attendee
 @return YES means sucessfull, otherwise not.
 @warning Only meeting host/co-host can run the function.
 @warning only normal meeting(non webinar meeting) can run the function.
 */
- (BOOL)changeAttendeeChatPriviledge:(MobileRTCMeetingChatPriviledgeType)privilege;

/*!
 @brief get Attendee Chat Priviledge when in-meeting
 @return the result of attendee chat priviledge.
 */
- (MobileRTCMeetingChatPriviledgeType)getAttendeeChatPriviledge;

/*!
 @brief Is meeting chat legal notice available.
 @return available or not.
 */
- (BOOL)isMeetingChatLegalNoticeAvailable;

/*!
 @brief Get chat legal notice prompt.
 @return chat legal notice prompt.
 */
- (NSString *_Nullable)getChatLegalNoticesPrompt;

/*!
 @brief Get explained text for chat legal notice.
 @return explained text for chat legal notice.
 */
- (NSString *_Nullable)getChatLegalNoticesExplained;

/*!
 @brief Get in-meeting chat message. 
 @param messageID The ID of the message sent in the meeting.
 @return The instance of in-meeting chat.
 @warning The method is optional.
 */
- (nullable MobileRTCMeetingChat*)meetingChatByID:(nonnull NSString*)messageID;

/*!
 @brief Send a chat message.
 @param msg The chat message.
 @return The result of sending the message.
 */
- (MobileRTCSendChatError)sendChatMsg:(nullable MobileRTCMeetingChat *)msg;


/*!
 @brief Delete chat message by message id.
 @param msgId the message id.
 @return The result of delete the message.
 */
- (BOOL)deleteChatMessage:(nonnull NSString *)msgId;

/*!
 @brief Get all chat message id.
 @return The all chat message id list. nil means failed.
 */
- (nullable NSArray <NSString *> *)getAllChatMessageID;

/*!
 @brief Determine whether the message can be delete.
 @param msgId the message id.
 @return The result of  the message can be deleted.
 */
- (BOOL)isChatMessageCanBeDeleted:(nonnull NSString *)msgId;

/*!
 @brief Is share meeting chat legal notice available.
 @return available or not.
 @warning need call in meeting.
 */
- (BOOL)isShareMeetingChatLegalNoticeAvailable;

/*!
 @brief Get start share meeting chat legal notice content.
 @return start share chat legal notice content.
 */
- (NSString *_Nullable)getShareMeetingChatStartedLegalNoticeContent;

/*!
 @brief Get stop share meeting chat legal notice content.
 @return stop share chat legal notice content.
 */
- (NSString *_Nullable)getShareMeetingChatStoppedLegalNoticeContent;

#pragma mark - file transfer -
/*!
@brief Determine whether file transfer is enabled.
@return True if file transfer is enabled, otherwise false.
*/
- (BOOL)isFileTransferEnabled;

/*!
@brief Send file to specify user in current meeting.
@param filePath The absolute path of the file.
@param userId Send the file to this user.
@return If the function succeeds, the return value is MobileRTCSDKError_Success.
@warning This interface is related to chat privilege. See @{MobileRTCMeetingChatPriviledgeType}.
*/
- (MobileRTCSDKError)transferFile:(NSString * _Nullable)filePath toUser:(NSUInteger)userId;

/*!
@brief Send file to all users in current meeting.
@param filePath The local path of the file.
@return If the function succeeds, the return value is MobileRTCSDKError_Success.
@warning This interface is related to chat privilege. See @{MobileRTCMeetingChatPriviledgeType}.
*/
- (MobileRTCSDKError)transferFileToAll:(NSString * _Nullable)filePath;

/*!
@brief Get the list of allowed file types in transfer.
@return The value of allowed file types in transfer, comma-separated if there are multiple values. Exe files are by default forbidden from being transferred.
*/
- (NSString *_Nullable)getTransferFileTypeAllowList;

/*!
@brief Get the maximum size for file transfer.
@return The maximum number of bytes for file transfer.
*/
- (unsigned long long)getMaxTransferFileSize;

@end
