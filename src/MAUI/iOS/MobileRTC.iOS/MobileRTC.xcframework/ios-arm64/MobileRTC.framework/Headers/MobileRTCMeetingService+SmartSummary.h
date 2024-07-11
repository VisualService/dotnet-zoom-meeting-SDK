//
//  MobileRTCMeetingService+SmartSummary.h
//  MobileRTC
//
//  Created by Jackie Chen on 10/10/23.
//  Copyright © 2023 Zoom Video Communications, Inc. All rights reserved.
//

#import <MobileRTC/MobileRTC.h>

/**
 * @brief interface to handle start smart summary request
 */
@interface MobileRTCSmartSummaryPrivilegeHandler : NSObject
/**
 * @brief Agree the start smart summary request.
 * @return if the function succeeds, the return value is MobileRTCSDKError_Success.
 * Otherwise the function fails. For more details, see {@link MobileRTCSDKError}.
 */
- (MobileRTCSDKError)accept DEPRECATED_MSG_ATTRIBUTE("Use MobileRTCAICompanionSmartSummaryHelper instead");

/**
 * @brief Decline the start smart summary request.
 * @return if the function succeeds, the return value is MobileRTCSDKError_Success.
 * Otherwise the function fails. For more details, see {@link MobileRTCSDKError}.
 */
- (MobileRTCSDKError)decline DEPRECATED_MSG_ATTRIBUTE("Use MobileRTCAICompanionSmartSummaryHelper instead");

/**
 * Ignore the start smart summary request.
 */
- (void)ignore DEPRECATED_MSG_ATTRIBUTE("Use MobileRTCAICompanionSmartSummaryHelper instead");
@end

@interface MobileRTCMeetingService (SmartSummary)

/**
 * @brief Determine if current meeting support smart summary feature.
 * @return true means the current meeting supports the smart summary feature, false means the feature is not supported.
 */
- (BOOL)isSmartSummarySupported DEPRECATED_MSG_ATTRIBUTE("Use MobileRTCAICompanionSmartSummaryHelper instead");

/**
 * @brief Determine if the smart summary feature is enabled in the meeting.
 * @return true means smart summary feature is enabled.
 */
- (BOOL)isSmartSummaryEnabled DEPRECATED_MSG_ATTRIBUTE("Use MobileRTCAICompanionSmartSummaryHelper instead");

/**
 * @brief Whether the current user can request the host to start the smart summary for the current meeting.
 * @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise the function fails. For more details, see {@link MobileRTCSDKError}.
 */
- (MobileRTCSDKError)canRequestStartSmartSummary DEPRECATED_MSG_ATTRIBUTE("Use MobileRTCAICompanionSmartSummaryHelper instead");

/**
 * @brief Request the host to start the smart summary for the current meeting.
 * @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise the function fails. For more details, see {@link MobileRTCSDKError}.
 */
- (MobileRTCSDKError)requestStartSmartSummary DEPRECATED_MSG_ATTRIBUTE("Use MobileRTCAICompanionSmartSummaryHelper instead");

/**
 * @brief Whether the current user is able to start smart summary.
 * @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise the function fails. For more details, see {@link MobileRTCSDKError}.
 */
- (MobileRTCSDKError)canStartSmartSummary DEPRECATED_MSG_ATTRIBUTE("Use MobileRTCAICompanionSmartSummaryHelper instead");

/**
 * @brief Start smart summary.
 * @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise the function fails. For more details, see {@link MobileRTCSDKError}.
 */
- (MobileRTCSDKError)startSmartSummary DEPRECATED_MSG_ATTRIBUTE("Use MobileRTCAICompanionSmartSummaryHelper instead");

/**
 * @brief Stop smart summary.
 * @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise the function fails. For more details, see {@link MobileRTCSDKError}.
 */
- (MobileRTCSDKError)stopSmartSummary DEPRECATED_MSG_ATTRIBUTE("Use MobileRTCAICompanionSmartSummaryHelper instead");

/**
 * @brief Query whether smart summary is started.
 * @return true means smart summary is started, false means it has not.
 */
- (BOOL)isSmartSummaryStarted DEPRECATED_MSG_ATTRIBUTE("Use MobileRTCAICompanionSmartSummaryHelper instead");

@end

