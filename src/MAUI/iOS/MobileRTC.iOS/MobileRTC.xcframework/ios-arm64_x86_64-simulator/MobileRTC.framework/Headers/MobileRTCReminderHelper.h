//
//  MobileRTCReminderHelper.h
//  MobileRTC
//
//  Created by Zoom on 3/27/23.
//  Copyright © 2023 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class MobileRTCReminderContent;
@class MobileRTCReminderHandler;

/**
 * @brief Reminder callback event.
 */
@protocol MobileRTCReminderDelegate <NSObject>
@optional

/**
 * @brief Callback event when the reminder dialog show.
 * @param content the detail content in the reminder dialog.
 * @param handler the helper to handle the reminder dialog.
 */
- (void)onReminderNotify:(MobileRTCReminderContent * _Nullable)content handle:(MobileRTCReminderHandler * _Nullable)handler;

@end

/**
 * @brief The reminder dialog content.
 */
@interface MobileRTCReminderContent : NSObject

/**
 *  the type of the reminder.
 */
@property (nonatomic, assign) MobileRTCReminderType type;

/**
 * the title of the reminder dialog.
 */
@property (nonatomic, copy, nullable) NSString *title;

/**
 * the detail content of the reminder dialog.
 */
@property (nonatomic, copy, nullable) NSString *content;

/**
 * whether block the user join or stay in the meeting.
 */
@property (nonatomic, assign) BOOL isBlock;

/**
 * Get the type of the action which user should take after receiving this reminder content.
 */
@property (nonatomic, assign) MobileRTCReminderActionType actionType;

/**
 * Get a list of reminder’s type.
 * @return List of the reminder’s type.
 */
- (NSArray<NSNumber*>*_Nonnull)getMultiReminderTypes;

@end

/**
 * @brief The interface to handle the reminder dialog.
 */
@interface MobileRTCReminderHandler : NSObject
/**
 * accept the reminder.
 */
- (MobileRTCSDKError)accept;

/**
 * declined the reminder.
 */
- (MobileRTCSDKError)declined;

/**
 * ignore the reminder.
 */
- (MobileRTCSDKError)ignore;

/**
 * Set not show the disclaimer in subsequent meetings.
 * @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise the function fails. Fed, for more details, see {@link MobileRTCSDKError}.
 */
- (MobileRTCSDKError)setHideFeatureDisclaimers;

@end


/**
 * @brief Config for the simplify dislciamer banner.

 */
@interface MobileRTCDisclaimerBannerConfig: NSObject
/**
 * Center of the simplify disclaimer banner.
 */
@property(nonatomic, assign) CGPoint center;
/**
 * Background of the simplify disclaimer banner.
 */
@property(nonatomic, strong) UIColor * _Nullable backgroundColor;

@end

@interface MobileRTCReminderHelper : NSObject

/**
 * @brief Callback to receive reminder events.
 */
@property (weak, nonatomic) id<MobileRTCReminderDelegate> _Nullable reminderDelegate;

/**
 * @brief Provide the simplify disclaimer banner UI's config for CustomUI.
 */
- (void)setDisclaimerBannerUIConfig:(MobileRTCDisclaimerBannerConfig *_Nonnull)config;

@end


