//
//  Transloadit.h
//  Transloadit
//
//  Created by Mark Masterson on 8/19/16.
//  Copyright © 2016 Mark R. Masterson. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TransloaditProtocol.h"
#import "Assembly.h"
#import "AssemblyStep.h"
#import "APIState.h"
#import "APIObjectType.h"
#import "NSString+Utils.h"
#import <TUSKit/TUSKit.h>

#pragma mark - Resource Includes

typedef void (^TransloaditUploadResultBlock)(NSURL* _Nonnull fileURL);
typedef void (^TransloaditUploadFailureBlock)(NSError* _Nonnull error);
typedef void (^TransloaditUploadProgressBlock)(int64_t bytesWritten, int64_t bytesTotal);

@interface Transloadit : NSObject<TransloaditProtocol>
@property (readwrite, copy) _Nullable TransloaditUploadResultBlock resultBlock;
@property (readwrite, copy) _Nullable TransloaditUploadFailureBlock failureBlock;
@property (readwrite, copy) _Nullable TransloaditUploadProgressBlock progressBlock;


@property (nonatomic, strong) TUSSession *tusSession; // Session to use for uploads

@property (nonatomic, strong) NSString *secret; // Transloadit Secret

@property (nonatomic, strong) NSString *key; // Transloadit Key

@property (nonatomic, strong) NSDictionary *headers;

@property (nonatomic, strong) TUSResumableUpload *tus;

@property (nonatomic, strong) TUSUploadStore *tusStore;


- (id)initWithKey:(NSString *)key andSecret:(NSString *)secret;

- (NSString*)generateSignatureWithParams:(NSDictionary *)params;

- (NSString *)signWithKey:(NSString *)key usingData:(NSString *)data;

- (void) invokeAssembly: (Assembly *)assembly;


@end
