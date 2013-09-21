//
//  AppboySession.h
//  AppboySDK
//
//  Copyright 2012 Appboy, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#ifndef APPBOY_SDK_VERSION
#define APPBOY_SDK_VERSION @"1.7.2" // September 21, 2013 build
#endif

@interface ABKAdvertising : NSObject
- (void) showBannerAtTopOfView:(UIView*)view withParentController:(UIViewController*)parent;
- (void) showBannerAtBottomOfView:(UIView*)view withParentController:(UIViewController*)parent;
@end

@interface ABKAppearanceConfigurationManager : NSObject

@property (nonatomic, assign) BOOL shouldResizeNavigationBarInLandscape;
@property (nonatomic, assign) BOOL useBackButtonToCloseAppboy;
@property (nonatomic, assign) float customImageCornerRadius;
@property (nonatomic, assign) float customButtonCornerRadius;
@property (nonatomic, retain) NSString *navTitleImageName;
@property (nonatomic, retain) NSString *navBackButtonImageName;
@property (nonatomic, retain) NSString *navBackButtonHighlightedImageName;
@property (nonatomic, retain) NSString *navBarButtonBackgroundImageName;
@property (nonatomic, retain) NSString *navBackgroundImageName;
@property (nonatomic, retain) NSString *sectionHeaderBackgroundImageName;
@property (nonatomic, retain) NSString *customBodyFont;
@property (nonatomic, retain) NSString *customTitleFont;
@property (nonatomic, retain) NSString *customHeaderFont;

@end

@interface AppboySession : NSObject;

/*!
 * @method advertising
 * @discussion Returns an ABKAdvertising object to be used for banner advertisements. Note that this feature is
 *   currently in beta and only available to early beta testers. Use of this method without having advertising
 *   enabled for your account will be a no-op. To become an early beta tester for banner ads, please contact
 *   beta@appboy.com.
 * @return ABKAdvertising object
 */
+ (ABKAdvertising *) advertising;

/*!
 * @method appearance
 * @discussion Returns an ABKAppearanceConfigurationManager object to be used for custom theming. These configuration
 *   options provide additional support than the over-the-air theming available on www.appboy.com. By default, you do
 *   not need to change any of these values.
 *
 *   The available theming properties are:
 *       * shouldResizeNavigationBarInLandscape: If YES, the Appboy navigation bar will be resized to 32 points
 *           when it is in landscape. This is the default for iOS. If NO, Appboy will fix the navigation bar height
 *           remain at 44 points when rotated to landscape. The default value is YES.
 *       * useBackButtonToCloseAppboy: If YES, and you provide a custom back button image for
 *           "navBackButtonImageName", Appboy will remove the close button on the Appboy navigation bar and put
 *           the back button on the left of the navigation bar as a close button; otherwise, the close button will be
 *           on the right side of the navigation bar. The default is NO.
 *       * customImageCornerRadius: The image corner radius (must be >= 0)
 *       * customButtonCornerRadius: The button corner radius (must be >= 0)
 *       * navTitleImageName: The image name of the title image to be used in the center of the navigation bar
 *       * navBackButtonImageName: The image name for the back button item on the navigation bar when in the normal state
 *       * navBackButtonHighlightedImageName: The image name for the back button item on the navigation bar when pressed
 *       * navBarButtonBackgroundImageName: The background image for all bar button items on the navigation bar. It is
 *           your responsibility to provide the right size image, as the SDK will just apply the image without any
 *           resizing. The recommended image height is 30 points and the width should be able to display the word
 *           "Cancel" in whatever font you will use.
 *       * navBackgroundImageName: The name of the image for the background of the navigation bar.
 *       * sectionHeaderBackgroundImageName: The name of the image for the background of table view's section header.
 *           The section header is the graphic that says "News & Alerts" or "Contact Us".
 *       * customBodyFont: The custom font name for all the body text in Appboy. If used, this will overwrite the
 *           font chosen on the appboy.com dashboard. Note if you use a custom font such as Robota, you need to be sure
 *           to include the font information in your plist. The body font is for things like a news item description.
 *       * customTitleFont: The custom font name for all the title text in Appboy. If used, this will overwrite the
 *           font chosen on the appboy.com dashboard. Note if you use a custom font such as Robota, you need to be sure
 *           to include the font information in your plist. The title font is for things like a news item title.
 *       * customHeaderFont: The custom font name for all the header text in Appboy. If used, this will overwrite the
 *           font chosen on the appboy.com dashboard. Note if you use a custom font such as Robota, you need to be sure
 *           to include the font information in your plist. The header font is for things like "News & Alerts".
 * @return ABKAppearanceConfigurationManager object
 *
 */
+ (ABKAppearanceConfigurationManager *) appearance;

/*!
* @method displayAppboy
* @discussion Displays the Appboy user interface. This method will display whatever tab or section the user last
*   visited.
*/
+ (void) displayAppboy;

/*!
 * @method closeAppboy
 * @discussion Closes the Appboy user interface if it is open
 */
+ (void) closeAppboy;

/*!
 * @method setEnabled:
 * @discussion Set whether or not Appboy is enabled. If Appboy is disabled then all public AppboySession methods will
 *   immediately return and Appboy will not send any data to its servers.
 */
+ (void) setEnabled:(BOOL)enabled;

/*!
 * @method isEnabled
 * @discussion Returns whether or not Appboy is enabled or disabled, as set by [AppboySession setEnabled:]
 * @return YES if Appboy is enabled, NO if disabled.
 */
+ (BOOL) isEnabled;

/*!
 * @method registerPushToken:
 * @discussion This method posts a token to Appboy's servers to associate with the current device.
 * @param token Device token that you would receive in the didRegisterForRemoteNotificationsWithDeviceToken delegate.
 */
+ (void) registerPushToken:(NSString *)token;

/*!
  * @method pushNotificationWasSentFromAppboy:
 * @discussion Returns whether or not a push notification was sent from Appboy.
 * @param options The options passed in from applicationDidFinishLaunchingWithOptions or the notification from
 *   applicationDidReceiveRemoteNotification.
 */
+ (BOOL) pushNotificationWasSentFromAppboy:(NSDictionary *)options;

/*!
 * @method registerApplicationDidFinishLaunchingWithOptions:launchOptions
 * @discussion This method registers with Appboy that your app finished launching. You should call this method in the
 *   application:didFinishLaunchingWithOptions method and pass in launchOptions. This method
 *   starts Appboy
 * @param launchOptions The launchOptions object passed into application:didFinishLaunchingWithOptions
 * @param apikey The API key for your app. You can find this on www.appboy.com in the "Settings" section for your app.
 * @param delegate The delegate that implements AppboySessionDelegate.
 * @return YES if Appboy was able to start a new session; NO if unsuccessful.
 */
+ (BOOL) registerApplication:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions withAppboyApiKey:(NSString *)apiKey usingDelegate:(id)delegate;

/*!
 * @method registerApplicationDidReceiveRemoteNotification:notification
 * @discussion This method registers with Appboy that your app received a remote notification. You should call this
 *   method in the application:didReceiveRemoteNotification method and pass in the notification. This method
 *   handles things like recording whether or not the app was opened due to an Appboy push notification.
 * @param notification The notifications object passed into application:didReceiveRemoteNotification
 */
+ (void) registerApplication:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)notification;

/*!
 * @method shareMessage:[imageUrlString]
 * @discussion Prompts the user to post a message to Facebook and Twitter.
 * @param message The string which will pre-populate the textbox containing the message to share on a user's
 *   social networks.
 * @param imagePath Optionally provide an image URL string to be used alongside the share. If the user shares on
 *   Facebook, this image will be displayed alongside the share message.
 */
+ (BOOL) shareMessage:(NSString *)message;

+ (BOOL) shareMessage:(NSString *)message imageUrlString:(NSString *)imagePath;

/*!
 * @method unreadNewsCount
 * @discussion Returns the number of unread news items in Appboy
 * @return int, number of unread news items in Appboy
 */
+ (int) unreadNewsCount;

/*!
 * @method unreadCrossPromotionsCount
 * @discussion Returns the number of unread cross promotion items in Appboy
 * @return int, number of unread cross promotion items in Appboy
 */
+ (int) unreadCrossPromotionsCount;

/*!
 * @method displayFeedback
 * @discussion Opens the Appboy user interface and takes the user to the Feedback section.
 */
+ (void) displayFeedback;

/*!
 * @method displayNews
 * @discussion Displays the News Section in Appboy.
 */
+ (void) displayNews;

/*!
 * @method displayExplore
 * @discussion Displays the Explore tab in Appboy.
 */
+ (void) displayExplore;

/*!
 * @method displayOverview
 * @discussion Displays the Overview tab in Appboy.
 */
+ (void) displayOverview;

/*!
 * @method isReady
 * @discussion This method is used to indicate that Appboy is available and refreshed with the latest information
 *   from the Appboy servers. Note that a return value of NO does not mean that Appboy cannot be displayed to the user.
 * @return YES if Appboy has the latest information from the Appboy servers, NO otherwise.
 */
+ (BOOL) isReady;

/*!
 * @method isDisplayed
 * @discussion Indicates whether or not the Appboy user interface is currently displayed and Appboy is in control of
 *   the view.
 * @return YES if Appboy is displayed, NO otherwise.
 */
+ (BOOL) isDisplayed;

/*!
 * @method enableDataCollectionFromTwitter
 * @discussion If you application does not currently access the user's Twitter account, you should call this method.
 *   This will prompt the user with the dialog box, "<YOUR APP> Would Like Access to Twitter Accounts." Once users
 *   accept this, Appboy will automatically pull down Twitter information about those users on regular intervals. If
 *   your app already asks users for access, this method is optional, as Appboy will detect your app's access and
 *   grab the user data. If you do not already prompt for Twitter access in your app, Appboy's active CRM features
 *   will become active for this user with their Twitter identity after calling this method. If you do prompt for
 *   Twitter access, this method is optional.
 *
 *   Note this only works for iOS5 and higher. In older versions, this method is a no-op.
 *
 *   We generally advise that you don't call this method on startup, as it will immediately prompt your users for
 *   Twitter access.
 */
+ (void) enableDataCollectionFromTwitter;

/*!
 * @method enableDataCollectionFromFacebook
 * @discussion If you application does not currently access the user's Facebook account, you should call this method.
 *   This will prompt the user with the dialog box, "<YOUR APP> Would Like Access to Facebook Accounts." Once users
 *   accept this, Appboy will automatically pull down Facebook information about those users on regular intervals. If
 *   your app already asks users for access, this method is optional, as Appboy will detect your app's access and
 *   grab the user data. If you do not already prompt for Facebook access in your app, Appboy's active CRM features
 *   will become active for this user with their Facebook identity after calling this method. If you do prompt for
 *   Facebook access in your app, this method is optional.
 *
 *   Use of this method requires that you add your Facebook App ID in your app's plist under the key "FacebookAppID"
 *   and you have configured a Facebook app with your bundle ID. For more help, see "Create a Facebook App" at
 *   https://developers.facebook.com/docs/getting-started/facebook-sdk-for-ios/3.1/
 *   Calls to this method without a defined FacebookAppID will NSLog an error and do nothing.
 *
 *   It is highly recommended that you also install the Facebook iOS SDK in your app. If you include the Facebook SDK
 *   in your app, this method will work for all iOS versions and provide a high-quality integration experience for the
 *   end user. If you do not include the Facebook SDK, this method call will only work on iOS6 or higher. For
 *   more documentation, refer to https://www.appboy.com/documentation or email support@appboy.com.
 *
 *   We generally advise that you don't call this method on startup, as it will immediately prompt your users for
 *   Facebook access.
 */
+ (void) enableDataCollectionFromFacebook;

/*!
 * @method setFacebookAccessToken:expiration:
 * @discussion THIS METHOD IS DEPRECATED. You should use the Facebook SDK instead.
 *
 *   This method passes Facebook OAuth token information for the current user to Appboy. For examples
 *   of why you want to do this and how to configure your app in the Appboy Dashboard, refer to
 *   https://www.appboy.com/documentation.
 * @param accessToken The OAuth token for the user you receive from Facebook. Refer to the Facebook SDK documentation
 *   at https://developers.facebook.com/docs/reference/iossdk/authentication/ for information about how to retrieve
 *   this value. Typically this can be retrieved through a call to [facebook accessToken].
 * @param expiration The date at which the OAuth access token expires. Refer to the Facebook SDK documentation for
 *   information about how to retrieve this value.  Typically this can be retrieved through a call to
 *   [facebook expirationDate].
 */
+ (void) setFacebookAccessToken:(NSString *)accessToken expiration:(NSDate *)expiresAt;

/*!
 * @method setTwitterAccessToken:secret:
 * @discussion THIS METHOD IS DEPRECATED. You should use the Twitter and Social frameworks instead.
 *
 *   This method passes Twitter OAuth token information for the current user to Appboy. For examples
 *   of why you want to do this and how to configure your app in the Appboy Dashboard, refer to
 *   https://www.appboy.com/documentation.
 * @param accessToken The OAuth token for the user you receive from Twitter. Refer to the Twitter SDK documentation
 *   at https://dev.twitter.com/docs/auth/obtaining-access-tokens for information about how to retrieve
 *   this value.
 * @param secret The OAuth secret for the user you receive from Twitter. Refer to the Twitter SDK documentation
 *   at https://dev.twitter.com/docs/auth/obtaining-access-tokens for information about how to retrieve
 *   this value.
 */
+ (void) setTwitterAccessToken:(NSString *)accessToken secret:(NSString *)secret;

/*!
 * @method setFoursquareAccessToken:secret:
 * @discussion This method passes Foursquare OAuth token information for the current user to Appboy. For examples
 *   of why you want to do this, refer to https://www.appboy.com/documentation.
 * @param accessToken The OAuth token for the user you receive from Foursquare. Refer to the Foursquare SDK
 *   documentation at https://developer.foursquare.com/overview/auth for information about how
 *   to retrieve this value.
 */
+ (void) setFoursquareAccessToken:(NSString *)accessToken;

/*!
* @method setFirstName:lastName:andEmail:
* @discussion THIS METHOD IS DEPRECATED. You should use setUserAttributes instead.
*
*   This method passes user identifiable information for the current user to Appboy. For examples
*   of why you want to do this, refer to https://www.appboy.com/documentation.
* @param firstName The user's first name you want to record in the user's profile.
* @param lastName The user's last name you want to record in the user's profile.
* @param andEmail The email address of the user to record in the user's profile.
*/
+ (void) setFirstName:(NSString *)firstName lastName:(NSString *)lastName andEmail:(NSString *)email;

/*!
* @method setEmail:email:
* @discussion THIS METHOD IS DEPRECATED. You should use setUserAttributes instead.
*
*   This method passes user identifiable information for the current user to Appboy. For examples
*   of why you want to do this, refer to https://www.appboy.com/documentation.
* @param email The email address of the user to record in the user's profile.
*/
+ (void) setEmail:(NSString *)email;

/*!
* @method getFacebookAccessToken:
* @discussion THIS METHOD IS DEPRECATED. You should use the Facebook SDK instead.
*
*   Returns the Facebook OAuth token for the current user that Appboy after the user has
*   authenticated inside the Appboy user interface (e.g., links his Facebook account to his profile). This value will
*   only be available if you have configured your Facebook app information on your app's settings page on the Appboy
*   Dashboard. If it is not configured, this method will not return anything. Typically you will want to call this
*   method from the AppboyDelegateAccountStatus delegate, which is called after a user successfully authenticates.
* @return The Facebook OAuth token for the current user after an authentication inside the Appboy user interface.
*/
+ (NSString *) getFacebookAccessToken;

/*!
* @method getFacebookAccessExpiration:
* @discussion THIS METHOD IS DEPRECATED. You should use the Facebook SDK instead.
*
*   Returns the Facebook OAuth token expiration date for the current user that Appboy after the user has
*   authenticated inside the Appboy user interface (e.g., links his Facebook account to his profile). This value will
*   only be available if you have configured your Facebook app information on your app's settings page on the Appboy
*   Dashboard. If it is not configured, this method will not return anything. Typically you will want to call this
*   method from the AppboyDelegateAccountStatus delegate, which is called after a user successfully authenticates.
* @return The Facebook OAuth token expiration date for the current user after an authentication inside the Appboy
*   user interface.
*/
+ (NSDate *) getFacebookAccessExpiration;

/*!
* @method getTwitterAccessToken:
* @discussion THIS METHOD IS DEPRECATED. You should use the Twitter and Social frameworks instead.
*
*   Returns the Twitter OAuth token for the current user that Appboy after the user has
*   authenticated inside the Appboy user interface (e.g., links his Twitter account to his profile). This value will
*   only be available if you have configured your Twitter app information on your app's settings page on the Appboy
*   Dashboard. If it is not configured, this method will not return anything. Typically you will want to call this
*   method from the AppboyDelegateAccountStatus delegate, which is called after a user successfully authenticates.
* @return The Twitter OAuth token for the current user after an authentication inside the Appboy user interface.
*/
+ (NSString *) getTwitterAccessToken;

/*!
* @method getTwitterAccessSecret:
* @discussion THIS METHOD IS DEPRECATED. You should use the Twitter and Social frameworks instead.
*
*   Returns the Twitter OAuth secret for the current user that Appboy after the user has
*   authenticated inside the Appboy user interface (e.g., links his Twitter account to his profile). This value will
*   only be available if you have configured your Twitter app information on your app's settings page on the Appboy
*   Dashboard. If it is not configured, this method will not return anything. Typically you will want to call this
*   method from the AppboyDelegateAccountStatus delegate, which is called after a user successfully authenticates.
* @return The Twitter OAuth secret for the current user after an authentication inside the Appboy user interface.
*/
+ (NSString *) getTwitterAccessSecret;

/*!
 * @method logAppEvent:
 * @discussion Adds an app specific event to event tracking log that's lazily pushed up to the server. Think of
 *   events like counters. That is, each time you log an event, we'll update a counter for that user. Events should be
 *   fairly broad like "beat level 1" or "watched video" instead of something more specific like "watched Katy
 *   Perry's Last Friday Night" so you can create more broad user segments for targeting.
 * @param eventName to log
 * @example
 *     [AppboySession logAppEvent:@"clicked_button"];
 */
+ (void) logAppEvent:(NSString *)eventName;

/*!
 * @method logAppPurchase:
 * @discussion Adds an in-app purchase to event tracking log that's lazily pushed up to the server
 * @param productId to log
 * @param price in cents
 * @example
 *     [AppboySession logAppPurchase:@"powerups" priceCents:99];
 */
+ (void) logAppPurchase:(NSString *)productId priceCents:(NSUInteger)price;

/*!
 * @method logFacebookShare
 * @discussion Records that the current user shared something to Facebook. This is added to the event tracking log
 *   that's lazily pushed up to the server
 */
+ (void) logFacebookShare;

/*!
 * @method logTwitterShare
 * @discussion Records that the current user shared something to Twitter. This is added to the event tracking log
 *   that's lazily pushed up to the server
 */
+ (void) logTwitterShare;

/*!
 * @discussion This method lets you associate Appboy's user record with your own user identifier. This is useful for
 *   tracking users across devices, linking a user to events posted to Appboy's Events API, or
 *   joins against your own database.
 *
 *   Once set, this user ID will be used by Appboy to identify the user until you change it or clear it.
 *
 *   You should not set this value to anything mutable: a different value signifies a different user, so do not use
 *   something such as an email address. The best choice here is your database's primary key value for this user.
 * @param userId The String identifier you use in your app.
 */
+ (void) setUserId:(NSString *)userId;

/*!
 * @discussion Clears out the user identifier for the current session.
 */
+ (void) clearUserId;

/*!
 * @discussion If there is a slideup ready to be shown, Appboy will call your delegate method
 * AppboyDelegateShouldDisplaySlideup (if you have implemented it) and take action depending on that result. This method
 * is useful if you want to postpone showing the slideup to some other time in your application.
 */
+ (void) displayNextAvailableSlideup;

/*!
 * @method setUserAttributes:
 * @discussion update the user attributes with the contents of the dictionary.
 *   the keywords in the dictionary must be one of the defined kAppboyAttribute string constants
 *   and the values must all be strings
 * @param attributes dictionary containing new user attributes
 * @example
 *     [AppboySession setUserAttributes:[NSDictionary dictionaryWithObject:@"M" forKey:kAppboyAttributeGender]]
 */
+ (void) setUserAttributes:(NSDictionary *)attributeDictionary;

/*!
 * @method userAttributes:
 * @discussion returns all the user attributes that you have set using setUserAttributes.
 */
+ (NSDictionary *) userAttributes;

/*!
 * @discussion Passing a key of kAppboyAttributeFirstName lets you update the current user's first name. Any string
 *   value is valid.
 *
 * @example  [AppboySession setUserAttributes:[NSDictionary dictionaryWithObject:@"Jon" forKey:kAppboyAttributeFirstName]]
 */
#define kAppboyAttributeFirstName @"first_name"

/*!
* @discussion Passing a key of kAppboyAttributeLastName lets you update the current user's last name. Any string
*   value is valid.
*
* @example  [AppboySession setUserAttributes:[NSDictionary dictionaryWithObject:@"Hyman" forKey:kAppboyAttributeLastName]]
*/
#define kAppboyAttributeLastName @"last_name"

/*!
* @discussion Passing a key of kAppboyAttributeEmail lets you update the current user's email. Any string
*   value is valid.
*
* @example  [AppboySession setUserAttributes:[NSDictionary dictionaryWithObject:@"jon@appboy.com" forKey:kAppboyAttributeEmail]]
*/
#define kAppboyAttributeEmail @"email"

/*!
 * @discussion Passing a key of kAppboyAttributeBio lets you update the current user's bio. Any string value is valid.
 *
 * @example
 *     [AppboySession setUserAttributes:[NSDictionary dictionaryWithObject:@"I'm from Texas!" forKey:kAppboyAttributeBio]]
 */
#define kAppboyAttributeBio @"bio"

/*!
 * @discussion Passing a key of kAppboyAttributeGender lets you update the current user's gender.
 *   The following strings are valid values:
 *     "M"
 *     "F"
 *
 * @example
 *     [AppboySession setUserAttributes:[NSDictionary dictionaryWithObject:@"M" forKey:kAppboyAttributeGender]]
 */
#define kAppboyAttributeGender @"gender"

/*!
 * @discussion Passing a key of kAppboyAttributeDOB lets you update the current user's birthday.
 *   The following string formats are valid values:
 *     "YYYY-MM-DD"
 *     "DD-MM-YYYY"
 *
 * @example
 *     [AppboySession setUserAttributes:[NSDictionary dictionaryWithObject:@"1985-11-24" forKey:kAppboyAttributeDOB]]
 */
#define kAppboyAttributeDOB @"dob"

/*!
 * @discussion Passing a key of kAppboyAttributeCountry lets you update the current user's country. Any string value is
 *   valid.
 *
 * @example  [AppboySession setUserAttributes:[NSDictionary dictionaryWithObject:@"USA" forKey:kAppboyAttributeCountry]]
 */
#define kAppboyAttributeCountry @"country"

/*!
 * @discussion Passing a key of kAppboyAttributeHomeCity lets you update the current user's home city. Any string
 *   value is valid.
 *
 * @example  [AppboySession setUserAttributes:[NSDictionary dictionaryWithObject:@"Dallas" forKey:kAppboyAttributeHomeCity]]
 */
#define kAppboyAttributeHomeCity @"home_city"

/*!
 * @discussion Passing a key of kAppboyAttributeEmailSubscribe lets you store whether or not the user has opted to
 *   subscribe to emails. Note that by default, this is opt-out (that is, users are subscribed to emails) so that you
 *   can send them feedback replies by email and send email campaigns to them. Users can change this value in the
 *   Appboy interface under "Settings" but you can also control it.
 *   Send the strings "true" or "false" to change this value.
 *
 * @example
 *     // Unsubscribe a user from receiving emails
 *     [AppboySession setUserAttributes:[NSDictionary dictionaryWithObject:@"false" forKey:kAppboyAttributeEmailSubscribe]]
 */
#define kAppboyAttributeEmailSubscribe @"email_subscribe"

/*!
 * @discussion Passing a key of kAppboyAttributePhoneNumber lets you set the user's phone number. Any phone number as
 *   a string is valid, but we will remove any non numerical values server-side.
 *
 * @example
 *     [AppboySession setUserAttributes:[NSDictionary dictionaryWithObject:@"2015551234" forKey:kAppboyAttributePhoneNumber]]
 */
#define kAppboyAttributePhoneNumber @"phone"

@end

// Return values for AppboyDelegateShouldDisplaySlideup
typedef enum {
  // This is the default return value when you do not implement AppboyDelegateShouldDisplaySlideup, it makes Appboy
  ShowSlideUpImmediately,
  // This return value will cause Appboy to not show a slide up and completely discard the slideup
  IgnoreSlideUp,
  // Use QueueSlideUpForLater if you intend to later call [AppboySession displayNextAvailableSlideup] in your
  // application.
  QueueSlideUpForLater
} AppboySlideUpQueueResult;

@protocol AppboySessionDelegate

@optional
/*!
 * @method AppboyDelegateStatusChange
 * @discussion This delegate is notified when [AppboySession isReady] changes from false to true. An example use case is
 *   that you could use this delegate to set an unread item count from [AppboySession unreadNewsCount].
 */
- (void) AppboyDelegateStatusChange:(UIWindow *)appboyWindow;

/*!
 * @method AppboyDelegateClosed
 * @discussion This delegate is notified when the Appboy window closes. An example use case is
 *   that you could use this delegate to update an unread item count from [AppboySession unreadNewsCount] after the user
 *   exits Appboy.
 */
- (void) AppboyDelegateClosed:(UIWindow *)appboyWindow;

/*!
 * @method AppboyDelegateAccountStatus
 * @discussion THIS METHOD IS DEPRECATED. You should use the Twitter and Social frameworks and Facebook SDK instead.
 *
 *   This delegate is notified after a user has successfully authenticated to a social network inside the
 *   Appboy user interface. It will only be triggered if you have Facebook and Twitter app information configured on
 *   your app's settings page. If this is not configured, the delegate will not be invoked.
 *
 *   As for timing, this delegate will be called when the user hits the Close button to exit out of Appboy and return
 *   to your application.
 */
- (void) AppboyDelegateAccountStatus;

/*!
 * @method AppboyDelegateShouldDisplaySlideup
 * @discussion Appboy sometimes slides up notifications to alert the user to new content. This delegate allows you to
 *   control whether or not the slideup is shown if Appboy has a message to display in it. This delegate is only called
 *   if Appboy has a message to display in the slideup.
 * @param slideupContext A dictionary of information describing the slideup. The main value you might want to inspect is
 *   the objectForKey:kAppboySlideupKeyMessage, which contains the message of the slideup.
 * @return AppboySlideUpQueueResult; if this method is not implemented, Appboy will treat it as if it returned
 * ShowSlideUpImmediately.
 */
- (AppboySlideUpQueueResult) AppboyDelegateShouldDisplaySlideup:(NSDictionary *)slideupContext;

/*!
 * Keywords to be used in the AppboyDelegateShouldDisplaySlideup:slideupContext dictionary.
 */

/*!
 * objectForKey:kAppboySlideupKeyMessage contains the message of the slideup.
 */
#define kAppboySlideupKeyMessage @"message"
@end
