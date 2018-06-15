/*
 * logs.h
 * Based in c rxi
 * https://github.com/rxi/log.c
 * License MIT
 *
 *  Created on: 12 de fev de 2018
 *      Author: felipevargas
 
 The MIT License (MIT)
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

#ifndef SRC_LOGS_LOGS_H_
#define SRC_LOGS_LOGS_H_

#include <Arduino.h>

#define BUF_SIZE  1000

#define LOG_VERSION "0.0.2"
#define LOG_USE_COLOR

enum {
	LOG_TRACE,
	LOG_DEBUG,
	LOG_INFO,
	LOG_WARN,
	LOG_ERROR,
	LOG_FATAL
};

#define logtrace(...) log_log(LOG_TRACE, __FILE__, __LINE__, __VA_ARGS__)
#define logdebug(...) log_log(LOG_DEBUG, __FILE__, __LINE__, __VA_ARGS__)
#define loginfo(...)  log_log(LOG_INFO,  __FILE__, __LINE__, __VA_ARGS__)
#define logwarn(...)  log_log(LOG_WARN,  __FILE__, __LINE__, __VA_ARGS__)
#define logerror(...) log_log(LOG_ERROR, __FILE__, __LINE__, __VA_ARGS__)
#define logfatal(...) log_log(LOG_FATAL, __FILE__, __LINE__, __VA_ARGS__)

void log_setserial(HardwareSerial *serial);
void log_setudata(void *udata);
void log_setlevel(int level);
void log_setquiet(int enable);

void log_log(int level, const char *file, const int line, const char *fmt, ...);

#endif /* SRC_LOGS_LOGS_H_ */
