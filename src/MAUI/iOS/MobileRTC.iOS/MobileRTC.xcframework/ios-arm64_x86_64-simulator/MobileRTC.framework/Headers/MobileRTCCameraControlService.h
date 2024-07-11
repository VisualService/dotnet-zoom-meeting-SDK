//
//  MobileRTCRemoteControlService.h
//  MobileRTC
//
//  Created by Zoom Video Communications on 2024/5/28.
//  Copyright © 2019 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, MobileRTCCameraControlRequestType) {
    MobileRTCCameraControlRequestType_RequestControl,
    MobileRTCWhiteboardStatus_GiveUpControl,
};

typedef NS_ENUM(NSInteger, MobileRTCCameraControlRequestResult) {
    MobileRTCCameraControlRequestResult_Approve,
    MobileRTCCameraControlRequestResult_Decline,
    MobileRTCCameraControlRequestResult_Revoke
};

/*!
 @brief Callback event of receiving remote control.
 */
@protocol MobileRTCCameraControlDelegate <NSObject>

@optional
/*!
 @brief Callback for when the current user is granted camera control access.
 Once the current user sends the camera control request, this callback will be triggered with the result of the request.
 @param userId  The user ID that accepted the request.
 @param isApproved The result of the camera control request.
 */
- (void)onCameraControlRequestResult:(NSUInteger)userId isApproved:(MobileRTCCameraControlRequestResult)isApproved;

@end

@interface MobileRTCCameraControlService : NSObject

/*!
 @brief Callback event of receiving camera control.
 */
@property (weak, nonatomic) id<MobileRTCCameraControlDelegate> _Nullable delegate;

/*!
 @brief the current controlled user id
 @return the current controlled user id
 */
-(NSInteger)getUserId;

/*!
 @brief Used to determine whether the camera can be controlled or not.
 @return YES means can control camera.
 */
- (BOOL)canControlCamera;

/*!
 * @brief Request to control remote camera.
 * @return If the function succeeds, the return value is MobileRTCSDKError, see \link MobileRTCSDKError \endlink enum.
 */
- (MobileRTCSDKError)requestControlRemoteCamera;

/*!
 * @brief Give up control of the remote camera.
 * @return If the function succeeds, the return value is MobileRTCSDKError, see \link MobileRTCSDKError \endlink enum.
 */
- (MobileRTCSDKError)giveUpControlRemoteCamera;

/*!
 * @brief Turn the camera to the left.
 * @param range Rotation range, range is between 10 and 100.
 * @return If the function succeeds, the return value is MobileRTCSDKError, see \link MobileRTCSDKError \endlink enum.
 */
- (MobileRTCSDKError)turnLeft:(NSInteger)range;

/*!
 * @brief Turn the camera to the right.
 * @param range Rotation range, range is between 10 and 100.
 * @return If the function succeeds, the return value is MobileRTCSDKError, see \link MobileRTCSDKError \endlink enum.
 */
- (MobileRTCSDKError)turnRight:(NSInteger)range;

/*!
 * @brief Turn the camera up.
 * @param range Rotation range, range is between 10 and 100.
 * @return If the function succeeds, the return value is MobileRTCSDKError, see \link MobileRTCSDKError \endlink enum.
 */
- (MobileRTCSDKError)turnUp:(NSInteger)range;

/*!
 * @brief Turn the camera down.
 * @param range Rotation range, range is between 10 and 100.
 * @return If the function succeeds, the return value is MobileRTCSDKError, see \link MobileRTCSDKError \endlink enum.
 */
- (MobileRTCSDKError)turnDown:(NSInteger)range;

/*!
 * @brief Zoom the camera in.
 * @param range Rotation range, range is between 10 and 100.
 * @return If the function succeeds, the return value is MobileRTCSDKError, see \link MobileRTCSDKError \endlink enum.
 */
- (MobileRTCSDKError)zoomIn:(NSInteger)range;

/*!
 * @brief Zoom the camera out.
 * @param range Rotation range, range is between 10 and 100.
 * @return If the function succeeds, the return value is MobileRTCSDKError, see \link MobileRTCSDKError \endlink enum.
 */
- (MobileRTCSDKError)zoomOut:(NSInteger)range;

@end

