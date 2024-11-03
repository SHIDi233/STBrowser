// Copyright (c) 2024 Marshall A. Greenblatt. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//    * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//    * Neither the name of Google Inc. nor the name Chromium Embedded
// Framework nor the names of its contributors may be used to endorse
// or promote products derived from this software without specific prior
// written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool and should not edited
// by hand. See the translator.README.txt file in the tools directory for
// more information.
//
// $hash=f5ca62ba996538f1ce7a3b94a70bb3ce2fcc9fca$
//

#ifndef CEF_INCLUDE_CAPI_VIEWS_CEF_LAYOUT_CAPI_H_
#define CEF_INCLUDE_CAPI_VIEWS_CEF_LAYOUT_CAPI_H_
#pragma once

#include "include/capi/cef_base_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

struct _cef_box_layout_t;
struct _cef_fill_layout_t;

///
/// A Layout handles the sizing of the children of a Panel according to
/// implementation-specific heuristics. Methods must be called on the browser
/// process UI thread unless otherwise indicated.
///
typedef struct _cef_layout_t {
  ///
  /// Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  /// Returns this Layout as a BoxLayout or NULL if this is not a BoxLayout.
  ///
  struct _cef_box_layout_t*(CEF_CALLBACK* as_box_layout)(
      struct _cef_layout_t* self);

  ///
  /// Returns this Layout as a FillLayout or NULL if this is not a FillLayout.
  ///
  struct _cef_fill_layout_t*(CEF_CALLBACK* as_fill_layout)(
      struct _cef_layout_t* self);

  ///
  /// Returns true (1) if this Layout is valid.
  ///
  int(CEF_CALLBACK* is_valid)(struct _cef_layout_t* self);
} cef_layout_t;

#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_VIEWS_CEF_LAYOUT_CAPI_H_
