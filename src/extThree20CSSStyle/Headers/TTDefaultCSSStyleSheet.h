//
// Copyright 2009-2011 Facebook
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#import "Three20Style/TTDefaultStyleSheet.h"

@class TTCSSStyleSheet;
@class TTCSSRuleSet;
@protocol TTCSSApplyProtocol;

#define TTCSSBGCOLOR(selector)  [[TTDefaultCSSStyleSheet globalCSSStyleSheet] \
                                  backgroundColorForCSSSelector:selector]

/**
 * Retrieve a Full CSS Rule (TTCSSRuleSet) for specified selector.
 */
#define TTCSSRule(selector) (TTCSSRuleSet*)[[TTDefaultCSSStyleSheet\
									globalCSSStyleSheet] css:selector]

/**
 * Retrieve an value for a property of an Rule Set (TTCSSRuleSet) for specified selector.
 */
#define TTCSS(selector,property) [TTCSSRule(selector) property]

/**
 * Apply an CSS style to specified object.
 * The object must conform with the TTCSSApplyProtocol.
 */
#define TTApplyCSS(selector,object) [[TTDefaultCSSStyleSheet globalCSSStyleSheet]\
												applyCssFromSelector:selector\
													toObject:object]


@interface TTDefaultCSSStyleSheet : TTDefaultStyleSheet {
@private
  TTCSSStyleSheet* _styleSheet;
}

@property (nonatomic, readonly) TTCSSStyleSheet* styleSheet;

- (BOOL)addStyleSheetFromDisk:(NSString*)filename;

- (UIColor*)backgroundColorForCSSSelector:(NSString*)cssSelector;

+ (TTDefaultCSSStyleSheet*)globalCSSStyleSheet;

/**
 * CSS Rule Set.
 */
-(TTCSSRuleSet*)css:(NSString*)selectorName;

/**
 * CSS Rule Set, also accept an specific state.
 */
-(TTCSSRuleSet*)css:(NSString*)selectorName forState:(UIControlState)state;

/**
 * Apply the rules for the specified selector to the informed object. This object
 * must conform with the TTCSSApplyProtocol to read and properly apply the CSS rules.
 */
-(void)applyCssFromSelector:(NSString*)selectorName toObject:(id<TTCSSApplyProtocol>)anObject;

@end
