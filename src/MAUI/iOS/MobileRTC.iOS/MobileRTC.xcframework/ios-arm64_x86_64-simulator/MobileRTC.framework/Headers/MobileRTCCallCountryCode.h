//
//  MobileRTCCallCountryCode.h
//  MobileRTC
//
//  Created by Zoom Video Communications on 2019/7/3.
//  Copyright © 2019 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MobileRTCCallCountryCode : NSObject
/*!
 @brief Get the ID of the country where a user can dial in.The country ID. (e.g. US, CA, etc.)
 */
@property (nonatomic, copy) NSString * _Nullable countryId;
/*!
 @brief Get the country name.
 */
@property (nonatomic, copy) NSString * _Nullable countryName;
/*!
 @brief Get the country code.
 */
@property (nonatomic, copy) NSString * _Nullable countryCode;
/*!
 @brief Get the country number.
 */
@property (nonatomic, copy) NSString * _Nullable countryNumber;
/*!
 @brief Whether free.
 */
@property (nonatomic, assign) BOOL tollFree;

@end
