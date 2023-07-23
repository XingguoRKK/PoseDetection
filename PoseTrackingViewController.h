// Copyright 2020 The MediaPipe Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#import <UIKit/UIKit.h>

#import <CoreVideo/CoreVideo.h>
#import <Foundation/Foundation.h>

#import "mediapipe/examples/ios/common/CommonViewController.h"

@interface FaceMeshIOSLibFaceLandmarkPoint : NSObject
@property (nonatomic) float x;
@property (nonatomic) float y;
@property (nonatomic) float z;
@end

@interface FaceMeshIOSLibNormalizedRect : NSObject
@property (nonatomic) float centerX;
@property (nonatomic) float centerY;
@property (nonatomic) float height;
@property (nonatomic) float width;
@property (nonatomic) float rotation;
@end

@protocol FaceMeshIOSLibDelegate <NSObject>
@optional
/** 
 * Array of faces, with faces represented by arrays of face landmarks 
*/
- (void)didReceiveFaces:(NSArray <NSArray<FaceMeshIOSLibFaceLandmarkPoint *>*>*)faces;
/** 
 * Array of faces, with faces represented by arrays of face landmarks 
*/
- (void)didReceiveFaceBoxes:(NSArray <FaceMeshIOSLibNormalizedRect *>*)faces;
@end


@interface PoseTrackingViewController : CommonViewController

@end
