//
//  MobileRTCAIQueryHelper.h
//  MobileRTC
//
//  Created by Zoom on 2024/5/7.
//  Copyright © 2024 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef NS_ENUM(NSUInteger, MobileRTCAICompanionQuerySettingOptions) {
    MobileRTCAICompanionQuerySettingOptions_None = 0,              ///<Initialization.
    MobileRTCAICompanionQuerySettingOptions_WhenQueryStarted,      ///<WhenQueryStarted. All participants can ask question, and answers are based on the meeting's start until now.
    MobileRTCAICompanionQuerySettingOptions_WhenParticipantsJoin,  ///<WhenParticipantsJoin. All participants can ask question, and answers are based on the current user's joining time until now.
    MobileRTCAICompanionQuerySettingOptions_OnlyHost               ///<OnlyHost. Only hosts and users with host privileges assigned before the meeting starts can ask question.
};

@interface MobileRTCStartQueryHandler : NSObject
/**
 @brief Start meeting query.
 @return If the function succeeds, it will return MobileRTCSDKError_Success. Otherwise the function fails.
 */
- (MobileRTCSDKError)startMeetingQuery;

/**
 @brief Determine if this handler for request enable query.
 @return YES means this handler is for request enable query. Otherwise it returns NO and is not available.
 */
- (BOOL)isForRequest;

@end

@interface ZoomSDKApproveStartQueryHandler : NSObject
/**
 @brief Get the requester's user ID.
 */
@property (nonatomic, assign, readonly) unsigned int senderUserID;
/**
 @brief Approve the request.
 @return If the function succeeds, it returns MobileRTCSDKError_Success. Otherwise the function fails.
 */
- (MobileRTCSDKError)approve;

/**
 @brief Decline the request.
 @return If the function succeeds, it returns MobileRTCSDKError_Success. Otherwise the function fails.
 */
- (MobileRTCSDKError)decline;

@end

@interface MobileRTCSendQueryHandler : NSObject

/**
 @brief Stop meeting query.
 @return If the function succeeds, it returns MobileRTCSDKError_Success. Otherwise the function fails.
 */
- (MobileRTCSDKError)stopMeetingQuery;

@end


@protocol MobileRTCAICompanionQueryHelperDelegate <NSObject>
@optional
/**
 @brief Notification that meeting does not support meeting query.
 */
- (void)onQueryStateNotSupported;

/**
 @brief Notification that the meeting supports query but query feature is disabled.
 @param handler The handler to enable the query.
 */
- (void)onQueryStateEnabledButNotStarted:(MobileRTCStartQueryHandler*)handler;

/**
 @brief Notification that the query is started.
 @param handler The handler to send the query.
 */
- (void)onQueryStateStarted:(MobileRTCSendQueryHandler*)handler;

/**
 @brief Notification that the query setting is changed.
 @param setting The selected query setting.
 */
- (void)onQuerySettingChanged:(MobileRTCAICompanionQuerySettingOptions)setting;

/**
 @brief Notification that the query failed to start the query.
 @param bTimeout YES means is timeout. Otherwise not.
 */
- (void)onFailedToStartQuery:(BOOL)bTimeout;

/**
 @brief Notification of receiving request to start query.
 @param handler The handler to handle the request.
 */
- (void)onReceiveRequestToStartQuery:(ZoomSDKApproveStartQueryHandler *)handler;

@end

@interface MobileRTCAICompanionQueryHelper : NSObject

@property(nonatomic, weak) id<MobileRTCAICompanionQueryHelperDelegate> delegate;

/**
 @brief Get the selected query setting.
 @return If the function succeeds, it returns the selected query setting. Otherwise the function fails.
 */
- (MobileRTCAICompanionQuerySettingOptions)getSelectedQuerySetting;

/**
 @brief Determine whether the current user can change the query setting.
 @return YES means that it can change the setting. Otherwise it can't change the setting.
 */
- (BOOL)canChangeQuerySetting;

/**
 @brief Change query setting.
 @return If the function succeeds, it returns MobileRTCSDKError_Success. Otherwise nthe function fails.
 */
- (MobileRTCSDKError)changeQuerySettings:(MobileRTCAICompanionQuerySettingOptions)setting;

@end
