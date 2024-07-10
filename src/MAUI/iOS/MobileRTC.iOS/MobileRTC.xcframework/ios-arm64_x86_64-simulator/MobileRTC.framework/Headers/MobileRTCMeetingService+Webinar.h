//
//  MobileRTCMeetingService+Webinar.h
//  MobileRTC
//
//  Created by chaobai admin on 07/08/2018.
//  Copyright © 2019 Zoom Video Communications, Inc. All rights reserved.
//

#import <MobileRTC/MobileRTC.h>

@interface MobileRTCMeetingService (Webinar)

/*!
 @brief Query if the user has the privilege to prompt or demote users in the webinar. 
 @return YES means that user owns the privilege, otherwise not.
 */
- (BOOL)hasPromptAndDePromptPrivilege;

/*!
 @brief Prompt Attendee to Panelist in Webinar.
 @return YES means that the method is called successfully, otherwise not.
 @warning Only meeting host/co-host can run the function.
 */
- (BOOL)promptAttendee2Panelist:(NSUInteger)userID;

/*!
 @brief Demote the panelist to attendee. 
 @return YES means that the method is called successfully, otherwise not.
 @warning Only meeting host/co-host can run the function.
 */
- (BOOL)dePromptPanelist2Attendee:(NSUInteger)userID;

/*!
 @brief Set the chat privilege of the panelist.
 @param privilege The chat privilege of the panelist
 @return YES means sucessfull, otherwise not.
 @warning Only meeting host/co-host can run the function.
 @warning Only webinar meeting can run the function.
 */
- (BOOL)changePanelistChatPrivilege:(MobileRTCPanelistChatPrivilegeType)privilege;

/*!
 @brief Get the chat privilege of the panelist.
 @return The chat privilege of the panelist.
 */
- (MobileRTCPanelistChatPrivilegeType)getPanelistChatPrivilege;
/*!
 @brief Allow attendee to chat.
 @return YES means that the method is called successfully, otherwise not.
 @warning Only meeting host/co-host can run the function.
 @warning only webinar meeting can run the function.
 */
- (BOOL)allowAttendeeChat:(MobileRTCChatAllowAttendeeChat)privilegeType;

/*!
 @brief get webinar attendee chat privilege type.
 @return The chat privilege type for the  webinar attendee.
 */
- (MobileRTCChatAllowAttendeeChat)getWebinarAttendeeChatPrivilege;

/*!
 @brief Query if attendee is allowed to talk in Webinar Meeting.
 @param userID The ID of user to be allowed. 
 @return YES means allowed, otherwise not.
 @warning Only meeting host/co-host can run the function.
 */
- (BOOL)isAllowAttendeeTalk:(NSUInteger)userID;

/*!
 @brief Allow attendee to talk in webinar.
 @param userID The ID of user to be allowed
 @param enable Enable/Disable to talk
 @return YES means that the method is called successfully, otherwise not.
 @warning Only meeting host/co-host can run the function.
 */
- (BOOL)allowAttenddeTalk:(NSUInteger)userID allow:(BOOL)enable;

/*!
 @brief Query if Panelist can start video in Webinar Meeting.
 @return YES means able, otherwise not.
 */
- (BOOL)isAllowPanelistStartVideo;

/*!
 @brief Allow Panelist to start video in Webinar.
 @param enable Enable/Disable Panelist to start video.
 @return YES means that the method is called successfully, otherwise not.
 @warning Only meeting host/co-host can run the function.
 */
- (BOOL)allowPanelistStartVideo:(BOOL)enable;

/*!
 @brief Determine if current webinar supports emoji reactions.
 @return YES means the current webinar supports emoji reactions, NO means the feature is not supported.
 */
- (BOOL)isWebinarEmojiReactionSupported;

/*!
@brief Query if emoji reactions status.
@return webinar emoji reaction be allowed or not
*/
- (BOOL)isWebinarEmojiReactionAllowed;

/*!
 @brief permitted to use emoji reactions.
 @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise the function fails. To get extended error information, see \link MobileRTCSDKError \endlink enum.
 @warning  If the function succeeds, the user will receive the callback onAllowWebinarReactionStatusChanged:. Available only for the host.
*/
- (MobileRTCSDKError)allowWebinarEmojiReaction;

/*!
 @brief Forbid use of emoji reactions.
 @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise the function fails. To get extended error information, see \link MobileRTCSDKError \endlink enum.
 @warning  If the function succeeds, the user will receive the callback onAllowWebinarReactionStatusChanged:. Available only for the host.
*/
- (MobileRTCSDKError)disallowWebinarEmojiReaction;

/*!
 @brief Query if attendee raise hand status.
 @return webinar attendee allow to reaise hand or not.
*/
- (BOOL)isAttendeeRaiseHandAllowed;

/*!
 @brief The attendee is allowed to use the raise hand.
 @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise the function fails. To get extended error information, see \link MobileRTCSDKError \endlink enum.
 @warning If the function succeeds, the user will receive the callback onAllowAttendeeRiseHandStatusChanged:. Available only for the host.
*/
- (MobileRTCSDKError)allowAttendeeRaiseHand;

/*!
 @brief Do not letthe attendee to raise their hand.
 @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise the function fails. To get extended error information, see \link MobileRTCSDKError \endlink enum.
 @warning If the function succeeds, the user will receive the callback onAllowAttendeeRiseHandStatusChanged:. Available only for the host.
*/
- (MobileRTCSDKError)disallowAttendeeRaiseHand;

/*!
 @brief Query if attendee to view the participant count.
 @return If it allow, the return value is YES, otherwise NO.
*/
- (BOOL)isAttendeeViewTheParticipantCountAllowed;

/*!
 @brief The attendee is allow to view the participant count.
 @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise the function fails. To get extended error information, see \link MobileRTCSDKError \endlink enum.
 @warning If the function succeeds, the user will receive the onAllowAttendeeViewTheParticipantCountStatusChanged: callback event. Available only for the host.
*/
- (MobileRTCSDKError)allowAttendeeViewTheParticipantCount;

/*!
 @brief Forbid the attendee to view the participant count.
 @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise the function fails. To get extended error information, see \link MobileRTCSDKError \endlink enum.
 @warning If the function succeeds, the user will receive the onAllowAttendeeViewTheParticipantCountStatusChanged: callback event. Available only for the host.
*/
- (MobileRTCSDKError)disallowAttendeeViewTheParticipantCount;

/*!
 @brief Get the participant count.
 @return The count of participant.
*/
- (NSUInteger)getParticipantCount;

/**
 * @brief Set the view mode of the attendee.
 * @param mode The view mode of the attendee.
 * @return If the function succeeds, it will return MobileRTCSDKError_Success. Otherwise failed.
 * @warning Only for host call this api, only for zoom ui mode.
 */
- (MobileRTCSDKError)setAttendeeViewMode:(MobileRTCAttendeeViewMode)mode;

/**
 * @brief Get the view mode of the attendee.
 * @return If the function succeeds, it will return the attendee's view mode. For more details, see @{@link MobileRTCSDKAttendeeViewMode}.
 * @warning Only for host call this api, only for zoom ui mode.
 */
- (MobileRTCAttendeeViewMode)getAttendeeViewMode;

/*!
 @brief Get poll legal notices prompt.
 @return poll legal notices prompt.
 */
- (NSString *_Nullable)getPollLegalNoticesPrompt;

/*!
 @brief is polling legal notice available.
 @return available or not.
 */
- (BOOL)isPollingLegalNoticeAvailable;

/*!
 @brief Get poll legal notices explained.
 @return poll legal notices explained.
 */
- (NSString *_Nullable)getPollLegalNoticesExplained;

/*!
 @brief Get poll anonymous legal notices explained.
 @return poll anonymous legal notices explained.
 */
- (NSString *_Nullable)getPollAnonymousLegalNoticesExplained;

/**
 * @brief Get annotation over share legal notices prompt.
 * @return annotation over share legal notices prompt.
 */
- (NSString *_Nullable)getWebinarRegistrationLegalNoticesPrompt;

/**
 * @brief Get annotation over share legal notices explained.
 * @return annotation over share legal notices explained.
 */
- (MobileRTCWebinarRegistLegalNoticeContent *_Nullable)getWebinarRegistrationLegalNoticesExplained;

@end
