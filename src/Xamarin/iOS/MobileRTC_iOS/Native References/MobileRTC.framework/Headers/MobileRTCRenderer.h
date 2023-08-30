//
//  MobileRTCRenderer.h
//  MobileRTC
//
//  Created by Zoom Video Communications on 2019/8/6.
//  Copyright © 2019 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MobileRTCMeetingDelegate.h"

@interface MobileRTCRenderer : NSObject

/*!
@brief MobileRTCRenderer's user ID.
*/
@property (nonatomic, assign, readonly) NSUInteger userId;

/*!
 @brief MobileRTCRenderer's video type defined in {@link MobileRTCVideoType}.
 */
@property (nonatomic, assign, readonly) MobileRTCVideoType videoType;

/*!
 @brief MobileRTCRenderer's video resolution defined in {@link MobileRTCVideoResolution}.
 */
@property (nonatomic, assign, readonly) MobileRTCVideoResolution resolution;

/*!
 @brief Initialize MobileRTCRenderer.
 @param delegate - The delegate to receive callbacks. See {@link MobileRTCVideoRawDataDelegate}.
 @return The MobileRTCRenderer object.
 */
- (instancetype _Nonnull)initWithDelegate:(id<MobileRTCVideoRawDataDelegate>_Nonnull) delegate;

/*!
 @brief Call the function to set video resolution.
 @return If the function succeeds, the return value is MobileRTCRawData_Success. Otherwise, the function fails and returns null. To get extended error information, see {@link MobileRTCRawDataError}.
 */
- (MobileRTCRawDataError)setRawDataResolution:(MobileRTCVideoResolution)resolution;

/*!
 @brief Call the function to subscribe to raw video data.
 @note Before entering the meeting, subscribe to your preview video data with userId = 0.
 @note If you are already in the meeting, subscribe to your own video data using the real userId or userId = 0.
 @return If the function succeeds, the return value is MobileRTCRawData_Success. Otherwise, the function fails and returns null. To get extended error information, see {@link MobileRTCRawDataError}.
 */
- (MobileRTCRawDataError)subscribe:(NSUInteger)userId
                    videoType:(MobileRTCVideoType)type;

/*!
 @brief Call the function to unsubscribe from raw video data.
 @return If the function succeeds, the return value is MobileRTCRawData_Success. Otherwise, the function fails and returns null. To get extended error information, see {@link MobileRTCRawDataError}.
 */
- (MobileRTCRawDataError)unSubscribe;

@end

