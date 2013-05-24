//
//  AudioUnitWithACAppDelegate.h
//  AudioUnitWithAC
//
//  Created by takeda on 13/05/19.
//  Copyright (c) 2013年 takeda. All rights reserved.
//

#import <UIKit/UIKit.h>

@class AudioUnitWithACViewController;

@interface AudioUnitWithACAppDelegate : NSObject <UIApplicationDelegate> {
    UIWindow *window;
    AudioUnitWithACViewController *viewController;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) IBOutlet AudioUnitWithACViewController *viewController;

@end

