//
//  MobileRTCReminderHelper.h
//  MobileRTC
//
//  Created by Zoom on 3/27/23.
//  Copyright © 2023 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MobileRTC/MobileRTC.h>
#import "MobileRTCConstants.h"

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
 * @param handle the helper to handle the reminder dialog.
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


@end

/**
 * @brief The interface to handle the reminder dialog.
 */
@interface MobileRTCReminderHandler : NSObject
/**
 * accept the reminder.
 */
- (void)accept;

/**
 * declined the reminder.
 */
- (void)declined;

/**
 * ignore the reminder.
 */
- (void)ignore;

@end

@interface MobileRTCReminderHelper : NSObject

/**
 * @brief Callback to receive reminder events.
 */
@property (weak, nonatomic) id<MobileRTCReminderDelegate> _Nullable reminderDelegate;

@end


