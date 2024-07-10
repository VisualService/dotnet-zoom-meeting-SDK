//
//  MobileRTCMeetingService+Whiteboard.h
//  MobileRTC
//
//  Created by Zoom Video Communications on 2023/11/23.
//  Copyright © 2023 Zoom Video Communications, Inc. All rights reserved.
//

#import <MobileRTC/MobileRTC.h>

@interface MobileRTCMeetingService (Whiteboard)

/*!
 @brief Determine whether the current meeting supports the whiteboard or not.
 @return YES indicates to support.
 */
- (BOOL)isSupportWhiteBoard;

/*!
 @brief Determine whether the current meeting can start sharing the whiteboard.
 @return The reason no oneof can start sharing the whiteboard. See [MobileRTCCannotShareReasonType].
 */
- (MobileRTCCannotShareReasonType)canStartShareWhiteboard;

/*!
 @brief Set parent viewctroller for whiteboard board view and whiteboard canvas.
 @param parentVC which use to present ViewController
 @warning The function only for Custom UI. This method is a prerequisite for using whiteboard. Suggest to call this function in "onMeetingStateChange:" for inMeeting status.
 @return If the function succeeds, the return value is MobileRTCSDKError_Success.
 */
- (MobileRTCSDKError)setParentViewCtroller:(UIViewController* _Nonnull)parentVC;

/*!
 @brief Show the dashboard web view window.
 @warning The function only for Custom UI.
 @return If the function succeeds, the return value is MobileRTCSDKError_Success.
 */
- (MobileRTCSDKError)showDashboardView;

/*!
 @brief Set the option for who can share a whiteboard.
 @param option New setting for who can share a whiteboard, see [MobileRTCWhiteboardShareOption].
 @return If the function succeeds, the return value is MobileRTCSDKError_Success.
 */
- (MobileRTCSDKError)setWhiteboardShareOption:(MobileRTCWhiteboardShareOption)option;

/*!
 @brief Get the option for who can share a whiteboard.
 @return Setting option for who can share a whiteboard, see [MobileRTCWhiteboardShareOption].
 */
- (MobileRTCWhiteboardShareOption)getWhiteboardShareOption;

/*!
 @brief Set the option for who can initiate a new whiteboard.
 @param option  Setting option for who can initiate a new whiteboard, see [MobileRTCWhiteboardCreateOption].
 @return If the function succeeds, the return value is MobileRTCSDKError_Success.
 */
- (MobileRTCSDKError)setWhiteboardCreateOption:(MobileRTCWhiteboardCreateOption)option;

/*!
 @brief Get the option for who can initiate a new whiteboard.
 @return Setting option for who can initiate a new whiteboard,  see [MobileRTCWhiteboardCreateOption].
 */
- (MobileRTCWhiteboardCreateOption)getWhiteboardCreateOption;

/*!
 @brief Enable the participants to create a new whiteboard without the host in the meeting.
 @param enable YES indicates to enable. NO not.
 @return If the function succeeds, the return value is MobileRTCSDKError_Success.
 */
- (MobileRTCSDKError)enableParticipantsCreateWithoutHost:(BOOL)enable;

/*!
 @brief Determine whether enable the participants create a new whiteboard without the host in the meeting.
 @return YES indicates that they have these permission.
 */
- (BOOL)isParticipantsCreateWithoutHostEnabled;

#pragma mark - UI setting -
/*!
 @brief Enable or disable the new Zoom Whiteboard feature (different from Classic Whiteboard). This feature enabled by default.
 @param disabled YES means disabled, otherwise not.
 @warning The function only for Zoom UI.
 */
- (void)disableCloudWhiteboard:(BOOL)disabled;

/*!
 @brief Allowing the developer to customize the URL of cloud whiteboard feedback.
 @param feedbackUrl customized URL.
 @return YES means the method is called successfully, otherwise not.
 */
- (BOOL)setCloudWhiteboardFeedbackUrl:(nullable NSString *)feedbackUrl;

/*!
@brief Set the Helper center button's visibility on cloud whiteboard. Default is displaying.
@param hide YES means hiding, otherwise means displaying.
*/
- (void)hideCloudWhiteboardHelperCenterButton:(BOOL)hide;

/*!
@brief Set the Open in browser button's visibility on cloud whiteboard. Default is displaying.
@param hide YES means hiding, otherwise means displaying.
*/
- (void)hideCloudWhiteboardOpenInBrowserButton:(BOOL)hide;

/*!
 @brief hide feedback button on cloud whiteboard.
 @param hide YES means hiding, otherwise means displaying.
 */
- (void)hideFeedbackButtonOnCloudWhiteboard:(BOOL)hide;

/*!
 @brief hide share button on cloud whiteboard.
 @param hide YES means hiding, otherwise means displaying.
 */
- (void)hideShareButtonOnCloudWhiteboard:(BOOL)hide;

/*!
 @brief About button’s visibility on the cloud whiteboard. Default is displaying.
 @param hide YES means hiding, otherwise means displaying.
 */
- (void)hideAboutButtonOnCloudWhiteboard:(BOOL)hide;

#pragma mark - legal related -
/*!
 @brief Is whiteboard legal notice available.
 @return YES if notice is available, otherwise not.
 */
- (BOOL)isWhiteboardLegalNoticeAvailable;

/*!
 @brief Get whiteboard legal notices message.
 @return The whiteboard legal notices message as a string.
 */
- (NSString *_Nullable)getWhiteboardLegalNoticesPrompt;

/*!
 @brief Get whiteboard legal notices detailed description.
 @return Whiteboard legal notices detailed description.
 */
- (NSString *_Nullable)getWhiteboardLegalNoticesExplained;
@end

