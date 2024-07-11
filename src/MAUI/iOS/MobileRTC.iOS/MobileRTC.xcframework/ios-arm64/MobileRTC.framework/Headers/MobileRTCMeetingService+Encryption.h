//
//  MobileRTCMeetingService+AppShare.h
//  MobileRTC
//
//  Created by Zoom Video Communications on 2017/2/27.
//  Copyright © 2019年 Zoom Video Communications, Inc. All rights reserved.
//

#import <MobileRTC/MobileRTC.h>

/*!
 @brief get encryption info of meeting
 */
@interface MobileRTCMeetingService (Encryption)

/*!
 @brief Get meeting encryption type.
 @return YES means the immersive view is active. Otherwise NO.
 */
- (MobileRTCMeetingEncryptionType)getEncryptionType;

/*!
 @brief Get E2EE meeting security code.
 @return If the function succeeds, it will return 40-digit security code. Otherwise failed.
 */
- (NSString* _Nullable)getE2EEMeetingSecurityCode;

/*!
 @brief Get security code passed seconds.
 @return If the function succeeds, it will return the time the security code exists, in seconds. Otherwise failed.
 */
- (unsigned int)getE2EEMeetingSecurityCodePassedSeconds;

/*!
 @brief Determine whether unencrypted exception data is valid,
 @note This method can only be called when the encryption type is ZoomSDKEncryptionType_Enhanced.
 @return YES means unencrypted exception data is valid.
 */
- (BOOL)isUnencryptedExceptionDataValid;

/*!
 @brief Get unencrypted exception count.
 @return If the function succeeds, it will return the unencrypted exception count. Otherwise failed.
 */
- (unsigned int)getUnencryptedExceptionCount;

/*!
 @brief Get unencrypted exception info.
 @return If the function succeeds, it will return unencrypted exception details. Otherwise failed.
 */
- (NSString* _Nonnull)getUnencryptedExceptionInfo;

/*!
 @brief Get data center info.
 @return If the function succeeds, it will return data center details. Otherwise failed.
 */
- (NSString* _Nonnull)getInMeetingDataCenterInfo;

@end
