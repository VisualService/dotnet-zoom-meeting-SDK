//
//  MobileRTCMeetingService+BO.h
//  MobileRTC
//
//  Created by Zoom Video Communications on 2020/2/11.
//  Copyright © 2020 Zoom Video Communications, Inc. All rights reserved.
//


#import <MobileRTC/MobileRTC.h>
#import "MobileRTCBORole.h"

@interface MobileRTCMeetingService (BO)

/*!
@brief get MobileRTCBOCreator object
*/
- (MobileRTCBOCreator * _Nullable)getCreatorHelper;

/*!
@brief get MobileRTCBOAdmin object
*/
- (MobileRTCBOAdmin * _Nullable)getAdminHelper;

/*!
@brief get MobileRTCBOAssistant object
*/
- (MobileRTCBOAssistant * _Nullable)getAssistantHelper;

/*!
@brief get MobileRTCBOAttendee object
*/
- (MobileRTCBOAttendee * _Nullable)getAttedeeHelper;

/*!
@brief get MobileRTCBOData object
*/
- (MobileRTCBOData * _Nullable)getDataHelper;

/*!
@brief is BO meeting started.
*/
- (BOOL)isBOMeetingStarted;

/*!
@brief is BO meeting feature enabled in web page.
*/
- (BOOL)isBOMeetingEnabled;

/*!
@brief is in bo meeting right now.
*/
- (BOOL)isInBOMeeting;

/*!
@brief Get current BO status
@return The return value is a enum for bo status.
*/
- (MobileRTCBOStatus)getBOStatus;

@end


