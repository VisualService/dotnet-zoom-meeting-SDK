//
//  MobileRTCMeetingService+AppShare.h
//  MobileRTC
//
//  Created by Zoom Video Communications on 2017/2/27.
//  Copyright © 2019年 Zoom Video Communications, Inc. All rights reserved.
//

#import <MobileRTC/MobileRTC.h>

@protocol MobileRTCShareActionDelegate <NSObject>
@optional
/**
 * @brief Callback event the moment the user receives the shared content.
 */
-(void)onSharingContentStartReceiving;
/**
 * @brief The callback is triggered before the shared action is destroyed.
 * @param sharingID Specify the sharing ID.
 * @remark The specified shared action is  destroyed once the function calls end. The user should complete the operations related to the shared action before the function calls end.
 */
-(void)onActionBeforeDestroyed:(NSUInteger)sharingID;

@end

@interface MobileRTCShareAction : NSObject
/**
 * @brief Set the share action delegate.
*/

- (void)setShareActionDelegate:(id<MobileRTCShareActionDelegate>_Nullable)delegate;

/**
 * @brief Get active share view from share action
*/

- (UIView *_Nullable)getActiveShareView;
/**
 * @brief Get the ID of the sharing ID.
 * @return If the function succeeds, the return value is the sharing ID. Otherwise the function fails, and the return value is ZERO (0).
 */

- (NSUInteger)getShareID;
/**
 * @brief Get the name of the sharing user.
 * @return If the function succeeds, the return value is the name. Otherwise the function fails, and the return value is nil.
 */

- (NSString*_Nullable)getSharingUserName;
/**
 * @brief Subscribe the sharing content.
 * @return If the function succeeds, the return value is SDKErr_Success. Otherwise the function fails. To get extended error information, see \link MobileRTCSDKError \endlink enum.
 */

- (MobileRTCSDKError)subscribe;

/**
 * @brief Unsubscribe the sharing content.
 * @return If the function succeeds, the return value is SDKErr_Success. Otherwise the function fails. To get extended error information, see \link MobileRTCSDKError \endlink enum.
*/
- (MobileRTCSDKError)unsubscribe;

@end

/*!
 @brief Starts an App share meeting.
 */
@interface MobileRTCMeetingService (AppShare)

/*!
 @brief Query if the current meeting was started with App Share.
 @return YES means that meeting was started by App Share, otherwise not.
 */
- (BOOL)isDirectAppShareMeeting;

/*!
 @brief Determine whether the current meeting can start sharing.
 @return The reason that no one can start sharing. See [MobileRTCCannotShareReasonType].
 */
- (MobileRTCCannotShareReasonType)canStartShare;

/*!
 @brief Share content with current view.
 @param view - The view shared.
 @warning view, recommend to pass a single UIView object e.g. UIView, UIImageView or WKWebView.
 @warning The UIView passed should not have any child subviews.
 */
- (void)appShareWithView:(nonnull id)view;

/*!
 @brief Set to start App Share.
 @return YES means starting App Share successfully, otherwise not.
 */
- (BOOL)startAppShare;

/*!
 @brief Set to stop App Share.
 */
- (void)stopAppShare;

/*!
 @brief Notify the current user if sharing has started.
 @return YES means that the current user is sharing, otherwise not.
 */
- (BOOL)isStartingShare;

/*!
 @brief Notify the current user if they are currently viewing an App Share.
 @return YES means that user is viewing the share, otherwise not.
 */
- (BOOL)isViewingShare;

/*!
 @brief Notify the current user if annotation is enabled.
 @return YES if enabled, otherwise not.
 */
- (BOOL)isAnnotationOff;

/*!
 @brief Suspend App Sharing.
 @param suspend - YES if sharing should be suspended, otherwise resume sharing.
 @return YES means successful, otherwise not.
 @warning When the customer goes to share content, consider the effects on device performance, and use this method to pause sharing when UI changes, and resume sharing when UI changes stop, see WebViewController.m in sample project.
 */
- (BOOL)suspendSharing:(BOOL)suspend;

/*!
 @brief Enable the sending of device audio.
 @param enableAudio - YES if device audio sharing should be enabled, otherwise disable.
 */
- (void)setShareAudio:(BOOL)enableAudio;

/*!
 @brief Get state of device audio sharing.
 @return YES if device is currently audio sharing.
 */
- (BOOL)isSharedAudio;

/*!
 @brief Get state of device screen sharing.
 @return YES if device is currently screen sharing.
 @warning When the onSinkMeetingActiveShare callback return. developer nned to judge that share screen state.
 */
- (BOOL)isDeviceSharing;

/**
* Allow participant to share white board
* @param allow YES: allow, NO: disallow
* @return error {@link MobileRTCSDKError}
*/
- (MobileRTCSDKError)allowParticipantsToShareWhiteBoard:(BOOL)allow;

/**
* Query is allow participant to share white board
* @return YES: allow, NO: disallow
*/
- (BOOL)isParticipantsShareWhiteBoardAllowed;
@end
