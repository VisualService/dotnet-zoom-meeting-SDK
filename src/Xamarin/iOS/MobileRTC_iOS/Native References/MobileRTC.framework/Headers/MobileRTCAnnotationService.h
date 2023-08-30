//
//  MobileRTCAnnotationService.h
//  MobileRTC
//
//  Created by Zoom Video Communications on 2018/6/12.
//  Copyright © 2019 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 @brief An enumeration of annotation tool types in meeting. 
 */
typedef NS_ENUM(NSUInteger, MobileRTCAnnoTool) {
    MobileRTCAnnoTool_None = 0,
    MobileRTCAnnoTool_Pen,
    MobileRTCAnnoTool_HighLighter,
    MobileRTCAnnoTool_AutoLine,
    MobileRTCAnnoTool_AutoRectangle,
    MobileRTCAnnoTool_AutoEllipse,
    MobileRTCAnnoTool_AutoArrow,
    MobileRTCAnnoTool_AutoArrow2,
    MobileRTCAnnoTool_AutoRectangleFill,
    MobileRTCAnnoTool_AutoEllipseFill,
    MobileRTCAnnoTool_SpotLight,
    MobileRTCAnnoTool_Arrow,
    MobileRTCAnnoTool_ERASER,
    MobileRTCAnnoTool_Picker,
    MobileRTCAnnoTool_AutoRectangleSemiFill,
    MobileRTCAnnoTool_AutoEllipseSemiFill,
    MobileRTCAnnoTool_AutoDoubleArrow,
    MobileRTCAnnoTool_AutoDiamond,
    MobileRTCAnnoTool_AutoStampArrow,
    MobileRTCAnnoTool_AutoStampCheck,
    MobileRTCAnnoTool_AutoStampX,
    MobileRTCAnnoTool_AutoStampStar,
    MobileRTCAnnoTool_AutoStampHeart,
    MobileRTCAnnoTool_AutoStampQm,
};

/*!
 @brief An enumeration of clear annotation tool types in meeting.
 */
typedef NS_ENUM(NSUInteger, MobileRTCAnnoClearType) {
    MobileRTCAnnoClearType_All = 0, ///<Clear all annotations. Hosts, managers and shared meeting owners can use.
    MobileRTCAnnoClearType_My,      ///<Clear only your own annotations. Everyone can use.
    MobileRTCAnnoClearType_Others,  ///<Clear only the others' annotations. Only shared meeting owners can use.
};

/*!
 @brief The method is used to provide annotate service. 
 @warning User, as the presenter, should stop the current share before starting another share. 
 */

@class MobileRTCAnnotationService;
/*!
 @class MobileRTCAnnotationServiceDelegate
 @brief the share sender will disable the annotation, this delegate will notify the status change to viewer #only for custom UI#.
 */
@protocol MobileRTCAnnotationServiceDelegate <NSObject>
@optional
- (void)onAnnotationService:(nullable MobileRTCAnnotationService *)service supportStatusChanged:(BOOL)support;
@end

@interface MobileRTCAnnotationService : NSObject

/*!
 @brief Callback of receiving meeting events.
 */
@property (weak, nonatomic) id<MobileRTCAnnotationServiceDelegate> _Nullable delegate;

/*!
 @brief Set to start annotations on the shared view. 
 @param view The shared view. 
 @return The result of operation.
 */
- (MobileRTCAnnotationError)startAnnotationWithSharedView:(nullable UIView*)view;

/*!
 @brief Set to stop annotations.
 @return The result of operation. 
 */
- (BOOL)stopAnnotation;

/*!
 @brief Set the colors of annotation tools.
 @return The result of setting the colors.
 */
- (MobileRTCAnnotationError)setToolColor:(nullable UIColor *)toolColor;

/*!
 @brief This method is used to get current Anno Tool Color.
 @return Get color by tool type.
 */
- (nullable UIColor *)getToolColor;

/*!
 @brief Set the types of annotation tools.  
 @return The result of operation.
 */
- (MobileRTCAnnotationError)setToolType:(MobileRTCAnnoTool)type;

/*!
 @brief Get the annotation tool type.
 @return The current tool type.
 */
- (MobileRTCAnnoTool)getToolType;

/*!
 @brief Set the line width of annotation tools.  
 @return The result of operation.
 */
- (MobileRTCAnnotationError)setToolWidth:(NSUInteger)width;

/*!
 @brief Get the annotation tool width.
 @return The current tool width.
 */
- (NSUInteger)getToolWidth;

/*!
 @brief Clears the annotation content.
 @param type the specify clear type.
 @return The result of it.
 */
- (MobileRTCAnnotationError)clear:(MobileRTCAnnoClearType)type;

/*!
 @brief Undo the last annotation.  
 @return The result of undoing the annotations.
 */
- (MobileRTCAnnotationError)undo;

/*!
 @brief Redo the last annotation.
 @return The result of redoing the annotations. 
 */
- (MobileRTCAnnotationError)redo;

/*!
 @brief Check if the current user is the presenter.
 @return Yes if be presenter.
 */
- (BOOL)isPresenter;

/*!
 @brief Check if support to disable viewer's annotation item.
 @return Yes if support.
 */
- (BOOL)canDisableViewerAnnoataion;

/*!
 @brief Check currently sender disabled the viewer's annotation or not.
 @return Yes if disabled viewer's annotation.
 */
- (BOOL)isViewerAnnoataionDisabled;

/*!
 @brief disable viewer's annotation.
 @return MobileRTCAnnotationError_Successed if disabled the viewer's annotation success.
 */
- (MobileRTCAnnotationError)disableViewerAnnoataion:(BOOL)isDisable;

/*!
 @brief Check can do annotation or not.
 @return Yes if can do the annotation.
 */
- (BOOL)canDoAnnotation;

/*!
 @brief Is annotation legal notice available.
 @return available or not.
 */
- (BOOL)isAnnotationLegalNoticeAvailable;

/*!
 @brief Get annotation over share legal notices prompt.
 @return annotation over share legal notices prompt.
 */
- (NSString *_Nullable)getAnnotationLegalNoticesPrompt;

/*!
 @brief Get annotation over share legal notices explained.
 @return annotation over share legal notices explained.
 */
- (NSString *_Nullable)getAnnotationLegalNoticesExplained;

@end
