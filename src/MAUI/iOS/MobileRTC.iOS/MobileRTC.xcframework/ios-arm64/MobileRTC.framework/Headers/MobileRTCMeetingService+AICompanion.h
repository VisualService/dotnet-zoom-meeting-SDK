//
//  MobileRTCMeetingService+AICompanion.h
//  MobileRTC
//
//  Created by Zoom on 2024/4/25.
//  Copyright © 2024 Zoom Video Communications, Inc. All rights reserved.
//

#import <MobileRTC/MobileRTC.h>
#import <MobileRTC/MobileRTCAICQueryHelper.h>
#import <MobileRTC/MobileRTCAICSmartSummaryHelper.h>
NS_ASSUME_NONNULL_BEGIN

/**
 *  AI Companion  in meeting
 */

@interface MobileRTCAICompanionTurnOnAgainHandler : NSObject
/**
 * @brief Get the list of features list that the attendeeis turnsed off by attendee.
 * @return the  AI Companion feature list. see {@link MobileRTCAICompanionType}.
*/
- (NSArray *)getFeatureList;
/**
 * @brief Get the feature list that the assets are deleted when the feature is turned off by attendee.
 * @return the  AI Companion feature list. see {@link MobileRTCAICompanionType}.
*/
- (NSArray *)getAssetsDeletedFeatureList;
/**
 * @brief Rurn on the auto  AI Companion feature which was stopped by the attendee before the host or cohost joined meeting.
 * @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise the function fails. For more details, see {@link MobileRTCSDKError}.
 */
- (MobileRTCSDKError)turnOnAgain;
/**
 * @brief Agree the auto   AI Companion  feature turn off status. Keep the  AI Companion feature off.
 * @return If the function succeeds, the return value is MobileRTCSDKError_Success. the function fails. For more details, see {@link MobileRTCSDKError}.
 */
- (MobileRTCSDKError)agreeTurnOff;

@end

/**
 * The handler to handle a user request to turn the  AI Companion features on or off.
 */

@interface MobileRTCAICompanionSwitchHandler : NSObject

/**
 * @brief The user ID who requests the host to turn the  AI Companion features on or off.
 * @return the request user ID.
 */
-(NSUInteger)getRequestUserID;
/**
 * @brief Turn the  AI Companion features on or off.
 * @return true means turn on the  AI Companion features.false means turn off the  AI Companion features.
 */
-(BOOL)isTurnOn;

/**
 * @brief Agree to the request to turn. the  AI Companion features on or off.
 * @param deleteAsserts true means delete the meeting asserts when turning off the  AI Companion features.
 * @return If the function succeeds, the return value is SDKErr_Success. Otherwise the function fails. For more details, see {@link MobileRTCSDKError}.
 */
- (MobileRTCSDKError)agree:(BOOL)deleteAsserts;

/**
 * @brief  Decline the request to turn the  AI Companion features on or off.
 * @return If the function succeeds, the return value is SDKErr_Success. the function fails. For more details, see {@link MobileRTCSDKError}.
*/
- (MobileRTCSDKError)decline;

@end


@interface MobileRTCMeetingService (AICompanion)

/**
 * @brief Whether the meeting supports turning off the  AI Companion features.
 * @return true means the meeting can support turning off the  AI Companion features. Otherwise the value is false.
 */
- (BOOL)isTurnoffAllAICompanionsSupported;
/**
 * @brief Whether the current user can turn off the  AI Companion features.
 * @return true means the user can turn off the  AI Companion features.
 */
- (BOOL)canTurnOffAllAICompanions;
/**
 * @brief turn off the  AI Companion features.
 * @remark All AI features includinge {@link MobileRTCAICompanionType_QUERY  }, {@linkMobileRTCAICompanionType_SMART_SUMMARY}, and {@link MobileRTCAICompanionType_SMART_RECORDING} can be turned off at once.
 * @param deleteMeetingAssets true whether delete the meeting assets when turn off the  AI Companion features.
 * @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise the function fails, for more details, see {@link MobileRTCSDKError}.
 */
- (MobileRTCSDKError)turnOffAllAICompanion:(BOOL)deleteMeetingAssets;
/**
 * @brief Whether the meeting supports turning off the AI Companion features.
 * @return true means the meeting can support turning on the  AI Companion features. Otherwise  the value is false.
 */
- (BOOL)isTurnOnAllAICompanionSupported;
/**
 * @brief Whether the current user can turn off the  AI Companion features.
 * @return true means the user can turn off the  AI Companion features.
 */
- (BOOL)canTurnOnAllAICompanion;
/**
 * @brief Turn on all the  AI Companion features.
 * @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise  the function fails. For more details, see {@link MobileRTCSDKError}.
 */
- (MobileRTCSDKError)turnOnAllAICompanion;
/**
 * @brief Whether the current user can ask the host to turn off all started  AI Companion features.
 * @remark if the current user joins the meeting before the host, they can check {@link #canTurnOffAllAICompanions} to turn off the AI Companion features by himself/herself.
 * @remark All AI features includinge {@link MobileRTCAICompanionType_QUERY  }, {@linkMobileRTCAICompanionType_SMART_SUMMARY}, and {@link MobileRTCAICompanionType_SMART_RECORDING} can be turned off at once.
 * @return true means the user can request host to turn off the  AI Companion features.
 */
- (BOOL)canRequestTurnoffAllAICompanion;
/**
 * @brief Ask host to turn off all started  AI Companion features.
 * @remark All AI features includinge {@link MobileRTCAICompanionType_QUERY  }, {@linkMobileRTCAICompanionType_SMART_SUMMARY}, and {@link MobileRTCAICompanionType_SMART_RECORDING} can be turned off at once.
 * @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise failed, for more details, see {@link MobileRTCSDKError}.
 */
- (MobileRTCSDKError)requestTurnoffAllAICompanion;
/**
 * @brief Whether the current user can ash the host to turn on all  AI Companion features if they are enabled for the current meeting.
 * @remark Only {@link MobileRTCAICompanionType_QUERY} and {@link MobileRTCAICompanionType_SMART_SUMMARY} can be turned on at once.
 * @return true means the user can ask the host to turn on the AI Companion features.
 */
- (BOOL)canRequestTurnOnAllAICompanion;
/**
 * @brief Ask host to turn on all  AI Companion features if they are enabled for the current meeting.
 * @remark Only {@link MobileRTCAICompanionType_QUERY} and {@link MobileRTCAICompanionType_SMART_SUMMARY} can be turned on at once.
 * @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise  the function fails. For more details, see {@link MobileRTCSDKError}.
 */
- (MobileRTCSDKError)requestTurnOnAllAICompanion;

/**
 * @brief Get  AI Companion Query Helper
 * @return it returns a instance of MobileRTCAICompanionQueryHelper. for more details, see {@link MobileRTCAICompanionQueryHelper}.
 */
- (MobileRTCAICompanionQueryHelper *)getQueryHelper;


/**
 * @brief Get the smart summary helper
 * @return If the function succeeds, the return value is a pointer to ZoomSDKAICompanionSmartSummaryHelper {@link MobileRTCAICompanionSmartSummaryHelper}. Otherwise the function returns nil.
 */
- (MobileRTCAICompanionSmartSummaryHelper *)getSmartSummaryHelper;

@end

NS_ASSUME_NONNULL_END
