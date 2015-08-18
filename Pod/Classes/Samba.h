//
//  Samba.h
//
//  Created by Oscar Antonio Duran Grillo on 18/8/15.
//  Copyright (c) 2015 © SkyDev 2015. All rights reserved.
//
//     _____                 __
//    / ___/____ _____ ___  / /_  ____ _
//    \__ \/ __ `/ __ `__ \/ __ \/ __ `/
//   ___/ / /_/ / / / / / / /_/ / /_/ /
//  /____/\__,_/_/ /_/ /_/_.___/\__,_/
//

#import <Foundation/Foundation.h>
#import <UIKit/UIDevice.h>

/**
 *  This block will be executed if validation passes
 */
typedef void (^SambaRunBlock)();

/**
 *  System version structure
 */
typedef struct {
    NSInteger majorVersion;
    NSInteger minorVersion;
    NSInteger patchVersion;
} SKOperatingSystemVersion;

NS_INLINE BOOL operatingSystemAtLeastVersion(SKOperatingSystemVersion version) {
    NSString *composedSystemVersion = [NSString stringWithFormat:@"%ld.%ld", version.majorVersion, version.minorVersion];
    NSString *systemVersion = [UIDevice currentDevice].systemVersion;
    
    if (version.patchVersion) {
        composedSystemVersion = [composedSystemVersion stringByAppendingFormat:@".%ld", version.patchVersion];
    }
    
    NSComparisonResult result = [systemVersion compare:composedSystemVersion options:NSNumericSearch];
    
    if (result == NSOrderedSame || result == NSOrderedDescending) {
        return YES;
    }
    return NO;
}

/**
 *  Check if the operating system is executing the same or later version than the `minimumSystemVersion`.
 *
 *  @param minimumSystemVersion The operating system version to test against.
 *  @param runBlock             Block that will be executed if the `minimumSystemVersion` is the same or later than the operating system version.
 *  @param elseRunBlock         Block that will be executed if the operating system version is before than the `minimumSystemVersion`,
 */
NS_INLINE void available(SKOperatingSystemVersion minimumSystemVersion, SambaRunBlock runBlock, SambaRunBlock elseRunBlock) {
    if (operatingSystemAtLeastVersion(minimumSystemVersion)) {
        if (runBlock) { runBlock(); return; }
    }
    if (elseRunBlock) { elseRunBlock(); }
}