//
//  ConverterOutput.h
//  AudioUnitWithAC
//
//  Created by takeda on 13/05/19.
//  Copyright (c) 2013年 takeda. All rights reserved.
//

#import <AudioUnit/AudioUnit.h>
#import <AudioToolbox/AudioToolbox.h>
#import <AudioToolbox/AudioConverter.h>


typedef struct AudioFileIO{
    AudioFileID		audioFileID;
    SInt64			startingPacketCount;
    char *			srcBuffer;
    UInt32			srcBufferSize;
    AudioStreamBasicDescription srcFormat;
    UInt32			srcSizePerPacket;
    UInt32			numPacketsToRead;
    AudioStreamPacketDescription * packetDescs;
    
    UInt64 totalPacketCount;
    BOOL isLoop;
    BOOL isDone;
}AudioFileIO;

@interface AUAudioFilePlayer : NSObject {
    AudioUnit audioUnit;
    BOOL isPlaying;
    
    AudioConverterRef audioConverter;
    AudioFileIO audioFileIO;    
    AudioStreamBasicDescription outputFormat;
}

-(void)fillBuffer:(AudioBufferList*)ioData inNumberFrames:(UInt32)inNumberFrames;

@property BOOL isLoop;
@property UInt64 currentPosition;

-(void)play;
-(void)stop;

-(UInt64)totalPacketCount;
-(UInt64)currentPosition;
-(void)setCurrentPosition:(UInt64)position;
-(void)setIsLoop:(BOOL)flag;

-(void)prepareAudioUnit;
-(void)prepareAudioConverter:(NSURL*)url;
@end