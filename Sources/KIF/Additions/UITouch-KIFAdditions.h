//
//  UITouch-KIFAdditions.h
//  KIF
//
//  Created by Eric Firestone on 5/20/11.
//  Licensed to Square, Inc. under one or more contributor license agreements.
//  See the LICENSE file distributed with this work for the terms under
//  which Square, Inc. licenses this file to you.

#import <UIKit/UIKit.h>
#import "IOHIDEvent+KIF.h"

@interface UIPanGestureVelocitySample : NSObject
@property (assign) double dt;     // @synthesize
@property (assign) CGPoint end;   // @synthesize
@property (assign) CGPoint start; // @synthesize
@end

@interface UIPanGestureRecognizer ()
- (void)_processTouchesMoved:(id)arg1 withEvent:(id)arg2;
- (void)_handleEndedTouches:(id)arg1 withFinalStateAdjustments:(id)arg2;
- (BOOL)_updateMovingTouchesArraySavingOldArray:(id *)arg1;
- (id)_velocitySample;
- (void)_resetVelocitySamples;
- (UIPanGestureVelocitySample *)_previousVelocitySample;

@end

@interface UITouch ()

- (void)setWindow:(UIWindow *)window;
- (void)setView:(UIView *)view;
- (void)setTapCount:(NSUInteger)tapCount;
- (void)setIsTap:(BOOL)isTap;
- (void)setTimestamp:(NSTimeInterval)timestamp;
- (void)setPhase:(UITouchPhase)touchPhase;
- (void)setGestureView:(UIView *)view;
- (void)_setLocationInWindow:(CGPoint)location resetPrevious:(BOOL)resetPrevious;
- (void)_setIsFirstTouchForView:(BOOL)firstTouchForView;
- (void)_setIsTapToClick:(BOOL)tapToClick;

- (void)_setHidEvent:(IOHIDEventRef)event;

@end

@interface UITouch (KIFAdditions)

@property (nonatomic, strong) UIView *hitTestView;

- (id)initInView:(UIView *)view;
- (id)initAtPoint:(CGPoint)point inView:(UIView *)view;
- (id)initAtPoint:(CGPoint)point inWindow:(UIWindow *)window;
- (void)setUITouchParams:(CGPoint)point inWindow:(UIWindow *)window;

- (void)setLocationInWindow:(CGPoint)location;
- (void)setPhaseAndUpdateTimestamp:(UITouchPhase)phase;

@end
