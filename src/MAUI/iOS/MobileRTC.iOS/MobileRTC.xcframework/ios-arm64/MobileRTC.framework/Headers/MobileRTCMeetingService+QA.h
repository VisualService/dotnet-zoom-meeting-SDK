//
//  MobileRTCMeetingService+QA.h
//  MobileRTC
//
//  Created by Zoom on 12/29/2023.
//  Copyright © 2019 Zoom Video Communications, Inc. All rights reserved.
//

#import <MobileRTC/MobileRTC.h>
#import <MobileRTC/MobileRTCQAItem.h>

@interface MobileRTCMeetingService (QA)

/*!
 @brief Query if Q&A is support of this meeting.
 @return YES means that Q&A is enabled, otherwise not.
 */
- (BOOL)isQAEnabled;

/*!
 @brief Set to enable/disable meeting QA.
 @param enable YES means enabled, NO disabled.
 @return If the function succeeds, it will return MobileRTCSDKError_Success. Otherwise failed.
 */
- (MobileRTCSDKError)enableMeetingQAFeature:(BOOL)enable;

/*!
 @brief Query if meeting QA is enabled in current meeting.
 @return YES means enabled, otherwise not.
 */
- (BOOL)isMeetingQAFeatureOn;

/*!
 @brief  Determine if the ask question is allowed by the host/co-host.
 @return If return YES means can ask question,otherwise not.
 */
- (BOOL)isAskQuestionEnabled;

/*!
 @brief Set attendee can ask question.
 @param enable If set YES means attendee can ask question,Otherwise not.
 @return If the function succeeds, it will return MobileRTCSDKError_Success. Otherwise failed.
 */
- (MobileRTCSDKError)enableAskQuestion:(BOOL)enable;
/*!
 @brief Set to present Zoom original Q&A ViewController.
 @param parentVC which use to present ViewController
 @return YES means that the method is called successfully, otherwise not.
 */
- (BOOL)presentQAViewController:(nonnull UIViewController*)parentVC;
/*!
 @brief Query if it is allowed to ask question anonymously in webinar.
 @return YES means allowed, otherwise not.
 */
- (BOOL)isAllowAskQuestionAnonymously;

/*!
 @brief Set if it is enabled to ask questions anonymously.
 @param enable Enable/Disable to ask questions anonymously.
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
 @param enable Enable/Disable attendee to view all questions.
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
 @param enable Allow/Disallow attendee to submit question.
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
 @param enable Allow/Disallow attendee to comment question.
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
 @param answerContent answer content.
 @return successs or not.
 @warning Only meeting host/co-host/panelist can run the function.
 */
- (BOOL)answerQuestionPrivate:(nonnull NSString *)questionID answerContent:(nonnull NSString *)answerContent;

/*!
 @brief Answer Quesion.
 @param questionID question id.
 @param answerContent question content.
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
@brief Get QA legal notices prompt.
@return QA legal notices prompt.
*/
- (NSString *_Nullable)getQALegalNoticesPrompt;

/*!
@brief Get QA legal notices explained.
@return QA legal notices explained.
*/
- (NSString *_Nullable)getQALegalNoticesExplained;


@end
