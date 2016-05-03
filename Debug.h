/*
 * Debug.h
 *
 *  Created on: 2016Äê5ÔÂ3ÈÕ
 *      Author: user
 */

#ifndef DEBUG_H_
#define DEBUG_H_

#define DEBUG

#undef DEBUG

#define SLASH /
#define STAR *

#ifdef DEBUG

//#define private public
#define PRIVATE public

#define BOC SLASH##SLASH
#define EOC SLASH##SLASH

#else

#define PRIVATE private

#define BOC SLASH##STAR
#define EOC STAR##SLASH

#endif

#endif /* DEBUG_H_ */
