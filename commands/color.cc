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

#include "color.h"

namespace compiler::commands {

string color(Color color, const string& value, bool tty) {
  if (!tty) {
    switch (color) {
      case Color::COMMAND:
      case Color::DESCRIPTION:
      case Color::ERROR:
        return value;
      case Color::OPTIONS:
      case Color::ARGUMENTS:
        return "[" + value + "]";
    }
  } else {
    switch (color) {
      case Color::COMMAND:
        return "\033[1m" + value + "\033[0m";
      case Color::DESCRIPTION:
        return value;
      case Color::OPTIONS:
        return "\033[2m[" + value + "]\033[0m";
      case Color::ARGUMENTS:
        return "\033[2m" + value + "\033[0m";
      case Color::ERROR:
        return "\033[31;1m" + value + "\033[0m";
    }
  }
}

}
