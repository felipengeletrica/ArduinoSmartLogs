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

#include <stdio.h>
#include <stdarg.h>


#include "logs.h"

static struct {
  void *udata;
  HardwareSerial *serial;
  int level;
  int quiet;
} L;


static const char *level_names[] = {
  "TRACE", "DEBUG", "INFO", "WARN", "ERROR", "FATAL"
};

#ifdef LOG_USE_COLOR
static const char *level_colors[] = {
  "\x1b[94m", "\x1b[36m", "\x1b[32m", "\x1b[33m", "\x1b[31m", "\x1b[35m"
};
#endif

void log_setserial(HardwareSerial *serial) {
  L.serial = serial;
}

void log_setudata(void *udata) {
  L.udata = udata;
}

void log_setlevel(int level) {
  L.level = level;
}

void log_setquiet(int enable) {
  L.quiet = enable ? 1 : 0;
}

void log_log(int level, const char *file,const int line,  const char *fmt, ...) {

  if (level < L.level){
    return;
  }
  if (!L.quiet) {
    va_list args;
    char header[50];
    char buf[BUF_SIZE];

  #ifdef LOG_USE_COLOR
  sprintf(header, "%s%-5s\x1b[0m \x1b[90m%s:%d\x1b[0m",
        level_colors[level], level_names[level], file, line);
  #else
      sprintf(header, "%-5s %s:%d", level_names[level], file, line);
  #endif
      	va_start(args, fmt);
      	ets_vsnprintf(buf, BUF_SIZE, fmt, args);
      	va_end(args);

      	char buff[BUF_SIZE];
      	sprintf(buff, "%s %s", header, buf);
        //Print to serial
        L.serial->println(buff);
    }
}
