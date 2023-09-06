//
//  MobileRTCVideoRawData.h
//  MobileRTC
//
//  Created by Zoom Video Communications on 2019/8/6.
//  Copyright © 2019 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MobileRTCVideoRawData : NSObject

/*!
 @brief The y-data pointer to a video's YUV data.
 */
@property (nonatomic, assign) char *yBuffer;

/*!
 @brief The u-data data pointer to a video's YUV data.
 */
@property (nonatomic, assign) char *uBuffer;

/*!
 @brief The v-data data pointer to a video's YUV data.
 */
@property (nonatomic, assign) char *vBuffer;

/*!
 @brief The video data's size.
 */
@property (nonatomic, assign) CGSize size;

/*!
 @brief The video data's raw data format defined in {@link MobileRTCVideoRawDataFormat}.
 */
@property (nonatomic, assign) MobileRTCFrameDataFormat format;

/*!
 @brief The video data's rotation defined in {@link MobileRTCVideoRawDataRotation}.
 */
@property (nonatomic, assign) MobileRTCVideoRawDataRotation rotation;

/*!
 @brief Whether adding a reference is allowed.
 @return true if allow. Otherwise, false.
 */
- (BOOL)canAddRef;

/*!
 @brief Add to reference count.
 @return true if successfully added. Otherwise, this returns false.
 */
- (BOOL)addRef;

/*!
 @brief Subtract from reference count.
 */
- (NSInteger)releaseRef;

@end

