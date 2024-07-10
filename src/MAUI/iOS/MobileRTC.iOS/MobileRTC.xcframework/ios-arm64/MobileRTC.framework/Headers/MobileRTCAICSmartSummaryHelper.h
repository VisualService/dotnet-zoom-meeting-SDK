//
//  MobileRTCAICSmartSummaryHelper.h
//  MobileRTC
//
//  Created by Zoom Video Communications on 5/23/24.
//  Copyright © 2024 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MobileRTCStartSmartSummaryHandler : NSObject
/*!
 * @brief Start meeting summary.
 * @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise the function fails. For more details, see {@link MobileRTCSDKError}.
 */
- (MobileRTCSDKError)startSmartSummary;

/*!
 * @brief Determine if this handler is for requesting to start the smart summary.
 * @return True means this handler is for request start smart summary. Otherwise not.
 */
- (BOOL)isForRequest;

@end

@interface MobileRTCStopSmartSummaryHandler : NSObject

/*!
 * @brief Stop meeting summary.
 * @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise the function fails. For more details, see {@link MobileRTCSDKError}.
 */
- (MobileRTCSDKError)stopSmartSummary;

@end

@interface MobileRTCApproveStartSmartSummaryHandler : NSObject
/*!
 * @brief Get the user ID of requester.
 * @return The user ID of requester.
 */
- (NSUInteger)getSenderUserID;

/*!
 * @brief Approve request.
 * @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise the function fails. For more details, see {@link MobileRTCSDKError}.
 */
- (MobileRTCSDKError)approve;

/*!
 * @brief Decline request.
 * @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise the function fails. For more details, see {@link MobileRTCSDKError}.
 */
- (MobileRTCSDKError)decline;

@end


@protocol MobileRTCAICompanionSmartSummaryHelperDelegate <NSObject>
@optional
/*!
 * @brief Notify the meting does not support smart summary.
 */
- (void)onSmartSummaryStateNotSupported;

/*!
 * @brief Notify the meting support smart summary but smart summary feature is disabled.
 */
- (void)onSmartSummaryStateSupportedButDisabled;

/*!
 * @brief Notify the meeting smart summary is not started.
 * @param handler The handler to start smart summary.
 */
- (void)onSmartSummaryStateEnabledButNotStarted:(MobileRTCStartSmartSummaryHandler *_Nullable)handler;

/*!
 * @brief Notify the meeting smart summary is started.
 * @param handler The handler to stop smart summary.
 * @warning If the user can not stop smart summary, the handler will be nil.
 */
- (void)onSmartSummaryStateStarted:(MobileRTCStopSmartSummaryHandler *_Nullable)handler;

/*!
 * @brief Notify failed to start the smart summary.
 * @param bTimeout True means timeout. Otherwise no timeout. May be declined by host or cohost.
 */
- (void)onFailedToStartSmartSummary:(BOOL)bTimeout;

/*!
 * @brief Notify receive request to start smart summary.
 * @param handler The handler to handle request.
 */
- (void)onSmartSummaryStartRequestReceived:(MobileRTCApproveStartSmartSummaryHandler *_Nullable)handler;

@end

/*!
 * @brief Smart Summary Helper in ZOOM meeting.
 */
@interface MobileRTCAICompanionSmartSummaryHelper : NSObject
@property(nonatomic, weak) id<MobileRTCAICompanionSmartSummaryHelperDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
