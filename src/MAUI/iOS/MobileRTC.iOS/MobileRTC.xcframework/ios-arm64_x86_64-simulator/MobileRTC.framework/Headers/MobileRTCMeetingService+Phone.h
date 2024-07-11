//
//  MobileRTCMeetingService+Phone.h
//  MobileRTC
//
//  Created by ZOOM on 2023/4/24.
//  Copyright © 2023 Zoom Video Communications, Inc. All rights reserved.
//

#import <MobileRTC/MobileRTC.h>

NS_ASSUME_NONNULL_BEGIN

@interface MobileRTCMeetingService (Phone)

/**
 * @brief Determine if the user account supports calling out.
 * @return YES means that the client supports the phone call-out feature. otherwise, phone call-out is not supported.
 */
-(BOOL)isSupportPhone;

/*!
 @brief Query if user can dial out in the meeting.
 @return YES means able, No disable.
 */
- (BOOL)isDialOutSupported;

/**
 * @brief Get the list of the countries which support to call out.
 * @return An NSArray contains ZoomSDKPhoneSupportCountryInfoList objects of all countries supporting to call out.  Otherwise nil.
 */
-(NSArray <MobileRTCCallCountryCode*>* _Nullable)getSupportCountryInfo;

/*!
 @brief Query if there is any outgoing call in process.
 @return YES means that there is outgoing call in process.
 */
- (BOOL)isDialOutInProgress;

/*!
 @brief Start to dial out.
 @param phone The phone number of destination, you should add the country code in front of the phone number, such as +86123456789.
 @param me YES means Call Me; NO means inviting others by Phone.
 @param username The name of the user to be called.
 @return YES means the method is called successfully, otherwise not.
 */
- (BOOL)dialOut:(nonnull NSString*)phone isCallMe:(BOOL)me withName:(nullable NSString*)username;

/*!
 @brief Cancel to dial out.
 @param isCallMe YES means Call Me; NO means inviting others by Phone.
 @return YES means the method is called successfully, otherwise not.
 */
- (BOOL)cancelDialOut:(BOOL)isCallMe;


/*!
 @brief Get countrycode for the current user's locale.
 @return The object of MobileRTCCallCountryCode for user's locale.
 */
- (nullable MobileRTCCallCountryCode *)getDialInCurrentCountryCode;

/*!
 @brief Get all countrycodes
 @return The array of all countrycode.
 */

- (nullable NSArray <NSArray <MobileRTCCallCountryCode *> *> *)getDialInAllCountryCodes;

/*!
 @brief Get to the countrycode specified by countryId
 @return The array of countrycode.
 */

- (nullable NSArray <MobileRTCCallCountryCode *> *)getDialInCallCodesWithCountryId:(nullable NSString *)countryId;

/*!
 @brief Make a phone call to access your voice
 @return YES means the method is called successfully, otherwise not.
 */
- (BOOL)dialInCall:(nullable NSString *)countryNumber;

@end

NS_ASSUME_NONNULL_END
