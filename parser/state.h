// Copyright 2020 Bret Taylor
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "../core/common.h"
#include "../core/error.h"
#include "ast.h"

namespace compiler::parser {

// Stores parser state when parsing the AST with Bison and Flex.
class State {
 public:
  State(shared_ptr<Error> error, shared_ptr<Module> module)
      : module(module),
        error(error),
        data(module->file->contents),
        state(nullptr),
        line(1),
        column(1) {
  }

  shared_ptr<Module> module;
  shared_ptr<Error> error;
  string data;
  void* state;
  int line;
  int column;
};

}
