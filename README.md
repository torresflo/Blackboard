![GitHub license](https://img.shields.io/github/license/torresflo/Blackboard.svg)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)](http://makeapullrequest.com)
![GitHub contributors](https://img.shields.io/github/contributors/torresflo/Blackboard.svg)
![GitHub issues](https://img.shields.io/github/issues/torresflo/Blackboard.svg)

<p align="center">
  <h1 align="center">Blackboard</h3>

  <p align="center">
    A C++ container that can store any value of any type referenced by a unique ID.
    <br />
    Usually, Blackboards are used in games in combination of a behavior tree to store and retrieve easily data or computation results.       <br/>
    But they can also be used as a usefull container that can store anything.
    <br />
    <a href="https://github.com/torresflo/Kinect-Lab/issues">Report a bug or request a feature</a>
  </p>
</p>

## Table of Contents

* [Getting Started](#getting-started)
  * [Installation](#installation)
* [Usage](#usage)
  * [Example](#example)
  * [Performance](#performance)
* [Contributing](#contributing)
* [License](#license)

## Getting Started

### Installation

Clone the repo (`git clone https:://github.com/torresflo/Blackboard.git`) and add the Container folder to your project, you are ready to go!

## Usage

You can have a look at the example below.

### Example

```cpp
#include <Container\Blackboard.hpp>

//Declaration of the blackboard and the managed types
Container::Blackboard<int, bool, std::string> blackboard;

//Declaration of some IDs to use
blackboard.declare<int>(BLACKBOARD_ID("IDInteger"), 0);
blackboard.declare<bool>(BLACKBOARD_ID("IDBool"), false);
blackboard.declare<std::string>(BLACKBOARD_ID("IDString"), "My String");

//Let's use the container
blackboard.setValue<int>(BLACKBOARD_ID("IDInteger"), 42);
int myInt = blackboard.getValue<int>(BLACKBOARD_ID("IDInteger"));

// Warning: you cannot access non existing IDs
bool myBoolean = blackboard.getValue<bool>(BLACKBOARD_ID("AnInvalidID")); //This will create an out_of_range exception.

//Better to do this if the id is unknown
if(blackboard.exist<bool>(BLACKBOARD_ID("AnUnknonwID")))
{
    bool myBoolean = blackboard.getValue<bool>(BLACKBOARD_ID("AnUnknonwID")); //Can access safely
    //...
}
//...

```

### Performance

Internally, the Blackboard is using `std::unordered_map` (you cannot access this container directly).

It means the complexity in both reading and writing is:
- Average case: constant
- Worst case: linear in size.

For information about performance and complexity of the `std::unordered_map`, see <a href="https://en.cppreference.com/w/cpp/container/unordered_map">here</a>.

## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<!-- LICENSE -->
## License

Distributed under the GNU General Public License v3.0. See `LICENSE` for more information.
