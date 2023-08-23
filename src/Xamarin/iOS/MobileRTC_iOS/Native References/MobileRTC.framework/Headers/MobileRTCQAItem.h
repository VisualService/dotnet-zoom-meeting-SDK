//
//  MobileRTCQAMessage.h
//  MobileRTC
//
//  Created by Zoom Video Communications on 2019/10/11.
//  Copyright © 2019 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 @brief The Q&A answer interface.
 */
@interface MobileRTCQAAnswerItem : NSObject

- (NSDate *_Nullable)getTime;
- (NSString *_Nullable)getText;
- (NSString *_Nullable)getSenderName;
- (NSString *_Nullable)getQuestionId;
- (NSString *_Nullable)getAnswerID;

- (BOOL)isPrivate;
- (BOOL)isLiveAnswer;
- (BOOL)isSenderMyself;

@end

/*!
 @brief The Q&A question interface.
 */
@interface MobileRTCQAItem : NSObject

- (NSString *_Nullable)getQuestionId;
- (NSDate *_Nullable)getTime;


- (NSString *_Nullable)getText;
- (NSString *_Nullable)getSenderName;


- (BOOL)isAnonymous;
- (BOOL)isMarkedAsAnswered;
- (BOOL)isMarkedAsDismissed;


- (NSUInteger)getUpvoteNumber;

- (BOOL)getHasLiveAnswers;
- (BOOL)getHasTextAnswers;


- (BOOL)isMySelfUpvoted;
- (BOOL)amILiveAnswering;
- (BOOL)isLiveAnswering;
- (NSString *_Nullable)getLiveAnswerName;

- (BOOL)isSenderMyself;

- (nullable NSArray <MobileRTCQAAnswerItem *>*)getAnswerlist;
@end


