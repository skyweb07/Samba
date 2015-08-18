
# Samba
 
[![Version](https://img.shields.io/cocoapods/v/Samba.svg?style=flat)](http://cocoapods.org/pods/Samba)
[![License](https://img.shields.io/cocoapods/l/Samba.svg?style=flat)](http://cocoapods.org/pods/Samba)
[![Platform](https://img.shields.io/cocoapods/p/Samba.svg?style=flat)](http://cocoapods.org/pods/Samba)

## Description

Samba is a mini port for Swift 2.0 availability checking. If you've been into the iOS development I'm sure that you know the tedious work to check if a particular API is available on the device your application is running on. Before Swift 2 availability check you probably had something like this

```objective-c
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 80000
	// use registerUserNotificationSettings
#else
	// use registerForRemoteNotificationTypes
#endif
```

or

```objective-c
if ([application respondsToSelector:@selector(registerUserNotificationSettings:)]) {
	// use registerUserNotificationSettings
} else {
	// use registerForRemoteNotificationTypes
}
```

or some macros for checking if the OS is at least a version and then do the dirty work. Well with Swift 2.0 this is as easy as

```swift
if #available(iOS 8.0, *) {
	// use registerUserNotificationSettings
} else {
	// use registerForRemoteNotificationTypes
}
```

`Simple and elegant`, that's what we want. In Objective-C we don't have that nice feature so `Samba` is trying to fix that hole with a simple function that do the system version check for you.

```objective-c
SKOperatingSystemVersion version = (SKOperatingSystemVersion) {8, 0, 0};

available(version, ^{
	// use registerUserNotificationSettings
}, ^{
	// use registerForRemoteNotificationTypes
});
```

Simple ha?, in the end `Samba` uses a simple compare againts *[UIDevice currentDevice].systemVersion* but it's simpler than having all your code full of if's checks. 

`Swift 2.0 availability check` is more powerfull than this but you get the idea behind `Samba`, if you want to keep reading about this Swift new feature you can check this docs:

- http://code.tutsplus.com/tutorials/swift-20-availability-checking--cms-24340

- https://www.hackingwithswift.com/new-syntax-swift-2-availability-checking

## Requirements

iOS 7.0 and later

## Installation

Samba is available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod "Samba"
```

## Author

Oscar Antonio Duran Grillo, skyweb09@hotmail.es

## License

Samba is available under the MIT license. See the LICENSE file for more info.

Happy coding 🍻
