//
//  MobileRTCPresenceHelper.h
//  MobileRTC
//
//  Created by Zoom on 2023/4/3.
//  Copyright © 2023 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MobileRTCConstants.h"

/*!
 @brief Presence information interface.
 */
@interface MobileRTCContactInfo : NSObject
/*!
 @brief Contact’s ID.
 */
@property (copy, nonatomic, readonly) NSString * _Nullable contactID;
/*!
 @brief Contact’s name.
 */
@property (copy, nonatomic, readonly) NSString * _Nullable contactName;
/*!
 @brief Contact’s presence status, such as MobileRTCPresenceStatus_Available.
 */
@property (assign, nonatomic, readonly) MobileRTCPresenceStatus presenceStatus;
/*!
 @brief Contact’s profile picture.
 */
@property (copy, nonatomic, readonly) NSString * _Nullable profilepicture;
/*!
 @brief Contact’s personal note.
 */
@property (copy, nonatomic, readonly) NSString * _Nullable personalNote;
/*!
 @brief Contact’s company name, such as "Acme Incorporated".
 */
@property (copy, nonatomic, readonly) NSString * _Nullable companyName;
/*!
 @brief Contact’s department, such as "Human resources".
 */
@property (copy, nonatomic, readonly) NSString * _Nullable department;
/*!
 @brief Contact’s job title, such as "Support engineer".
 */
@property (copy, nonatomic, readonly) NSString * _Nullable jobTitle;
/*!
 @brief Contact’s phone number, such as "+1 000 000-0000".
 */
@property (copy, nonatomic, readonly) NSString * _Nullable phoneNumber;
/*!
 @brief Contact’s email, such as "jillchill@example.com".
 */
@property (copy, nonatomic, readonly) NSString * _Nullable email;

@end

/*!
 @brief Process after the user receives an invitation from another user to join a meeting.
 */
@interface MobileRTCInvitationMeetingHandler : NSObject

/*!
 @brief Inviter’s name.
 */
@property (copy, nonatomic, readonly) NSString * _Nullable senderName;

/*!
 @brief Invite meeting number.
 */
@property (assign, nonatomic, readonly) long long meetingNumber;

/*!
 @brief Whether this invitation is from the channel.
 */
@property (assign, nonatomic, readonly) BOOL isChannelInvitation;

/*!
 @brief Channel name.
 */
@property (copy, nonatomic, readonly) NSString *_Nullable channelName;

/*!
 @brief Channel member count.
 */
@property (assign, nonatomic, readonly) unsigned int channelMemberCount;

/*!
 @brief set the screen name for join meeting.
*/
- (void)setScreenName:(NSString * _Nullable)screenName;
/*!
 @brief Instance to accept the invitation, join the meeting, and finally self-destruct.
*/
- (MobileRTCSDKError)accept;
/*!
 @brief Instance to decline the invitation, finally self-destruct.
 */
- (MobileRTCSDKError)decline;
/*!
 @brief Instance to let the invitation time out, finally self-destruct.
 */
- (MobileRTCSDKError)timeout;

@end

/*!
 @brief Presence helper callback event.
 */
@protocol MobileRTCPresenceHelperDelegate <NSObject>

/*!
 @brief Callback to request star contact ID list.
 @param contactIDList Star contact result value.
 */
- (void)onRequestStarContact:(NSArray <NSString *> *_Nullable)contactIDList;

/*!
 @brief Callback to request the contact detail information list.
 @param contactList Contact detail information list.
 */
- (void)onRequestContactDetailInfo:(NSArray <MobileRTCContactInfo *> *_Nullable)contactList;

/*!
 @brief Contact presence changed callback.
 @param contactId The contact’s ID.
 @param status contact presence status.
 */
- (void)onUserPresenceChanged:(NSString *_Nullable)contactID presenceStatus:(MobileRTCPresenceStatus)status;

/*!
 @brief Starred contact list changed callback.
 @param contactList The ID list of change contacts.
 @param add Specifies whether the contact list is added.
*/
- (void)onStarContactListChanged:(NSArray <NSString *> *_Nullable)contactIDList isAdd:(BOOL)add;

/*!
 @brief Callback to receive a meeting invitation.
 @param handler A pointer to the IInvitationMeetingHandler. For more details, see [MobileRTCInvitationMeetingHandler].
*/
- (void)onReceiveInvitationToMeeting:(MobileRTCInvitationMeetingHandler *_Nullable)handler;
/*!
 @brief The meeting invitation is canceled by inviter callback.
 @param meetingNumber Cancel meeting number.
*/
- (void)onMeetingInvitationCanceled:(long long)meetingNumber;

/*!
 @brief Callback to accept the meeting invitation on another device.
 @param meetingNumber Accept meeting number.
*/
- (void)onMeetingAcceptedByOtherDevice:(long long)meetingNumber;

/*!
 @brief Callback to decline the meeting invitation on another device.
 @param contactID meeting number that declined by other device.
*/
- (void)onMeetingInvitationDeclined:(NSString *_Nullable)contactID;

/*!
 @brief Callback to decline the meeting invitation.
 @param meetingNumber The IDs of contacts who decline the invitation.
 */
- (void)onMeetingDeclinedByOtherDevice:(long long)meetingNumber;


@end

@interface MobileRTCPresenceHelper : NSObject

/*!
 @brief The delegate for  presence helper's event handler.
 */
@property(nonatomic, assign, nullable)id<MobileRTCPresenceHelperDelegate> delegate;

/*!
 @brief Send a request to get the starred contact IDs..
 @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise failed. To get extended error information, see [MobileRTCSDKError].
 */
- (MobileRTCSDKError)requestStarContact;

/*!
 @brief Send a request to add the contact into a starred contact list.
 @param contactId The contact ID.
 @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise failed. To get extended error information, see [MobileRTCSDKError].
*/
- (MobileRTCSDKError)starContact:(NSString *_Nonnull)contactID;

/*!
 @brief Send a request to remove a contact from the starred contact list.
 @param contactId The contact ID.
 @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise failed. To get extended error information, see [MobileRTCSDKError].
*/
- (MobileRTCSDKError)unStarContact:(NSString *_Nonnull)contactID;

/*!
 @brief Send an invitation to a contact to join a meeting.
 @param contactId The contact ID.
 @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise failed. To get extended error information, see [MobileRTCSDKError].
*/
- (MobileRTCSDKError)inviteContact:(NSString *_Nonnull)contactID;

/*!
 @brief batch invite a list of specified contact to the current meeting.
 @param contactIDList A list which contains contactsID of the specified user.
 @return If the function succeeds, it will return MobileRTCSDKError_Success, otherwise not.
 */
- (MobileRTCSDKError)inviteContactList:(NSArray <NSString *> *_Nonnull)contactIDList;
/*!
 @brief Send a request for contact detail information according to the contact id  list.
 @param contactIDList The contact id list.
 @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise failed. To get extended error information, see [MobileRTCSDKError].
*/
- (MobileRTCSDKError)requestContactDetailInfo:(NSArray <NSString *> *_Nonnull)contactIDList;

/*!
 @brief Send a request to subscribe contact presence status according to the contact id list.
 @param contactIDList The contact id list.
 @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise failed. To get extended error information, see [MobileRTCSDKError].
*/
- (MobileRTCSDKError)subscribeContactPresence:(NSArray <NSString *> *_Nonnull)contactIDList;

/*!
 @brief Send a request to unsubscribe contact presence status according to the contact id list.
 @param contactIDList The contact id list.
 @return If the function succeeds, the return value is MobileRTCSDKError_Success. Otherwise failed. To get extended error information, see [MobileRTCSDKError].
*/
- (MobileRTCSDKError)unSubscribeContactPresence:(NSArray <NSString *> *_Nonnull)contactIDList;

@end



