//
//  MobileRTCAutoFramingParameter.h
//  MobileRTC
//
//  Created by Zoom on 5/12/23.
//  Copyright © 2023 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MobileRTCConstants.h"

/*!
 @brief The AutoFraming parameter.
 */
@interface MobileRTCAutoFramingParameter : NSObject
/**
 * @brief The ratio of auto framing, for each mode the ratio is different. {@link MobileRTCAutoFramingMode}
 */
@property (nonatomic, assign) CGFloat ratio;
/**
 * @brief The auto framing fail strategy,  {@link MobileRTCFaceRecognitionFailStrategy}
 */
@property (nonatomic, assign) MobileRTCFaceRecognitionFailStrategy failStrategy;
@end

