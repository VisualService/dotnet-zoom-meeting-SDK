//
//  MobileRTCMeetingService+Customize.h
//  MobileRTC
//
//  Created by Zoom Video Communications on 2017/2/27.
//  Copyright © 2019年 Zoom Video Communications, Inc. All rights reserved.
//

#import <MobileRTC/MobileRTC.h>
#import <MobileRTC/MobileRTCRoomDevice.h>
#import <MobileRTC/MobileRTCCallCountryCode.h>

/*!
 @brief Provide interfaces for outgoing calls and Call Room Device.
 */
@interface MobileRTCMeetingService (Customize)

/*!
 @brief Set to customize the meeting title which will be displayed in the meeting bar. 
 @param title The topic/title of the meeting.
 @warning User should call the method before starting or joining the meeting if he wants to reset the title/topic of the meeting.
 */
- (void)customizeMeetingTitle:(NSString * _Nullable)title;

/*!
@brief Set to customize the meeting topic which will be displayed in the meeting info view.
 @param meetingTopic The topic of the meeting.
@warning only meeting original host can call the function.
@warning only in-meeting can call the function.
*/
- (BOOL)setMeetingTopic:(NSString *_Nonnull)meetingTopic;

/*!
 @brief Query if it is able to Call Room device(H.323).
 @return YES means able, otherwise not.
 */
- (BOOL)isCallRoomDeviceSupported;

/*!
 @brief Query if it is in process to call room device.
 @return YES means calling room device in process, otherwise not. 
 */
- (BOOL)isCallingRoomDevice;

/*!
 @brief Cancel to call room device.
 @return YES means the method is called successfully, otherwise not.
 */
- (BOOL)cancelCallRoomDevice;

/*!
 @brief Get an array of IP Addresses of room device which is used for calling.
 @return The array of IP Address; if there is no existed IP Address, it will return nil.
 */
- (nullable NSArray <NSString *> *)getIPAddressList;

/*!
 @brief Get the password of the meeting running on H.323 device.
 @return The meeting password. If no meeting is running, it will return nil.
 */
- (nullable NSString*)getH323MeetingPassword;

/*!
 @brief Get room devices that can be called. 
 @return The array of room devices. If there is no any room device. it will return nil.
 */
- (nullable NSArray <MobileRTCRoomDevice *> *)getRoomDeviceList;

/*!
 @brief Get the pairing code when the room device call in. 
 @param code The pairing code which enable the device connect to the meeting.
 @param meetingNumber The number of meeting.
 @return YES means the method is called successfully, otherwise not.
 @warning App can invite Room System while App is in Meeting or in pre-Meeting.
 */
- (BOOL)sendPairingCode:(nonnull NSString*)code WithMeetingNumber:(unsigned long long)meetingNumber;

/*!
 @brief The user calls out to invite the room device. 
 @param device The room device.
 @return YES means the method is called successfully, otherwise not.
 */
- (BOOL)callRoomDevice:(nonnull MobileRTCRoomDevice*)device;

/*!
 @brief Get Participant ID.
 @return The Participant ID.
 */
- (NSUInteger)getParticipantID;

/*!
 @brief Allowing the developer to customize the URL of create/edit the polling
 @param pollingURL customized URL.
 @param bCreate When bCreate is true, it changes the URL of creating a polling. Otherwise, it changes the URL of editing a polling.
 @return YES means the method is called successfully, otherwise not.
 */
- (BOOL)setCustomizedPollingUrl:(nullable NSString *)pollingURL bCreate:(BOOL)bCreate;

@end
