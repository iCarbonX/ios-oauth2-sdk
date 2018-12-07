//
//  ICXOauthView.h
//  ManYue
//
//  Created by yangcq on 2018/12/7.
//  Copyright © 2018年 ICX. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
//#import <WebViewJavascriptBridge/WebViewJavascriptBridge.h>
#import "WebViewJavascriptBridge.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ICXOauthType) {
    ICXOauthTypeOauth,          //走授权模式
    ICXOauthTypeGetCode,        //直接获取code
};

@protocol ICXOauthViewDelegate <NSObject>

//js回调信息
- (void)icxOauthViewAouthInfo:(NSDictionary *)info;

@optional

//获取到的code
- (void)icxOauthViewGetcode:(NSString *)code;

@end


@interface ICXOauthView : UIView <WKNavigationDelegate,WKUIDelegate>

@property (nonatomic,assign) BOOL isDebug;
@property (nonatomic,strong) WKWebView *webView;
@property (nonatomic,strong) WebViewJavascriptBridge *bridge;
@property (nonatomic,strong) NSString *loginToken;
@property (nonatomic,assign) ICXOauthType oauthType;

@property (nonatomic,weak)id <ICXOauthViewDelegate> icxOauthViewDelegate;

//使用loginToken和oauthType初始化设置后，调用此函数加载授权页
- (void)loadOauthView;

@end

NS_ASSUME_NONNULL_END
