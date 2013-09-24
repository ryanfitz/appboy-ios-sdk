## 1.7.2 (09/21/2013)
* Fixes a crashing issue affecting all iPhone 5c and 5s devices. All users of previous versions of v1 of the Appboy SDK are recommended to upgrade to version 2.1.1 or later. However, if continued use of v1 is required, or upgrading to 2.1.1 or later would delay the release of a version of your app with the new Appboy SDK, this version will fix the crashing issue with no other changes required.

## 1.7 (03/28/2013)
* Updates Appboy session start signature which improves handling of app interruptions

## 1.6.15 (03/26/2013)
* Updates version collection used for analytics from using the bundle's kCFBundleVersionKey to CFBundleShortVersionString

## 1.6.13 (03/12/2013)
* Fixes a memory leak and potential crash with location manager

## 1.6.11 (02/18/2013)
* Adds [AppboySession setUserId] to allow you to track users across devices and tie them to your database
* Adds supporting architecture for future improvements

## 1.6.10 (02/10/2013)
* Adds [AppboySession appearance] for enhanced custom theming
* Optimizations

## 1.6.9 (01/22/2013)
* Added [AppboySession pushNotificationWasSentFromAppboy:] to allow you to determine if a push notification came from Appboy

## 1.6.7 (01/17/2013)
* Added [AppboySession unreadNewsCount] and [AppboySession unreadCrossPromotionsCount] to allow you to determine the number of unread items in Appboy
* Bug fixes

## 1.6.6 (01/15/2013)
* Added the delegate AppboyDelegateClosed which triggers when the Appboy window closes
* Improved performance for protocol URLs in news items
* Various other improvements

## 1.6.5 (12/19/2012)
* Bug fixes

## 1.6.4 (12/17/2012)
* Added [AppboySession closeAppboy] to allow for programmatic closing of Appboy
* Added [AppboySession setEnabled] to enable/disable Appboy

## 1.6.3 (11/30/2012)
* Internal updates to support future updates. We recommend updating to this version if you &lt; 1.6.3

## 1.6.2 (11/20/2012)
* Bug fix: If Twitter was in a bad state on the device and unable to authenticate, Appboy could crash


## 1.6.1 (11/14/2012)
* Added email address as a required field for submitting feedback


## 1.6 (10/25/2012)
* Appboy now <%= link_to "integrates entirely with the Twitter Framework, Social Framework, and Facebook SDK",
                     {:controller => :documentation,
                      :action => :integration,
                      :pill => :identity, :anchor => "social-framework"}, :class => 'push-state' %>
* Added [AppboySession logTwitterShare] and [AppboySession logFacebookShare] to allow developers to track social network sharing
* Added [AppboySession registerApplication:didFinishLaunchingWithOptions] when app starts up
* Added [AppboySession registerApplication:didReceiveRemoteNotification] for push notification tracking and in-app notification upon push arrival
* Added [AppboySession registerApplication:didReceiveRemoteNotification] for push notification tracking and in-app notification upon push arrival
* Improved iOS6 support
* Automatically tracking more device attributes such as carrier, resolution, locale, and device model
* Improved performance
* Deprecations: The following methods are deprecated and will be removed in the next version of Appboy.
  * The delegate AppboyDelegateAccountStatus. You should now use the Facebook SDK to get OAuth tokens.
  * [AppboySession setFirstName:lastName:andEmail] has been deprecated in favor of [AppboySession setUserAttributes]
  * [AppboySession setEmail] has been deprecated in favor of [AppboySession setUserAttributes]
  * [AppboySession setFacebookAccessToken:expiration] has been deprecated in favor of using the Facebook SDK
  * [AppboySession setTwitterAccessToken:secret] has been deprecated in favor of using the Twitter and Social Frameworks in your app

## 1.5.5 (09/20/2012)
* Added support for iOS6

## 1.5.4 (08/30/2012)
* Removed lightning bolt from the UI
* Added custom theming for adding an image to Appboy's header bar

## 1.5.3 (08/23/2012)
* Added extra attributes for [AppboySession setUserAttributes] to set phone number, country, and city
* Improved theming when using custom fonts

## 1.5.2 (08/13/2012)
* Added [AppboySession setUserAttributes] method for user identification
* Minor UI tweaks (autoresizing for iPad port, reworded labels on Appboy tab bar)

## 1.5.1 (08/07/2012)
* Added iPad Support by porting the iPhone user interface to iPad &mdash; a new UI/UX for iPad is coming soon
* Added automatic impression tracking of Cross Promotion items on the Explore tab
* Added [AppboySession logAppEvent] to allow developers to track custom events on a per-user basis
* Added [AppboySession logAppPurchase] to allow developers to record that a user made an in-app purchase
* [AppboySession shareWithMessage] now opens up the keyboard automatically to reduce friction for sharing
* Improved connectivity monitoring so if your app is opened without internet connectivity, Appboy will contact our servers as soon as connectivity resumes
* Various bug fixes

## 1.4.1 (07/11/2012)
* Bug fix: [AppboySession displayNews] crashes if you don't have any news
* Bug fix: Feedback and share messages with percent signs cannot be sent

## 1.4 (06/22/2012)
* Added [AppboySession setFoursquareAccessToken], [AppboySession setEmail], and [AppboySession setFirstName lastName andEmail] for user identification
* [AppboySession set*AccessToken] methods now operate in the background
* Removed the need for [AppboySession isReady] guard clauses around Appboy calls. If not ready, Appboy will display a loading spinner.
* Improved user interface of Appboy slideup and various other UI tweaks

## 1.3.1 (06/06/2012)
* Added AppboyDelegateAccountStatus delegate to allow developers to get Facebook and Twitter credentials from Appboy
* Bug fix: Appboy now does not go into landscape if the host app is portrait-only
* Bug fix: Further improvements to location service handling to consume less power
* Various UI tweaks

## 1.3 (06/01/2012)
* BREAKING CHANGE: The view controller referenced in [AppboySession sessionWithApiKey: usingDelegate:self.viewController] must now implement AppboySessionDelegate
* BREAKING CHANGE: Removed [AppboySession displayWith:] in favor of [AppboySession displayAppboy]
* BREAKING CHANGE: Removed [AppboySession isEnabled] and [AppboySession hasConnectivity]. These methods are now abstracted behind [AppboySession isReady]
* Added landscape views
* Added support for push notifications
* Added [AppboySession setFacebookAccessToken] and [AppboySession setTwitterAccessToken] to allow you to pass user information to Appboy
* Added [AppboySession display*] methods to programmatically open Appboy's different sections
* Embedded and renamed internal SBJson to avoid conflicts with host applications that use older versions of SBJson
* Bug fix: Improved location service handling to consume less power
* Bug fix: Dozens of UI fixes and issues with poor internet connectivity

## 1.2 (04/19/2012)
* Added automatic location collection if CoreLocation.framework is included in the build
* Added AppboyDelegateStatusChange delegate to notify when Appboy is ready
* Added AppboyDelegateShouldDisplaySlideup to allow developer to suppress the slideup
* Added support for theming Appboy button, header, and lightning bolt colors
* Renamed &quot;AB&quot; prefix on all Appboy classes to avoid conflicts with Address Book libraries
* Bug fix: Linking social networks on Join tab moves to Overview tab after authentication if it is the first social network link.
* Bug fix: Authenticating to social networks via the Share tab doesn't tear down the UIWebView
* Bug fix: Feedback from users who log in then immediately provide feedback shows up as a Guest account on the dashboard

## 1.1 (03/22/2012)
* Initial release.
