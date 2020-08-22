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

#include "parse.h"

#include "../core/error.h"
#include "../parser/parse.h"

namespace compiler::commands {

Parse::Parse()
    : Command("parse", "Verify the syntax of a program",
              {
                  Option("strict", "Treat compiler warnings as fatal errors"),
              },
              "path…") {
}

bool Parse::execute(const string& executable, map<string, bool>& flags,
                    map<string, string>& options,
                    vector<string>& arguments) {
  if (arguments.size() < 1) {
    print_help(executable);
    return false;
  }
  auto error = make_shared<TerminalError>();
  Error::Level fail_level =
      flags["strict"] ? Error::Level::WARNING : Error::Level::ERROR;
  bool success = true;
  for (auto path : arguments) {
    if (!parser::parse(error, path)) {
      success = false;
    }
  }
  return success && error->count(fail_level) == 0;
}

}
