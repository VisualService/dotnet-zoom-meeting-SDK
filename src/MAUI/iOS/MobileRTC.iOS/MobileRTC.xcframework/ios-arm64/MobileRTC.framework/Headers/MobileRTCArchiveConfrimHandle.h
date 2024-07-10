//
//  MobileRTCArchiveConfrimHandle.h
//  MobileRTC
//
//  Created by Zoom Video Communications on 5/6/24.
//  Copyright © 2024 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MobileRTC/MobileRTCConstants.h>

/**
 * @brief the interface for user to handle confirm whether start archive after joining the meeting
 */
@interface MobileRTCArchiveConfrimHandle : NSObject
/*!
 @brief join the meeting.
 @param startArchive true means start the archive when join meeting, false means not start the archive then join meeting.
 @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise fails. For more details, see {@link MobileRTCSDKError}.
 */
- (MobileRTCSDKError)joinWithArchive:(BOOL)startArchive;

/*!
 @brief The content that notify user to confirm start archive when join meeting.
 @return The content that notify user to confirm start archive when join meeting.
 */
- (NSString * _Nullable)getArchiveConfirmContent;
@end

