//
//  ABKFeedViewControllerPopoverContext.h
//  AppboySDK
//
//  Copyright (c) 2013 Appboy. All rights reserved.
//
//  The FeedViewController classes implement the scrolling view of cards you display for users of your app.
//  To integrate, simply create a FeedViewController -- either programmatically or in a storyboard -- like
//  you'd create any view controller, and present it.
//
//  There are four different versions of the FeedViewController: Generic, Modal, Popover, and Navigation.
//  Pick the one which matches the context in which you're using the FeedViewController; for example,
//  if you present the FeedViewController in a modal view, use FeedViewControllerModalContext. If you
//  present it in a popover, use FeedViewControllerPopoverContext.
//
// ---------------------------------------------------------------------------------------------------------------
//
//  Use the FeedViewControllerPopoverContext to present a feed view controller in a popover.
//
//  This controller provides a "close" button on the popover's navigation bar. When the button
//  is tapped, the controller sends the ABKFeedViewControllerPopoverContextCloseTapped:sender message to
//  closeButtonDelegate.  You can use this message to trigger closing the popover.
//  The delegate should adopt the ABKFeedViewControllerPopoverContextDelegate protocol.

#import <UIKit/UIKit.h>
#import "ABKFeedViewControllerContext.h"

@protocol ABKFeedViewControllerPopoverContextDelegate;

@interface ABKFeedViewControllerPopoverContext : ABKFeedViewControllerContext

// Title displayed in the top bar
@property (retain, nonatomic) NSString *navigationBarTitle;

// Delegate
@property (assign, nonatomic) id closeButtonDelegate;

@end


@protocol ABKFeedViewControllerPopoverContextDelegate <NSObject>

- (void) feedViewControllerPopoverContextCloseTapped:(ABKFeedViewControllerPopoverContext *)sender;

@end
