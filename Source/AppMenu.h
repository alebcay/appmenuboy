//
//  AppMenu.h
//  AppMenu
//
//  Created by David Oster on 1/20/08.
//  Copyright 2008 Google Inc.
//
//  Licensed under the Apache License, Version 2.0 (the "License"); you may not
//  use this file except in compliance with the License.  You may obtain a copy
//  of the License at
// 
//  http://www.apache.org/licenses/LICENSE-2.0
// 
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
//  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
//  License for the specific language governing permissions and limitations under
//  the License.
//
// See AppMenu.m for a real read-me

#import <Cocoa/Cocoa.h>

// is app's delegate. is dockMenu's delegate
@interface AppMenu : NSObject {
  IBOutlet NSMenu *dockMenu_;
  IBOutlet NSWindow *preferencesWindow_;
  IBOutlet NSControl *ignoringParentheses_;

  // builder thread only
  NSMenu *appMenu_;
  BOOL isIgnoringParentheses_;

  // Maps paths to kqueues
  NSMutableDictionary *kqueues_;

  // builder state machine reentrancy guard
  BOOL isRebuilding_;

  // between KQueue callback, builder
  BOOL moreToDo_;

  NSTimeInterval timeOfLastYield_;
}
- (IBAction)showPreferencesPanel:(id)sender;
- (IBAction)toggleIgnoringParentheses:(id)sender;
@end
