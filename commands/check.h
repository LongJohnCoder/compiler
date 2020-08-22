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

#include "command.h"

namespace compiler::commands {

// Verifies the semantic correctness of a program.
class Check : public Command {
 public:
  Check();

 protected:
  virtual bool execute(const string& executable, map<string, bool>& flags,
                       map<string, string>& options,
                       vector<string>& arguments) override;
};

}
