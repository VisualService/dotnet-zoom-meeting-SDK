//
//  MobileRTCMeetingService+Webinar.h
//  MobileRTC
//
//  Created by chaobai admin on 07/08/2018.
//  Copyright © 2019 Zoom Video Communications, Inc. All rights reserved.
//

#import <MobileRTC/MobileRTC.h>
#import "MobileRTCQAItem.h"

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
 @param userId The ID of user to be allowed. 
 @return YES means allowed, otherwise not.
 @warning Only meeting host/co-host can run the function.
 */
- (BOOL)isAllowAttendeeTalk:(NSUInteger)userID;

/*!
 @brief Allow attendee to talk in webinar.
 @param userId The ID of user to be allowed
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

#pragma mark Q&A relate Action in Webinar Meeting
/*!
 @brief Query if it is allowed to ask question anonymously in webinar.
 @return YES means allowed, otherwise not.
 */
- (BOOL)isAllowAskQuestionAnonymously;

/*!
 @brief Set if it is enabled to ask questions anonymously.
 @param Enable Enable/Disable to ask questions anonymously.
 @return YES means that the method is called successfully, otherwise not.
 @warning Only meeting host/co-host can run this function.
 */
- (BOOL)allowAskQuestionAnonymously:(BOOL)enable;

/*!
 @brief Query if attendee is allowed to view all question.
 @return YES means allowed, otherwise not.
 */
- (BOOL)isAllowAttendeeViewAllQuestion;

/*!
 @brief Allow attendee to view all question.
 @param Enable Enable/Disable attendee to view all questions.
 @return YES means that the method is called successfully, otherwise not.
 @warning Only meeting host/co-host can run this function.
 */
- (BOOL)allowAttendeeViewAllQuestion:(BOOL)enable;

/*!
 @brief Query if attendee is allowed to submit questions. 
 @return YES means allowed, otherwise not.
 */
- (BOOL)isAllowAttendeeUpVoteQuestion;

/*!
 @brief Allow attendee to submit questions.
 @param Enable Allow/Disallow attendee to submit question.
 @return YES means that the method is called successfully, otherwise not.
 @warning Only meeting host/co-host can run the function.
 */
- (BOOL)allowAttendeeUpVoteQuestion:(BOOL)enable;

/*!
 @brief Query if attendee is allowed to comment questions.
 @return YES means allowed, otherwise not.
 */
- (BOOL)isAllowCommentQuestion;

/*!
 @brief Allow attendee to comment question.
 @param Enable Allow/Disallow attendee to comment question.
 @return YES means that the method is called successfully, otherwise not.
 @warning Only meeting host/co-host can run the function.
 */
- (BOOL)allowCommentQuestion:(BOOL)enable;

/*!
 @brief Get all questions.
 @return All questions list.
 */
- (nullable NSArray <MobileRTCQAItem *> *)getAllQuestionList;

/*!
 @brief Get My questions.
 @return My questions list.
 @warning Only attendee can run the function.
 */
- (nullable NSArray <MobileRTCQAItem *> *)getMyQuestionList;

/*!
 @brief Get Open questions.
 @return Open questions list.
 @warning Only meeting host/co-host/panelist can run the function.
 */
- (nullable NSArray <MobileRTCQAItem *> *)getOpenQuestionList;

/*!
 @brief Get Dismissed questions.
 @return Dismissed questions list.
 @warning Only meeting host/co-host/panelist can run the function.
 */
- (nullable NSArray <MobileRTCQAItem *> *)getDismissedQuestionList;

/*!
 @brief Get Answered questions.
 @return Answered questions list.
 @warning Only meeting host/co-host/panelist can run the function.
 */
- (nullable NSArray <MobileRTCQAItem *> *)getAnsweredQuestionList;

/*!
 @brief Get the amount of all questions.
 @return Amount of all questions.
 */
- (int)getALLQuestionCount;

/*!
 @brief Get the amount of my questions.
 @return Amount of open-ended questions.
 */
- (int)getMyQuestionCount;

/*!
 @brief Get the amount of Open questions.
 @return Amount of open-ended questions.
 */
- (int)getOpenQuestionCount;

/*!
 @brief Get the amount of dissmissed questions.
 @return Amount of open-ended questions.
 */
- (int)getDismissedQuestionCount;

/*!
 @brief Get the amount of answered questions.
 @return Amount of open-ended questions.
 */
- (int)getAnsweredQuestionCount;

/*!
 @brief get question item by questionID.
 @param questionID question id.
 @return the question item.
 */
- (nullable MobileRTCQAItem *)getQuestion:(nonnull NSString *)questionID;

/*!
 @brief get answer item by questionID.
 @param answerID answer id.
 @return the answer item.
 */
- (nullable MobileRTCQAAnswerItem *)getAnswer:(nonnull NSString *)answerID;

/*!
 @brief Add Quesion.
 @param content question content.
 @param anonymous if true anonymously.
 @return successs or not.
 @warning Only attendee can run the function.
 */
- (BOOL)addQuestion:(nonnull NSString *)content anonymous:(BOOL)anonymous;

/*!
 @brief Answer quesion in private.
 @param questionID question id.
 @param content question content.
 @param destUserID destination userId.
 @return successs or not.
 @warning Only meeting host/co-host/panelist can run the function.
 */
- (BOOL)answerQuestionPrivate:(nonnull NSString *)questionID answerContent:(nonnull NSString *)answerContent;

/*!
 @brief Answer Quesion.
 @param questionID question id.
 @param content question content.
 @return successs or not.
 @warning Only meeting host/co-host/panelist can run the function.
 */
- (BOOL)answerQuestionPublic:(nonnull NSString *)questionID answerContent:(nonnull NSString *)answerContent;

/*!
 @brief Attendee comment Quesion.
 @param questionID question id.
 @param commentContent comment content.
 @return successs or not.
 @warning Only meeting attendee can run the function.
 */
- (BOOL)commentQuestion:(nonnull NSString *)questionID commentContent:(nonnull NSString *)commentContent;

/*!
 @brief Dismiss Quesion.
 @param questionID question id.
 @return successs or not.
 @warning Only meeting host/co-host/panelist can run the function.
 */
- (BOOL)dismissQuestion:(nonnull NSString *)questionID;

/*!
 @brief Reopen Quesion.
 @param questionID question id.
 @return successs or not.
 @warning Only meeting host/co-host/panelist can run the function.
 */
- (BOOL)reopenQuestion:(nonnull NSString *)questionID;

/*!
 @brief Vote up Quesion.
 @param questionID question id.
 @return successs or not.
 @warning Only meeting host/co-host/panelist can run the function.
 */
- (BOOL)voteupQuestion:(nonnull NSString *)questionID voteup:(BOOL)voteup;

/*!
 @brief startLiving Quesion.
 @param questionID question id.
 @return successs or not.
 @warning Only meeting host/co-host/panelist can run the function.
 */
- (BOOL)startLiving:(nonnull NSString *)questionID;

/*!
 @brief endLiving Quesion.
 @param questionID question id.
 @return successs or not.
 @warning Only meeting host/co-host/panelist can run the function.
 */
- (BOOL)endLiving:(nonnull NSString *)questionID;

/*!
 @brief delete Quesion.
 @param questionID question id.
 @return successs or not.
 @warning Only meeting host/co-host/panelist can run the function.
 */
- (BOOL)deleteQuestion:(nonnull NSString *)questionID;

/*!
 @brief delete answerID.
 @param answerID answerID id.
 @return successs or not.
 @warning Only meeting host/co-host/panelist can run the function.
 */
- (BOOL)deleteAnswer:(nonnull NSString *)answerID;

/*!
@brief Is QA legal notice available.
@return available or not.
*/
- (BOOL)isQALegalNoticeAvailable;

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
@brief Get QA legal notices prompt.
@return QA legal notices prompt.
*/
- (NSString *_Nullable)getQALegalNoticesPrompt;

/*!
@brief Get QA legal notices explained.
@return QA legal notices explained.
*/
- (NSString *_Nullable)getQALegalNoticesExplained;

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
