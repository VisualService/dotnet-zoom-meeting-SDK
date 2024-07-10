//
//  MobileRTCMeetingService+Polling.h
//  MobileRTC
//
//  Created by Zoom on 2023/11/29.
//  Copyright © 2023 Zoom Video Communications, Inc. All rights reserved.
//

#import <MobileRTC/MobileRTC.h>


@interface MobileRTCPollingItem : NSObject
- (NSString *_Nullable)getPollingID;
- (NSString *_Nullable)getPollingName;
- (MobileRTCPollingType)getPollingType;
- (MobileRTCPollingStatus)getPollingStatus;
- (NSInteger)getPollingQuestionCount;
- (NSInteger)getTotalVotedUserCount;
- (BOOL)isLibraryPolling;
@end

@interface MobileRTCPollingAnswerItem : NSObject
- (NSString *_Nullable)getPollingID;
- (NSString *_Nullable)getPollingQuestionID;
- (NSString *_Nullable)getPollingSubQuestionID;
- (NSString *_Nullable)getPollingAnswerID;
- (NSString *_Nullable)getPollingAnswerName;
- (NSString *_Nullable)getPollingAnsweredContent;
- (BOOL)isChecked; //This property has no meaning for the correct answer.
@end

@interface MobileRTCPollingQuestionItem : NSObject
- (NSString *_Nullable)getPollingID;
- (NSString *_Nullable)getPollingQuestionID;
- (NSString *_Nullable)getPollingQuestionName;
- (MobileRTCPollingQuestionType)getPollingQuestionType;
- (NSInteger)getAnsweredCount;
- (BOOL)isRequired;
- (NSArray <MobileRTCPollingQuestionItem *> * _Nullable)getPollingSubQuestionItemList;
- (NSArray <MobileRTCPollingAnswerItem *> * _Nullable)getPollingAnswerItemList;
@end

@interface MobileRTCPollingAnswerResultItem : NSObject
- (NSString *_Nullable)getPollingID;
- (NSString *_Nullable)getPollingQuestionID;
- (NSString *_Nullable)getPollingSubQuestionID;
- (NSString *_Nullable)getPollingAnswerID;
- (NSString *_Nullable)getPollingAnswerName;
- (NSInteger)getSelectedCount;
@end


@interface MobileRTCMeetingService (Polling)

#pragma mark - for all users -
/*!
 * @brief Determine whether the current meeting can do the polling.
 * @return True indicates you can do polling.
 */
- (BOOL)canDoPolling;

/*!
 * @brief Get the active poll's ID.
 * @return The shared result or started poll's ID.
 */
- (NSString *_Nullable)getActivePollingID;

/*!
 * @brief Get the list of polling question's subquestion.
 * @param pollingID pollingID Specify the question's polling ID.
 * @return If the function succeeds, the return value is NSArray<MobileRTCPollingQuestionItem*>. Otherwise, the return value is nil.
 */
- (NSArray <MobileRTCPollingQuestionItem *> * _Nullable)getPollingQuestionItemList:(NSString *_Nullable)pollingID;

/*!
 * @brief Determine if the right answer item list can be allowed to get.
 * @param pollingID Specify the right answer's polling ID.
 * @return Yes means can get th right.
 */
- (BOOL)canGetRightAnswerItemList:(NSString *_Nullable)pollingID;

/*!
 * @brief Get the list of polling question or subquestion's right answer.
 * @param pollingID Specify the right answer's polling ID.
 * @return If the function succeeds, the return value is NSArray<MobileRTCPollingAnswerItem*>. Otherwise, the return value is nil.
 */
- (NSArray <MobileRTCPollingAnswerItem *> * _Nullable)getPollingRightAnswerItemList:(NSString *_Nullable)pollingID;

/*!
 * @brief Determine if the answer result list can be show.
 * @param pollingID Specify the right answer's polling ID.
 * @return Yes means can show the answer list.
 */
- (BOOL)canShowAnswerResultList:(NSString *_Nullable)pollingID;

/*!
 * @brief Get the list of polling answer result item.
 * @param pollingID Specify the right answer's polling ID.
 * @return If the function succeeds, the return value is NSArray<MobileRTCPollingAnswerResultItem*>. Otherwise, the return value is nil.
 */
- (NSArray <MobileRTCPollingAnswerResultItem *> * _Nullable)getPollingAnswerResultItemList:(NSString *_Nullable)pollingID;

/*!
 * @brief Get the polling item object of specified polling ID.
 * @param pollingID Specify the polling ID for which you want to get the information.
 * @return If the function succeeds, the return value is MobileRTCPollingItem. Otherwise, the return value is nil.
 */
- (MobileRTCPollingItem * _Nullable)getPollingItemByID:(NSString *_Nullable)pollingID;

/*!
 * @brief Get the polling question's image path.
 * @param pollingID Specify the answer's polling ID.
 * @param questionID Specify the answer's question ID.
 * @return If the function succeeds, the return value is the question's image path, Otherwise the function fails, and the return value is nil.
 */
- (NSString *_Nullable)getPollingQuestionImagePath:(NSString *_Nullable)pollingID questionID:(NSString *_Nullable)questionID;

/*!
 * @brief Get the polling question's minimum length.
 * @param pollingID Specify the poll's polling ID.
 * @param questionID Specify the question's question ID.
 * @return the integer value of question's minimum length.
 */
- (NSInteger)getQuestionCharactersMinLen:(NSString*_Nullable)pollingID questionID:(NSString*_Nullable)questionID;

/*!
 * @brief Get the polling question's maximum length.
 * @param pollingID Specify the poll's polling ID.
 * @param questionID Specify the question's question ID.
 * @return the integer value of question's maximum length.
 */
- (NSInteger)getQuestionCharactersMaxLen:(NSString*_Nullable)pollingID questionID:(NSString*_Nullable)questionID;

/*!
 * @brief Determine if the question is case sensitive.
 * @param pollingID Specify the question's polling ID.
 * @param questionID Specify the question's question ID..
 * @return This function can only be used by fill blank questions..
 */
- (BOOL)isQuestionCaseSensitive:(NSString *_Nullable)pollingID questionID:(NSString *_Nullable)questionID;

#pragma mark - for host -

/*!
 * @brief Determine if the host can add polling.
 * @return The result of it.
 * @warning Only the origin host can add polling.
 */
- (BOOL)canAddPolling;

/*!
 * @brief Create polling in a web browser.
 * @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise the function fails. To get extended error information, see \link MobileRTCSDKError \endlink enum.
 */
- (MobileRTCSDKError)addPolling;

/*!
 * @brief Determine if the host can edit polling.
 * @param pollingID Specify the edit poll's polling ID.
 * @return Can edit or not.
 * @warning Only the origin host can edit polling.
 */
- (BOOL)canEditPolling:(NSString *_Nullable)pollingID;

/*!
 * @brief Open edit polling in a web browser.
 * @param pollingID Specify the edit poll's polling ID.
 * @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise the function fails. To get extended error information, see \link MobileRTCSDKError \endlink enum.
 */
- (MobileRTCSDKError)editPolling:(NSString *_Nullable)pollingID;

/*!
 * @brief Determine if the host can delete polling.
 * @param pollingID Specify the edit poll's polling ID.
 * @return Can delete the polling or not.
 * @warning Only the origin host can delete polling.
 */
- (BOOL)canDeletePolling:(NSString *_Nullable)pollingID;

/*!
 * @brief Delete the polling.
 * @param pollingID Specify the edit poll's polling ID.
 * @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise the function fails. To get extended error information, see \link MobileRTCSDKError \endlink enum.
 */
- (MobileRTCSDKError)deletePolling:(NSString *_Nullable)pollingID;

/*!
 * @brief Determine if the host can duplicate polling.
 * @param pollingID Specify the duplicate poll's polling ID.
 * @return Can duplicate the polling or not.
 * @warning Only the origin host can duplicate polling.
 */
- (BOOL)canDuplicatePolling:(NSString *_Nullable)pollingID;

/*!
 * @brief Duplicate the polling.
 * @param pollingID Specify the edit poll's polling ID.
 * @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise the function fails. To get extended error information, see \link MobileRTCSDKError \endlink enum.
 */
- (MobileRTCSDKError)duplicatePolling:(NSString *_Nullable)pollingID;

/*!
 * @brief Determine if the user can view polling results in the browser.
 * @param pollingID Specify the duplicate poll's polling ID.
 * @return Can view the polling result or not.
 */
- (BOOL)canViewPollingResultFromBrowser:(NSString *_Nullable)pollingID;

/*!
 * @brief Open a polling result in the web browser.
 * @param pollingID Specify the edit poll's polling ID.
 * @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise the function fails. To get extended error information, see \link MobileRTCSDKError \endlink enum.
 */
- (MobileRTCSDKError)viewPollingResultFromBrowser:(NSString *_Nullable)pollingID;

/*!
 * @brief Get the list of poll item.
 * @return If the function succeeds, the return value is a pointer to the NSArray<MobileRTCPollingItem *>. Otherwise, the return value is nil.
 */
- (NSArray <MobileRTCPollingItem *> * _Nullable)getPollingItemList;

/*!
 * @brief Determine if the host or co-host can start the polling.
 * @param pollingID Specify the poll's polling ID.
 * @return Can start the poll or not.
 */
- (BOOL)canStartPolling:(NSString *_Nullable)pollingID;

/*!
 * @brief Start the polling.
 * @param pollingID Specify the edit poll's polling ID.
 * @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise the function fails. To get extended error information, see \link MobileRTCSDKError \endlink enum.
 */
- (MobileRTCSDKError)startPolling:(NSString *_Nullable)pollingID;

/*!
 * @brief Stop the polling.
 * @param pollingID Specify the edit poll's polling ID.
 * @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise the function fails. To get extended error information, see \link MobileRTCSDKError \endlink enum.
 */
- (MobileRTCSDKError)stopPolling:(NSString *_Nullable)pollingID;

/*!
 * @brief Determine if the host or co-host can restart the polling.
 * @param pollingID Specify the poll's polling ID.
 * @return Can restart the poll or not.
 */
- (BOOL)canRestartPolling:(NSString *_Nullable)pollingID;

/*!
 * @brief Restart the polling.
 * @param pollingID Specify the edit poll's polling ID.
 * @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise the function fails. To get extended error information, see \link MobileRTCSDKError \endlink enum.
 */
- (MobileRTCSDKError)restartPolling:(NSString *_Nullable)pollingID;

/*!
 * @brief Determine if the host or co-host can share the poll's result.
 * @param pollingID Specify the poll's polling ID.
 * @return Can share the poll result or not.
 */
- (BOOL)canSharePollingResult:(NSString *_Nullable)pollingID;

/*!
 * @brief Share the poll's result.
 * @param pollingID Specify the edit poll's polling ID.
 * @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise the function fails. To get extended error information, see \link MobileRTCSDKError \endlink enum.
 */
- (MobileRTCSDKError)startSharePollingResult:(NSString *_Nullable)pollingID;

/*!
 * @brief Stop the poll's result.
 * @param pollingID Specify the edit poll's polling ID.
 * @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise the function fails. To get extended error information, see \link MobileRTCSDKError \endlink enum.
 */
- (MobileRTCSDKError)stopSharePollingResult:(NSString *_Nullable)pollingID;

/*!
 * @brief Set to enable show right answer to participants when share quiz's result.
 * @param enable YES indicates to enable. NO not.
 * @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise the function fails. To get extended error information, see \link MobileRTCSDKError \endlink enum.
 */
- (MobileRTCSDKError)enableGetRightAnswerList:(BOOL)enable;

/*!
 * @brief Determine if the host can download poll's result from browser.
 * @return Can download the poll result or not.
 */
- (BOOL)canDownloadResult;

/*!
 * @brief Download all stopped poll's result from browser.
 * @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise the function fails. To get extended error information, see \link MobileRTCSDKError \endlink enum.
 */
- (MobileRTCSDKError)downLoadResult;

#pragma mark - for attendee -

/*!
 * @brief Attendee set answer's check.
 * @param answerItem Specify the answer item where you want to set check.
 * @param check Specify whether you want to select the answer or not.
 * @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise the function fails. To get extended error information, see \link MobileRTCSDKError \endlink enum.
 * @waning This function should only be used by single, matching, rank order, multi, rating scale, or drop down questions.
 */
- (MobileRTCSDKError)setAnswerCheck:(MobileRTCPollingAnswerItem * _Nullable)answerItem check:(BOOL)check;

/*!
 * @brief Attendee set answer's content.
 * @param answerItem Specify the answer item  where you want to ansswer.
 * @param answerText Specify you want to reply answer's content.
 * @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise the function fails. To get extended error information, see \link MobileRTCSDKError \endlink enum.
 * @waning This function should only be used by fill blank, short answer, and long answer questions..
 */
- (MobileRTCSDKError)setAnswerContent:(MobileRTCPollingAnswerItem * _Nullable)answerItem answerText:(NSString *_Nullable)answerText;

/*!
 * @brief Determine if the attendee can submit the polling.
 * @param pollingID Specify the submit poll's polling ID.
 * @return Can submit the polling or not.
 */
- (BOOL)canSubmitPolling:(NSString *_Nullable)pollingID;

/*!
 * @brief Attendee set answer's content.
 * @param pollingID pollingID Specify the submit poll's polling ID.
 * @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise the function fails. To get extended error information, see \link MobileRTCSDKError \endlink enum.
 */
- (MobileRTCSDKError)submitPolling:(NSString *_Nullable)pollingID;
@end

