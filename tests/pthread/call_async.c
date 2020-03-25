/*
 * Copyright 2020 The Emscripten Authors.  All rights reserved.
 * Emscripten is available under two separate licenses, the MIT license and the
 * University of Illinois/NCSA Open Source License.  Both these licenses can be
 * found in the LICENSE file.
 */

#include <stdio.h>
#include <assert.h>
#include <emscripten/threading.h>

int state = 0;

void increment() {
  state++;
}

void finish() {
#ifdef REPORT_RESULT
	REPORT_RESULT(1);
#endif
}

int main() {
  assert(state == 0);
  // This maybe_async call will be synchronous since we are on the right
  // thread already.
  emscripten_call_on_thread_maybe_async(emscripten_main_browser_thread_id(), EM_FUNC_SIG_V, &increment, 0);
  assert(state == 1);
  // This async call will actually be async.
  emscripten_call_on_thread_async(emscripten_main_browser_thread_id(), EM_FUNC_SIG_V, &increment, 0);
  assert(state == 1);
  emscripten_call_on_thread_async(emscripten_main_browser_thread_id(), EM_FUNC_SIG_V, &finish, 0);
}
