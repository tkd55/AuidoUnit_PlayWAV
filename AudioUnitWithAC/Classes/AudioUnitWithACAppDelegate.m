//
//  AudioUnitWithACAppDelegate.m
//  AudioUnitWithAC
//
//  Created by takeda on 13/05/19.
//  Copyright (c) 2013年 takeda. All rights reserved.
//
#import "AudioUnitWithACAppDelegate.h"
#import "AudioUnitWithACViewController.h"

@implementation AudioUnitWithACAppDelegate

@synthesize window;
@synthesize viewController;


- (void)applicationDidFinishLaunching:(UIApplication *)application {    
    
    // Override point for customization after app launch    
    [window addSubview:viewController.view];
    [window makeKeyAndVisible];
}


- (void)dealloc {
    [viewController release];
    [window release];
    [super dealloc];
}


@end
